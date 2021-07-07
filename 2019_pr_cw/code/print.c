#include "print.h"

void printUserMenu(){
    wprintf(L"\033[1;96mВыберите действие:\033[0m\n"
            L"\t\033[1;33m1 - Распечатать каждое слово и количество его повторений в тексте.\n"
            L"\t2 - Преобразовать каждое предложение так, чтобы символы в каждом слове шли в обратном порядке.\n"
            L"\t3 - Удалить предложения, в которых встречается запятая.\n"
            L"\t4 - Отсортировать предложения по уменьшению значения кода 5 символа предложения.\n"
            L"\tОстальные цифры - Выйти.\033[0m\n"
            L"\n\033[1;96mВведите соответствующий номер: \033[0m");
}

void printText(Text* text){
    wprintf(L"\033[1;92mРезультат:\n\033[0m");
    for(int i=0; i<text->size;i++)
        wprintf(L"%ls\n",text->arr[i].normal);
}

void printWordCount(WordCount* OList){
    wprintf(L"\033[1;92mРезультат:\n\033[0m");
    for(int i = 0; i < OList->size; i++)
        wprintf(L"%ls = %d\n", OList->words[i], OList->counts[i]);
}