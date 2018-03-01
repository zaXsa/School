#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int count;
    char *pText;                                                            /* must point to dynamic allocated memory! */
} problem_t;

int deepCopy(problem_t *pDestination, const problem_t *pSource);

int main(void){
    problem_t s1 = {1, NULL};                                               /* do not do ... = {1, ";ABC";} */
    problem_t s2 = {2, NULL};
    s1.pText = (char*)malloc(4 * sizeof(char));                             /* array of 4 chars */
    if (s1.pText != NULL)
    {
        strcpy(s1.pText, "111");
        deepCopy(&s2, &s1);
        s2.pText[0] = 'A';
        printf("s1 = %d %s\n", s1.count, s1.pText);
        printf("s2 = %d %s\n", s2.count, s2.pText);
        free(s1.pText);
        s1.pText = NULL;
    }
    s2.pText[1] = 'B';
    printf("s1 = %d %s\n", s1.count, s1.pText);
    printf("s2 = %d %s\n", s2.count, s2.pText);
    return 0;
}

int deepCopy(problem_t *pDestination, const problem_t *pSource){
    size_t nchars = strlen(pSource->pText) + 1;                                        // Determens the size of the needed space to get allocated to th pointer
    pDestination->count = pSource->count;                                              //
    free(pDestination->pText);                                                         //
    pDestination->pText = (char*)malloc(nchars);                                       //
    if (pDestination->pText == NULL)                                                   // Checks for errors
    {
        return -1;
    }
    strcpy(pDestination->pText, pSource->pText);
    return 0;
}
