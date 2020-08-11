#ifndef control_h_
#define control_h_

#include"userlink.h"
#include"userlottery.h"
#include"issuelink.h"
#include"usercancel.h"
#include"menuview.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <assert.h>
#include <time.h>
#include"link.h"

//帐号查重
userlink_t* findname(userlink_t*,char*);  

//注册函数
int regist(userlink_t*);     

//登录函数
int login(userlink_t*,userlottery_t*,issuelink_t*,usercancel_t*); 

//密码隐藏
char* getstr(char* str);  

//验证码---验证  (验证通过返回值为1)
int identifyCode(void);  

//功能输入
char getch();   


//void getstring(char*,int);

//退出函数
void goback();
















void goback();  

#endif  
