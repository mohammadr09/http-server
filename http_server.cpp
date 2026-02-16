#include <iostream>
#include <string>
#include <sstream>

#include <sys/socket.h>

int main() {
    int file_descriptor = socket(AF_INET, SOCK_STREAM, 0); 

    std::string request;
    char temp[1024]; // store chunks of the incoming request one at a time; limiting this to 1kb (arbitrary) for now
    
    while (true) { // we infinitely loop because we do not know the exact number of reads needed during TCP
        // read whatever has arrived so far
        int bytes = recv(
            file_descriptor, // client socket 
            temp, // where to store the data
            sizeof(temp), // max bytes of 1024
            0 // flags
        ); 

        if (bytes <= 0) break;

        request.append(temp, bytes); // we append so that there isn't duplicating info & garbage

        // check if HTTP headers are finished
        if (request.find("\r\n\r\n") != std::string::npos) break;
    }

    std::istringstream stream();
    std::string line;
}