#ifndef userlottery_h_
#define userlottery_h_

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"link.h"

#define  LEN2 sizeof(lottery_t)
#define  LEN3 sizeof(userlottery_t)

/*
typedef struct lottery lottery_t;				//个人彩票
typedef struct lotterylink userlottery_t;			//个人彩票别名

struct lottery   //个人彩票链表
{
	char name[20]; //购买者账号
	int datetime;
	int id; //彩票标志
	int num[7];//购买的号码
	float price;
	float money;//本次中奖奖金
	int notes; //购买者注数，如中奖就是该注数
	int state;  //是否中奖，特等奖6，其他123,0未中奖
};

struct lotterylink
{
	lottery_t data;   			//数据
	struct lotterylink* next;	//指向后一个
	struct lotterylink* prev;	//指向前一个
};
*/

 //个人彩票链表
userlottery_t* init2();

//保存个人彩票的链表
void savelottery(userlottery_t*);  

//加载个人彩票的链表
void loadlottery(userlottery_t*);      

  //释放个人彩票的节点
void freelottery(userlottery_t*);      


#endif
