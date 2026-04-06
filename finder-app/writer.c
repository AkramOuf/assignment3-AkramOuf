#include <fcntl.h>      // For open() flags (O_WRONLY, O_CREAT)
#include <unistd.h>     // For write(), close()
#include <string.h>     // For strlen()
#include <sys/stat.h>   // For permissions (S_IRUSR, etc.)
#include <syslog.h>     // For syslog()

int main(int argc, char *argv[]) {
    // Open syslog for logging errors
    openlog(NULL, 0, LOG_USER);
    // 1. Check if both arguments are provided
    if (argc < 3) {
        syslog(LOG_ERR, "Usage: %s <filepath> <text_string>", argv[0]);
        return 1;
    }

    char *filepath = argv[1];
    char *text = argv[2];

    // 2. Open the file (System Call)
    // O_WRONLY: Write only
    // O_CREAT: Create it if it doesn't exist
    // O_TRUNC: If it exists, wipe it clean first
    // 0644: Permissions (Read/Write for owner, Read for others)
    int fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    if (fd == -1) {
        syslog(LOG_ERR, "Error creating file %s", filepath);
        return 1;
    }

    // 3. Write to the file (System Call)
    ssize_t bytes_written = write(fd, text, strlen(text));
    
    if (bytes_written == -1) {
        syslog(LOG_ERR, "Error writing to file %s", filepath);
        close(fd);
        return 1;
    }

    // 4. Close the file (System Call)
    if (close(fd) == -1) {
        syslog(LOG_ERR, "Error closing file %s", filepath);
        return 1;
    }

    syslog(LOG_DEBUG, "Writing <%s> to <%s>", text, filepath);
    closelog();
    return 0;
}