#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TERM "Dragon flew away!"

int read_til_terminal(char*** totext, char* terminal);

char* get_sentence();

int del_by_feature(char** text, int n);

int main(){
    char** text = malloc(1*sizeof(char));
    int n = read_til_terminal(&text, TERM);
    int m = del_by_feature(text, n);
    for(int i=0; i<m; i++){
        puts(text[i]);
        free(text[i]);
    }
    puts(text[n]);
    free(text[n]);
    free(text);
    printf("Количество предложений до %d и количество предложений после %d", n, m);
    return 0;
}

int read_til_terminal(char*** totext, char* terminal){
    int n = 0;
    do{
        *totext = realloc(*totext, (++n)*sizeof(char*));
        *(*totext+n-1) = get_sentence();

    }while(strcmp(*(*totext+n-1), terminal));
    //free(*(*totext+n-1)); //terminal sentence deletion
    return n-1;
}

char* get_sentence(){
    char* newsntc = malloc(1*sizeof(char));
    char c;
    int i = 0;
    while((c = getc(stdin)) && (c != '.') && (c != '?') && (c != ';') && (c != '!')){
        newsntc[i] = c;
        i++;
        newsntc = realloc(newsntc, (i+1)*sizeof(char));
    }
    newsntc = realloc(newsntc, (i+2)*sizeof(char));
    newsntc[i++] = c;
    newsntc[i] = '\0';
    c = getc(stdin);
    return newsntc;
}

int del_by_feature(char** text, int n){
    int count = 0;
    int i = 0;
    while(i<n){
        count = 0;
        for(int j = 0; j<strlen(text[i]); j++){
            if(isupper(text[i][j]))
                count++;
        }
        if(count > 1){
            free(text[i]);
            for(int u = i+1; u<n; u++)
                text[u-1] = text[u];
            n--;
        }
        else{
            i++;
        }
    }
    return n;
}