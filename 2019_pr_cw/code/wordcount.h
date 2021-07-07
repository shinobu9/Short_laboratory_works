#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#define DEF_SIZE 8

typedef struct WordCount{
	wchar_t** words;
	int* counts;
	int size;
} WordCount;

void wordCountReduce(WordCount* OList);
void freeWordCount(WordCount* OList);