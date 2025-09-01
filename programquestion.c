#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "programquestion.h"



struct programquestion* creat_program() {      //创建单个选择题
    struct programquestion* node = (struct programquestion*)malloc(sizeof(struct programquestion));
    node->next = node;
    node->prev = node;
    return node;
}

void show_programquestion(struct programquestion* node) {               //显示每个选择题
    printf("%s\n", node->name);
    printf("%s\n", node->ans);
    //printf("%s         %s\n", node->option[0], (node->ans == 0) ? "√" : " ");
    //printf("%s         %s\n", node->option[1], (node->ans == 1) ? "√" : " ");
    //printf("%s         %s\n", node->option[2], (node->ans == 2) ? "√" : " ");
    //printf("%s         %s\n", node->option[3], (node->ans == 3) ? "√" : " ");
}

void test_insert_program(struct programquestion* head) {                 //测试->插入选择题
    char temp[3][512] = {
        "已知某二叉树的前序遍历序列是“stuwv”中序遍历序列是“uwtvs”它的后序遍历序是,utwvs,",
        "深度为5的满二叉树有       个叶子结点,16个分支结点,",
        "32位系统中定义char **p[3][2]则sizeof(pp)为，24字节,"
    };
    struct programquestion* rear = creat_program();
    rear = head;

    for (int i = 0; i < 3; i++) {
        struct programquestion* node = (struct programquestion*)malloc(sizeof(struct programquestion));
        //sscanf是从字符串中解析格式化的数据的函数
        sscanf(temp[i], "%[^,],%[^,]", node->name, node->ans);

        rear->next = node;
        node->prev = rear;
        node->next = head;
        head->prev = node;

        rear = node;
    }

}

void choice_one_programquestion(struct programquestion* head) {         //查看->选择上一题还是下一题
    int i = -1;

    while (1) {
        system("clear");             //清空终端

        printf("                    编程题                    \n");
        if (i == 0)
            break;
        else if (i == 1)
            head = head->next;
        else if (i == 2)
            head = head->prev;
        show_programquestion(head);
        printf("请输入（0.返回 1.上一题 2.下一题）");

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

struct programquestion* insert_programquestion(struct programquestion* head) {       //管理->选择题->增加
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
    printf("请输入题目："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->name);
    printf("\n");
    //printf("选项A："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[0]);
    //printf("\n");
    //printf("选项B："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[1]);
    //printf("\n");
    //printf("选项C："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[2]);
    //printf("\n");
    //printf("选项D："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[3]);
    //printf("\n");
    printf("请输入答案："); while ((c = getchar()) != '\n' && c != EOF); scanf("%d", node->ans);

    return node;
}

struct programquestion* delet_programquestion(struct programquestion* head) {        //管理->选择题->删除
    if (head == NULL) {
        printf("链表为空！\n");
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
    head->next = NULL;                      //释放节点要把所有的指针都释放掉，否则残留的指针可能会引起指针的错误
    head->prev = NULL;

    return new_head;
}

void admin_one_programquestion(struct programquestion* head) {          //管理题目（上一题、下一题、增加、删除）
    int i = -1;
    while (1) {
        printf("                    简答题                    \n");
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
        system("clear");             //清空终端
        show_programquestion(head);
        printf("请输入（0.返回 1.上一题 2.下一题 3.增加 4.删除）");

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
    //打开文件，读取文件（一行一行的读），关闭文件
    FILE* file = fopen("./programquestion.txt", "r");
    //r只读， w只写（写入模式（清空原内容或创建新文件））， a+(追加模式（在文件末尾添加内容）)，  w+读写（会清空文件）, r+读写
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
    //打开文件，写入文件（一行一行的读），关闭文件
    FILE* file = fopen("./programquestion.txt", "a");
    if (file == NULL)
        return head;

    struct programquestion* node = creat_program();

    int c;
    printf("请输入题目："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->name);
    printf("\n");
    //printf("选项A："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[0]);
    //printf("\n");
    //printf("选项B："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[1]);
    //printf("\n");
    //printf("选项C："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[2]);
    //printf("\n");
    //printf("选项D："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[3]);
    //printf("\n");
    printf("请输入答案："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->ans);



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