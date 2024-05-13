#include <iostream>
#include <vector>
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

    // Server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // Port on which server is listening
    server_addr.sin_addr.s_addr = INADDR_LOOPBACK; // localhost

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error connecting to server" << std::endl;
        return 1;
    }

    // Read integers from the terminal
    int vector_size;
    std::cout << "Enter the size of the integer vector: ";
    std::cin >> vector_size;

    std::vector<int> int_array(vector_size);
    std::cout << "Enter " << vector_size << " integers:" << std::endl;
    for (int i = 0; i < int_array.size(); ++i) {
        std::cin >> int_array[i];
    }

    // Send the size of the vector to the server
    int bytes_sent = send(sockfd, &vector_size, sizeof(vector_size), 0);
    if (bytes_sent < 0) {
        std::cerr << "Error sending vector size" << std::endl;
        return 1;
    }

    // Send the array of integers to the server
    bytes_sent = send(sockfd, int_array.data(), vector_size * sizeof(int), 0);
    if (bytes_sent < 0) {
        std::cerr << "Error sending data" << std::endl;
        return 1;
    }

		// Receive the sorted integers from the server
		std::vector<int> sorted_integers(vector_size); // Initialize with the correct size
		for (int i = 0; i < vector_size; ++i) {
				int received_int;
				int bytes_received = recv(sockfd, &received_int, sizeof(int), 0);
				if (bytes_received < 0) {
						std::cerr << "Error receiving sorted data from server" << std::endl;
						return 1;
				}
				sorted_integers[i] = received_int;
		}

    std::cout << "Received sorted integers from server:";
    for (int i = 0; i < vector_size; ++i) {
        std::cout << " " << sorted_integers[i];
    }
    std::cout << std::endl;

    // Close the socket
    close(sockfd);

    return 0;
}
