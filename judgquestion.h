#pragma once
#include<stdio.h>
#include<stdlib.h>

#ifndef JUDGQUESTION_H
#define JUDGQUESTION_H



struct judgquestion {
    char name[128];
    char ans;
    struct judgquestion* next;
    struct judgquestion* prev;
};

struct judgquestion* creat_judg();
void test_insert_judg(struct judgquestion* head);
void choice_one_judgquestion(struct judgquestion* head);
void show_judgquestion(struct judgquestion* node);
struct judgquestion* insert_judgquestion(struct judgquestion* head);
struct judgquestion* delet_judgquestion(struct judgquestion* head);
void admin_one_judgquestion(struct judgquestion* head);
void load_judgfile(struct judgquestion* head);
struct judgquestion* save_judgfile(struct judgquestion* head);

#endif // JUDGQUESTION_H
