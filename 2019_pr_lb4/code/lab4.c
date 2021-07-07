#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
 
int cmp (const void * a, const void * b)
{
    return (strcmp(*(char**)a, *(char**)b));
}
 
int main() {
    char source[1001];
    char patch[31];
    fgets(source, 1001, stdin);
    fgets(patch, 31, stdin);

    char** arr = NULL;
    int n = 0;
    char * ptr = strtok(source, " .");
    while (ptr != NULL)
    {
        arr = realloc(arr, (n+1) * sizeof(char*));
        arr[n] = ptr;
        n++;
        ptr = strtok(NULL, " .");
    }
 
    qsort(arr, n, sizeof(char*), cmp);
    char** patch_p = (char **) &patch;
    ptr = (char*)bsearch(&patch_p, arr, n, sizeof(char*), cmp);

    if(ptr)
        printf("exists\n");
    else
        printf("doesn't exist\n");
 
    free(arr);
 
    return 0;
}