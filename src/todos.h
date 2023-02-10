#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

//todo: set the stats of a todo
//todo: add a section for the done and the todos

void createTODO(char* name);
void showLIST();
void clearList();
void RemoveTODO(const char* name);

void OpenFile(const char* file_path, char* todoName);