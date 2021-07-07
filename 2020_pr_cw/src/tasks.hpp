#pragma once

#include "structures.hpp"

int divideFile(Rgb** arr, BitmapFileHeader* bmfh_p, BitmapInfoHeader* bmih_p, int countH, int countW, char* prefix);

void replaceColor(Rgb** arr, BitmapInfoHeader* bmih, int* old_color, int* new_color);

int reflectFragmentX(Rgb** arr, int* left, int* right);

int reflectFragmentY(Rgb** arr, int* left, int* right);

int copyPatch(Rgb** arr, BitmapInfoHeader* bmih_p, int* left, int* right, int* to);