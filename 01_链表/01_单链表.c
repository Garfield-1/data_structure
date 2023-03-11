#include<stdio.h>
#include<stdlib.h>

struct LNode
{
    struct LNode *next;
    char data;
};

/* 输出链表 */
void PrintNode(struct LNode *P)
{
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
    PrintNode(Head);
    return 0;
}