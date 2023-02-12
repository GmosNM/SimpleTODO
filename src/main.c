#include <stdio.h>
#include <stdlib.h>
#include "todos.h"
#include <string.h>

void print_usage(char **argv) {
    printf("\nUSAGE: %s [FLAGS]\n", argv[0]);
    printf("Flags:\n"
          "   `-help`           :: Show this help and usage information.\n"
          "   'list'            :: shows the list.\n"
          "   'clear'           :: clears both lists.\n"\
          "   'clearDONE'       :: clears done list.\n"
          "   'clearTODO'       :: clears todo list.\n"
          "   'move'            :: change todo status to done.\n"
          "   'remove'          :: remove a todo from the list.\n"
          "   `add`             :: add todo to the todo list.\n");
}

int main(int argc, char *argv[]){
    if(argc < 2){
        print_usage(argv);
        exit(1);
    }

    for (int i = 1; i < argc; ++i) {
        char *argument = argv[i];
        if (strcmp(argument, "add") == 0){
            createTODO(argv[2]);
        }else if (strcmp(argument, "list") == 0){
            showLIST();
        }else if (strcmp(argument, "clearTODO") == 0){
            clearTODO();
        }else if (strcmp(argument, "clearDONE") == 0){
            clearDONE();
        }else if (strcmp(argument, "clear") == 0){
            clearALL();
        }else if (strcmp(argument, "move") == 0){
            MoveTODO();
        }else if (strcmp(argument, "remove") == 0)
            RemoveTODO();
    }

    return 0;
}