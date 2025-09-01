#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "chionsequestion.h"

// struct choicequestion{
//     char name[128];
//     char option[4][128];
//     int ans;
//     struct choicequestion* next;
//     struct choicequestion* prev;
// };

struct choicequestion* creat() {      //��������ѡ����
    struct choicequestion* node = (struct choicequestion*)malloc(sizeof(struct choicequestion));
    node->next = node;
    node->prev = node;
    return node;
}

void show_question(struct choicequestion* node) {               //��ʾÿ��ѡ����
    printf("%s\n", node->name);

    printf("%s         %s\n", node->option[0], (node->ans == 0) ? "��" : " ");
    printf("%s         %s\n", node->option[1], (node->ans == 1) ? "��" : " ");
    printf("%s         %s\n", node->option[2], (node->ans == 2) ? "��" : " ");
    printf("%s         %s\n", node->option[3], (node->ans == 3) ? "��" : " ");
}

void test_insert(struct choicequestion* head) {                 //����->����ѡ����
    char temp[3][512] = {
        "һ��������CԴ������,Ҫ��һ����������һ�����ϵķ�����������,��һ���ҽ���һ����������������ϵķ�����������,Ҫ��һ����������һ�����ϵķ�����������,��һ����ֻ��һ������������������������,0,",
        "����һ��void�ͺ�����ζ�ŵ��øú���ʱ����,ͨ��return����һ���û���ϣ���ĺ���ֵ,����һ��ϵͳĬ��ֵ,û�з���ֵ,����һ����ȷ����ֵ,1,",
        "�����庯��float *fun( )����fun�ķ���ֵΪ,һ��ʵ��,һ��ָ��ʵ�ͱ�����ָ��,һ��ָ��ʵ�ͺ�����ָ��,һ��ʵ�ͺ�������ڵ�ַ,2,"
    };
    struct choicequestion* rear = creat();
    rear = head;

    for (int i = 0; i < 3; i++) {
        struct choicequestion* node = (struct choicequestion*)malloc(sizeof(struct choicequestion));
        //sscanf�Ǵ��ַ����н�����ʽ�������ݵĺ���
        sscanf(temp[i], "%[^,],%[^,],%[^,],%[^,],%[^,],%d", node->name, node->option[0], node->option[1], node->option[2], node->option[3], &node->ans);

        rear->next = node;
        node->prev = rear;
        node->next = head;
        head->prev = node;

        rear = node;
    }

}

void choice_one_question(struct choicequestion* head) {         //�鿴->ѡ����һ�⻹����һ��
    int i = -1;

    while (1) {
        system("clear");             //����ն�

        printf("                    ѡ����                    \n");
        if (i == 0)
            break;
        else if (i == 1)
            head = head->next;
        else if (i == 2)
            head = head->prev;
        show_question(head);
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

struct choicequestion* insert_choicequestion(struct choicequestion* head) {       //����->ѡ����->����
    system("clear");

    struct choicequestion* node = (struct choicequestion*)malloc(sizeof(struct choicequestion));
    if (head->next == head) {
        node->next = head;
        node->prev = head;
        head->prev = node;
        head->next = node;
    }

    struct choicequestion* rear = head;
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
    printf("ѡ��A��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[0]);
    printf("\n");
    printf("ѡ��B��"); while ((c = getchar()) != '\n' && c != EOF);scanf("%s", node->option[1]);
    printf("\n");
    printf("ѡ��C��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[2]);
    printf("\n");
    printf("ѡ��D��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[3]);
    printf("\n");
    printf("������𰸣�"); while ((c = getchar()) != '\n' && c != EOF); scanf("%d", &node->ans);

    return node;
}

struct choicequestion* delet_choicequestion(struct choicequestion* head) {        //����->ѡ����->ɾ��
    if (head == NULL) {
        printf("����Ϊ�գ�\n");
        return head;
    }
        
    if (head->next == head) {
        free(head);
        return head;
    }

    struct choicequestion* new_head = head->next;
    head->prev->next = head->next;
    head->next->prev = head->prev;

    free(head);
    head->next = NULL;                      //�ͷŽڵ�Ҫ�����е�ָ�붼�ͷŵ������������ָ����ܻ�����ָ��Ĵ���
    head->prev = NULL;

    return new_head;
}

void admin_one_question(struct choicequestion* head) {          //������Ŀ����һ�⡢��һ�⡢���ӡ�ɾ����
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
            head = save_file(head);
        else if (i == 4)
            head = delet_choicequestion(head);
        system("clear");             //����ն�
        show_question(head);
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

void load_file(struct choicequestion* head) {
//���ļ�����ȡ�ļ���һ��һ�еĶ������ر��ļ�
    FILE* file = fopen("./question.txt", "r");
    //rֻ���� wֻд��д��ģʽ�����ԭ���ݻ򴴽����ļ������� a+(׷��ģʽ�����ļ�ĩβ������ݣ�)��  w+��д��������ļ���, r+��д
    if (file == NULL)
        return;

    char line[512] = { 0 };
    struct choicequestion* rear = head;
    while (fgets(line, 512, file)) {
        struct choicequestion* node = (struct choicequestion*)malloc(sizeof(struct choicequestion));
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%d", node->name, node->option[0], node->option[1], node->option[2], node->option[3], &node->ans);
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

struct choicequestion* save_file(struct choicequestion* head) {
//���ļ���д���ļ���һ��һ�еĶ������ر��ļ�
    FILE* file = fopen("./question.txt", "a");
    if (file == NULL)
        return head;

    struct choicequestion* node=creat();

    int c;
    printf("��������Ŀ��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->name);
    printf("\n");
    printf("ѡ��A��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[0]);
    printf("\n");
    printf("ѡ��B��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[1]);
    printf("\n");
    printf("ѡ��C��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[2]);
    printf("\n");
    printf("ѡ��D��"); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[3]);
    printf("\n");
    printf("������𰸣�"); while ((c = getchar()) != '\n' && c != EOF); scanf("%d", &node->ans);



    char linebuffer[512] = { 0 };
    sprintf(linebuffer, "%s,%s,%s,%s,%s,%d\n", node->name, node->option[0], node->option[1], node->option[2], node->option[3], node->ans);
    fwrite(linebuffer, 1, strlen(linebuffer), file);

    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;

    fclose(file);

    return head;
}