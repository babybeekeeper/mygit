#include"nottery.h"

/*
	award:发奖操作
*/
void award(userlink_t* head1,userlottery_t* head2,issuelink_t* head3)
{
	system("clear");
	printf("你正准备发奖\n");
	printf("*****************************************\n");
	int i=0,j=0;
	char ch=0;
	char str=0;
	float money=0,moneyt=0,money1=0,money2=0,money3=0,money_t=0;
	if(head2->next==head2 && head3->next->data.flag==1 )    //
	{
		head3->next->data.temp=1; //没人买也要置1,开奖时已经判断无人购买时不会开奖
		printf("*****************************************\n");
		printf("至今无人购买\n");
		goback();
		return;
	}
	printf("准备发奖\n");
	if(head3->next->data.flag==1)
	{
		printf("此期彩票已开奖，正在查询是否已发奖\n");
		if(head3->next->data.temp==0)
	 	{
	  		i=1;
			printf("此期彩票还未发奖可以发奖\n");
	  	}
		else if(head3->next->data.temp==1)
		{
	  		printf("此期彩票已发奖\n");
	  		printf("*****************************************\n");
	  	}
	}
	else if(head3->next->data.flag==0)
	{
		printf("此期彩票还未开奖，无法发奖\n");
		printf("*****************************************\n");
		goback();
		return ;
	}
	else if(head3->next==head3)
	{
		printf("彩票还未发行，等待管理员发行\n");
		printf("*****************************************\n");
		goback();
		return;
	}
	if(i==1)               //发奖，分配奖金
	{
		printf("开始发奖(Y/y)，输入其他退出:");
		scanf("%c",&ch);
		while(getchar() !=10);
		if(ch !='y' && ch!='Y')
		{
			printf("退出\n");
			sleep(2);
			return;			
		}
		printf("奖池金额为(元):%g\n",head3->next->data.money);	
		printf("奖池金额40%%做为奖金\n");
		money=(head3->next->data.money)*0.4;
		printf("分配给玩家的金额为(元):%g\n",money);
	}
	else
	{  //i=0已发奖
		goback();
		return;
	}
	printf("下面是中奖信息:\n");
	userlottery_t* p2=head2->next;
	int sumt=0,sum1=0,sum2=0,sum3=0;         //中奖总人数
	int notest=0,notes1=0,notes2=0,notes3=0; //中奖总注数
	while(p2 !=head2 && p2->data.datetime==head3->next->data.datetime)
	{
		j=0;
		for(i=0;i<7;i++)
		{
			if(p2->data.num[i]==head3->next->data.num[i])
			{
				j++;
			}
		}
		if(j==7)
		{	
			printf("\033[15C特等奖人员和对应注数为:");
			printf("%4s,%d\n",p2->data.name,p2->data.notes);
			notest=p2->data.notes+notest;
			sumt++;
		}
		else if(j==6)
		{	
			printf("\033[15C一等奖人员和对应注数为:");
			printf("%4s,%d\n",p2->data.name,p2->data.notes);
			notes1=p2->data.notes+notes1;
			sum1++;
		}
		else if(j==5)
		{	
			printf("\033[15C二等奖人员和对应注数为:");
			printf("%4s,%d\n",p2->data.name,p2->data.notes);
			notes2=p2->data.notes+notes2;
			sum2++;
		}
		else if(j==4)
		{	
			printf("\033[15C三等奖人员和对应注数为:");
			printf("%4s,%d\n",p2->data.name,p2->data.notes);
			notes3=p2->data.notes+notes3;
			sum3++;
		}
		else
		{
			printf("\033[15C本期无人中奖\n");
		}	
		p2=p2->next;
	}
	if(sumt !=0)
	{
		moneyt=(money*0.4)/(notest);
		printf("\033[15C特等奖中奖人数为(人):%d\n",sumt);
		printf("\033[15C特等奖一注分得奖金为(元):%g\n",moneyt);
	}
	else
	{
		printf("\033[15C无人中得特等奖\n");
	}
	if(sum1 !=0)
	{
		money1=(money*0.3)/(notes1);
		printf("\033[15C一等奖中奖人数为(人):%d\n",sum1);
		printf("\033[15C一等奖一注分得奖金为(元):%g\n",money1);
	}
	else
	{
		printf("\033[15C无人中得一等奖\n");
	}
	if(sum2 !=0)
	{
		money2=(money*0.2)/(notes2);
		printf("\033[15C二等奖中奖人数为(人):%d\n",sum2);
		printf("\033[15C二等奖一注分得奖金为(元):%g\n",money2);
	}
	else
	{
		printf("\033[15C无人中得二等奖\n");
	}
	if(sum3 !=0)
	{
		money3=(money*0.1)/(notes3);
		printf("\033[15C三等奖中奖人数为(人):%d\n",sum3);
		printf("\033[15C三等奖一注分得奖金为(元):%g\n",money3);
	}
	else
	{
		printf("\033[15C无人中得三等奖\n");
	}
	printf("确认发奖(Y/y),输入其他退出:");
	scanf("%s",&str);
	while(getchar() != 10);
	if(str!='Y' && str!='y')
	{
		printf("***************************************\n");
		printf("退出\n");
		sleep(2);
		return;
	}
	p2=head2->next;
	while(p2 !=head2 && p2->data.datetime==head3->next->data.datetime)
	{
		j=0;
		for(i=0;i<7;i++)
		{
			if(p2->data.num[i]==head3->next->data.num[i])
			{
				j++;
			}
		}
		if(j==7)
		{	
			userlink_t* temp=findname(head1,p2->data.name);
			temp->data.ownmoney=temp->data.ownmoney+moneyt*(p2->data.notes);
			p2->data.money=moneyt*(p2->data.notes);
			p2->data.state=6; //标志位，中奖了
		}
		else if(j==6)
		{	
			userlink_t* temp=findname(head1,p2->data.name);
			temp->data.ownmoney=temp->data.ownmoney+money1*(p2->data.notes);
			p2->data.money=money1*(p2->data.notes);
			p2->data.state=1;
		}
		else if(j==5)
		{	
			userlink_t* temp=findname(head1,p2->data.name);
			temp->data.ownmoney=temp->data.ownmoney+money2*(p2->data.notes);
			p2->data.money=money2*(p2->data.notes);
			p2->data.state=2;
		}
		else if(j==4)
		{	
			userlink_t* temp=findname(head1,p2->data.name);
			temp->data.ownmoney=temp->data.ownmoney+money3*(p2->data.notes);
			p2->data.money=money3*(p2->data.notes);
			p2->data.state=3;
		}
		else
		{
			p2->data.money=0;
			p2->data.state=0;
		}
		p2=p2->next;
	}
	money_t=moneyt*notest+money1*notes1+money2*notes2+money3*notes3;
	head3->next->data.money=(head3->next->data.money)-money_t;
	head3->next->data.temp=1;  //1已发奖
	printf("发奖成功\n");
	printf("***************************************\n");
	while(ch !='q')
	{
		printf("输入q退出:");
		scanf("%c",&ch);
		while(getchar() !=10);
	}
}
/*
	findwho:查询此期彩票中奖信息
*/
void findwho(userlink_t* head1,userlottery_t* head2,issuelink_t* head3)
{
	system("clear");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	int i=0,j=0;
	char st1=0;
	printf("正在查询此期彩票中奖人员信息\n");
	printf("******************************************\n");
	userlottery_t* p2=head2->next;
	if(p2 == head2)
	{
		printf("至今为止无人购买彩票\n");
		goback();
		return;
	}
	printf("输入f查询此期彩票中奖人员，输入其他退出:");
	scanf("%c",&st1);
	while(getchar() !=10);
	if(st1 !='f')
	{
		printf("\033[10C退出\n");
		sleep(2);
		return;
	}
	printf("本期彩票中奖号码为:");
	for(i=0;i<7;i++)
	{
		printf("%4d",head3->next->data.num[i]);
	}
	printf("\n");
	int temp=0;
	while(p2 !=head2)
	{	
		j=0;
		if(p2->data.datetime == head3->next->data.datetime)
		{
			for(i=0;i<7;i++)
			{
				if(p2->data.num[i]==head3->next->data.num[i])
				{
					j++;
				}
			}
			if(j==7)
			{	
				temp++;
				printf("特等奖人员和对应注数为:");
				printf("%s,%d注\n",p2->data.name,p2->data.notes);
				printf("其购买的号码为:");
				for(i=0;i<7;i++)
				{
					printf("%4d",p2->data.num[i]);
				}
				printf("\n");
			}
			else if(j==6)
			{	
				temp++;
				printf("一等奖人员和对应注数为:");
				printf("%s,%d注\n",p2->data.name,p2->data.notes);
				printf("其购买的号码为:");
				for(i=0;i<7;i++)
				{
					printf("%4d",p2->data.num[i]);
				}
				printf("\n");
			}
			else if(j==5)
			{	
				temp++;
				printf("二等奖人员和对应注数为:");
				printf("%s,%d注\n",p2->data.name,p2->data.notes);
				printf("其购买的号码为:");
				for(i=0;i<7;i++)
				{
					printf("%4d",p2->data.num[i]);
				}
				printf("\n");
			}
			else if(j==4)
			{
				temp++;	
				printf("三等奖人员和对应注数为:");
				printf("%s,%d注\n",p2->data.name,p2->data.notes);
				printf("购买的号码为:");
				for(i=0;i<7;i++)
				{
					printf("%4d",p2->data.num[i]);
				}
				printf("\n");
			}
		}
		p2=p2->next;
	}
	if(temp==0)
	{
		printf("无人中奖\n");
	}
	printf("******************************************\n");
	goback();
}
/*

	openflag:开奖操作
*/
void openflag(userlink_t* head1,userlottery_t* head2,issuelink_t* head3)
{
	system("clear");
	printf("\033[5B");
	char ch=0;
	int i=0;
	int temp=0; //判断有没有人买
	int num[7]={0};
	int c=0;
	userlottery_t* p2=head2->next;
	printf("\033[20C欢迎来到开奖界面\n");
	printf("******************************************************\n");
	while(p2 !=head2)
	{
		if(head3->next->data.datetime == p2->data.datetime)  
		{
			temp++;
		}
		p2=p2->next;
	}
	if(temp==0)
	{
		printf("此期彩票无人购买\n");
		printf("******************************************************\n");
		goback();
		return;
	}
	if(head3->next->data.state==1)
	{
		printf("1.手动开奖，2.自动开奖\n");
		printf("请选择:");
		scanf("%d",&c);
		while(getchar() !=10);
		if(c==2)		
		{
			if(head3->next->data.flag==0)
			{
				printf("此期彩票还未开奖，可以进行开奖操作\n");
				printf("输入y进行开奖:");
				scanf("%c",&ch);
				while(getchar() !=10);
				if(ch=='y')
				{
					printf("\n");
					autobonus();
					printf("\n");
				}
				else
				{
					printf("退出\n"); 
					sleep(2);
					return;
				}
				printf("开奖号码为:");
				for(i=0;i<7;i++)
				{
					printf("%4d-",num[i]);
					head3->next->data.num[i]=num[i];
				}
				printf("此期彩票生成成功\n");
				head3->next->data.flag=1;
				printf("开奖成功\n");
				char ch=0;
				while(ch !='q')
				{
					printf("输入q退出:");
					scanf("%c",&ch);
					while(getchar() !=10);
				}
				//sleep(2);	
			}	
			else if(head3->next->data.flag==1)
			{
				printf("上期彩票已开奖，等待管理员发行下一期彩票\n");
				goback();
				return;
			}
		}
		else if(c==1)
		{
			if(head3->next->data.flag==0)
			{
				printf("此期彩票还未开奖，可以进行开奖操作\n");
				printf("输入y进行开奖:");
				scanf("%c",&ch);
				while(getchar() !=10);
				if(ch=='y')
				{
					printf("输入开奖号码:");
					for(i=0;i<7;i++)
					{
						scanf("%d",&num[i]);
					}
					while(getchar() !=10);
				}
				else
				{
					printf("\033[10C退出");
					//sleep(2);
					return;
				}
				printf("此期彩票生成成功\n");
				printf("彩票号码为:");
				for(i=0;i<7;i++)
				{
					printf("%4d",num[i]);
					head3->next->data.num[i]=num[i];
				}
				printf("\n");
				head3->next->data.flag=1;
				printf("开奖成功\n");	
			}	
			else if(head3->next->data.flag==1)
			{
				printf("上期彩票已开奖，等待管理员发行下一期\n");
				goback();
				return;
			}
		}
	}
	else if(head3->next==head3)
	{
		printf("还未有彩票发行，等待管理员发行一期\n");
		goback();
		return ;
	}
	printf("****************************************************\n");
}
/*
	buyname:根据姓名查找其购买过的彩票
*/
void buyname(userlink_t* head1,userlottery_t* head2,issuelink_t* head3)
{
	system("clear");
	printf("\033[5B\n");
	char name[20]={0};
	printf("正在按姓名查找历史发行彩票信息\n");
	printf("************************************************\n");
	printf("请输入你想查找的姓名:");
	scanf("%s",name);
	while(getchar() !=10);
	userlottery_t* p2=head2->next;
	userlink_t* temp=findname(head1,name);
	if(temp==head1)
	{
		printf("\033[15C不存在的账号\n");
		goback();
		return;
	}
	int i=0;  //购买次数
	int j=0;
	if(p2 ==head2)
	{
		printf("至今无人购买彩票\n");
		goback();
		return;
	}
	while(p2!=head2)
	{
		if(strcmp(p2->data.name,name)==0)
		{
			i++;
			printf("购票人姓名:%s\n",p2->data.name);
			printf("购买期号为:%4d\n",p2->data.datetime);
			printf("彩票标注id为:%d\n",p2->data.id);
			printf("购买的彩票号码为:");
			for(j=0;j<7;j++)
			{
				printf("%d",p2->data.num[j]);
			}
			printf("彩票一注单价为(元):%g\n",p2->data.price);
			printf("彩票购买的注数(注):%d\n",p2->data.notes);
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
	printf("*******************************************\n");
	printf("该账号共买彩票%d次\n",i);
	printf("*******************************************\n");
	goback();
}

/*
	issuetime:根据期号查看该期信息
*/
void issuetime(issuelink_t* head3)
{
	system("clear");
	int datetime=0;
	int i=0;
	printf("根据期号查找售卖信息\n");
	printf("*********************************************************\n");
	printf("请输入查询期号:");
	scanf("%d",&datetime);
	while(getchar() !=10);
	issuelink_t* p3=head3->next;
	if(p3 ==head3)
	{
		printf("暂时还未发行彩票\n");
		goback();
		return;
	}
	int temp=0; //看有没有这一期
	while(p3 !=head3)
	{
		if(p3->data.datetime == datetime)
		{
			temp++;
		}
		if(p3->data.datetime==datetime && p3->data.flag==1)
		{
			printf("期号为:%d\n",p3->data.datetime);
			printf("该期中奖的彩票号码为:");
			for(i=0;i<7;i++)
			{
				printf("%4d-",p3->data.num[i]);
			}
			printf("\n");
			printf("彩票一注单价为(元):%g\n",p3->data.price);
			printf("彩票卖出的注数(注):%d\n",p3->data.notes);
			printf("开奖号奖池金额为(元):%g\n",p3->data.money);
			printf("查询完成\n");
		}
		else if(p3->data.datetime==datetime && p3->data.flag==0)
		{
			printf("本次还未开奖,中奖号码无法查询\n");
			printf("期号为:%d\n",head3->next->data.datetime);
			printf("彩票一注单价为(元):%g\n",head3->next->data.price);
			printf("彩票卖出的注数(注):%d\n",head3->next->data.notes);
			printf("开奖前奖池金额为(元):%g\n",head3->next->data.money);
			printf("查询完成\n");
			goback();
			return;
		}	
		p3=p3->next;
	}
	if(temp==0)
	{
		printf("还没发行这期\n");
	}
	printf("\033[10C****************************************************\n");
	goback();
}

/*
	findlot:进入查看历史彩票信息界面
*/
void finlot(userlink_t* head1,userlottery_t* head2,issuelink_t* head3)
{
	char ch=0;
	while(1)
	{
		system("clear");
		printf("\033[5B");
		printf("\033[15C你正在查看历史彩票信息\n");
		printf("\033[10C**************************************\n");
		printf("\033[15C输入相应数字进行选择功能\n");
		printf("\033[15C1: 按购买人姓名查找售卖彩票信息\n");
		printf("\033[15C2: 按发行期号查找发行历史彩票信息\n");
		printf("\033[15C3: 查询最新一期彩票信息\n");
		printf("\033[15C0：返回上一级\n");
		printf("\033[10C**************************************\n");
		printf("\033[10C输入你的选择:");
		scanf("%c",&ch);
		while(getchar() !=10);
		switch(ch)
		{
			case '1':
			{
				buyname(head1,head2,head3);
				break;
			}
			case '2':
			{
				issuetime(head3);
				break;
			}
			case '3':
			{
				newissue(head3);
				break;
			}
			case '0':
			{
				return;
			default:
				break;
			}
		}
	}
}
