#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "chionsequestion.h"
#include "fillintheblank.h"
#include "judgquestion.h"
#include "shortanswerquestion.h"
#include "programquestion.h"


// 1.����:ubuntu+vscode��gcc��c����
// 2.����: �������ϵͳ
// 3.��������:
//  c.�ѺõĽ�������(�ַ�����)
//  d.֧�֣�ѡ���⣬����⣬�ж��⣬����⣬�����
//  e.�����Ͳ鿴��Ŀ(ѡ���⣬����⣬�ж��⣬����⣬�����)
//  f.������Ŀ(��ӣ�ɾ�������ң��޸�)
//  g.���ݴ洢(���ݹ̻�)

struct choicequestion* head = NULL;
struct blankquestion* head_blank = NULL;
struct judgquestion* head_judg = NULL;
struct shortquestion* head_short = NULL;
struct programquestion* head_program = NULL;



void brower_ui_view() {
    int back_flag = 1;
    while (back_flag) {
        system("clear");
        printf("-------------�Ծ�鿴ϵͳ---------------\n");
        printf("-              1.ѡ����                -\n");
        printf("-              2.�����                -\n");
        printf("-              3.�ж���                -\n");
        printf("-              4.�����                -\n");
        printf("-              5.�����                -\n");
        printf("-              0.����                  -\n");
        printf("-               �����룺               -\n");
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
        printf("-------------�Ծ����ϵͳ---------------\n");
        printf("-              1.ѡ����                -\n");
        printf("-              2.�����                -\n");
        printf("-              3.�ж���                -\n");
        printf("-              4.�����                -\n");
        printf("-              5.�����                -\n");
        printf("-              0.����                  -\n");
        printf("-               �����룺               -\n");
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

void brower_ui() {        //�������
    int back_flag = 1;
    while (back_flag) {
        system("clear");
        printf("-------------�Ծ����ϵͳ-----------------\n");
        printf("-                                       -\n");
        printf("-               0.�˳�                  -\n");
        printf("-               1.�鿴                  -\n");
        printf("-               2.����                  -\n");
        printf("-                                       -\n");
        printf("-               �����룺                 -\n");
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