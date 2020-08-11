#ifndef user_h_
#define user_h_

#include"control.h"
#include"userlink.h"
#include"userlottery.h"
#include"issuelink.h"
#include"usercancel.h"
#include"menuview.h"
#include"link.h"


//1.查看用户信息
void printown(userlink_t*,userlink_t*);  

//2.修改个人信息
int updateown(userlink_t*,userlink_t*);

//4.充值  
void Rechargesystem(userlink_t*); 

//6.买票   
void Bets(userlink_t* ,userlottery_t*,issuelink_t*); 

//3.注销个人信息
void removeown(userlink_t* ,userlink_t* ,userlottery_t*,usercancel_t*);

//5.查询中奖记录(是否中奖)  
void wetheraward(userlink_t* ,userlottery_t*,issuelink_t*);  

//7.查询购票记录
void findbuy(userlink_t* ,userlottery_t*,issuelink_t*); 


//8.小游戏  

#endif
