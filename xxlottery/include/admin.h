#ifndef admin_h_
#define admin_h_

#include"userlink.h"
#include"userlottery.h"
#include"issuelink.h"
#include"usercancel.h"
#include"menuview.h"
#include"control.h"
#include"link.h"

typedef int (*comp)(userlink_t*,userlink_t*);

//判断能否发行下一期彩票
int whetherflag(issuelink_t*);

//1.发行彩票   
void issuelot(issuelink_t*);

//2.选择查询 
void findlotp(userlink_t*,userlottery_t*,issuelink_t*,usercancel_t*);

//按余额范围查询彩民信息
void balance(userlink_t*);

//3.排序选择   
void sort(userlink_t*,userlottery_t*);

//ｓort,compare双向循环链表的快速排序,排姓名，余额
void sort1(userlink_t*,userlink_t*,comp);

//ｓort,compare双向循环链表的快速排序,排姓名，余额
int compare_money(userlink_t*,userlink_t*);

//ｓort,compare双向循环链表的快速排序,排姓名，余额
int compare_name(userlink_t*,userlink_t*);   

//根据输入的期号查找相应的购买彩票信息
void issuedatetime(userlottery_t*,issuelink_t* );  

  //根据期号查看该期信息
void issuetime(issuelink_t*);

//查看最新一期的彩票信息 
void newissue(issuelink_t*);   

 //根据姓名查看彩民的信息
void nameinforma(userlink_t*);

 //根据信息查看注销的彩民信息   
void findremove(usercancel_t*);


#endif
