#include <stdio.h>
#include <stdlib.h>
#include "token.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    FILE *fileOp = fopen(argv[1], "r");
    if (!fileOp) {
        fprintf(stderr, "Could not open file", argv[1]);
        return 1;
    }

    fclose(fileOp);
    return 0;
}

