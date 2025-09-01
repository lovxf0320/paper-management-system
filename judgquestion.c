#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "judgquestion.h"



struct judgquestion* creat_judg() {      //创建单个选择题
    struct judgquestion* node = (struct judgquestion*)malloc(sizeof(struct judgquestion));
    node->next = node;
    node->prev = node;
    return node;
}

void show_judgquestion(struct judgquestion* node) {               //显示每个选择题
    printf("%s\n", node->name);
    printf("%c\n", node->ans);
    //printf("%s         %s\n", node->option[0], (node->ans == 0) ? "√" : " ");
    //printf("%s         %s\n", node->option[1], (node->ans == 1) ? "√" : " ");
    //printf("%s         %s\n", node->option[2], (node->ans == 2) ? "√" : " ");
    //printf("%s         %s\n", node->option[3], (node->ans == 3) ? "√" : " ");
}

void test_insert_judg(struct judgquestion* head) {                 //测试->插入选择题
    char temp[3][512] = {
        "FTP是TCP/IP的应用层协议,√,",
        "for(int x=0,y=0; !x && y<=5; y++)语句执行循环的次数是5,×,",
        "数据的存储结构是指数据的逻辑结构在计算机中的表示，√,"
    };
    struct judgquestion* rear = creat_judg();
    rear = head;

    for (int i = 0; i < 3; i++) {
        struct judgquestion* node = (struct judgquestion*)malloc(sizeof(struct judgquestion));
        //sscanf是从字符串中解析格式化的数据的函数
        sscanf(temp[i], "%[^,],%[^,]", node->name, &node->ans);

        rear->next = node;
        node->prev = rear;
        node->next = head;
        head->prev = node;

        rear = node;
    }

}

void choice_one_judgquestion(struct judgquestion* head) {         //查看->选择上一题还是下一题
    int i = -1;

    while (1) {
        system("clear");             //清空终端

        printf("                    判断题                    \n");
        if (i == 0)
            break;
        else if (i == 1)
            head = head->next;
        else if (i == 2)
            head = head->prev;
        show_judgquestion(head);
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

struct judgquestion* insert_judgquestion(struct judgquestion* head) {       //管理->选择题->增加
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
    printf("请输入答案："); while ((c = getchar()) != '\n' && c != EOF); scanf("%d", &node->ans);

    return node;
}

struct judgquestion* delet_judgquestion(struct judgquestion* head) {        //管理->选择题->删除
    if (head == NULL) {
        printf("链表为空！\n");
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
    head->next = NULL;                      //释放节点要把所有的指针都释放掉，否则残留的指针可能会引起指针的错误
    head->prev = NULL;

    return new_head;
}

void admin_one_judgquestion(struct judgquestion* head) {          //管理题目（上一题、下一题、增加、删除）
    int i = -1;
    while (1) {
        printf("                    选择题                    \n");
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
        system("clear");             //清空终端
        show_judgquestion(head);
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

void load_judgfile(struct judgquestion* head) {
    //打开文件，读取文件（一行一行的读），关闭文件
    FILE* file = fopen("./judgquestion.txt", "r");
    //r只读， w只写（写入模式（清空原内容或创建新文件））， a+(追加模式（在文件末尾添加内容）)，  w+读写（会清空文件）, r+读写
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
    //打开文件，写入文件（一行一行的读），关闭文件
    FILE* file = fopen("./judgquestion.txt", "a");
    if (file == NULL)
        return head;

    struct judgquestion* node = creat_judg();

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
    printf("请输入答案："); while ((c = getchar()) != '\n' && c != EOF); scanf("%c", &node->ans);



    char linebuffer[512] = { 0 };

    //与sscanf规则相似，在输入int、char之类的数据时，需要用&符号，表示地址，而不是值
    sprintf(linebuffer, "%s,%s\n", node->name, &node->ans);      
    fwrite(linebuffer, 1, strlen(linebuffer), file);

    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;

    fclose(file);

    return head;
}