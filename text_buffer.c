/*================================================================
*    @file             : text_buffer.c
*    @brief            : text buffer high level code
*    @author           : Rewan Dabies
=================================================================*/

/* Linking Section starts */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text_buffer.h"
/* Linking Section ends */


TextBuffer* create_text_buffer(){
TextBuffer *buffer = (TextBuffer *)malloc(sizeof(TextBuffer));
buffer->head = NULL;
buffer->tail = NULL;
buffer->line_count = 0;
return buffer;
}

void free_text_buffer(TextBuffer *buffer){
line *current = buffer->head;
while(NULL != current){
   line *next = current->next;
   free(current->text);
   free(current);
   current = next;
}
free(buffer);
}


void display_text(TextBuffer *buffer) {
    line *current = buffer->head;
    while (current != NULL) {
        printf("%s", current->text);
        current = current->next;
}
}


void insert_line(TextBuffer *buffer, const char *text){
line *new_line = (line *)malloc(sizeof(line));
new_line->text = strdup(text);
new_line->next = NULL;
if(buffer->tail){
    buffer->tail->next = new_line;
}
else{
    buffer->head = new_line;
}
buffer->tail = new_line;
buffer->line_count++;
}


void delete_line(TextBuffer *buffer){
if(buffer->head == NULL){
    return;
}
line *to_delete = buffer->head;
buffer->head = buffer->head->next;
if(buffer->head == NULL){
    buffer->tail = NULL;
}
free(to_delete->text);
free(to_delete);
buffer->line_count--;
}

/*==============================================================================

    Date                By                  Description
    ------------        ------------        ------------
    3september2024      Rewan Dabies        creating text buffer file
==============================================================================*/
