//
//  LinkList.h
//  链表
//
//  Created by 赵旭鹏 on 2018/6/10.
//  Copyright © 2018 赵旭鹏. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#define OK 1
#define ERROR 0

#include <stdio.h>

typedef int    Status;             //定义函数返回值类型
typedef int    ElemType;        //结点数据的数据类型声明
typedef struct Node *LinkList;

/**
 "*L":这里我们传入的是一个指向头指针的指针，因为我们传入的头指针初始化指向的是 NULL，在函数中我们要修改头指针变量指向的地址(即头指针变量的值)使其指向头结点，所以要修改头指针变量的值我们必须把头指针变量的地址传进来，头指针变量的地址存在指向头指针的指针中，所以这里传入的是指向头指针的指针；如果不穿地址，传头指针变量，则相当于传入的是头指针变量的值，函数内部会复制一份副本，达不到真正修改原头指针指向的目的。（这里把头指针看做一个普通变量可以方便理解，只不过指针存的是地址）
 */
//链表初始化
Status initLinkList(LinkList *L);
/**
 *L:链表头指针
 n:链表长度
 */
//头插法整表创建
Status createLinkLisAtHead(LinkList *L, int n);
/**
 *L:链表头指针
 n:链表长度
 */
//尾插法整表创建
Status createLinkLisAtTail(LinkList *L, int n);
//整表删除
Status clearLinkList(LinkList *L);
//获取链表长度 返回值为链表长度
int getLinkListLength(LinkList *L);
//打印整个链表
Status printLinkList(LinkList *L);
/**
 *L:链表头指针
 index:指定下标
 *data:指向获取到的值的地址
 */
//获取指定位置结点的值
Status getData(LinkList *L, int index, ElemType *data);
/**
 *L:链表头指针
 index:指定插入下标
 data:要插入的值
 */
//在链表任意位置插入数据
Status instertData(LinkList *L, int index, ElemType data);
/**
 *L:链表头指针
 data:要新增的值
 */
//在链表末尾追加数据
Status appendData(LinkList *L, ElemType data);
/**
 *L:链表头指针
 index:指定删除的下标
 data:删除的结点的值
 */
//删除某一结点
Status  deleteNode(LinkList *L, int index, ElemType *data);
//翻转链表
Status reserveLinkList(LinkList *L);
#endif /* LinkList_h */
