#include "todos.h"


#define BUFFER_SIZE 1024
char buffer[BUFFER_SIZE];
char doneBuf[BUFFER_SIZE];

void createTODO(char* name){
    if(name == NULL){
        exit(1);
    }
    AddTODO("src/todos.txt", name);
}

void MoveTODO(){
    Move_To_Done();
}

void showLIST(){
    FILE *f = fopen("src/todos.txt", "r");
    FILE *done = fopen("src/done.txt", "r");
    if(f == NULL || done == NULL){
        printf("ERROR: %c:",errno);
        exit(1);
    }
    fseek(f, 0, SEEK_SET);
    fseek(done, 0, SEEK_SET);
    fread(buffer, 1024, 1, f);
    fread(doneBuf, 1024, 1, done);
    fseek(done, 0, SEEK_END);
    fseek(f, 0, SEEK_END);
    printf("--------------TODO--------------\n");
    printf("%s\n", buffer);
    printf("--------------DONE--------------\n");
    printf("%s\n", doneBuf);
    fclose(f);
    fclose(done);
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


void Move_To_Done() {
    FILE *f, *done;

    char *filename = "src/todos.txt";
    char *done_file = "src/done.txt";

    int done_line = 0;

    printf("Done TODO: (line number): ");
    scanf("%d", &done_line);

    f = fopen(filename, "r");
    done = fopen(done_file, "a");

    if (f == NULL || done == NULL){exit(1);}
    bool keep_reading = true;
    int current_line = 1;
    do{
        fgets(buffer, BUFFER_SIZE, f);
        if (feof(f)) keep_reading = false;
        else if (current_line == done_line)
            fputs(buffer, done);
            current_line++;
    } while (keep_reading);
    fclose(f);
    fclose(done);
    RemoveLINE(filename,done_line);
}

void clearTODO() {
    FILE *f = fopen("src/todos.txt", "w+");
    if(f == NULL){
        printf("ERROR: %c:",errno);
        exit(1);
    }
    fprintf(f,"");
}

void clearDONE() {
    FILE *f = fopen("src/done.txt", "w+");
    if(f == NULL){
        printf("ERROR: %c:",errno);
        exit(1);
    }
    fprintf(f,"");
}

void clearALL() {
    FILE *f = fopen("src/done.txt", "w+");
    FILE *f2 = fopen("src/todos.txt", "w+");
    if(f == NULL || f2 == NULL){
        printf("ERROR: %c:",errno);
        exit(1);
    }
    fprintf(f,"");
    fprintf(f2,"");
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

    if (f == NULL || temp == NULL){exit(1);}
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

void RemoveLINE(char *file_name, int line) {
    FILE *f, *temp;

    char *filename = file_name;
    char *temp_filename = "src/temp.temp";

    f = fopen(filename, "r");
    temp = fopen(temp_filename, "w");

    if (f == NULL || temp == NULL){exit(1);}
    bool keep_reading = true;
    int current_line = 1;
    do
    {
        fgets(buffer, BUFFER_SIZE, f);
        if (feof(f)) keep_reading = false;
        else if (current_line != line)
            fputs(buffer, temp);
        current_line++;
    } while (keep_reading);
    fclose(f);
    fclose(temp);
    remove(filename);
    rename(temp_filename, filename);
}
