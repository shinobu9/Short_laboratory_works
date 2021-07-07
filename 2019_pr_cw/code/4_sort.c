#include "4_sort.h"

void sortByFifth(Text* text){
    qsort(text->arr, text->size, sizeof(Sentence), symcodecmp);
}

int symcodecmp(const void* a, const void* b){
    Sentence* snt1 = (Sentence*)a;
    Sentence* snt2 = (Sentence*)b;

    if(wcslen(snt1->normal) < 5)
        return 1;
    if(wcslen(snt2->normal) < 5)
        return -1;

    int index = 4;
    wchar_t c1 = snt1->normal[index];
    if( c1 == L' ')
        c1 = snt1->normal[index+1];
    wchar_t c2 = snt2->normal[index];
    if( c2 == L' ')
        c2 = snt2->normal[index+1];
    return (int)c2 - (int)c1;
}