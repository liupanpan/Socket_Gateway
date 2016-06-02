#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <netinet/tcp.h>
#include <signal.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <sys/select.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>
#include "Socket_Server_T.hpp"

Socket_Server_T::Socket_Server_T(unsigned short port_number)
	:m_accept_fd(-1),
	 m_port_number(port_number),
	 m_exit_requested(0)
{

}

Socket_Server_T::~Socket_Server_T()
{
	
}

void Socket_Server_T::create_connection(unsigned short port_number, int &accept_fd)
{
	while(accept_fd < 0)
	{
		accept_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if(accept_fd < 0)
		{
		}
		else
		{
			struct sockaddr_in socket_adr;
			int result = 0;
			int sock_opt = 1;

			result = setsockopt(accept_fd, SOL_SOCKET, SO_REUSEADDR, &sock_opt, sizeof sock_opt);
			if(result < 0)
			{
			}
			result = setsockopt(accept_fd, IPPROTO_TCP, TCP_NODELAY, &sock_opt, sizeof sock_opt);
			if(result < 0)
			{
			}
			
			memset(&socket_adr, 0, sizeof(socket_adr));

         		socket_adr.sin_family = AF_INET;
         		socket_adr.sin_port = htons(port_number);
         		socket_adr.sin_addr.s_addr = INADDR_ANY;

			result = bind(accept_fd, (struct sockaddr*) (&socket_adr), sizeof(socket_adr));
			if(result < 0)
			{
			}
			else
			{
				int listen_result;
				if (fcntl(accept_fd, F_SETFD, FD_CLOEXEC) != 0)
				{
				}
				if (fcntl(accept_fd, F_SETFL, O_NONBLOCK) != 0)
				{
				}

				listen_result = listen(accept_fd, 128)
				if(listen_result < 0)
				{
				}
			}


		}
	}
}
	
void Socket_Server_T::Run()
{
	while(!m_exit_requested)
	{
		create_connection(m_port_number, m_accept_fd);
	}	
}




