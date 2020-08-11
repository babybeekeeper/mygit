#ifndef nottery_h_
#define nottery_h_

#include"userlink.h"
#include"userlottery.h"
#include"issuelink.h"
#include"usercancel.h"
#include"menuview.h"
#include"admin.h"
#include"award.h"
#include"link.h"

//开奖操作，没人买无法开奖
void openflag(userlink_t*,userlottery_t*,issuelink_t*); 

//查询此期彩票中奖信息 
void findwho(userlink_t* ,userlottery_t*,issuelink_t*); 

//发奖操作
void award(userlink_t*,userlottery_t*,issuelink_t*);

//进入查看历史彩票信息界面
void finlot(userlink_t*,userlottery_t*,issuelink_t*);

 //根据姓名查找其购买过的彩票
void buyname(userlink_t*,userlottery_t*,issuelink_t*);   
void issuedatetime(userlottery_t*,issuelink_t*);

//根据期号查看该期信息
void issuetime(issuelink_t* );  

#endif
