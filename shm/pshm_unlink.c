#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (shm_unlink(argv[1]) == -1) {
        printf("shm_unlink failed\n");
        exit(-1);
    }

    exit(EXIT_SUCCESS);
}
