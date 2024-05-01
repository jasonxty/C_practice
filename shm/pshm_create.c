#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int flags, opt, fd;
    mode_t perms;
    size_t size;
    void *addr;

    /* Create shared memory object and set its size */
    fd = shm_open(argv[1], O_RDWR|O_CREAT, 0777);
    if(fd == -1) {
        printf("shm_open failed\n");
        exit(-1);
    }
    
    if(ftruncate(fd, 10000) == -1) {
        perror("ftranslate failed:");
        exit(-1);
    }

    /* Map shared memory object */
    addr = mmap(NULL, 9999, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        printf("mmap failed\n");
    }

    printf("create shm object sucess, please check /dev/shm/%s\n", argv[1]);

    exit(EXIT_SUCCESS);
}
