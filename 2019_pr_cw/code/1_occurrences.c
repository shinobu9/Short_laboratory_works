#include "1_occurrences.h"

WordCount* countOccurrences(Text* text){
    WordCount* OList = malloc(sizeof(WordCount));
    OList->size = DEF_SIZE;
    OList->words = malloc(OList->size * sizeof(wchar_t*));
    OList->counts = calloc(OList->size, sizeof(int));
    wchar_t** wbuf;
    int* cbuf;
    int n = 0;
    int index;
    for(int i=0; i<text->size; i++){
        for(int j = 0; j < text->arr[i].length; j++){
            index = isInList(text->arr[i].tokenized[j], OList->words, n);
            if(index >= 0)
                OList->counts[index] += 1;
            else {
                OList->words[n] = text->arr[i].tokenized[j];
                OList->counts[n] = 1;
                n++;
            }
            if(n == OList->size){
                OList->size+=DEF_SIZE;
                wbuf = realloc(OList->words, OList->size * sizeof(wchar_t*));
                if(!wbuf){
                    wprintf(L"\033[1;91mНедостаточно памяти для массива слов\n\033[1;91m");
                    freeWordCount(OList);
                    exit(1);
                }
                OList->words = wbuf;
                cbuf = realloc(OList->counts, OList->size * sizeof(int));
                if(!cbuf){
                    wprintf(L"\033[1;91mНедостаточно памяти для массива вхождений\n\033[1;91m");
                    freeWordCount(OList);
                    exit(1);
                }
                OList->counts = cbuf;
            }
        }
    }
    OList->size = n;
    wordCountReduce(OList);
    return OList;
}

int isInList(wchar_t* token, wchar_t** list, int n){
    for(int i = 0; i < n; i++){
        if(!wcscasecmp(token, list[i]))
            return i;
    }
    return -1;
}
