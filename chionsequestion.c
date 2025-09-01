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

struct choicequestion* creat() {      //创建单个选择题
    struct choicequestion* node = (struct choicequestion*)malloc(sizeof(struct choicequestion));
    node->next = node;
    node->prev = node;
    return node;
}

void show_question(struct choicequestion* node) {               //显示每个选择题
    printf("%s\n", node->name);

    printf("%s         %s\n", node->option[0], (node->ans == 0) ? "√" : " ");
    printf("%s         %s\n", node->option[1], (node->ans == 1) ? "√" : " ");
    printf("%s         %s\n", node->option[2], (node->ans == 2) ? "√" : " ");
    printf("%s         %s\n", node->option[3], (node->ans == 3) ? "√" : " ");
}

void test_insert(struct choicequestion* head) {                 //测试->插入选择题
    char temp[3][512] = {
        "一个完整的C源程序是,要由一个主函数或一个以上的非主函数构成,由一个且仅由一个主函数和零个以上的非主函数构成,要由一个主函数和一个以上的非主函数构成,由一个且只有一个主函数或多个非主函数构成,0,",
        "定义一个void型函数意味着调用该函数时函数,通过return返回一个用户所希望的函数值,返回一个系统默认值,没有返回值,返回一个不确定的值,1,",
        "若定义函数float *fun( )则函数fun的返回值为,一个实数,一个指向实型变量的指针,一个指向实型函数的指针,一个实型函数的入口地址,2,"
    };
    struct choicequestion* rear = creat();
    rear = head;

    for (int i = 0; i < 3; i++) {
        struct choicequestion* node = (struct choicequestion*)malloc(sizeof(struct choicequestion));
        //sscanf是从字符串中解析格式化的数据的函数
        sscanf(temp[i], "%[^,],%[^,],%[^,],%[^,],%[^,],%d", node->name, node->option[0], node->option[1], node->option[2], node->option[3], &node->ans);

        rear->next = node;
        node->prev = rear;
        node->next = head;
        head->prev = node;

        rear = node;
    }

}

void choice_one_question(struct choicequestion* head) {         //查看->选择上一题还是下一题
    int i = -1;

    while (1) {
        system("clear");             //清空终端

        printf("                    选择题                    \n");
        if (i == 0)
            break;
        else if (i == 1)
            head = head->next;
        else if (i == 2)
            head = head->prev;
        show_question(head);
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

struct choicequestion* insert_choicequestion(struct choicequestion* head) {       //管理->选择题->增加
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
    printf("请输入题目："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->name);
    printf("\n");
    printf("选项A："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[0]);
    printf("\n");
    printf("选项B："); while ((c = getchar()) != '\n' && c != EOF);scanf("%s", node->option[1]);
    printf("\n");
    printf("选项C："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[2]);
    printf("\n");
    printf("选项D："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[3]);
    printf("\n");
    printf("请输入答案："); while ((c = getchar()) != '\n' && c != EOF); scanf("%d", &node->ans);

    return node;
}

struct choicequestion* delet_choicequestion(struct choicequestion* head) {        //管理->选择题->删除
    if (head == NULL) {
        printf("链表为空！\n");
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
    head->next = NULL;                      //释放节点要把所有的指针都释放掉，否则残留的指针可能会引起指针的错误
    head->prev = NULL;

    return new_head;
}

void admin_one_question(struct choicequestion* head) {          //管理题目（上一题、下一题、增加、删除）
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
            head = save_file(head);
        else if (i == 4)
            head = delet_choicequestion(head);
        system("clear");             //清空终端
        show_question(head);
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

void load_file(struct choicequestion* head) {
//打开文件，读取文件（一行一行的读），关闭文件
    FILE* file = fopen("./question.txt", "r");
    //r只读， w只写（写入模式（清空原内容或创建新文件））， a+(追加模式（在文件末尾添加内容）)，  w+读写（会清空文件）, r+读写
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
//打开文件，写入文件（一行一行的读），关闭文件
    FILE* file = fopen("./question.txt", "a");
    if (file == NULL)
        return head;

    struct choicequestion* node=creat();

    int c;
    printf("请输入题目："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->name);
    printf("\n");
    printf("选项A："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[0]);
    printf("\n");
    printf("选项B："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[1]);
    printf("\n");
    printf("选项C："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[2]);
    printf("\n");
    printf("选项D："); while ((c = getchar()) != '\n' && c != EOF); scanf("%s", node->option[3]);
    printf("\n");
    printf("请输入答案："); while ((c = getchar()) != '\n' && c != EOF); scanf("%d", &node->ans);



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