#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stuff {
    int salary;
    char snum[10], name[30], sex[10], birth[10], email[30];
};

struct node {
    stuff sf;
    node *next;
};

node *load(char *filename, int *n)
{
    node *head = NULL;
    FILE *f = fopen(filename, "rb");
//        printf("....%d",*n);
    if (fread(n, sizeof(int), 1, f) == 1) {
        for (int i = 0; i < *n; i++) {
            node *p = (node *) malloc(sizeof(stuff));
            fread(&(p->sf), sizeof(stuff), 1, f);
            p->next = head;
            head = p;
        }
    }
    return head;
}

void save(char *filename, int n, node *head)
{
    FILE *f = fopen(filename, "wb");
    fwrite(&n, sizeof(int), 1, f);
    while (head != NULL) {
        fwrite(&(head->sf), sizeof(stuff), 1, f);
        head = head->next;
    }
}

void print(node *head)
{
    while (head != NULL) {
        printf("worker num: %s\nname: %s\nsex: %s\nbirthday: %s\nemail: %s\nsalary: %d\n\n", head->sf.snum,
               head->sf.name, head->sf.sex, head->sf.birth, head->sf.email, head->sf.salary);
        head = head->next;
    }
}

node *add(node *head, int *n)
{
    (*n)++;
    node *p = (node *) malloc(sizeof(node));
    p->next = head;
    head = p;
    scanf("%s%s%s%s%s%d", head->sf.snum, head->sf.name, head->sf.sex, head->sf.birth, head->sf.email,
          &(head->sf.salary));
    return head;
}

node *del(node *head, int *n, char *snum)
{
//    if (strcmp(head->sf.snum, snum) == 0)  printf("nnmmmnnnn");
    if (strcmp(head->sf.snum, snum) == 0) {
        (*n)--;
        node *p = head;
        head = head->next;
//        free(p);
//        printf("nnmmmnnnn");
    } else {
        node *p = head;
        node *prev = NULL;
        while (p != NULL && strcmp(p->sf.snum, snum) != 0) {
            prev = p;
            p = p->next;
        }
        if (p != NULL) {
            (*n)--;
            prev->next = p->next;
//            free(p);
        }
    }
    return head;
}

void find(node* head, char* snum){

}

int main()
{
    int n = 2;
    node *head = NULL;
    /*node *p = (node *) malloc(sizeof(stuff));
    p->next = head;
    head = p;
    p->sf.salary = 100;
    strcpy(p->sf.email, "123@qq.com");
    strcpy(p->sf.birth, "19111111");
    strcpy(p->sf.sex, "man");
    strcpy(p->sf.name, "lmao");
    strcpy(p->sf.snum, "123456");
    p = (node *) malloc(sizeof(stuff));
    p->next = head;
    head = p;
    p->sf.salary = 1000;
    strcpy(p->sf.email, "666@qq.com");
    strcpy(p->sf.birth, "19221111");
    strcpy(p->sf.sex, "woman");
    strcpy(p->sf.name, "haha");
    strcpy(p->sf.snum, "654321");*/
    char *filename = "test.bin";
    head = load(filename, &n);
//    printf("nnnnnn");
    char snum[]="666777";
//    head = del(head,&n, snum);
//    save(filename, n, head);
    print(head);
//    save(filename, n, head);
}