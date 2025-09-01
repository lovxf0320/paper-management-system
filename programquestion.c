#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "programquestion.h"



struct programquestion* creat_program() {      //��������ѡ����
    struct programquestion* node = (struct programquestion*)malloc(sizeof(struct programquestion));
    node->next = node;
    node->prev = node;
    return node;
}

void show_programquestion(struct programquestion* node) {               //��ʾÿ��ѡ����
    printf("%s\n", node->name);
    printf("%s\n", node->ans);
    //printf("%s         %s\n", node->option[0], (node->ans == 0) ? "��" : " ");
    //printf("%s         %s\n", node->option[1], (node->ans == 1) ? "��" : " ");
    //printf("%s         %s\n", node->option[2], (node->ans == 2) ? "��" : " ");
    //printf("%s         %s\n", node->option[3], (node->ans == 3) ? "��" : " ");
}

void test_insert_program(struct programquestion* head) {                 //����->����ѡ����
    char temp[3][512] = {
        "��֪ĳ��������ǰ����������ǡ�stuwv��������������ǡ�uwtvs�����ĺ����������,utwvs,",
        "���Ϊ5������������       ��Ҷ�ӽ��,16����֧���,",
        "32λϵͳ�ж���char **p[3][2]��sizeof(pp)Ϊ��24�ֽ�,"
    };
    struct programquestion* rear = creat_program();
    rear = head;

    for (int i = 0; i < 3; i++) {
        struct programquestion* node = (struct programquestion*)malloc(sizeof(struct programquestion));
        //sscanf�Ǵ��ַ����н�����ʽ�������ݵĺ���
        sscanf(temp[i], "%[^,],%[^,]", node->name, node->ans);

        rear->next = node;
        node->prev = rear;
        node->next = head;
        head->prev = node;

        rear = node;
    }

}

void choice_one_programquestion(struct programquestion* head) {         //�鿴->ѡ����һ�⻹����һ��
    int i = -1;

    while (1) {
        system("clear");             //����ն�

        printf("                    �����                    \n");
        if (i == 0)
            break;
        else if (i == 1)
            head = head->next;
        else if (i == 2)
            head = head->prev;
        show_programquestion(head);
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

struct programquestion* insert_programquestion(struct programquestion* head) {       //����->ѡ����->����
    system("clear");

    struct programquestion* node = (struct programquestion*)malloc(sizeof(struct programquestion));
    if (head->next == head) {
        node->next = head;
        node->prev = head;
        head->prev = node;
        head->next = node;
    }

    struct programquestion* rear = head;
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
    printf("������𰸣�"); while ((c = getchar()) != '\n' && c != EOF); scanf("%d", node->ans);

    return node;
}

struct programquestion* delet_programquestion(struct programquestion* head) {        //����->ѡ����->ɾ��
    if (head == NULL) {
        printf("����Ϊ�գ�\n");
        return head;
    }

    if (head->next == head) {
        free(head);
        return head;
    }

    struct programquestion* new_head = head->next;
    head->prev->next = head->next;
    head->next->prev = head->prev;

    free(head);
    head->next = NULL;                      //�ͷŽڵ�Ҫ�����е�ָ�붼�ͷŵ������������ָ����ܻ�����ָ��Ĵ���
    head->prev = NULL;

    return new_head;
}

void admin_one_programquestion(struct programquestion* head) {          //������Ŀ����һ�⡢��һ�⡢���ӡ�ɾ����
    int i = -1;
    while (1) {
        printf("                    �����                    \n");
        if (i == 0)
            break;
        else if (i == 1)
            head = head->next;
        else if (i == 2)
            head = head->prev;
        else if (i == 3)
            head = save_programfile(head);
        else if (i == 4)
            head = delet_programquestion(head);
        system("clear");             //����ն�
        show_programquestion(head);
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

void load_programfile(struct programquestion* head) {
    //���ļ�����ȡ�ļ���һ��һ�еĶ������ر��ļ�
    FILE* file = fopen("./programquestion.txt", "r");
    //rֻ���� wֻд��д��ģʽ�����ԭ���ݻ򴴽����ļ������� a+(׷��ģʽ�����ļ�ĩβ������ݣ�)��  w+��д��������ļ���, r+��д
    if (file == NULL)
        return;

    char line[512] = { 0 };
    struct programquestion* rear = head->prev;

    while (fgets(line, 512, file)) {
        struct programquestion* node = creat_program();
        sscanf(line, "%[^,],%[^,]", node->name, node->ans);
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

struct programquestion* save_programfile(struct programquestion* head) {
    //���ļ���д���ļ���һ��һ�еĶ������ر��ļ�
    FILE* file = fopen("./programquestion.txt", "a");
    if (file == NULL)
        return head;

    struct programquestion* node = creat_program();

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
    printf("������𰸣�"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->ans);



    char linebuffer[512] = { 0 };
    sprintf(linebuffer, "%s,%s\n", node->name, node->ans);
    fwrite(linebuffer, 1, strlen(linebuffer), file);

    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;

    fclose(file);

    return head;
}