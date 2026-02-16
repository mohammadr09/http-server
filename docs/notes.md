# notes.md

A simple request looks like this
```bash
GET /index.html HTTP/1.1
Host: localhost:8080
User-Agent: Mozilla/5.0...
(Empty Line)
```

**Objectives:**
* obtain the type of request (GET, etc.)
* obtain the index path 

```cpp
int socket(int domain, int type, int protocol);

/**
 * domain - AF_INET - address family / domain; use IPv4 Addresses
 * type - SOCK_STREAM - use TCP (Transmission Control Protocol) 
 * protocol - 0 - standard protocol
``