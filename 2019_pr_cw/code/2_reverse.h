#pragma once

#include <string.h>
#include <wchar.h>
#include "text.h"

void wordReverse(wchar_t* word, unsigned long int end);
void backwardTokens(Text* text);