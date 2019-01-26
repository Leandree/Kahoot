#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/inotify.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define EVENT_BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )
#define MAX_BUF 1024

sem_t semaphore;

void *connectClient(char* name)
{

	char link[30];
	strcpy(link,  "/tmp/kahoot/");
	strcat(link,name);
    printf("Nous sommes dans le thread.%s\n",link);
    
    int fd;
    char * myfifo = link;
    char buf[MAX_BUF];

    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
    read(fd, buf, MAX_BUF);
    printf("Received: %s\n", buf);
    close(fd);


}



int main(){

	int fdi = inotify_init();
	int wd, error;
	int length, i = 0;
	int t=0;
	char buffer[EVENT_BUF_LEN];
	pthread_t thread[10];
	sem_init(&semaphore,1,2);

	system("mkdir -p /tmp/kahoot");

	wd = inotify_add_watch( fdi, "/tmp/kahoot", IN_CREATE);

	length = read( fdi, buffer, EVENT_BUF_LEN ); 


	while ( t < 30 ) {   
		struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];     if ( event->len ) {
      if ( event->mask & IN_CREATE ) {
        if ( event->mask & IN_ISDIR ) {

          printf( "New directory %s created.\n", event->name );
        }
        else {
			printf( "New file %s created.\n", event->name );
        	t++;
        	wd = inotify_add_watch( fdi, "/tmp/kahoot", IN_CREATE);

			length = read( fdi, buffer, EVENT_BUF_LEN ); 
          
        }
      }
    }
  }


    

    return 0;

}