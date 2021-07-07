#include "processing.hpp"

int processing(Params* params, Rgb** arr, BitmapInfoHeader* bmih, BitmapFileHeader* bmfh){
	char* saveto = NULL;

	if(params->alternative == NULL){
        saveto = (char*)calloc(strlen(params->filename)+1, sizeof(char));
        strcpy(saveto, params->filename);
    }else{
        saveto = (char*)calloc(strlen(params->alternative)+1, sizeof(char));
        strcpy(saveto, params->alternative);
    }
    
    char c;
    for(int i = 0; i<params->action_counter; i++){
        c = params->actions[i];
        switch (c){
            case 'c':
                if(operandCheck(c, bmih, params->start, params->end, params->to, params->old_color, params->new_color)
                	&& copyPatch(arr, bmih, params->start, params->end, params->to)){
                    saveFile(saveto, arr, bmfh, bmih, 0, 0);
                }
                else{
                    printf("Incorrect operands in --copy-patch. See -h(--help).\n");
                    return 0;
                }
                break;

            case 'x':
                if(operandCheck(c, bmih, params->start, params->end, params->to, params->old_color, params->new_color)
                	&& reflectFragmentX(arr, params->start, params->end)){
                    saveFile(saveto, arr, bmfh, bmih, 0, 0);
                }
                else{
                    printf("Incorrect operands in --reflect-x. See -h(--help).\n");
                    return 0;
                }
                break;

            case 'y':
                if(operandCheck(c, bmih, params->start, params->end, params->to, params->old_color, params->new_color)
                	&& reflectFragmentY(arr, params->start, params->end)){
                    saveFile(saveto, arr, bmfh, bmih, 0, 0);
                }
                else{
                    printf("Incorrect operands in --reflect-y. See -h(--help).\n"); 
                    return 0;
                }
                break;

            case 'r':
                if(operandCheck(c, bmih, params->start, params->end, params->to, params->old_color, params->new_color)){
                    replaceColor(arr, bmih, params->old_color, params->new_color);
                    saveFile(saveto, arr, bmfh, bmih, 0, 0);
                }
                else{
                    printf("Incorrect operands in --replace-color. See -h(--help).\n");
                    return 0;
                }
                break;

            case 'd':
            	if(params->alternative != NULL && params->alternative[strlen(params->alternative)-1] != '/'){
            		printf("Invalid alternative path for --divide. Must be a directory.\n");
            		//memoClean(arr, bmih->height, params->filename, params->alternative, saveto);
            		return 0;
            	}
                char* saveto_copy = NULL;

                if(params->alternative == NULL){
                    int len = strlen(params->filename)-1;
                    while(len>=0 && params->filename[len]!='/'){
                        len = len - 1;
                    }
                    if(len==-1){ // save to current directory
                        saveto_copy = (char*)calloc(3, sizeof(char));
                        strcpy(saveto_copy, "./");
                    }else{ // save to the same directory as original file
                        saveto_copy = (char*)calloc(len+2, sizeof(char));
                        memmove(saveto_copy, params->filename, (len+1)*sizeof(char));
                        }
                }else{ // save to alternative directory
                    saveto_copy = (char*)calloc(strlen(params->alternative)+1, sizeof(char));
                    strcpy(saveto_copy, params->alternative);
                }
                if(!divideFile(arr, bmfh, bmih, params->counts[1], params->counts[0], saveto_copy)){
                    printf("Incorrect operands in --divide. See -h(--help).\n");
                    return 0;
                }
                else
                    printf("Result will be saved in: %s\n", saveto_copy);
                if(saveto_copy)
                    free(saveto_copy);
                break;
            }
        }
    if(saveto){
    	free(saveto);
    }
    return 1;
}