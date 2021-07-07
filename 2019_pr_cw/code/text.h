#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#define DEF_SIZE 8
#include "sentence.h"

typedef struct Text{
	Sentence* arr;
	int size;
} Text;

void initializeText(Text *text);
void textReduce(Text* text);
void readText(Text* text);
void removeRepeated(Text* text);
void deleteSentenceFromArray(Text* text, int index);
void freeText(Text* text);