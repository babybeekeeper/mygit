#include"game.h"
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
void gaming()
{
	int com=0,user=0;
	char c=0;
	srand((unsigned)time(NULL)); //初始化随机数，如果没有这条语句，每次运行电脑产生的随机数序列都是一样的
	printf("进入游戏\n");
	do{
		printf("请出拳（1.剪刀、2.石头、3.布）:");
		scanf("%d",&user);
		com=rand()%3+1; //产生1-3范围内的随机数
		printf("电脑出%s\n",com==1?"剪刀":com==2?"石头":"布");
		switch(com-user) //用电脑产生的数和用户输入的数的差值来判断胜负
		{
			case 0:
				printf("平手\n");
				break;
			case 1:
			case -2:
				printf("电脑赢了\n");
				break;
			case -1:
			case 2:
				printf("你赢了\n");
		}
		printf("继续游戏按(Y/y)键、其它键退出");
		getchar();
		c=getchar();
	}while(c=='y' || c=='Y');
	printf("已经退出游戏\n");
}
