#include "wordcount.h"


void wordCountReduce(WordCount* OList){
	OList->words = realloc(OList->words, OList->size * sizeof(wchar_t*));
    OList->counts = realloc(OList->counts, OList->size * sizeof(int));
}

void freeWordCount(WordCount* OList){
    free(OList->words);
    free(OList->counts);
    free(OList);
}
