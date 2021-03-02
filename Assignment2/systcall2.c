#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * f;
    char path[100];

    char ch;
    int chars, words, lines;


    /* Input path of files to merge to third file */
    printf("Enter source file path: ");
    scanf("%s", path);

    /* Open source files in 'r' mode */
    file = fopen(path, "r");
    /* Check if file opened successfully */
    if (f == NULL)
    {
        printf("\nUnable to open file.\n");
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

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            lines++;

        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }
    /* Increment words and lines for last word */
    if (chars > 0)
    {
        words++;
        lines++;
    }

    /* Print file statistics */
    printf("\n");
    printf("Total characters = %d\n", chars);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);


    /* Close files to release resources */
    fclose(f);

    return 0;
}

   
