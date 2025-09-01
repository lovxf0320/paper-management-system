#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "chionsequestion.h"
#include "fillintheblank.h"
#include "judgquestion.h"
#include "shortanswerquestion.h"
#include "programquestion.h"


// 1.环境:ubuntu+vscode，gcc，c语言
// 2.名称: 试题管理系统
// 3.功能需求:
//  c.友好的交互界面(字符界面)
//  d.支持，选择题，填空题，判断题，简答题，编程题
//  e.按类型查看题目(选择题，填空题，判断题，简答题，编程题)
//  f.管理题目(添加，删除，查找，修改)
//  g.数据存储(数据固化)

struct choicequestion* head = NULL;
struct blankquestion* head_blank = NULL;
struct judgquestion* head_judg = NULL;
struct shortquestion* head_short = NULL;
struct programquestion* head_program = NULL;



void brower_ui_view() {
    int back_flag = 1;
    while (back_flag) {
        system("clear");
        printf("-------------试卷查看系统---------------\n");
        printf("-              1.选择题                -\n");
        printf("-              2.填空题                -\n");
        printf("-              3.判断题                -\n");
        printf("-              4.简答题                -\n");
        printf("-              5.编程题                -\n");
        printf("-              0.返回                  -\n");
        printf("-               请输入：               -\n");
        printf("-----------------------------------------");
        printf("\033[8;25H");
        int i = -1;
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        scanf("%d", &i);
        switch (i) {
        case 0:back_flag = 0; break;
        case 1:head = creat(); load_file(head); choice_one_question(head); break;
        case 2:head_blank = creat_blank(); load_blankfile(head_blank); choice_one_blankquestion(head_blank); break;
        case 3:head_judg = creat_judg(); load_judgfile(head_judg); choice_one_judgquestion(head_judg); break;
        case 4:head_short = creat_short(); load_shortfile(head_short); choice_one_shortquestion(head_short); break;
        case 5:head_program = creat_program(); load_programfile(head_program); choice_one_programquestion(head_program); break;
        default:break;
        }
    }
}

void brower_ui_admin() {
    int back_flag = 1;
    while (back_flag) {
        system("clear");
        printf("-------------试卷管理系统---------------\n");
        printf("-              1.选择题                -\n");
        printf("-              2.填空题                -\n");
        printf("-              3.判断题                -\n");
        printf("-              4.简答题                -\n");
        printf("-              5.编程题                -\n");
        printf("-              0.返回                  -\n");
        printf("-               请输入：               -\n");
        printf("-----------------------------------------");
        printf("\033[8;25H");
        int i = -1;
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        scanf("%d", &i);
        switch (i) {
        case 0:back_flag = 0; break;
        case 1:head = creat(); load_file(head); admin_one_question(head); break;
        case 2:head_blank= creat_blank(); load_blankfile(head_blank); admin_one_blankquestion(head_blank); break;
        case 3:head_judg = creat_judg(); load_judgfile(head_judg); admin_one_judgquestion(head_judg); break;
        case 4:head_short = creat_short(); load_shortfile(head_short); admin_one_shortquestion(head_short); break;
        case 5:head_program = creat_program(); load_programfile(head_program); admin_one_programquestion(head_program); break;
        default:break;
        }
    }
}

void brower_ui() {        //管理界面
    int back_flag = 1;
    while (back_flag) {
        system("clear");
        printf("-------------试卷管理系统-----------------\n");
        printf("-                                       -\n");
        printf("-               0.退出                  -\n");
        printf("-               1.查看                  -\n");
        printf("-               2.管理                  -\n");
        printf("-                                       -\n");
        printf("-               请输入：                 -\n");
        printf("----------------------------------------");
        printf("\033[7;25H");
        int i = -1;
        scanf("%d", &i);
        switch (i) {
        case 0:back_flag = 0; break;
        case 1:brower_ui_view(); break;
        case 2:brower_ui_admin(); break;
        }
    }
}

void main() {
    brower_ui();
}