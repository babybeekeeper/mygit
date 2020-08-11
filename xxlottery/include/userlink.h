#ifndef userlink_h_
#define userlink_h_

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"link.h"

#define  LEN  sizeof(userlink_t)
#define  LEN1 sizeof(user_t) 

/*
//用户链表
typedef struct user user_t; 
//用户链表别名			
typedef struct userlink userlink_t;			

struct user   //用户链表
{
	char name[20];
	char passwd[20];
	int id;          //注销时的标记
	float ownmoney;  //账户余额
};

struct userlink
{
	user_t data;		 //值域
	struct userlink* next;   //指向后一个
	struct userlink* prev;	//指向前一个
};*/

//用户链表节点
userlink_t* init1();  

 //保存用户的链表
void loaduser(userlink_t*);        

//加载用户的链表
void saveuser(userlink_t* );   

//释放用户链表节点
void free_user(userlink_t*);   

#endif
