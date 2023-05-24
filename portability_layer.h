#include <netinet/in.h>


#ifndef __PORTABILITY_LAYER_H__
#define __PORTABILITY_LAYER_H__

struct SocketPackage {
    int domain;
    int type;
    int protocol;
};

struct AcceptPackage {
    int sockfd;
};

struct BindPackage {
    int sockfd;
    union {
        struct sockaddr_in addr;
        struct sockaddr_in6 addr6;
    };
    socklen_t addrlen;
};

struct ListenPackage {
    int sockfd;
    int backlog;
};

struct WritePackage {
    int sockfd;
    size_t count;
};

struct SendToPackage {
    int sockfd;
    int flags;
    union {
        struct sockaddr_in addr;
        struct sockaddr_in6 addr6;
    };
    socklen_t addrlen;
};

struct ReadPackage {
    int sockfd;
    size_t count;
};

struct RecvFromPackage {
    int sockfd;
    size_t count;
    int flags;
};

struct ClosePackage {
    int sockfd;
};

struct AcceptResponsePackage {
    union {
        struct sockaddr_in addr;
        struct sockaddr_in6 addr6;
    };

    socklen_t addrlen;
};

struct SyscallResponsePackage {
    int result;
    union {
        struct AcceptResponsePackage acceptResponse;
    };
};


struct SyscallPackage {
    char syscallId[20];
    int bufferedMessage;
    size_t bufferedCount;
    void *buffer;
    union {
        struct SocketPackage socketPackage;
        struct BindPackage bindPackage;
        struct ListenPackage listenPackage;
        struct AcceptPackage acceptPackage;
        struct BindPackage connectPackage;
        struct WritePackage writePackage;
        struct SendToPackage sendToPackage;
        struct ClosePackage closePackage;
        struct ReadPackage readPackage;
        struct RecvFromPackage recvFromPackage;
    };
};

struct packetdrill_syscalls {
    void (*socket_syscall)(void);
    void (*bind_syscall)(void);
    void (*listen_syscall)(void);
    void (*accept_syscall)(void);
    void (*connect_syscall)(void);
    void (*write_syscall)(void);
    void (*read_syscall)(void);
    void (*close_syscall)(void);
    void (*init_syscall)(void);
};

typedef void (*packetdrill_run_syscalls_fn)(struct packetdrill_syscalls*);


#endif /*__PORTABILITY_LAYER_H__*/
