#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "judgquestion.h"



struct judgquestion* creat_judg() {      //��������ѡ����
    struct judgquestion* node = (struct judgquestion*)malloc(sizeof(struct judgquestion));
    node->next = node;
    node->prev = node;
    return node;
}

void show_judgquestion(struct judgquestion* node) {               //��ʾÿ��ѡ����
    printf("%s\n", node->name);
    printf("%c\n", node->ans);
    //printf("%s         %s\n", node->option[0], (node->ans == 0) ? "��" : " ");
    //printf("%s         %s\n", node->option[1], (node->ans == 1) ? "��" : " ");
    //printf("%s         %s\n", node->option[2], (node->ans == 2) ? "��" : " ");
    //printf("%s         %s\n", node->option[3], (node->ans == 3) ? "��" : " ");
}

void test_insert_judg(struct judgquestion* head) {                 //����->����ѡ����
    char temp[3][512] = {
        "FTP��TCP/IP��Ӧ�ò�Э��,��,",
        "for(int x=0,y=0; !x && y<=5; y++)���ִ��ѭ���Ĵ�����5,��,",
        "���ݵĴ洢�ṹ��ָ���ݵ��߼��ṹ�ڼ�����еı�ʾ����,"
    };
    struct judgquestion* rear = creat_judg();
    rear = head;

    for (int i = 0; i < 3; i++) {
        struct judgquestion* node = (struct judgquestion*)malloc(sizeof(struct judgquestion));
        //sscanf�Ǵ��ַ����н�����ʽ�������ݵĺ���
        sscanf(temp[i], "%[^,],%[^,]", node->name, &node->ans);

        rear->next = node;
        node->prev = rear;
        node->next = head;
        head->prev = node;

        rear = node;
    }

}

void choice_one_judgquestion(struct judgquestion* head) {         //�鿴->ѡ����һ�⻹����һ��
    int i = -1;

    while (1) {
        system("clear");             //����ն�

        printf("                    �ж���                    \n");
        if (i == 0)
            break;
        else if (i == 1)
            head = head->next;
        else if (i == 2)
            head = head->prev;
        show_judgquestion(head);
        printf("�����루0.���� 1.��һ�� 2.��һ�⣩");

        int sum = 0;
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        scanf("%d", &sum);
        if (sum == 0)
            i = 0;
        else if (sum == 1)
            i = 1;
        else if (sum == 2)
            i = 2;
    }
}

struct judgquestion* insert_judgquestion(struct judgquestion* head) {       //����->ѡ����->����
    system("clear");

    struct judgquestion* node = (struct judgquestion*)malloc(sizeof(struct judgquestion*));
    if (head->next == head) {
        node->next = head;
        node->prev = head;
        head->prev = node;
        head->next = node;
    }

    struct judgquestion* rear = head;
    while (rear->next != head) {
        rear = rear->next;
    }
    node->next = head;
    head->prev = node;
    rear->next = node;
    node->prev = rear;
    int c;
    printf("��������Ŀ��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->name);
    printf("\n");
    //printf("ѡ��A��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[0]);
    //printf("\n");
    //printf("ѡ��B��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[1]);
    //printf("\n");
    //printf("ѡ��C��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[2]);
    //printf("\n");
    //printf("ѡ��D��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[3]);
    //printf("\n");
    printf("������𰸣�"); while ((c = getchar()) != '\n' && c != EOF); scanf("%d", &node->ans);

    return node;
}

struct judgquestion* delet_judgquestion(struct judgquestion* head) {        //����->ѡ����->ɾ��
    if (head == NULL) {
        printf("����Ϊ�գ�\n");
        return head;
    }

    if (head->next == head) {
        free(head);
        return head;
    }

    struct judgquestion* new_head = head->next;
    head->prev->next = head->next;
    head->next->prev = head->prev;

    free(head);
    head->next = NULL;                      //�ͷŽڵ�Ҫ�����е�ָ�붼�ͷŵ������������ָ����ܻ�����ָ��Ĵ���
    head->prev = NULL;

    return new_head;
}

void admin_one_judgquestion(struct judgquestion* head) {          //������Ŀ����һ�⡢��һ�⡢���ӡ�ɾ����
    int i = -1;
    while (1) {
        printf("                    ѡ����                    \n");
        if (i == 0)
            break;
        else if (i == 1)
            head = head->next;
        else if (i == 2)
            head = head->prev;
        else if (i == 3)
            head = save_judgfile(head);
        else if (i == 4)
            head = delet_judgquestion(head);
        system("clear");             //����ն�
        show_judgquestion(head);
        printf("�����루0.���� 1.��һ�� 2.��һ�� 3.���� 4.ɾ����");

        int sum = 0;
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        scanf("%d", &sum);
        if (sum == 0)
            i = 0;
        else if (sum == 1)
            i = 1;
        else if (sum == 2)
            i = 2;
        else if (sum == 3)
            i = 3;
        else if (sum == 4)
            i = 4;
    }
}

void load_judgfile(struct judgquestion* head) {
    //���ļ�����ȡ�ļ���һ��һ�еĶ������ر��ļ�
    FILE* file = fopen("./judgquestion.txt", "r");
    //rֻ���� wֻд��д��ģʽ�����ԭ���ݻ򴴽����ļ������� a+(׷��ģʽ�����ļ�ĩβ������ݣ�)��  w+��д��������ļ���, r+��д
    if (file == NULL)
        return;

    char line[512] = { 0 };
    struct judgquestion* rear = head;

    while (fgets(line, 512, file)) {
        struct judgquestion* node = creat_judg();
        sscanf(line, "%[^,],%[^,]", node->name, &node->ans);

        if (head->prev == head) {
            head->prev = node;
            head->next = node;
            node->prev = head;
            node->next = head;
        }
        else {
            rear->next = node;
            node->prev = rear;
            node->next = head;
            head->prev = node;
        }

        rear = node;
    }
    fclose(file);
}

struct judgquestion* save_judgfile(struct judgquestion* head) {
    //���ļ���д���ļ���һ��һ�еĶ������ر��ļ�
    FILE* file = fopen("./judgquestion.txt", "a");
    if (file == NULL)
        return head;

    struct judgquestion* node = creat_judg();

    int c;
    printf("��������Ŀ��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->name);
    printf("\n");
    //printf("ѡ��A��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[0]);
    //printf("\n");
    //printf("ѡ��B��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[1]);
    //printf("\n");
    //printf("ѡ��C��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[2]);
    //printf("\n");
    //printf("ѡ��D��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[3]);
    //printf("\n");
    printf("������𰸣�"); while ((c = getchar()) != '\n' && c != EOF); scanf("%c", &node->ans);



    char linebuffer[512] = { 0 };

    //��sscanf�������ƣ�������int��char֮�������ʱ����Ҫ��&���ţ���ʾ��ַ��������ֵ
    sprintf(linebuffer, "%s,%s\n", node->name, &node->ans);      
    fwrite(linebuffer, 1, strlen(linebuffer), file);

    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;

    fclose(file);

    return head;
}