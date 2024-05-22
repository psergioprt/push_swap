#include "get_next_line.h"
#include <fcntl.h>  // For open()
#include <stdio.h>  // For printf()
#include <stdlib.h>  // For malloc() and free()

int main(void) {
    char *str;
    int fd;

    fd = open("test.txt", O_RDONLY);  // Open file in read-only mode
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    while ((str = get_next_line(fd)) != NULL) {  // Read until EOF
        printf("%s", str);  // Print the line
        free(str);  // Free the line memory
    }
    close(fd);  // Close the file
    return 0;
}

