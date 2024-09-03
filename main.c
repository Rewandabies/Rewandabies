/*================================================================
*    @file             : main.c
*    @brief            : text editor high level code
*    @author           : Rewan Dabies
=================================================================*/

/* Linking Section starts */
#include <stdio.h>
#include <stdlib.h>
#include "text_buffer.h"
#include "file_operations.h"
/* Linking Section ends */

/* Main Program Section */
int main()
{

    TextBuffer *buffer = create_text_buffer();
    char command[100];
    printf("( T | E | X | T ) ( E | D | I | T | O | R )\n");

    while (1) {
        printf("\nEnter command:\n");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. save\n");
        printf("4. load\n");
        printf("5. display\n");
        printf("6. exit\n");

        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "insert", 6) == 0) {
            printf("Enter text to insert: ");
            char text[MAX_LINE_LEN];
            fgets(text, sizeof(text), stdin);
            insert_line(buffer, text);

        } else if
        (strncmp(command, "delete", 6) == 0) {
            delete_line(buffer);

        } else if (strncmp(command, "save", 4) == 0) {
            save_to_file(buffer, "output.txt");

        } else if (strncmp(command, "load", 4) == 0) {
            load_from_file(buffer, "output.txt");

        } else if (strncmp(command, "display", 7) == 0) {
            display_text(buffer);

        } else if (strncmp(command, "exit", 4) == 0) {
            break;

        } else {
            printf("Unknown command.\n");
        }
    }

    free_text_buffer(buffer);
    return 0;

}

/*==============================================================================

    Date                By                  Description
    ------------        ------------        ------------
    3september2024      Rewan Dabies        creating text editor file
==============================================================================*/
