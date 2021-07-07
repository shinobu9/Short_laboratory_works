#include <iostream>
#include <cstdlib>
#include <cstring>
#include <getopt.h>
#include "structures.hpp"
#include "printInfoHelp.hpp"
#include "tasks.hpp"
#include "saveFile.hpp"
#include "checker.hpp"
#include "argumentHandler.hpp"
#include "processing.hpp"

//using namespace std;

int main(int argc, char **argv){

    int c;
    int index;
    char* next;
    int i = 0;

    char* filename = NULL;
    char* alternative = NULL;
    
    FILE* f = NULL;
    Rgb **arr = NULL;
    BitmapFileHeader bmfh;
	BitmapInfoHeader bmih;

    int counts[2] = {-1,-1};
	int start[2] = {-1,-1};
	int end[2] = {-1,-1};
	int to[2] = {-1,-1};
	int old_color[3] = {-1,-1,-1};
	int new_color[3] = {-1,-1,-1};

    char actions[100];
    int action_counter = 0;

    while (action_counter < 100)
    {
      static struct option long_options[] = {
          {"info",          required_argument,  0, 'i'},          
          {"file",          required_argument,  0, 'f'},
          {"copy-patch",    no_argument,        0, 'c'},
          {"reflect-x",     no_argument,        0, 'x'},
          {"reflect-y",     no_argument,        0, 'y'},
          {"replace-color", no_argument,        0, 'r'},
          {"divide",        required_argument,  0, 'd'},
          {"alter",         required_argument,  0, 'a'},
          {"start",         required_argument,  0, 's'},
          {"end",           required_argument,  0, 'e'},
          {"old",           required_argument,  0, 'o'},
          {"new",           required_argument,  0, 'n'},
          {"to",            required_argument,  0, 't'},
          {"help",          no_argument,        0, 'h'},
          {0, 0, 0, 0}
        };

      int option_index = 0;

      c = getopt_long (argc, argv, "i:hf:a:cxyrd:s:e:o:n:t:", long_options, &option_index);

      	if (c == -1)
       		break;
      	switch (c){

        case 'i': // info
        	filename = (char*)malloc((strlen(optarg)+1)*sizeof(char));
            strcpy(filename, optarg);
            f = fopen(filename, "rb");
            if(f==NULL){
            	printf("Could not open the file.\n");
              free(filename);
            	return 1;
            }
			       fread(&bmfh,1,sizeof(BitmapFileHeader),f);
			       fread(&bmih,1,sizeof(BitmapInfoHeader),f);
			       printInfo(bmfh, bmih);
    		    if(!typeCheck(&bmfh, &bmih)){
        		    printf("Unfortunately, this format is not supported. See -h(--help).\n");
    		    }
    		    fclose(f);
            free(filename);
            break;

        case 'h': // help
            printHelp();
            return 0;

        case 'f': // file
            filename = (char*)realloc(filename, (strlen(optarg)+1)*sizeof(char));
            strcpy(filename, optarg);
			       if(!fillArr(filename, &arr, &bmfh, &bmih) || arr==NULL){
                free(filename);
				        return 1;
              }
            break;

        case 'a': // alternative
            alternative = (char*)malloc((strlen(optarg)+1)*sizeof(char));
            strcpy(alternative, optarg);
            break;

        case 'c': // --copy-patch no args
            actions[action_counter++] = 'c';
            break;

        case 'x': // --reflect-x no args
            actions[action_counter++] = 'x';
            break;

        case 'y': // --reflect-y no args
            actions[action_counter++] = 'y';
            break;

        case 'r': // --replace no args
            actions[action_counter++] = 'r';
            break;

        case 'd': // --divide 2 args
            optind = readOperands(argc, optind, argv, counts, 2);
            actions[action_counter++] = 'd';
            break;

        case 's': // start
            optind = readOperands(argc, optind, argv, start, 2);
          	break;

        case 'e': // end
            optind = readOperands(argc, optind, argv, end, 2);
          	break;

        case 't': // to
            optind = readOperands(argc, optind, argv, to, 2);
          	break;

        case 'o': // 3 args
            optind = readOperands(argc, optind, argv, old_color, 3);
          	break;

        case 'n': // 3 args
            optind = readOperands(argc, optind, argv, new_color, 3);
          	break;        

        case ':': /* error - missing operand */
            fprintf(stderr, "Option -%c requires an operand. See -h(--help).\n", optopt);
            break;

        case '?': /* error - unknown option */
            fprintf(stderr, "See -h(--help).\n");
            return 1;

        default:
            return 0;
      }
      
    }

    if(filename == NULL){
        if (optind < argc){
            while (optind < argc){
                filename = (char*)realloc(filename, (strlen(argv[optind])+1)*sizeof(char));
                strcpy(filename, argv[optind]);
                optind++;
            }
        }
        else{
            printf("Filename not entered. See -h(--help).\n");
            //memoClean(arr, bmih.height, filename, alternative);
            if(alternative)
              free(alternative);
            return 1;
        }
        if(!fillArr(filename, &arr, &bmfh, &bmih) || arr==NULL){
            free(filename);
            if(alternative)
              free(alternative);
            return 1;
        }
    }
    Params params;
    params.filename 		= filename;
    params.alternative		= alternative;
    params.counts			= counts;
    params.start 			= start;
    params.end 				= end;
    params.to 				= to;
    params.old_color 		= old_color;
    params.new_color 		= new_color;
    params.actions			= actions;
    params.action_counter 	= action_counter;

    processing(&params, arr, &bmih, &bmfh);
    memoClean(arr, bmih.height, filename, alternative);
    
return 0;
}