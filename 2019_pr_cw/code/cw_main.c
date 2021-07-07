#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "print.h"
#include "sentence.h"
#include "text.h"
#include "wordcount.h"
#include "1_occurrences.h"
#include "2_reverse.h"
#include "3_del.h"
#include "4_sort.h"

int main()
{
	setlocale(LC_ALL, "");
	Text* text = malloc(sizeof(Text));
	initializeText(text);
	int choice = 0;
	wprintf(L"\033[1;96mВведите текст:\033[0m\n");
	readText(text);
	removeRepeated(text);
	while(1){
		printUserMenu();
        wscanf(L"%d", &choice);
		switch(choice){
			case 1:;
				WordCount* OList = countOccurrences(text);
				printWordCount(OList);
				freeWordCount(OList);
				break;
			case 2:
				backwardTokens(text);
                printText(text);
				break;
			case 3:
				deleteByComma(text);
				printText(text);
				break;
			case 4:
				sortByFifth(text);
				printText(text);
				break;
		   	default:
		        freeText(text);
				return 0;
		}
	}
}