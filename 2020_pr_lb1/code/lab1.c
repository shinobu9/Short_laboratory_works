#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#define TERM "Fin."
#define ADDSIZE 16

int read_til_terminal(char*** totext, char* terminal);

char* get_sentence();

int main(){
    char* regexString = "(\\w+\\:\\/\\/)?(www\\.)?((\\w+\\.)+(\\w+))\\/(\\w+\\/)*(\\w+\\.\\w+)";
    size_t maxGroups = 8;
    regmatch_t groupArray[maxGroups];
    regex_t regexCompiled;
    if(regcomp(&regexCompiled, regexString, REG_EXTENDED)){
        printf("Could not compile regular expression.\n");
        return 0;
    }
    char** text = malloc(1*sizeof(char*));
    int n = read_til_terminal(&text, TERM);

    for(int i = 0; i < n; i++){
        if(regexec(&regexCompiled, text[i], maxGroups, groupArray, 0) == 0){
            for(int j = groupArray[3].rm_so; j < groupArray[3].rm_eo; j++){
                printf("%c", text[i][j]);
            }
            printf(" - ");
            for(int k = groupArray[7].rm_so; k < groupArray[7].rm_eo; k++){
                printf("%c", text[i][k]);
            }
            printf("\n");
        }
    }
    regfree(&regexCompiled);
    for(int i = 0; i < n; i++){
        free(text[i]);
    }
    free(text);
    return 0;
}
int read_til_terminal(char*** totext, char* terminal){
    int n = 0;
    char** totexttest;
    do{
        totexttest = realloc(*totext, (++n)*sizeof(char*));
        if(!totexttest){
            printf("Could not allocate memory for text\n");
            free(*totext);
            return 0;
        }
        *totext = totexttest;
        *(*totext+n-1) = get_sentence();
    }while(strcmp(*(*totext+n-1), terminal));
    return n;
}

char* get_sentence(char*** totext){
    char* newsntc = malloc(ADDSIZE*sizeof(char));
    char* newsntctest;
    char c;
    int size = ADDSIZE;
    int i = 0;
    while((c = getc(stdin)) && (c != '\n')){
        if(i == size-2){
            size += ADDSIZE;
            newsntctest = realloc(newsntc, size*sizeof(char));
            if(!newsntctest){
                printf("Could not allocate memory for sentence\n");
                free(newsntc);
                free(*totext);
                return 0;
            }
            newsntc = newsntctest;
        }
        newsntc[i] = c;
        i++;
        if(strcmp(newsntc, TERM) == 0){
            newsntc[i] = '\0';
            return newsntc;
        }
    }
    newsntc[i] = '\0';
    return newsntc;
}