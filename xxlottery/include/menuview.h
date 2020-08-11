#ifndef menuview_h_
#define menuview_h_

#include"userlink.h"
#include"userlottery.h"
#include"issuelink.h"
#include"usercancel.h"
#include"control.h"
#include"nottery.h"
#include"admin.h"
#include"user.h"
#include"game.h"


//用户界面
void userlot(userlink_t*,userlink_t*,userlottery_t*,issuelink_t*,usercancel_t*); 

//管理员界面
void issue(userlink_t*,userlottery_t*,issuelink_t*,usercancel_t*);  

//公证员界面
void notary(userlink_t*,userlottery_t*,issuelink_t*);





#endif
