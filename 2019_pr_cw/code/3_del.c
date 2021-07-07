#include "3_del.h"

void deleteByComma(Text* text){
    int i = 0;
    while(i < text->size){
        if(wcschr(text->arr[i].normal, L','))
            deleteSentenceFromArray(text, i);
        else
            i++;
    }
    textReduce(text);
}