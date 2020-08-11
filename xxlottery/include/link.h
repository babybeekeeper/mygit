#ifndef link_h_
#define link_h_


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
};


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



#endif
