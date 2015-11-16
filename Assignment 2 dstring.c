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

char *dstring_sub(const char *start, const char *next)
{
    char *sub_string;
    int size = strlen(start) - strlen(next), i = 0;
    sub_string = (char*) malloc(size);
    if (sub_string == NULL){
        printf("Did not work, not enough space in the memory.\n");
    }

    while(i<=size){ sub_string[i] = start[i]; ++i; }

    return sub_string;
}

int main()
{
    char* temp;
    char* temp2;

    temp = dstring_duplicate("Ahmed"); // Här så skriver den ut första strängen och kollar om det funkade.

    printf("This is the string: %s\n", temp); // Slriver ut första strängen.

    if ((dstring_catenate(&temp, "Allan") == 0)) // Här så kollar den om det gick att sätta ihop båda strängarna annars så får man ett meddlenade som visar att det inte fungerade.
    {
        printf("Error!");
    }

    printf("This is the new string: %s\n", temp); // Här så skrtiver den ut båda strängarna efter varandra.

    temp2 = dstring_sub(&temp[2], &temp[6]);

    printf("This is the sub string: %s\n", temp2);

    free(temp);
    free(temp2);

    return 0;
}

