#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>


#define MAX_BUF 1024

int main()
{
    int fd;
    char * myfifo = "/tmp/kahoot/azer2";
    char *first;


    mkfifo(myfifo, 0666);

    fd = open(myfifo, O_WRONLY);
    scanf("%s",first);
    write(fd, first, sizeof(first));
    close(fd);

    unlink(myfifo);

    return 0;
}