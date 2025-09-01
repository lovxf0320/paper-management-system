#pragma once
#include<stdio.h>
#include<stdlib.h>

#ifndef SHORTANSWERQUESTION_H
#define SHORTANSWERQUESTION_H



struct shortanswerquestion {
    char name[128];
    char ans[512];
    struct shortanswerquestion* next;
    struct shortanswerquestion* prev;
};

struct shortanswerquestion* creat_short();
void test_insert_short(struct shortanswerquestion* head);
void choice_one_shortquestion(struct shortanswerquestion* head);
void show_shortquestion(struct shortanswerquestion* node);
struct shortanswerquestion* insert_shortquestion(struct shortanswerquestion* head);
struct shortanswerquestion* delet_shortquestion(struct shortanswerquestion* head);
void admin_one_shortquestion(struct shortanswerquestion* head);
void load_shortfile(struct shortanswerquestion* head);
struct shortanswerquestion* save_shortfile(struct shortanswerquestion* head);

#endif // SHORTANSWERQUESTION_H
