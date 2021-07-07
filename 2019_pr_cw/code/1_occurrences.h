#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#define DEF_SIZE 8
#include "text.h"
#include "wordcount.h"

WordCount* countOccurrences(Text* text);
int isInList(wchar_t* token, wchar_t** list, int n);