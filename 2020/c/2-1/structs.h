#ifndef FILE_CONTENT
#define FILE_CONTENT

typedef struct FileContent
{
    int t_chars;
    int t_lines;
    char *lines[];
} FileContent;

#endif
