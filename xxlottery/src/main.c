#include"userlink.h"
#include"userlottery.h"
#include"issuelink.h"
#include"usercancel.h"
#include"menuview.h"
#include"user.h"
#include"admin.h"
#include"nottery.h"
#include"control.h"
int main(int argc, char* argv[])
{
	int ch;
	int temp=0,flag=1;
	int i=1;
	userlink_t* head1=init1();
	loaduser(head1);
	userlottery_t* head2=init2();
	loadlottery(head2);
	issuelink_t* head3=init3();
	loadissue(head3);
	usercancel_t* head4=init4();
	loadcancel(head4);
	while(flag==1)
	{
		system("clear");
		printf("\033[31m****************欢迎进入中国福利彩票*****************\033[0m\n");
		printf("\n");   
		printf("\t\t1:\t\t注册\n");          
		printf("\t\t2:\t\t登录\n");            
		printf("\t\t0:\t\t退出\n");
		printf("\n");
		printf("\t\033[8C系统提示，请选择:");
		scanf("%d",&ch);
		while(getchar()!=10);
		switch(ch)
		{
			case 1:
			{
				regist(head1);   //注册
				saveuser(head1);  //保存用户链表
				break;
			}
			case 2:
			{	
				temp=0;
				//i=1;
				if(i<4)
				{	
					while(temp == 0 && i!=4)
					{
						system("clear");
							temp=login(head1,head2,head3,head4);    //登录
							if(temp==0)
							{
								i++;
								printf("输入剩余次数为：%d次\n",4-i);
								sleep(2);
							}
							else if(temp==1)
							{
								issue(head1,head2,head3,head4);  //彩票链表
								break;
							}
							else if(temp==2)
							{
								notary(head1,head2,head3);     //开奖
								break;
							}
							else if(temp==3)
							{
								break;
							}
					}
				}
				else if(i>=4)
				{
					printf("次数超过现在无法登录\n");
					sleep(2);
				}	
				break;
			}
			case 0:
			{
				flag=0;
				break;
			}
			default:
				break;
		}
	}
	free_user(head1);   //释放用户链表节点
	freelottery(head2); //释放个人彩票节点
	freeissue(head3); //释放彩票链表节点
	freecancel(head4);  //释放删除用户记录节点
	return 0;
}

