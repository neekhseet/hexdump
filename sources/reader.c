#include "../includes/reader.h"


filedata readfile(const char *path) {
    filedata data;
    memset(&data, 0, sizeof(data)); 

    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        return data; 
    }

    char buffer[MAX_BUFF_SIZE]; 
    ssize_t readed_bytes = read(fd, buffer, sizeof(buffer) - 1);
    
    if (readed_bytes <= 0) {
        close(fd);
        return data;
    }

    buffer[readed_bytes] = '\0'; 

    data.data = (char *)malloc(readed_bytes + 1);
    if (data.data == NULL) {
        close(fd);
        return data;
    }

    memcpy(data.data, buffer, readed_bytes);
    data.data[readed_bytes] = '\0'; 
    data.length = (size_t)readed_bytes; 

    close(fd); 
    return data;
}
