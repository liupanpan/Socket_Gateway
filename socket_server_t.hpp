
class Socket_Server_T
{
	public:
		Socket_Server_T(unsigned short port_number);

		virtual ~Socket_Server_T();
		
		void Socket_Server_T::Run()



		int m_accept_fd;

		unsigned short m_port_number;

		unsigned char m_exit_requested;
}


