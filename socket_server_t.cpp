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
	 m_port_number(port_number)
{

}

Socket_Server_T::~Socket_Server_T()
{
	
}

void Socket_Server_T::Run()
{

}
