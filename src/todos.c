#include "todos.h"



char buffer[1024];

void createTODO(char* name){
    if(name == NULL){
        exit(1);
    }
    OpenFile("src/todos.txt", name);
}

void showLIST(){
    FILE *f = fopen("src/todos.txt", "r");
    if(f == NULL){
        printf("ERROR: %c:",errno);
        exit(1);
    }
    fseek(f, 0, SEEK_SET);
    fread(buffer, 1024, 1, f);
    printf("-------------------------------\n");
    printf("%s\n", buffer);
    printf("-------------------------------\n");
    fclose(f);
}

void OpenFile(const char *file_path, char* todoName) {
    FILE *f = fopen(file_path, "a");
    if(f == NULL){
        printf("ERROR: %c:",errno);
        exit(1);
    }
    fprintf(f,"TODO: %s", todoName);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(f,"\t\t\t\t | Date: %d-%02d-%02d %02d:%02d:%02d",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fputc('\n', f);
    fclose(f);
}

void clearList() {
    FILE *f = fopen("src/todos.txt", "w+");
    if(f == NULL){
        printf("ERROR: %c:",errno);
        exit(1);
    }
    fprintf(f,"");
}

void RemoveTODO(const char *name) {
    if(name == NULL) exit(1);
    FILE *f = fopen("src/todos.txt", "r");
    if(f == NULL){
        printf("ERROR: %c:",errno);
        exit(1);
    }
    //todo: read the file

    //todo: remove the line
    fclose(f);
}
