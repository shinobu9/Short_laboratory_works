#include "text.h"


void initializeText(Text *text) {
    text->arr = NULL;
    text->size = 0;
}

void textReduce(Text* text){
    text->arr = realloc(text->arr, text->size * sizeof(Sentence));
}

void readText(Text* text){
    int arr_size = DEF_SIZE;
    Sentence* buf = NULL;
    int newline = 0;
    text->arr = malloc(arr_size * sizeof(Sentence));
    while(newline < 2) {
        wchar_t *ws = readNormalSentence();
        if (!wcscmp(ws, L"\n")) {
            free(ws);
            newline += 1;
        } else {
            newline = 0;
            initializeSentence(&text->arr[text->size]);
            text->arr[text->size].normal = ws;
            tokenizeSentence(&text->arr[text->size]);
            text->size += 1;
            if (text->size == arr_size - 1) {
                arr_size += DEF_SIZE;
                buf = realloc(text->arr, arr_size * sizeof(Sentence));
                if (!buf) {
                    freeText(text);
                    wprintf(L"\033[1;91mНедостаточно памяти для текста\033[0m\n");
                    exit(1);
                }
                text->arr = buf;
            }
        }
    }
    textReduce(text);
}

void removeRepeated(Text* text){
    int i = 0;
    while(i < text->size-1){
        int j = i+1;
        while(j < text->size){
            if(!wcscasecmp(text->arr[i].normal, text->arr[j].normal)){
                deleteSentenceFromArray(text, j);
            }
            else{
                j++;
            }
        }
        i++;
    }
    textReduce(text);
}

void deleteSentenceFromArray(Text* text, int index){
    freeSentence(&text->arr[index]);
    for(int k = index; k < text->size-1; k++)
        text->arr[k] = text->arr[k+1];
    text->size--;
}

void freeText(Text* text){
    for (int i = 0; i < text->size; i++)
        freeSentence(&text->arr[i]);
    free(text->arr);
    text->size = 0;
    free(text);
}