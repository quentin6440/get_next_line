#include <stdio.h>    // Includes standard I/O functions like perror, printf
#include <unistd.h>   // Includes functions for closing file descriptors
#include <fcntl.h>    // Includes functions for opening files
#include <stdlib.h>   // Includes functions for memory allocation, e.g., malloc, free
#include <string.h>   // Includes functions for string manipulation, e.g., strcpy, strncat

#define BUFFER_SIZE 10  // Defines the buffer size for reading the file

int main() {
    char buffer[BUFFER_SIZE];  // Buffer to hold chunks of data read from the file
    int fd, bytes_read;  // File descriptor and number of bytes read
    int i, line_length = 0;  // Loop index and length of the line read so far
    char *line = malloc(1);  // Initial allocation for the line
    if (line == NULL) {  // Check if memory allocation failed
        perror("Error allocating memory");  // Print error message
        return 1;  // Exit the program with an error code
    }
    line[0] = '\0';  // Initialize the line as an empty string

    // Open the file for reading
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {  // Check if the file failed to open
        perror("Error opening file");  // Print error message
        free(line);  // Free the initial allocation
        return 1;  // Exit the program with an error code
    }

    // Read and store characters until EOF is encountered
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {  // Read BUFFER_SIZE bytes at a time
        int new_length = line_length + bytes_read;  // Calculate new length of the line
        char *temp = malloc(new_length + 1);  // Allocate new memory for the line
        if (temp == NULL) {  // Check if memory allocation failed
            perror("Error allocating memory");  // Print error message
            free(line);  // Free previously allocated memory
            close(fd);  // Close the file descriptor
            return 1;  // Exit the program with an error code
        }
        strcpy(temp, line);  // Copy the existing line to the newly allocated memory
        free(line);  // Free the old memory
        line = temp;  // Update the line pointer to the new memory
        strncat(line, buffer, bytes_read);  // Append the buffer content to the line
        line_length = new_length;  // Update the line length

        // Check for newline character in the buffer
        for (i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n') {  // If newline character is found
                line[line_length - bytes_read + i + 1] = '\0';  // Null-terminate the line
                printf("Line: %s", line);  // Print the line
                line_length = 0;  // Reset line length for the next line
                line = malloc(1);  // Reallocate memory for the next line
                if (line == NULL) {  // Check if memory allocation failed
                    perror("Error allocating memory");
                    close(fd);  // Close the file descriptor
                    return 1;  // Exit the program with an error code
                }
                line[0] = '\0';  // Initialize the new line as an empty string
            }
        }
    }

    // Print any remaining line content if the file does not end with a newline
    if (line_length > 0) {
        printf("Line: %s", line);
    }

    // Close the file descriptor
    close(fd);
    free(line);  // Free the memory allocated for the line

    return 0;  // Exit the program successfully
}
