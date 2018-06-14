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
/**
 思路:使用快慢指针，使快指针每次走两步，慢指针每次走一步，如果两个指针在某个位置相遇，则有环
 */
//判断链表中是否存在环
Status checkExistLoop(LinkList *L);
/**
 思路:使用两个指针初始指向第一个节点，假设倒数第K个节点前有m个节点，则倒数第K个节点即是正数第m+1个节点，
 则指针要走m步才能指向第m+1个节点，由于链表长度未知，所以m无法确定，所以转换思路，将倒数第K转化为正数第K，
 则正数第K个节点后同样有m个节点,所以如此先使一个指针移动到指向正数第K个节点，然后两个指针一起前进，则当前
 边的指针走到链表末尾，即指向NULL时，后出发的指针正好指向要找的倒数第K个节点
 */
//返回链表中倒数第K个节点的值
Status getCountDownK(LinkList *L, int k, ElemType *data);
#endif /* LinkList_h */
