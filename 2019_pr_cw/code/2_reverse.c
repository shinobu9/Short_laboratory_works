#include "2_reverse.h"

void wordReverse(wchar_t* word, unsigned long int end){
    wchar_t temp;
    unsigned long int start = 0;
    while (start < end)
    {
        temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        start++;
        end--;
    }
}

void backwardTokens(Text* text){
    unsigned long len;
    unsigned long index;
    for(int i = 0; i < text->size; i++){
        index = 0;
        for(int j = 0; j < text->arr[i].length; j++){
            len = wcslen(text->arr[i].tokenized[j]);
            wordReverse(text->arr[i].tokenized[j], len-1);
            memcpy(text->arr[i].normal + index, text->arr[i].tokenized[j], len * sizeof(wchar_t));
            index += len + 1;
        }
    }
}