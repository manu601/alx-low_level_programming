#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to standard output.
 * @filename: The name of the file to be read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed. Returns 0 if the
 * file cannot be opened or read, if filename is NULL, or if write fails or
 * does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    if (filename == NULL)
        return 0; // Return 0 if filename is NULL

    int file = open(filename, O_RDONLY); // Open the file in read-only mode
    if (file == -1)
        return 0; // Return 0 if the file cannot be opened

    char *buffer = malloc(letters); // Allocate memory for the buffer
    if (buffer == NULL)
    {
        close(file);
        return 0; // Return 0 if memory allocation fails
    }

    ssize_t bytesRead = read(file, buffer, letters); // Read from file to buffer
    if (bytesRead == -1)
    {
        close(file);
        free(buffer);
        return 0; // Return 0 if reading fails
    }

    ssize_t bytesWritten = write(STDOUT_FILENO, buffer, bytesRead); // Write buffer to standard output
    if (bytesWritten != bytesRead)
    {
        close(file);
        free(buffer);
        return 0; // Return 0 if writing fails or does not write expected bytes
    }

    close(file);
    free(buffer);

    return bytesRead; // Return the actual number of letters read and printed
}

