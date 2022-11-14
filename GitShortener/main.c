#include <stdio.h>
#include <err.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "reverse.h"
#include "getpath.h"


int main(int argc, char** argv) {

    if (argc < 2) return -1;
    if (2 == argc && strcmp(argv[1], "-c") && strcmp(argv[1], "-t")) {

        char commitMessage[] = "git commit -m ";
        strcat(commitMessage, argv[1]);
        system("git add -A");        
        system(commitMessage);
        system("git push");
    }

    else if ("-t" != argv[1] || "-c" != argv[1]) return -1;

    else if ("-c" == argv[1]) {

        FILE *fptr;
        char tag;
        fptr = fopen("tags", "w+");

        if (NULL == fptr) {

            errx(1, "Failed (null pointer)");
            exit(1);
        }

        printf("Enter tag for this project : ");
        scanf("%s", &tag);
        fprintf(fptr, "%s=%s-0\n", getPath(),tag);
        fclose(fptr);
    }


    else if ("-t" == argv[1]) {

        FILE *fptr;
        ssize_t r;
        char* tag;
        char* line = NULL;
        fptr = fopen("tags", "w+");

        if (NULL == fptr) {

            errx(1, "Failed (null pointer)");
            exit(1);
        }

        while(r!=-1) {

            r = getline(line, 0, fptr);   
            if (r!=-1 && strcmp(strtok(line, "="), getPath()) == 0) {

                char tagName[] = "git tag -a ";
                int tagNum;
                char* stringTag;
                char commitMessage[] = "git commit -m ";
                strcat(commitMessage, argv[2]);
                system("git add -A");
                system(commitMessage);
                strcat(tagName, strtok(line, "-"));
                tagNum = atoi(strtok(line, ""));
                tagNum++;
                strcat(tagName, "-");
                itoa(tagNum, stringTag);
                strcat(tagName, stringTag);
                strcat(tagName, "-m ");
                strcat(tagName, argv[2]);
                system(tagName);
                system("git push --follow-tags");
            }
        }
    }
    return 0;
}
