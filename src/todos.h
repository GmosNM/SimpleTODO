#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>


//todo: set the status of a todo
//todo: add a section for the done and the todos

void createTODO(char* name);
void MoveTODO();
void showLIST();
void clearTODO();
void clearALL();
void clearDONE();
void RemoveTODO();
void AddTODO(const char* file_path, char* todoName);
void Move_To_Done();
void RemoveLINE(char* file_name,int line);