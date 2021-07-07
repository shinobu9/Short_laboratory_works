#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <sys/types.h>
#define HOMEPATH "./labyrinth"
#define PATTERN "@include (\\S+.txt)"
 
int isValid(char* string){
    regex_t regexCompiled;
 
    size_t maxGroups = 2;
 
    regmatch_t groupArray[maxGroups];
 
    const char* regexString = PATTERN;
 
    if(regcomp(&regexCompiled, regexString, REG_EXTENDED)){
        printf("Compiling error\n");
        return 0;
    }
 
    if(regexec(&regexCompiled, string, maxGroups, groupArray, 0) == 0){
        memmove(string, &string[groupArray[1].rm_so], sizeof(char) * ( groupArray[1].rm_eo - groupArray[1].rm_so ));
        string[groupArray[1].rm_eo - groupArray[1].rm_so] = '\0';
        regfree(&regexCompiled);
        return 1;
    }
    else{
        regfree(&regexCompiled);
        return 0;
    }  
}

void findFile(char* path, char* toFind, FILE** logPtr, char*** wayToMinotaur, int size, int cur);
void readFile(char* name, char* path, FILE** logPtr, char*** wayToMinotaur, int size, int cur);
 
int main(){
    FILE* result = fopen("result.txt", "w");
 
    int size = 3000;
    int cur = 0;
    char** wayToMinotaur = malloc(sizeof(char*) * size);
    for(int i=0; i<size; i++){
        wayToMinotaur[i] = malloc(128*sizeof(char));
    }
 
    if(!result){
        perror ("Could not open the result file");
        return 0;
    }
    char path[9000] = HOMEPATH;
    char first[10] = "file.txt";
    findFile(path, first, &result, &wayToMinotaur, size, cur);
    return 0;
}
 
void findFile(char* path, char* toFind, FILE** logPtr, char*** wayToMinotaur, int size, int cur){
    DIR *dir = opendir(path);
    if(dir){
        char buf[9000];
        struct dirent *de = readdir(dir);
        while(de){
            if(de->d_type == DT_DIR && strcmp(de->d_name, ".")!=0 && strcmp(de->d_name, "..")!= 0){
                int len = strlen(path);
                strcat(path, "/");
                strcat(path, de->d_name);
                findFile(path, toFind, logPtr, wayToMinotaur, size, cur);
                path[len] = '\0';
            }
            if(de->d_type == DT_REG && strcmp(de->d_name, toFind)==0){
                strcpy(buf, path);
                strcat(buf, "/");
                strcat(buf, de->d_name);
                readFile(buf, path, logPtr, wayToMinotaur, size, cur);
            }
            de = readdir(dir);
        }
        closedir(dir);
    }
}
 
void readFile(char* name, char* path, FILE** logPtr, char*** wayToMinotaur, int size, int cur){
    FILE* f = fopen(name, "r");
 
    if(!f){
        perror ("Could not open the text file");
        return;
    }
 
    char string[100];
 
    while(!feof(f)){
 
        fgets(string, 100, f);
        if(strchr(string, '\n')){
            *(strchr(string, '\n')) = '\0';
        }
       
        if(cur == 0 || strcmp((*wayToMinotaur)[cur-1], name)!=0){
            strcpy((*wayToMinotaur)[cur], name);
            cur++;
        }
 
        if(strcmp("Minotaur", string)==0){
            for(int i=0; i<cur; i++){
                fprintf(*logPtr, "%s\n", (*wayToMinotaur)[i]);
            }
            fclose(f);
            fclose(*logPtr);
            for(int i=0; i<size; i++){
                free((*wayToMinotaur)[i]);
            }
            free(*wayToMinotaur);
            exit(0);
        }
 
        if(isValid(string)){
            strcpy(path, HOMEPATH); 
            findFile(path, string, logPtr, wayToMinotaur, size, cur);
            char c = getc(f);
            if(c==PATTERN[0]){ungetc(PATTERN[0], f);}
        }
 
        if(strcmp("Deadlock", string)==0 || strcmp("Deadlock ", string)==0){      
            cur = cur - 1;
            break;
        }
    }
    fclose(f);
}
