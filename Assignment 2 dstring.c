#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dstring_duplicate(const char *s)
{
    int len = strlen(s);
    char *copy;
    copy = (char*) malloc(len + 1);
    strcpy(copy, s);
    return copy;
}

int dstring_catenate(char **dest, const char *src)
{
    int i = 0, n;
    while(src[i++]);
    for(n = 0; (*dest)[n]; ++n);
    if((*dest = realloc(*dest,(i + n))) != NULL){
        strcat(*dest, src);
        return 1;
    }
    return 0;
}

void dstring_sub(const char *s, const char *start, const char *next)
{
    char *substring;
    int membytes = strlen(start) - strlen(next);
    substring = (char*)malloc(membytes);
    strcpy(substring, start);

    printf("%s", substring);
}


int main()
{
    int x = 5;
    printf("x \t\t= %d\n", x);
    printf("&x \t\t= %d\n", &x);
    int *ptr = &x;
    printf("ptr \t\t= %d\n", ptr);
    printf("*ptr \t\t= %d\n", *ptr);
    printf("&ptr \t\t= %d\n", &ptr);
    int **dblptr = &ptr;
    printf("dblptr \t\t= %d\n", dblptr);
    printf("*dblptr \t= %d\n", *dblptr);
    printf("**dblptr \t= %d\n", **dblptr);
    printf("&dblptr \t= %d", &dblptr);



    return 0;
}

