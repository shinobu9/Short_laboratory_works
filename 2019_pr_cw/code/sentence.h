#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#define DEF_SIZE 8

typedef struct Sentence{
	wchar_t** tokenized;
	wchar_t* normal;
	int length; // число слов
} Sentence;

void initializeSentence(Sentence *snt);
void sentenceReduce(wchar_t** snt);
wchar_t* readNormalSentence();
void tokenizeSentence(Sentence* snt);
void freeSentence(Sentence *snt);
