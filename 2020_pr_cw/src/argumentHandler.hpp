#pragma once

#include "structures.hpp"
#include "checker.hpp"

int fillArr(char* filename, Rgb*** arr_p, BitmapFileHeader* bmfh_p, BitmapInfoHeader* bmih_p);

int readOperands(int argc, int optind, char** argv, int* operands, int operand_count);

void memoClean(Rgb** arr, int H, char* filename, char* alternative);