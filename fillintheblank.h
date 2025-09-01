#pragma once
#include<stdio.h>
#include<stdlib.h>

#ifndef FILLINTHEBLANK_H
#define FILLINTHEBLANK_H



struct blankquestion {
    char name[128];
    char ans[512];
    struct blankquestion* next;
    struct blankquestion* prev;
};

struct blankquestion* creat_blank();
void test_insert_blank(struct blankquestion* head);
void choice_one_blankquestion(struct blankquestion* head);
void show_blankquestion(struct blankquestion* node);
struct blankquestion* insert_blankquestion(struct blankquestion* head);
struct blankquestion* delet_blankquestion(struct blankquestion* head);
void admin_one_blankquestion(struct blankquestion* head);
void load_blankfile(struct blankquestion* head);
struct blankquestion* save_blankfile(struct blankquestion* head);

#endif // FILLINTHEBLANK_H
