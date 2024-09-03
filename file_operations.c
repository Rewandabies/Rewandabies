/*================================================================
*    @file             : file_operations.c
*    @brief            : file operations high level code
*    @author           : Rewan Dabies
=================================================================*/

/* Linking Section starts */
#include <stdio.h>
#include <stdlib.h>
#include "text_buffer.h"
#include "file_operations.h"
/* Linking Section ends */


void save_to_file(TextBuffer *buffer, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
}

    line *current = buffer->head;
    while (current != NULL) {
        fprintf(file, "%s", current->text);
        current = current->next;
}

    fclose(file);
}


void load_from_file(TextBuffer *buffer, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
}

    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), file)) {
        insert_line(buffer, line);
}

    fclose(file);
}


/*==============================================================================

    Date                By                  Description
    ------------        ------------        ------------
    3september2024      Rewan Dabies        creating file operations
==============================================================================*/
