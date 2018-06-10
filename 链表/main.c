//
//  main.c
//  链表
//
//  Created by 赵旭鹏 on 2018/6/9.
//  Copyright © 2018 赵旭鹏. All rights reserved.
//

//

/**
 *链表的结点由存放数据元素的数据域和存放后继结点地址的指针域组成
 *链表中第一个节点的存储位置叫做头指针
 *线性列表的最后一个结点指针为“空”，NULL
 *头指针：
    是指链表指向第一个结点的指针，若链表则是指向头结点的指针；
    头指针具有标识作用，所以常用头指针冠以链表的名字；
    无论链表是否为空，头指针都不为空，头指针是链的必要元素；
 *头结点：
    头结点是为了操作的统一和方便而设立的，放在第一元素的结点之前，其数据域一般无意义（也可存放链表的长度）
    有了头结点，对在第一元素结点前插入结点和删除第一结点，其操作与其他结点的操作就统一了
    头结点不是链表第一要素
 */

typedef int ElemType;

//线性表的单链表存储结构
typedef struct Node
{
    ElemType data;
    struct Node *next;
    
}Node, *LinkList;

//typedef struct Node *LinkList; //同上

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
