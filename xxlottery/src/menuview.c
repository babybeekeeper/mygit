#include"menuview.h"
/*
	userlot:进入用户界面
*/
void userlot(userlink_t* head1,userlink_t* p,userlottery_t* head2,issuelink_t* head3,usercancel_t* head4)
{
	char ch;
	int temp=0;
	while(1)
	{
		system("clear");
		printf("\t*************** 欢迎来到用户界面 ************\n");
		printf("\t              1: 查看个人信息                 \n");
		printf("\t              2: 修改账号密码                 \n");
		printf("\t              3: 注销个人账号                 \n");
		printf("\t              4: 充值             	    \n");
		printf("\t              5: 买票                      \n");
		printf("\t              6: 查询中奖记录      	    \n");
		printf("\t              7: 查询购票记录                 \n");
		printf("\t              8：小游戏\n");
		printf("\t              0：返回上一级             \n");
		printf("\t*******************************************\n");
		printf("\t请选择:");
		scanf("%c",&ch);
		while(getchar() != 10);
		switch(ch)
		{
			case '1':
			{
				printown(head1,p);   //查看个人信息
				break;
			}
			case '2':
			{
				int i=1;
				while(temp == 0 || i!=4)
				{	
					char st=0;
					system("clear");
					printf("\033[5B");				
					printf("输入q加回车退出,输入其他继续:");
					scanf("%c",&st);
					while(getchar()!= 10);
					if(st=='q')
					{
						break;
					}
					temp=updateown(head1,p); 
					saveuser(head1);   
					if(temp==0)
					{
						i++;
						printf("\033[10C输入剩余次数为：%d次\n",4-i);
						//sleep(2);
					}
					else if(temp==-1)
					{
						return;
					}
					temp=0;
				}
				break;
				
			}
			case '3':
			{
				removeown(head1,p,head2,head4);   
				saveuser(head1);            
				savelottery(head2);			
				savecancel(head4);           
				return;
			}
			case '4':
			{
				Rechargesystem(p);   
				saveuser(head1); 
				break;
			}
			case '5':
			{
				Bets(p,head2,head3);   
				saveuser(head1);  
				saveissue(head3);  
				savelottery(head2);  
				break;	
			}
			case '6':
			{
				wetheraward(p,head2,head3);   
				break;
			}
			case '7':
			{
				findbuy(p,head2,head3);        
				break;
			}
			case '8':
			{
				gaming();
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
	issue:进入管理系统，选择相应的功能
*/
void issue(userlink_t* head1,userlottery_t* head2,issuelink_t* head3,usercancel_t* head4)
{
	char ch;
	int temp=0;
	while(1)
	{
		system("clear");
		printf("\033[5B");
		printf("\033[10C***********欢迎来到管理员界面**************\n");
		printf("\033[15C1: 发行彩票\n");
		printf("\033[15C2: 查询彩民信息\n");
		printf("\033[15C3: 排序选择\n");
		printf("\033[15C0: 返回上一级\n");
		printf("\033[10C*****************************************\n");
		printf("\033[10C系统提示，请选择:");
		scanf("%c",&ch);
		while(getchar() != 10);
		switch(ch)
		{
			case '1':
			{
				temp=whetherflag(head3);
				if(temp==1)
				{
					issuelot(head3);
				}
				saveissue(head3);
				temp=0;
				break;
			}
			case '2':
			{
				findlotp(head1,head2,head3,head4);
				break;
			}
			case '3':
			{
				sort(head1,head2);
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
natory:进入公证员界面
*/
void notary(userlink_t* head1,userlottery_t* head2,issuelink_t* head3)
{
	while(1)
	{
		char ch;
		system("clear");
		printf("\033[5B");
		printf("\033[20C欢迎来到公证人员界面\n");
		printf("\033[10C***************************************\n");
		printf("\033[15C1: 彩票开奖\n");
		printf("\033[15C2: 查询此期彩票中奖人员信息\n");
		printf("\033[15C3: 查看此期彩票中奖金额发奖\n");
		printf("\033[15C4: 查询已发行的彩票信息\n");
		printf("\033[15C0: 返回上一级\n");
		printf("\033[10C***************************************\n");
		printf("\033[10C系统提示，请选择:");
		scanf("%c",&ch);
		while(getchar() !=10);
		switch(ch)
		{
			case '1':
			{
				openflag(head1,head2,head3);
				savelottery(head2);
				saveissue(head3);
				break;
			}
			case '2':
			{
				findwho(head1,head2,head3);
				break;
			}
			case '3':
			{
				award(head1,head2,head3); //发奖，分配奖金
				saveuser(head1);
				savelottery(head2);
				saveissue(head3);
				break;
			}
			case '4':
			{
				finlot(head1,head2,head3);
				break;
			}
			case '0':
			{
				return;
			}
		
		}
		
	}
};
