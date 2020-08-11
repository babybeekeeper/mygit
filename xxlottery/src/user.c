#include"user.h"
/*
	whetheraward:查看是否中奖
*/
void wetheraward(userlink_t* p,userlottery_t* head2,issuelink_t* head3)
{
	system("clear");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("正在查看中奖信息\n");
	int i=0;
	userlottery_t* p2=head2->next;
	if(p2 ==head2)
	{
		printf("彩票至今无人购买\n");
		goback();
		return;
	}
	if(head3->next->data.flag==0)
	{
		printf("彩票还未开奖\n");
		goback();
		return;
	}
	else if(head3->next->data.flag==1)
	{
		printf("已开奖\n");
	}
	while(p2 !=head2 && (p2->data.datetime == head3->next->data.datetime))
	{
		if(strcmp(p->data.name,p2->data.name) ==0)
		{
			if(p2->data.state==0)
			{
				printf("第%d期你没中奖\n",p2->data.datetime);
			}
			else if(p2->data.state ==1 || p2->data.state ==2 || p2->data.state ==3)
			{
				printf("你中了%d等奖，奖金为%g元,恭喜\n",p2->data.state,p2->data.money);
			}
			else if(p2->data.state==6)
			{
				printf("特等奖，奖金为%g元\n",p2->data.money);
			}
			i++;
		}
		p2=p2->next;
	}
	if(i==0)
	{
		printf("你未购买此期彩票\n");
		goback();
		return;
	}
	else
	{
		printf("此期彩票你一共购买%d次\n",i);
		printf("*****************************************\n");
		goback();
		return;
	}
}

/*
	6.买票
*/
void Bets(userlink_t* p,userlottery_t* head2,issuelink_t* head3)
{
	system("clear");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("正在购买彩票\n");
	if(head3->next->data.state ==1 && head3->next->data.flag ==0)//买票条件:已发行，未开奖
	{
		int num[7]={0};
		char str1=0;
		char str=0;
		char ch=0;
		char st=0;
		int i=0;
		int notes=0;
		int temp1=1;
		printf("彩票已发行,彩票未开奖,是否购买?\n");
		printf("输入购买(Y/y)，其他退出:");
		scanf("%c",&ch);
		while(getchar() != 10);
		if(ch=='y' || ch=='Y')
		{
			printf("开始购买彩票\n");
			printf("彩票单价(元):%g\n",head3->next->data.price);
			printf("奖池金额(元)：%g\n",head3->next->data.money);
			printf("输入你想购买的彩票号码(7位):");
			for(i=0;i<7;i++)
			{
				scanf("%d",&num[i]);
			}
			while(getchar() != 10); 
			printf("你购买的彩票号码为:");
			for(i=0;i<7;i++)
			{
				printf("%4d",num[i]);
			}
			printf("\n");
			printf("确认彩票号码(Y/y):");
			scanf("%c",&st);
			while(getchar() != 10);
			if(st=='y' || st=='Y')
			{
				while(temp1==1)
				{
					printf("输入购买注数(限5注):");
					scanf("%d",&notes);
					while(getchar() != 10);
					if(notes>0 && notes<=5)
					{
						printf("你购买的注数为%d注\n",notes);
						temp1=0;
					}
					else
					{
						printf("大于5注，请重新输入\n");
						temp1=1;
					}
				}
			}
			else 
			{
				printf("退出\n");
				sleep(2);
				return;
			}
		}
		else
		{
			printf("退出\n");
			sleep(2);
			return;
		}
		printf("确认购买(Y/y):");
		scanf("%s",&str);
		while(getchar() !=10);
		if(str!='y' && str!='Y')
		{
			printf("退出\n");
			sleep(2);
			return;
		}
		while(p->data.ownmoney < (head3->next->data.price)*notes)
		{
			printf("余额不足\n1.重新充值\n2.减少注数\n输入其他退出:");
			scanf("%c",&str1);
			while(getchar() !=10);
			if(str1=='1')
			{
				printf("进行充值\n");
				Rechargesystem(p);
			}
			else if(str1=='2')
			{
				temp1=1;
				printf("重新输入购买注数:\n");
				while(temp1==1)
				{
					printf("输入购买注数(限5注):\n");
					scanf("%d",&notes);
					while(getchar() != 10);
					if(notes>0 && notes<=5)
					{
						printf("购买注数为%d注\n",notes);
						temp1=0;
					}
					else
					{
						printf("限5注，请重新输入\n");
						temp1=1;
					}
				}
			}
			else
			{
				printf("退出\n");
				sleep(2);
				return;
			}
		}
		userlottery_t* p2=calloc(1,LEN3);
		p2->next=head2->next;
		head2->next->prev=p2;
		p2->prev=head2;
		head2->next=p2;
		strcpy(p2->data.name,p->data.name);
		p2->data.notes=notes;
		p2->data.id=p2->next->data.id+1;
		p2->data.datetime=head3->next->data.datetime;
		p2->data.price=head3->next->data.price;
		p->data.ownmoney=p->data.ownmoney-(head3->next->data.price)*notes;
		head3->next->data.money=head3->next->data.money + (head3->next->data.price)*notes;
		head3->next->data.notes=head3->next->data.notes+notes;
		for(i=0;i<7;i++)
		{
			p2->data.num[i]=num[i];
		}
		printf("彩票购买成功\n");
	}
	else if(head3->next->data.flag==1)
	{
		printf("彩票已开奖,等待下期发行\n");
	}
	else
	{
		printf("彩票系统发行0次，无法购买\n");
	}
	goback();
}

/*
	4.账户充值
*/
void Rechargesystem(userlink_t* p)
{
	system("clear");
	float money=0;
	char ch=0;
	int temp=1;
	printf("\033[5B");
	printf("欢迎进入商城\n");
	printf("**********************************\n");
	while(temp==1)
	{
		printf("输入充值金额(元):");
		scanf("%f",&money);
		while(getchar() != 10);
		if(money<=0)
		{
			printf("GUN!\n");
			temp=1;
		}
		else if(money>1000000)
		{
			printf("请保持冷静!\n");
		}  
		else
		{
			temp=0;
		}
	}
	printf("请确认充值(Y/y):");
	scanf("%s",&ch);
	while(getchar() != 10);
	if(ch=='y' || ch=='Y')
	{
		p->data.ownmoney=money+p->data.ownmoney;
		printf("充值成功\n");
		printf("**********************************\n");
		goback();
		return;
	}
	else
	{
		printf("充值失败\n");
		printf("**********************************\n");
		goback();
		return;
	}
}

/*
	3.注销个人信息
*/
void removeown(userlink_t* head1,userlink_t* p,userlottery_t* head2,usercancel_t* head4)
{
	system("clear");
	char passwd[20]={0};
	char passwd1[20]={0};
	char ch=0;;
	userlottery_t* p2=head2->next;
	printf("\033[5B");
	printf("正在进行注销账号---\n");
	printf("**************************************************\n");
	printf("输入账户密码:");
	getstr(passwd1);
	strcpy(passwd,passwd1);
	if(strcmp(passwd,p->data.passwd) != 0)
	{
		printf("密码错误，无法继续\n");
		printf("**************************************************\n");
		return ;
	}
	int temp=identifyCode();
	if(temp!=1)
	{
		return;
	}	
	printf("确认注销(Y/y)，其他取消修改:");
	scanf("%s",&ch);
	while(getchar() != 10);
	if(ch=='y' || ch=='Y')
	{
		while(p2 !=head2)
		{
			if(strcmp(p->data.name,p2->data.name)==0)
			{
				p2->prev->next=p2->next;
				p2->next->prev=p2->prev;
				free(p2);
			}
			p2=p2->next;
		}
		usercancel_t* p4=calloc(1,sizeof(usercancel_t));
		p4->next=head4->next;
		head4->next->prev=p4;
		head4->next=p4;
		p4->prev=head4;
		p4->data.id=p->data.id;
		strcpy(p4->data.name,p->data.name);
		p->prev->next=p->next;
		p->next->prev=p->prev;
		free(p);
		printf("账户注销成功！\n");
		printf("**************************************************\n");
		goback();
		return ;
	}
	else
	{
		printf("账户注销失败\n");
		printf("**************************************************\n");
		goback();
		return ;
	}	
}

/*
	printown:1.查看个人信息
*/
void printown(userlink_t* head1,userlink_t* p)
{
	system("clear");
	while(1)
	{
		char ch=0;
		printf("\033[5B");
		printf("你正在查看你的个人信息\n");
		printf("************************************\n");	
		printf("你的账号为:%s\n",p->data.name);
		printf("你的账号密码为:%s\n",p->data.passwd);
		printf("你的账号余额为(元):%g\n",p->data.ownmoney);
		printf("*************************************\n");
		printf("输入q退出:");
		scanf("%c",&ch);
		while(getchar()!=10);
		if(ch=='q')
		{
			return;
		}
	}
}

/*
	2.修改个人信息
*/
int updateown(userlink_t* head1,userlink_t* p)
{
	system("clear");
	char passwd1[20]={0};
	char passwd2[20]={0};
	char passwd[20]={0};
	char ch;
	printf("\033[3B");
	printf("正在修改账号密码---\n");
	printf("****************************************\n");
	printf("输入原密码:");
	getstr(passwd);
	strcpy(passwd,passwd);
	if(strcmp(passwd,p->data.passwd) != 0)
	{
		printf("密码与原密码不一致\n");
		printf("****************************************\n");
		sleep(2);
		return 0;
	}
	printf("修改后的密码:");
	getstr(passwd1);
	strcpy(passwd1,passwd1);
	printf("确认密码:");
	getstr(passwd2);
	strcpy(passwd2,passwd2);
	if(strcmp(passwd1,passwd2) != 0)
	{
		printf("密码不一致\n");
		printf("****************************************\n");
		sleep(2);
		return 0;
	}
	if(strcmp(passwd1,p->data.passwd)==0)
	{
		printf("密码一致，修改失败\n");
		printf("****************************************\n");
		goback();
		return 0;
	}
	printf("确认修改(Y/y)，其他取消修改:");
	scanf("%c",&ch);
	while(getchar() != 10);
	if(ch=='y' || ch=='Y')
	{
		strcpy(p->data.passwd,passwd1);
		printf("密码修改成功！\n");
		printf("****************************************\n");
		goback();
		return -1;
	}
	else
	{
		printf("取消修改密码");
		printf("****************************************\n");
		//sleep(2);
		return -1;
	}
}

/*
	findbuy:查看购票记录
*/
void findbuy(userlink_t* p,userlottery_t* head2,issuelink_t* head3)
{
	system("clear");
	printf("\033[3B");
	printf("***************正在查找购票历史信息*******************\n");
	userlottery_t* p2=head2->next;
	int i=0;  //购买次数
	int j=0;
	if(p2 ==head2)
	{
		printf("\033[15C你还未购买过彩票\n");
		goback();
		return;
	}
	while(p2!=head2)
	{
		if(strcmp(p2->data.name,p->data.name)==0)
		{
			i++;
			printf("购票账户名:%s\n",p2->data.name);
			printf("购买期号:%4d\n",p2->data.datetime);
			printf("彩票标注id:%d\n",p2->data.id);
			printf("购买的彩票号码为:");
			for(j=0;j<7;j++)
			{
				printf("%d-",p2->data.num[j]);
			}
			printf("\n");
			printf("彩票单价为:%g元\n",p2->data.price);
			printf("彩票购买的注数:%d注\n",p2->data.notes);
			if(p2->data.state != 0 )
			{
				if(p2->data.state==6)
				{
					printf("该次中了特等奖，奖金为(元):%g\n",p2->data.money);
				}
				else if(p2->data.state==1)
				{
					printf("该次中了一等奖，奖金为(元):%g\n",p2->data.money);
				}
				else if(p2->data.state==2)
				{
					printf("该次中了二等奖，奖金为(元):%g\n",p2->data.money);
				}
				else if(p2->data.state==3)
				{
					printf("该次中了三等奖，奖金为(元):%g\n",p2->data.money);
				}
			}
			else if(p2->data.state == 0 && head3->next->data.flag==0)
			{
				printf("本期未中奖\n");
			}
			else if(p2->data.state == 0 && head3->next->data.flag==1)
			{
				printf("本期未中奖\n");
			}
		}
		p2=p2->next;
	}
	printf("你共买彩票%d次\n",i);
	printf("************************************\n");
	goback();
}

