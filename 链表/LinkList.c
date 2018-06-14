//
//  LinkList.c
//  链表
//
//  Created by 赵旭鹏 on 2018/6/10.
//  Copyright © 2018 赵旭鹏. All rights reserved.
//

#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//线性表的单链表存储结构
typedef struct Node
{
    ElemType data;
    struct Node *next;
    
}Node;

Status initLinkList(LinkList *L)
{
    //L 是头指针,指向头结点
    (*L)  = (LinkList)malloc(sizeof(Node));
    if ((*L) == NULL) {
        printf("链表初始化失败!\n");
        return ERROR;
    }
    printf("链表初始化成功!\n");
    //初始化头结点指针指向 NULL，数据域不做处理
    (*L)->next = NULL;
    return OK;
}

Status createLinkLisAtHead(LinkList *L, int n)
{
    if ((*L) == NULL) {
        printf("链表未初始化!\n");
        return ERROR;
    }
    LinkList p; //声明指向新节点的指针
    srand((int)time(0));//随机数种种子
    for (int i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        if (p == NULL) {
            printf("第%d 个结点创建失败!\n",i);
            return ERROR;
        }
        p->data = rand() % 100;
        p->next = (*L)->next;
        (*L)->next = p;
    }
    printf("头插法链表整表创建成功!\n");
    return OK;
}

Status createLinkLisAtTail(LinkList *L, int n)
{
    if ((*L) == NULL) {
        printf("链表未初始化!\n");
        return ERROR;
    }
    LinkList p; //声明指向新节点的指针
    LinkList tail = *L;//保存尾结点的临时变量
    srand((int)time(0));//随机数种种子
    for (int i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        if (p == NULL) {
            printf("第%d 个结点创建失败!\n",i);
            return ERROR;
        }
        p->data = rand() % 100;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    printf("尾插法链表整表创建成功!\n");
    return OK;
}

Status clearLinkList(LinkList *L)
{
    if ((*L) == NULL) {
        printf("链表未初始化!\n");
        return ERROR;
    }
    LinkList p;//声明遍历链表指向当前结点的指针
    LinkList q;//临时指向当前结点下一个结点的指针
    p = (*L)->next;//指向第一个节点
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;//头结点指针域置空
    return OK;
}

int getLinkListLength(LinkList *L)
{
    if ((*L) == NULL) {
        printf("链表未初始化!\n");
        return ERROR;
    }
    int length = 0;
    LinkList p;//声明遍历链表指向当前结点的指针
    p = (*L)->next;//指向第一个节点
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

Status printLinkList(LinkList *L)
{
    if ((*L) == NULL) {
        printf("链表未初始化!\n");
        return ERROR;
    }
    int i = 0;
    LinkList p;//声明遍历链表指向当前结点的指针
    p = (*L)->next;//指向第一个节点
    if (p == NULL) {
        printf("链表为空!\n");
        return ERROR;
    }
    while (p) {
        i++;
        printf("链表第%d个元素值为:%d!\n", i, p->data);
        p = p->next;
    }
    return OK;
}

Status getData(LinkList *L, int index, ElemType *data)
{
    *data = -1;
    if ((*L) == NULL) {
        printf("链表未初始化!\n");
        return ERROR;
    }
    int currentIndex = 1;
    LinkList p;//声明遍历链表指向当前结点的指针
    p = (*L)->next;//指向第一个节点
    if (p == NULL) {
        printf("链表为空!\n");
        return ERROR;
    }
    if (index < 1) {
        printf("查询下标不能小于1!\n");
        return ERROR;
    }
    while (p && currentIndex < index) {
        p = p->next;
        currentIndex++;
    }
    if (p == NULL) {
        printf("查询下标超出了链表的最大长度!\n");
        return ERROR;
    }
    *data = p->data;
    return OK;
}

Status instertData(LinkList *L, int index, ElemType data)
{
    if ((*L) == NULL) {
        printf("链表未初始化!\n");
        return ERROR;
    }
    if (index < 1) {
        printf("插入下标不能小于1!\n");
        return ERROR;
    }
    int currentIndex = 1;
    LinkList p;//声明遍历链表指向当前结点的指针
    LinkList newNode;//声明一个新节点
    p = *L;//头指针
    while (p && currentIndex < index) { //寻找第 index - 1个结点
        p = p->next;
        currentIndex++;
    }
    if (p == NULL) {
        printf("插入下标超出了链表的范围!\n");
        return ERROR;
    }
    newNode = (LinkList)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}

Status appendData(LinkList *L, ElemType data)
{
    if ((*L) == NULL) {
        printf("链表未初始化!\n");
        return ERROR;
    }
    LinkList p;//声明遍历链表指向当前结点的指针
    LinkList newNode;//声明一个新节点
    LinkList tail = NULL;//记录尾结点
    p = *L;//头指针
    while (p) {
        tail = p;
        p = p->next;
    }
    newNode = (LinkList)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    tail->next = newNode;
    return OK;
}

Status  deleteNode(LinkList *L, int index, ElemType *data)
{
    if ((*L) == NULL) {
        printf("链表未初始化!\n");
        return ERROR;
    }
    LinkList p,pnext;
    int j = 0;
    p = (*L);
    if (p->next == NULL) {
        printf("链表为空，无法删除指定节点.\n");
        *data = -1;
        return ERROR;
    }
    while (p->next && j < index - 1) {
        j++;
        p = p->next;
    }//条件最多定位到最后一个节点；
    if ( p->next == NULL) {
        printf("您要删除的节点，超过了链表的长度 %d，请重新操作！\n", j);
        *data = -1;
        return ERROR;
        }
    pnext = p->next;
    p->next = pnext->next;
    *data = pnext->data;
    free(pnext);
    printf("节点删除成功\n");
    return OK;
}

Status reserveLinkList(LinkList *L)
{
    if (*L == NULL) {
        printf("链表没有初始化");
        return ERROR;
    }
    if ((*L)->next == NULL) {
        printf("链表为空");
        return ERROR;
    }
    LinkList p, pPro, pNext;
    p = (*L)->next;
    pNext = p->next;
    pPro = NULL;
    while (pNext != NULL) {
        p->next = pPro;
        pPro = p;
        p = pNext;
        pNext = pNext->next;
    }
    p->next = pPro;
    pPro = p;
    (*L)->next = pPro;
    pPro = p = NULL;
    
    return OK;
}

Status checkExistLoop(LinkList *L)
{
    if (*L == NULL) {
        printf("链表没有初始化!\n");
        return ERROR;
    }
    if ((*L)->next == NULL) {
        printf("链表为空");
        return ERROR;
    }
    LinkList fast, slow;
    slow = fast = (*L)->next;
    while (slow != NULL && fast != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            printf("该链表中有环\n");
            return OK;
        }
    }
    printf("该链表中没有环\n");
    return ERROR;
}

Status getCountDownK(LinkList *L, int k, ElemType *data)
{
    if (*L == NULL) {
        printf("链表没有初始化!\n");
        return ERROR;
    }
    if ((*L)->next == NULL) {
        printf("链表为空");
        return ERROR;
    }
    LinkList front, back;
    int count = 1;
    front = back = (*L)->next;//指向第一个节点
    while (front->next != NULL) {
        count ++;
        if (count > k) {
            back = back->next;
        }
        front = front->next;
    }
    if (k > count) {
        printf("所求值不在链表范围内\n");
        return ERROR;
    }
    *data = back->data;
    printf("倒数第%d个结点的值获取成功:%d\n", k, *data);
    return OK;
}
