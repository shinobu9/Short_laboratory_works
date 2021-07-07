#include "tasks.hpp"
#include "saveFile.hpp"

int divideFile(Rgb** arr, BitmapFileHeader* bmfh_p, BitmapInfoHeader* bmih_p, int countH, int countW, char* prefix){
    if(countH < 1 || countH > bmih_p->height || countW < 1 || countW > bmih_p->width){
        return 0;
    }
    int chunkHeight = bmih_p->height / countH;
    int chunkWidth = bmih_p->width / countW;
    
    int old_height = bmih_p->height;
    int old_width = bmih_p->width;

    bmih_p->height = chunkHeight;
    bmih_p->width = chunkWidth;
    bmfh_p->filesize = chunkHeight * chunkWidth * sizeof(Rgb);
    bmih_p->imageSize = chunkHeight * chunkWidth * sizeof(Rgb);
    
    int number = 0;
    char s[100];
    char newFileName[strlen(prefix)+100];
    for(int i=0; i < countH; i++){
        for(int j=0; j < countW; j++){
            strcpy(newFileName, prefix);
            sprintf(s, "%d", countH-i);
            strcat(newFileName, s);
            strcat(newFileName, ".");
            sprintf(s, "%d", j+1);

            strcat(newFileName, s);
            strcat(newFileName, ".bmp");

            if(!saveFile(newFileName, arr, bmfh_p, bmih_p, i*chunkHeight, j*chunkWidth))
                return 0;
        }
    }

    // back to old parameters
    bmih_p->height = old_height;
    bmih_p->width = old_width;
    bmfh_p->filesize = old_height * old_width * sizeof(Rgb);
    bmih_p->imageSize = old_height * old_width * sizeof(Rgb);

    return 1;
}


void replaceColor(Rgb** arr, BitmapInfoHeader* bmih, int* old_color, int* new_color){
    for(int i = 0; i < bmih->height; i++){
        for(int j = 0; j < bmih->width; j++){
            if((abs(arr[i][j].b - old_color[2]) < 50)&&(abs(arr[i][j].g - old_color[1]) < 50)&&(abs(arr[i][j].r - old_color[0]) < 50)){
                arr[i][j] = {(unsigned char)new_color[2], (unsigned char)new_color[1], (unsigned char)new_color[0]};
            }
        }
    }
}


int reflectFragmentX(Rgb** arr, int* left, int* right){
    int fr_width = (right[0] - left[0])* sizeof(Rgb);
    int fr_height = (left[1] - right[1])/2;
    if(fr_width<=0 || fr_height<=0){
    	//printf("Invalid coordinates in --reflect-x.\n");
        return 0;
    }
    Rgb **half = (Rgb**)malloc(fr_height * sizeof(Rgb*));
    int count = 0;
    // copy upper half to memory
    for(int i = left[1]; i > left[1]-fr_height; i--){
        count++;
        half[fr_height-count] = (Rgb*)malloc(fr_width * sizeof(Rgb));
        memmove(half[fr_height-count], arr[i]+left[0], fr_width);
    }
    // copy lower half and insert it into upper half upside down
    count = 0;
    for(int i = right[1]; i < right[1] + fr_height; i++){
        memmove(arr[left[1] - count] + left[0], arr[i] + left[0], fr_width);
        count++;
    }
    // insert upper half from memo into lower half upside down
    count = 0;
    for(int i = right[1]; i < right[1] + fr_height; i++){
        count++;
        memmove(arr[i] + left[0], half[fr_height - count], fr_width);
    }
    for(int i = 0; i < fr_height; i++) {
        free(half[i]);
    }
    if(half){
    	free(half);
    }
    return 1;
}


int reflectFragmentY(Rgb** arr, int* left, int* right){
    int fr_width = (right[0] - left[0])/2;
    int fr_height = (left[1] - right[1]);
    if(fr_width<=0 || fr_height<=0){
        //printf("Invalid coordinates in --reflect-y.\n");
        return 0;
    }
   	Rgb temp;
    for(int i = right[1]; i <= left[1]; i++){
        for(int j = 0; j <= fr_width; j++){
            temp = arr[i][left[0] + j];
            arr[i][left[0] + j] = arr[i][right[0] - j];
            arr[i][right[0] - j] = temp;
        }
    }
    return 1;
}


int copyPatch(Rgb** arr, BitmapInfoHeader* bmih_p, int* left, int* right, int* to){
    int patch_width = right[0] - left[0];
    int patch_height = left[1] - right[1];
    if(patch_width <= 0 || patch_height <= 0){
        //printf("Invalid coordinates in --copy-patch.\n");
        return 0;
    }
    if(to[1] - patch_height < 0){
        patch_height = to[1];
    }
    if(to[0] + patch_width > bmih_p->width){
        patch_width = bmih_p->width - to[0];
    }
    patch_width *= sizeof(Rgb);
    int j = 0;
    for(int i = left[1]; i >= left[1] - patch_height; i--){
        memmove(arr[to[1] - j] + to[0], arr[i]+left[0], patch_width);
        j++;
    }
    return 1;
}