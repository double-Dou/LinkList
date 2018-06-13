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
 
 *假设指针标量 p 指向链表中的任意结点，则访问结点分量有一下方式:
    1.(*p).data 和 (*p).next
    2.p->data 和 p->next
 
 *链表操作中动态存储分配要使用的标准函数：
    1. malloc(size):在内存的动态存储区申请一个长度为 size 字节的连续空间
    2. calloc(n, size):在内存的动态存储区申请 n 个长度为 size 字节的连续空间，函数返回值为分配空间的首地址，若函数执行失败，则返回值为0
    3. free(p):释放右指针 p 所指向的存储单元，而存储单元的大小是最近一次调用 malloc 或 calloc 函数时所申请的存储空间
    以上函数包含在 stdlib.h 文件中
    调用动态存储分配函数返回的指针是指向 void 类型或 char 类型的指针，在具体使用时，要根据所指向的数据类型进行强制类型转换
 
 
 *单链表建立的头插法和尾插法
    1.头插法：
    头插法是将连败哦右端看成是固定的，链表不断向左延伸而得到的；头插法最先得到的是尾结点。
    2.尾插法：
    尾插法是将链表的左端固定，链表不断的向右延伸而得到的；尾插法最先得到的是头结点。
 */

#include <stdio.h>
#include "LinkList.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    LinkList list = NULL;
    initLinkList(&list);//链表初始化
    printf("链表的首地址为:%p\n",list);
    createLinkLisAtHead(&list, 10);//头插法
    printLinkList(&list);
    reserveLinkList(&list);
    printLinkList(&list);
//    createLinkLisAtTail(&list, 10);//尾插法
//    int length = getLinkListLength(&list);//获取链表长度
//    printf("链表的长度为：%d\n",length);
//    int data;
//    getData(&list, 5, &data);
//    printf("链表的第5个结点的值是：%d\n", data);
    return 0;
}
