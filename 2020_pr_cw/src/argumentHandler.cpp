#include "argumentHandler.hpp"

int fillArr(char* filename, Rgb*** arr_p, BitmapFileHeader* bmfh_p, BitmapInfoHeader* bmih_p){
	FILE* f = fopen(filename, "rb");
    if(f==NULL){
        fprintf(stderr, "Co!uld not open the file: %s\n", filename);
        return 0;
    }
	fread(bmfh_p,1,sizeof(BitmapFileHeader),f);
	fread(bmih_p,1,sizeof(BitmapInfoHeader),f);
    if(!typeCheck(bmfh_p, bmih_p)){
        printf("Unfortunately, this format is not supported. See -h(--help).\n");
        return 0;
    }

	unsigned int H = bmih_p->height;
	unsigned int W = bmih_p->width;

	*arr_p = (Rgb**)malloc(H*sizeof(Rgb*));
    if(*arr_p==NULL){
        fprintf(stderr, "Too little memory.\n");
        return 0;
    }
	for(int i=0; i<H; i++){
		(*arr_p)[i] = (Rgb*)malloc(W * sizeof(Rgb) + (W*3)%4);
        if((*arr_p)[i] == NULL){
            for(int j=0; j<i; j++)
                free((*arr_p)[j]);
            free(*arr_p);
            fprintf(stderr, "Too little memory.\n");
            return 0;
        }
		fread((*arr_p)[i],1,W * sizeof(Rgb) + (W*3)%4,f);
	}
	fclose(f);
	return 1;
}

void memoClean(Rgb** arr, int H, char* filename, char* alternative){
    for(int i=0; i<H; i++){
        if(arr[i]!=NULL)
            free(arr[i]);
    }
    if(arr!=NULL)
        free(arr);
    if(alternative!=NULL)
        free(alternative);
    if(filename!=NULL)
        free(filename);
    
}

int readOperands(int argc, int optind, char** argv, int* operands, int operand_count){
    // returns optind
    int index = optind - 1;
    int i=0;
    //char* next = argv[index];
    while(i < operand_count && index < argc){// && next[0] != '-'){
        //next = argv[index];
        operands[i++] = atoi(argv[index]);
        index++;
    }
    if(index < argc){
        return index-1;
    }
    else{
        return index;
    }
}