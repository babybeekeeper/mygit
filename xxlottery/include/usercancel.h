#ifndef usercancel_h_
#define usercancel_h_

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"link.h"
#define  LEN6 sizeof(cancel_t)
#define  LEN7 sizeof(usercancel_t)

/*
//帐号注销结构体
typedef struct cancel cancel_t;	
//注销链表别名					
typedef struct usercancel usercancel_t;      

struct cancel   //删除用户链表
{
	char name[20];
	char passwd[20];
	int id;
	float ownmoney;  //注销时的账户余额
};

struct usercancel
{
	cancel_t data;				//数据
	struct usercancel* next;	//指向后一个
	struct usercancel* prev;  //指向前一个
};
*/

//删除用户链表
usercancel_t* init4();
 //保存删除的用户的链表
void savecancel(usercancel_t*); 
 //加载删除用户的链表
void loadcancel(usercancel_t*); 
 //释放删除用户链表节点
void freecancel(usercancel_t*);

#endif
