#ifndef issuelink_h_
#define issuelink_h_

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"link.h"

#define  LEN4 sizeof(issue_t)
#define  LEN5 sizeof(issuelink_t)
/*
//彩票信息结构体
typedef struct issue issue_t;	
//彩票链表别名				
typedef struct issuelink issuelink_t;			

struct issue   //彩票链表
{
	int datetime; 
	int num[7]; 	//中奖号码
	float price;
	int notes;    //售出注数
	float money;  //奖池
	int flag;     //是否开奖
	int temp;     //是否发奖
	int state;    //是否发行
};

struct issuelink
{
	issue_t data;				//数据
	struct issuelink* next;		//指向后一个
	struct issuelink* prev;		//指向前一个
};
*/
//彩票链表节点
issuelink_t* init3(); 

//保存发行的彩票
void saveissue(issuelink_t*); 

//加载发行的彩票
void loadissue(issuelink_t*); 

//释放发行的彩票的节点
void freeissue(issuelink_t*);  






#endif
