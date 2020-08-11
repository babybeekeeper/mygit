#include"userlottery.h"

void savelottery(userlottery_t* head2)   //保存个人彩票
{
	userlottery_t* p=head2->prev;
	FILE* fp=fopen("./doc/userlotteryDB.txt","w");
	while(p!=head2)
	{
		fwrite(&(p->data),LEN2,1,fp);
		p=p->prev;
	}
	fclose(fp);
}

void loadlottery(userlottery_t* head2)      //加载个人彩票
{
	lottery_t data={0};
	int res=0;
	FILE* fp=fopen("./doc/userlotteryDB.txt","r");
	if(fp==0)
	{
		return;
	}
	while(1)
	{
		res=fread(&data,LEN2,1,fp);
		if(res==0)
		{
			break;
		}
		userlottery_t* newNode=calloc(1,LEN3);
		newNode->data=data;
		newNode->next=head2->next;
		head2->next->prev=newNode;
		newNode->prev=head2;
		head2->next=newNode;
	}
	fclose(fp);
}

userlottery_t* init2()      //个人彩票链表节点
{
	userlottery_t* head2=calloc(1,LEN3);
	head2->next=head2;
	head2->prev=head2;
	return head2;
}

void freelottery(userlottery_t* head2)    //释放个人彩票节点
{
	userlottery_t* p2=head2->next;
	userlottery_t* temp=head2;
	while(p2 !=head2)
	{
		temp=p2;
		p2=p2->next;
		free(temp);
	}
	free(head2);
}



