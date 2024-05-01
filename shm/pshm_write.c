#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd;
    size_t len;
    char *addr;

    /* Open existing object */
    fd = shm_open(argv[1], O_RDWR, 0);
    if (fd == -1) {
        printf("shm_open failed\n");
        exit(-1);
    }

    len = strlen(argv[2]);
    if (ftruncate(fd, len) == -1) {
        printf("ftruncate failed\n");
        exit(-1);
    }

    addr = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        printf("mmap failed\n");
        exit(-1);
    }

    if (close(fd) == -1) {
        printf("close failed\n");
        exit(-1);
    }

    printf("copying %ld bytes\n", (long)len);
    memcpy(addr, argv[2], len);
    exit(EXIT_SUCCESS);

}
