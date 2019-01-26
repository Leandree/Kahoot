#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/inotify.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define EVENT_BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )


int main(){

	int fdi = inotify_init();
	int wd;
	int length, i = 0;
	char buffer[EVENT_BUF_LEN];


	system("mkdir -p /tmp/kahoot");

	wd = inotify_add_watch( fdi, "/tmp/kahoot", IN_CREATE);

	length = read( fdi, buffer, EVENT_BUF_LEN ); 

	while ( i < length ) {     struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];     if ( event->len ) {
      if ( event->mask & IN_CREATE ) {
        if ( event->mask & IN_ISDIR ) {
          printf( "New directory %s created.\n", event->name );
        }
        else {
          printf( "New file %s created.\n", event->name );
        }
      }
    }
    i += EVENT_SIZE + event->len;
  }

  /*

	int fd;
    char * myfifo = "/tmp/kahoot/myfifo";

    mkfifo(myfifo, 0666);

    fd = open(myfifo, O_WRONLY);
    write(fd, "Hi", sizeof("Hi"));
    close(fd);

    unlink(myfifo);

    */

    return 0;

}