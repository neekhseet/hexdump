#include "../includes/reader.h"

Bytes *readfile(const char *path)
{
    Bytes *head = NULL;
    Bytes *temp = NULL;
    Bytes *new = NULL;

    int fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        return head;
    }

    char buffer[17];

    for (;;)
    {
        ssize_t readed_bytes = read(fd, buffer, 16);

        if (readed_bytes < 0)
            break;

        if (readed_bytes == 0)
            break;

        new = malloc(sizeof(Bytes));

        if (new == NULL)
            break;

        memcpy(new->data, buffer, readed_bytes);
        new->data[readed_bytes] = '\0';
        new->next = NULL;

        if (head == NULL)
        {
            head = new;
            temp = new;
        }
        else
        {
            temp->next = new;
            temp = new;
        }
    }

    close(fd);
    return head;
}
