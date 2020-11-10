#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>


inline int unix_dgram_socket()
{
    return socket(AF_UNIX, SOCK_DGRAM, 0);
}


inline int unix_dgram_server_bind(const int sock, const char* path)
{
    int size = strlen(path);
    if(size > 107) return -1;
    unlink(path);
    struct sockaddr_un unix_addr;
    unix_addr.sun_family = AF_UNIX;
    memcpy(unix_addr.sun_path, path, size);
    int ret = bind(sock, reinterpret_cast<const sockaddr*>(&unix_addr), sizeof(struct sockaddr_un));
    return ret;
}

inline int unix_dgram_server_send(const int sock, const char* buff, const int size, const struct sockaddr_un* pUnix_addr)
{
    return sendto(sock, buff, size, 0, reinterpret_cast<const sockaddr*>(pUnix_addr), sizeof(struct sockaddr_un));
}

inline int unix_dgram_server_read(int sock, char* buff, int size)
{
    return read(sock, buff, size);
}