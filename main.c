#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    char *src = read_file(argc[1]);

}

