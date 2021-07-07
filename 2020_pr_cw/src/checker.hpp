#pragma once

#include "structures.hpp"

int typeCheck(BitmapFileHeader* bmfh, BitmapInfoHeader* bmih);

int operandCheck(int flag, BitmapInfoHeader* bmih, int* start, int* end, int* to, int* old_color, int* new_color);