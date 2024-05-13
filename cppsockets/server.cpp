#include <iostream>
#include <vector>
#include <algorithm> // Include algorithm header for std::sort
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    // Bind the socket to an address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // Port to listen on
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on any available interface

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error binding socket" << std::endl;
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        std::cerr << "Error listening on socket" << std::endl;
        return 1;
    }

    std::cout << "Server is listening for connections..." << std::endl;

    // Accept a client connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_fd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
    if (client_fd < 0) {
        std::cerr << "Error accepting connection" << std::endl;
        return 1;
    }

    std::cout << "Client connected" << std::endl;

    // Receive size of vector from client
    int vector_size;
    int bytes_received = recv(client_fd, &vector_size, sizeof(vector_size), 0);
    if (bytes_received < 0) {
        std::cerr << "Error receiving vector size" << std::endl;
        return 1;
    }

    std::cout << "Received vector size: " << vector_size << std::endl;

    // Receive data from client
    std::vector<int> int_array(vector_size);
    bytes_received = recv(client_fd, int_array.data(), vector_size * sizeof(int), 0);
    if (bytes_received < 0) {
        std::cerr << "Error receiving data" << std::endl;
        return 1;
    }

    std::cout << "Received data from client" << std::endl;

    // Sort the received integers
    std::sort(int_array.begin(), int_array.end());

    // Send the sorted integers back to the client
    int bytes_sent = send(client_fd, int_array.data(), vector_size * sizeof(int), 0);
    if (bytes_sent < 0) {
        std::cerr << "Error sending sorted data to client" << std::endl;
        return 1;
    }

    std::cout << "Sorted integers sent back to client" << std::endl;

    // Close the client socket
    close(client_fd);

    // Close the server socket
    close(sockfd);

    return 0;
}
