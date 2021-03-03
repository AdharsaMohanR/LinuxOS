#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * f;
    char path[70],ch;
    int chars, words, lines;
    printf("Enter source file path: ");
    scanf("%s", path);
    file = fopen(path, "r");
    if (f == NULL)
    {
        printf("Not able  to open file.\n");
        printf(" check if file exists and  have read privilege.\n");

        exit(EXIT_FAILURE);
    }

    /*
     * Logic to count characters, words and lines.
     */
    chars = words = lines = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        chars++;
        if (ch == '\n' || ch == '\0')
            lines++;
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }
    /* Increment words and lines for last word */
    if (chars > 0)
    {
        words++;
        lines++;
    }
    printf("\n");
    printf("characters = %d\n", chars);
    printf(" words      = %d\n", words);
    printf("lines      = %d\n", lines);


    /* Close files to release resources */
    fclose(f);

    return 0;
}

   
