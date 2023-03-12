#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct LNode
{
    struct LNode *next;
    char data;
};

/* 输出链表 */
void PrintNode(struct LNode *P)
{
    if(P == NULL) {
        printf("当前链表为空\n");
        return;
    }

    while(P != NULL ) {
        printf("%c ",P->data);
        P = P->next;
    }
    printf("\n");
    return;
}

/* 尾插法新增节点 */
void InsertTail(struct LNode *P)
{
    while(P->next != NULL ) {
        P = P->next;
    }

    struct LNode *Node;
    Node = (struct LNode *)malloc(sizeof(struct LNode));
    Node->next = NULL;
    Node->data = 'a';

    P->next = Node;

    return;
}

/* 头插法新增节点 */
void InsertHead(struct LNode *P)
{
    struct LNode *Node;
    Node = (struct LNode *)malloc(sizeof(struct LNode));
    Node->data = 'b';

    Node->next = P->next;
    P->next = Node;

    return;
}

/* 将链表中的src替换为dest */
void ChangeNode(struct LNode *P, char src, char dest)
{
    while(P != NULL) {
        if(P->data == src) {
            P->data = dest;
        }
        P = P->next;
    }
    return;
}

/* 删除链表中的第N个节点 */
void DelListNumber(struct LNode *P, int num)
{
    struct LNode *L;
    int counter = 0;
    while(P->next != NULL && counter != num-1) {
        P = P->next;
        counter++;
    }

    L = P->next;
    P->next = P->next->next;
    free(L);
    L->next = NULL;
}

/* 递归销毁链表 */
void DelListRecursion(struct LNode *P)
{
    if(P == NULL) {
        return;
    }

    DelListRecursion(P->next);
    printf("Node= %p\n",P);
    free(P);
    /* 
     * free不会清理对应内存，需要手动将当前节点的指针域置空，此操作会递归修改整个链表，确保节点之间的联系被切断
     * 由于是递归修改，此处的Node实际是上一层调用栈中的入参Node->next，不能通过一级指针直接修改指针本身，所以Node=NULL无意义
     */
    P->next = NULL;

    return;
}

/* 顺序销毁链表 */
void DelListOrdinal(struct LNode *P)
{
    struct LNode *L;
    while(P) {
        L = P;
        P = P->next;
        free(L);
    }
    return;
}

int main()
{
    struct LNode *Head;

    /* 初始化头节点 */
    Head = (struct LNode *)malloc(sizeof(struct LNode));
    Head->next = NULL;

    for(int i = 0; i<3 ;i++) {
        InsertTail(Head);
        InsertHead(Head);
    }
    ChangeNode(Head, 'a', 'd');
    DelListNumber(Head,3);
    PrintNode(Head);
    return 0;
}