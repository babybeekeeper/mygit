#include"admin.h"


/*
	issuelot:发行彩票
*/
void issuelot(issuelink_t* head3)
{
	system("clear");
	printf("\033[5B");
	printf("*****************************************\n");
	printf("正准备发行彩票\n");
	char ch=0;
	float price=0; 
	printf("开始发行(Y/y):");
	scanf("%c",&ch);
	while(getchar()!=10);
	if(ch!='Y' && ch!='y')
	{
		return;
	}
	printf("彩票单价:");
	scanf("%f",&price);
	while(getchar() !=10);
	printf("确认发行(Y/y):");
	scanf("%c",&ch);
	while(getchar()!=10);
	if(ch=='y' || ch=='Y')
	{
		issuelink_t* p3=calloc(1,LEN5);
		p3->next=head3->next;
		head3->next->prev=p3;
		p3->prev=head3;
		head3->next=p3;
		p3->data.datetime=p3->next->data.datetime+1;
		p3->data.price=price;
		printf("奖池金额为:%g\n",p3->data.money=p3->next->data.money); //发行时奖池的初始金额
		printf("彩票期号为:%d\n",p3->data.datetime); 
		p3->data.flag=0;  //未开奖
		p3->data.state=1; //已发行
		p3->data.temp=0; //未发奖金
		printf("发行成功，等待用户购买和公证人员开奖\n");
		printf("*****************************************\n");
		while(ch !='q')
		{
			printf("输入q退出:");
			scanf("%c",&ch);
			while(getchar() !=10);
		}
		printf("退出\n");
	}
	else
	{
		printf("退出\n");
		return;
	}
}
/*
	whetherflag:判断能否发行下一期彩票
*/
int whetherflag(issuelink_t* head3)
{
	system("clear");
	printf("\033[5B");
	if(head3->next==head3)
	{
		printf("该彩票还未发行过，可以进行第一次发行\n");
		sleep(2);
		return 1;
	}
	else if(head3->next->data.flag==0)
	{
		printf("上期彩票还未开奖，暂时不能发行\n");
		goback();
		return 0;
	}
	else if(head3->next->data.flag==1 )
	{
		printf("上期彩票已开奖\n");
		if(head3->next->data.temp==1)
		{
			printf("上期已发奖且发奖，可以发行\n");
			sleep(2);
			return 1;
		}
		else
		{
			printf("上期还未发奖,不能发行\n");
			sleep(2);
			return 0;
		}
	}
	return 0;
}

/*
	balance:按余额范围查询彩民信息
*/
void balance(userlink_t* head1)
{
	system("clear");
	printf("\033[5B");
	printf("彩民账户余额查询\n");
	printf("************************************************\n");
	float money_max=0;
	float money_min=0;
	int i=0;
	printf("输入你想查询的金额(最大值和最小值):");
	scanf("%f%f",&money_max,&money_min);
	while(getchar() !=10);
	userlink_t* p=head1->next;
	if(p ==head1)
	{
		printf("还未有用户注册\n");
		goback();
	}
	while(p!=head1)
	{
		if(((p->data.ownmoney)-money_min>=0.0 ) && (money_max -(p->data.ownmoney)>=0.0))
		{
			printf("在该区间的彩民账号为:");
			printf("%s\n",p->data.name);
			printf("账户余额为%g\n",p->data.ownmoney);
			i++;
		}
		p=p->next;
	}
	printf("该余额区间彩民人数为%d人\n",i);
	printf("***********************************************\n");
	goback();
}

/*
	issuedatetime:根据输入的期号查找相应的购买彩票信息
*/
void issuedatetime(userlottery_t* head2,issuelink_t* head3)
{
	system("clear");
	printf("\033[5B");
	int datetime=0;
	int i=0;
	int temp=0;
	printf("正在根据发行期号查找彩票历史售卖信息\n");
	printf("*************************************************\n");
	printf("请输入你所想要查找的期号:");
	scanf("%d",&datetime);
	while(getchar() !=10);
	userlottery_t* p2=head2->next;
	if(p2 == head2)
	{
		printf("彩票至今暂时无人购买彩票\n");
		printf("************************************************\n");
		goback();
		return;
	}
	while(p2 !=head2)
	{
		if(p2->data.datetime==datetime)
		{
			temp++;
		}
		if(p2->data.datetime==datetime)
		{
			printf("购买此期彩票用户名为:%s\n",p2->data.name);
			printf("期号为:%d\n",p2->data.datetime);
			printf("彩票标注id为:%d\n",p2->data.id);
			printf("该期中奖的彩票号码为:");
			for(i=0;i<7;i++)
			{
				printf("%d",p2->data.num[i]);
			}
			printf("\n");
			printf("彩票一注单价为(元):%g\n",p2->data.price);
			printf("彩票卖出的注数(注):%d\n",p2->data.notes);
			if(p2->data.state != 0)
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
			else if(p2->data.state == 0 && head3->next->data.flag ==1)
			{
				printf("本次未中奖\n");
			}
			else if(p2->data.state == 0 && head3->next->data.flag ==0)
			{
				printf("本次未开奖\n");
			}
			printf("查询完成\n");
		}	
		p2=p2->next;
	}
	if(temp==0)
	{
		printf("还没发行这期或该期购买账户被注销或没人购买，查看有没发行在历史中查询\n");
	}
	printf("************************************************\n");
	goback();
}

/*
	nameinforma:根据姓名查看彩民的信息
*/
void nameinforma(userlink_t* head1)
{
	system("clear");
	printf("\033[5B");
	printf("你正在查看彩民的个人信息\n");
	printf("****************************************\n");
	char name[20]={0};
	printf("\033[15C输入想查找的姓名:");
	scanf("%s",name);
	while(getchar() !=10);
	userlink_t* p=findname(head1,name);
	if(p ==head1)
	{
		printf("该账号不存在\n");
		printf("****************************************\n");
		goback();
		return;
	}
	else
	{
		printf("该彩民的个人信息为:\n");	
		printf("你的账号为:%s\n",p->data.name);
		printf("你的账号余额为(元):%g\n",p->data.ownmoney);
		printf("****************************************\n");
	}
	goback();
}
/*
	findremove:根据信息查看注销的彩民信息
*/
void findremove(usercancel_t* head4)
{
	system("clear");
	printf("\033[5B");
	printf("正在查看注销的信息\n");
	printf("******************************************\n");
	char name[20]={0};
	usercancel_t* p4=head4->next;
	printf("输入查找的姓名:");
	scanf("%s",name);
	while(getchar() !=10);
	if(p4 ==head4)
	{
		printf("未有注销的账户\n");
		printf("******************************************\n");
		goback();
		return;
	}
	while(p4 !=head4)
	{
		if(strcmp(p4->data.name,name)==0)
		{
			printf("该注销的个人信息为:\n");	
			printf("账号为:%s\n",p4->data.name);
			printf("id为:%d\n",p4->data.id);
		}
		p4=p4->next;
	}
	printf("\033[10C******************************************\n");
	goback();
}
/*
	findlop:根据对应选项选择相应的功能

*/
void findlotp(userlink_t* head1,userlottery_t* head2,issuelink_t* head3,usercancel_t* head4)
{
	char ch=0;
	while(1)
	{
		system("clear");
		printf("\033[5B");
		printf("\033[15C你正在查看彩民信息\n");
		printf("\033[10C***************************************************\n");
		printf("\033[18C输入相应数字进行选择功能\n");
		printf("\033[15C1: 按姓名查找彩民信息\n");
		printf("\033[15C2: 按余额区间查询\n");
		printf("\033[15C3: 查询注销账户信息\n");
		printf("\033[15C0：返回上一级\n");
		printf("\033[10C**************************************************\n");
		printf("\033[10C请选择:");
		scanf("%c",&ch);
		while(getchar() !=10);
		switch(ch)
		{
			case '1':
			{
				nameinforma(head1);
				break;
			}
			case '2':
			{
				balance(head1);  //按余额查询
				break;
			}
			case '3':
			{
				findremove(head4);
				break;
			}
			case '0':
			{
				return;
			}
		}
	}
}
/*
	ｓort,compare双向循环链表的快速排序,排姓名，余额
*/

int compare_money(userlink_t* a,userlink_t* b)
{
	return a->data.ownmoney - b->data.ownmoney;
}

int compare_name(userlink_t* a,userlink_t* b)
{
	return strcmp(a->data.name,b->data.name);
}

void sort1(userlink_t* head1,userlink_t* tail,comp func)
{
	//降序:左边找比key小的，右边找比key大的
	userlink_t* left = head1;
	userlink_t* right = tail;
	if(left==right || right->next == left)
	{
		return;
	}
	userlink_t* l = left;
	userlink_t* r  = right;
	userlink_t* key = left;
	user_t temp = {0};
	while(l!=r)
	{
		while(l!=r)
		{
			//key中的某一个值 - r中的某一个值 < 0
			if(func(key,r)<0)
			{
				break;
			}
			else
			{
				r = r->prev;
			}
		}
		while(l!=r)
		{
			if(func(key,l)>0)
			{
				break;
			}
			else
			{
				l = l->next;
			}
		}
		temp = l->data;
		l->data = r->data;
		r->data = temp;
	}
	temp = l->data;
	l->data = left->data;
	left->data = temp;
	sort1(head1,l->prev,func);
	sort1(l->next,tail,func);
}

/*
		sort:排序选择
*/
void sort(userlink_t* head1,userlottery_t* head2)
{
	char ch=0;
	while(1)
	{
		system("clear");
		printf("\033[5B");
		printf("\033[15C你正在查看排序功能\n");
		printf("\033[10C***************************************\n");
		printf("\033[15C输入相应数字进行选择功能\n");
		printf("\033[15C1: 按姓名排序\n");
		printf("\033[15C2: 按余额排序\n");
		printf("\033[15C0：返回上一级\n");
		printf("\033[10C***************************************\n");
		printf("\033[10C请选择:");
		scanf("%c",&ch);
		while(getchar() !=10);
		switch(ch)
		{
			case '1':
			{
				sort1(head1->next,head1->prev,compare_name);
				userlink_t* p=head1->next;
				if(p ==head1)
				{
					printf("\033[15C无人注册\n");
					goback();
				}
				printf("\033[15C按姓名排序为:");
				while(p !=head1)
				{
					printf("%s  ",p->data.name);
					p=p->next;
				}
				printf("\n");
				printf("\033[10C********************************************\n");
				saveuser(head1);
				goback();
				break;
			}
			case '2':
			{
				sort1(head1->next,head1->prev,compare_money);
				userlink_t* p=head1->next;
				if(p ==head1)
				{
					printf("\033[10C无人注册\n");
					goback();
				}
				printf("\033[10C按余额排序为:");
				while(p !=head1)
				{
					printf("%g  ",p->data.ownmoney);
					p=p->next;
				}
				printf("\n");
				printf("\033[10C********************************************\n");
				saveuser(head1);
				goback();
				break;
			}
			case '0':
			{
				return;
			}
		}
	}

}
/*
	newissue:查看最新一期的彩票信息
*/
void newissue(issuelink_t* head3)
{
	system("clear");
	printf("\033[5B");
	int i=0;
	printf("\033[20C正在最新一期彩票信息\n");
	printf("\033[10C*********************************************************\n");
	if(head3->next ==head3)
	{
		printf("\033[15C暂时还未发行彩票\n");
		printf("\033[10C*********************************************************\n");
		goback();
		return;
	}
	if(head3->next->data.flag==1)
	{
		printf("\033[15C期号为:%d\n",head3->next->data.datetime);
		printf("\033[15C该期中奖的彩票号码为:");
		for(i=0;i<7;i++)
		{
			printf("%4d",head3->next->data.num[i]);
		}
		printf("\n");
		printf("\033[15C彩票一注单价为(元):%g\n",head3->next->data.price);
		printf("\033[15C彩票卖出的注数(注):%d\n",head3->next->data.notes);
		printf("\033[15C开奖发奖后奖池金额为(元):%g\n",head3->next->data.money);
		printf("\033[15C查询完成\n");
	}
	else if(head3->next->data.flag==0)
	{
		printf("\033[15C本次还未开奖,中奖号码无法查询\n");
		printf("\033[15C期号为:%d\n",head3->next->data.datetime);
		printf("\033[15C彩票一注单价为(元):%g\n",head3->next->data.price);
		printf("\033[15C彩票卖出的注数(注):%d\n",head3->next->data.notes);
		printf("\033[15C开奖前奖池金额为(元):%g\n",head3->next->data.money);
		printf("\033[15C查询完成\n");
		
	}	
	printf("\033[10C*********************************************************\n");
	goback();
}
