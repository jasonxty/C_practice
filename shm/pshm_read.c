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
    char *addr;
    struct stat sb;

    /* Open existing object */
    fd = shm_open(argv[1], O_RDONLY, 0);
    if (fd == -1) {
        printf("shm_open failed\n");
        exit(-1);
    }

    /* Use shared memory object size as length argument for mmap() */
    if (fstat(fd, &sb) == -1) {
        printf("fstat failed\n");
        exit(-1);
    }

    addr = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        printf("mmap failed\n");
        exit(-1);
    }

    if (close(fd) == -1) {
        printf("close failed");
        exit(-1);
    }

    write(STDOUT_FILENO, addr, sb.st_size);
    printf("\n");
    exit(EXIT_SUCCESS);
}
