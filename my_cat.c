#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

typedef struct
{
    FILE *file;
    unsigned char buffer[BUFFER_SIZE];
    int position;
    int length;
} MyStream;

void init_stream(MyStream *stream, FILE *file)
{
    stream->file = file;
    stream->position = 0;
    stream->length = 0;
}

int my_fgetc(MyStream *stream)
{
    if (stream == NULL || stream->file == NULL)
    {
        return EOF;
    }

    if (stream->position >= stream->length)
    {
        stream->length = fread(stream->buffer, 1, BUFFER_SIZE, stream->file);
        stream->position = 0;

        // If nothing was read, we're at EOF
        if (stream->length == 0)
        {
            return EOF;
        }
    }

    return (int)stream->buffer[stream->position++];
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    MyStream mystream;
    init_stream(&mystream, file);

    int ch;
    while ((ch = my_fgetc(&mystream)) != EOF)
    {
        putchar(ch);
    }

    fclose(file);
    return 0;
}