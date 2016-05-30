#include "cfg_file_util.h"
#include <iostream>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

static unsigned short SS_Port_Number = 1255;
static Socket_Server_T *SS_Server;

int main(int argc, char *argv[])
{
	char const *port_str;

	port_str = Get_Config_String_From_File("1255", "/var/socket_server_port");
	if(port_str != NULL)
	{
		SS_Port_Number = (unsigned short) strtoul(port_str, NULL, 0);
      		Free_Config_String(&port_str);		
	}

	SS_Server = new Socket_Server_T(SS_Port_Number);
	if(SS_Server == NULL)
	{
		exit(-1);
	}

	SS_Server->Run();

	return 0;
}	
