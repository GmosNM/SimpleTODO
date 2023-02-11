#include "todos.h"


#define BUFFER_SIZE 1024
char buffer[BUFFER_SIZE];

void createTODO(char* name){
    if(name == NULL){
        exit(1);
    }
    AddTODO("src/todos.txt", name);
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

void AddTODO(const char *file_path, char* todoName) {
    FILE *f = fopen(file_path, "a");
    if(f == NULL){
        printf("ERROR: %c:",errno);
        exit(1);
    }
    fprintf(f,"TODO: %s",todoName);

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


void RemoveTODO() {
    FILE *f, *temp;

    char *filename = "src/todos.txt";
    char *temp_filename = "src/temp.temp";

    int delete_line = 0;

    printf("Delete TODO: (line number): ");
    scanf("%d", &delete_line);

    f = fopen(filename, "r");
    temp = fopen(temp_filename, "w");

    if (f == NULL || temp == NULL)
    {
        printf("Error opening file(s)\n");
        exit(1);
    }
    bool keep_reading = true;
    int current_line = 1;
    do
    {
        fgets(buffer, BUFFER_SIZE, f);
        if (feof(f)) keep_reading = false;
        else if (current_line != delete_line)
            fputs(buffer, temp);
        current_line++;
    } while (keep_reading);
    fclose(f);
    fclose(temp);
    remove(filename);
    rename(temp_filename, filename);
}

