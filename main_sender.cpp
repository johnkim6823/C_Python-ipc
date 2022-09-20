////////////////////////// main_sender.c
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "type_definitions.h"

typedef struct {
	long  data_type;
	char  data_buff[BUFF_SIZE];
} t_data;

int main( void)
{
	int      msqid;
	t_data   data;
	int fps = 30;
	unsigned char size, format;
	size = 0x01;
	format = 0x21;
	
	if ( -1 == ( msqid = msgget( (key_t)1234, IPC_CREAT | 0666)))
	{
		perror( "msgget() failed");
		exit( 1);
	}

	// by Header
	data.data_type = TYPE_CAMERA_CFG;
	memcpy(data.data_buff, &size, sizeof(unsigned char));
	memcpy(data.data_buff+sizeof(unsigned char), &format, sizeof(unsigned char));
	memcpy(data.data_buff+sizeof(unsigned char)*2, &fps, sizeof(int));
	
	if ( -1 == msgsnd( msqid, &data, sizeof( t_data) - sizeof( long), 0))
	{
		perror( "msgsnd() failed");
		exit( 1);
	}
	
	else {
		cout << "MSG_SENT" << endl;
	}

}
