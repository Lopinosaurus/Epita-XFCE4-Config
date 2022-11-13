#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** argv) {

    if (argc < 2) {
        printf("Not enough args given. \n");
        return -1;
    }

    char commitMessage[];
    char tagName[];
    bool isTagging = false;

    if (argc == 2) commitMessage = argv[1];

    else if (argv[1] == "-t") {
        tagName = argv[2];
        commitMessage = argv[3];
        isTagging = true;
    }

    else {
        printf("Args given not correct.")
        return -1;
    }

    if (isTagging) {
        system("git add -A");
        system("git commit -m " + commitMessage);
        system("git tag -a " + tag_name + " -m " + commitMessage);
        system("git push --follow-tags");
    }

    else {
        system("git add -A");
        system("git commit -m " + commitMessage);
        system("git push");
    }

    return 0;
}

