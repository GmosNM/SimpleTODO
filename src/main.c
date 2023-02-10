#include <stdio.h>
#include <stdlib.h>
#include "todos.h"
#include <string.h>

void print_usage(char **argv) {
    printf("\nUSAGE: %s [FLAGS]\n", argv[0]);
    printf("Flags:\n"
          "   `-help`           :: Show this help and usage information.\n"
          "   'list'            :: shows the list of todos.\n"
          "   'clear'           :: clears the list.\n"
          "   'remove'           :: remove a todo from the list.\n"
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
        }else if (strcmp(argument, "clear") == 0){
            clearList();
        }else if (strcmp(argument, "remove") == 0){
            RemoveTODO(argv[2]);
    }
 }

    return 0;
}
