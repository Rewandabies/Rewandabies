#ifndef TEXT_BUFFER.H
#define TEXT_BUFFER.H

#define MAX_LINE_LEN 1024

typedef struct {
char *text;
struct  line *next;
}line;

typedef struct {
line *head;
line *tail;
int line_count;
}TextBuffer;

TextBuffer* create_text_buffer();
void free_text_buffer(TextBuffer *buffer);
void display_text(TextBuffer *buffer);
void insert_line(TextBuffer *buffer, const char *text);
void delete_line(TextBuffer *buffer);

#endif // TEXT_BUFFER
