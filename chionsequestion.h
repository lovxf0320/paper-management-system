#pragma once
#include<stdio.h>
#include<stdlib.h>

#ifndef CHIONSEQUESTION_H
#define CHIONSEQUESTION_H



struct choicequestion {
    char name[128];
    char option[4][128];
    int ans;
    struct choicequestion* next;
    struct choicequestion* prev;
};

struct choicequestion* creat();
void test_insert(struct choicequestion* head);
void choice_one_question(struct choicequestion* head);
void show_question(struct choicequestion* node);
struct choicequestion* insert_choicequestion(struct choicequestion* head);
struct choicequestion* delet_choicequestion(struct choicequestion* head);
void admin_one_question(struct choicequestion* head);
void load_file(struct choicequestion* head);
struct choicequestion* save_file(struct choicequestion* head);
#endif // CHIONSEQUESTION_H