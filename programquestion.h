#pragma once
#include<stdio.h>
#include<stdlib.h>

#ifndef PROGRAMQUESTION_H
#define PROGRAMQUESTION_H



struct programquestion {
    char name[128];
    char ans[512];
    struct programquestion* next;
    struct programquestion* prev;
};

struct programquestion* creat_program();
void test_insert_program(struct programquestion* head);
void choice_one_proramquestion(struct programquestion* head);
void show_programquestion(struct programquestion* node);
struct programquestion* insert_programquestion(struct programquestion* head);
struct programquestion* delet_programquestion(struct programquestion* head);
void admin_one_programquestion(struct programquestion* head);
void load_programfile(struct programquestion* head);
struct programquestion* save_programfile(struct programquestion* head);

#endif // PROGRAMQUESTION_H
