////////////////////////// main_receiver.c
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "type_definitions.h"

#define  BUFF_SIZE 12

using namespace std;

typedef struct {
	long  data_type;
	unsigned char  data_buff[BUFF_SIZE];
} t_data;

int main( void)
{
	int      msqid;
	t_data   data;
	int   	 fps;
	unsigned char size, format;

	if ( -1 == ( msqid = msgget( (key_t)1234, IPC_CREAT | 0666)))
	{
		perror( "msgget() failed");
		exit( 1);
	}

	while( 1 )
	{
		// datatype 0: receive all datatype
		// change datatype to 1 if you want to receive python data
		if ( -1 == msgrcv( msqid, &data, sizeof( t_data) - sizeof( long), 0, 0)) {
			perror( "msgrcv() failed");
			exit( 1);
		}
		printf("*** New message received ***\nRaw data: ");
		
		int i;
		for(i = 0; i<BUFF_SIZE; i++)
			printf("%02X ", data.data_buff[i]);
		printf("\n");
		
		if (data.data_type == TYPE_CAMERA_CFG) {
			memcpy(&size, data.data_buff, sizeof(unsigned char));
			memcpy(&format, data.data_buff+sizeof(unsigned char), sizeof(int));
			memcpy(&fps, data.data_buff+sizeof(unsigned char)+sizeof(int), sizeof(int));
			cout << "SIZE: " << size << endl;				
			cout << "FPS: " << fps << endl;
			cout << "FORMAT : " << format << endl;
	
		}
	}
}
