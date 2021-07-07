#include "sentence.h"

void initializeSentence(Sentence *snt) {
    snt->tokenized = NULL;
    snt->normal = NULL;
    snt->length = 0;
}

void sentenceReduce(wchar_t** snt){
    *snt = realloc(*snt, (wcslen(*snt)+1) * sizeof(wchar_t));
}

wchar_t* readNormalSentence(){
    int size = DEF_SIZE;
    int n = 0;
    wchar_t* input = malloc(size * sizeof(wchar_t));
    if(!input){
        wprintf(L"\033[1;91mНедостаточно памяти для нового предложения.\033[0m\n");
        exit(1);
    }
    wchar_t* buf = NULL;
    wchar_t wc;
    do{
        wc = fgetwc(stdin);
        if((n != 0)||(wc != L' ')){
            input[n] = wc;
            n++;
        }
        if(n == size - 2){
            size += DEF_SIZE;
            buf = realloc(input, size * sizeof(wchar_t));
            if(!buf){
                free(input);
                wprintf(L"\033[1;91mНедостаточно памяти для предложения.\033[0m\n");
                exit(1);
            }
            input = buf;
        }
    }while(!wcschr(L".\n", wc));
    input[n] = L'\0';
    sentenceReduce(&input);
    return input;
}

void tokenizeSentence(Sentence* snt){
    wchar_t* wcs = malloc( (wcslen(snt->normal)+1) * sizeof(wchar_t));
    memcpy(wcs, snt->normal, (wcslen(snt->normal)+1) * sizeof(wchar_t));
    wchar_t* pwc;
    wchar_t* tmp;
    wchar_t** tok = malloc(1 * sizeof(wchar_t*)); // array of words
    int n = 0;
    pwc = wcstok(wcs, L" ", &tmp);
    while (pwc != NULL)
    {
        tok[n] = pwc;
        n++;
        tok = realloc(tok, (n+1)*sizeof(wchar_t*));
        pwc = wcstok(NULL, L" ", &tmp);
    }
    snt->tokenized = tok;
    snt->length = n;
}

void freeSentence(Sentence *snt) {
    free(*snt->tokenized);
    free(snt->tokenized);
    free(snt->normal);
    snt->length = 0;
}