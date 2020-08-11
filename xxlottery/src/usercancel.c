#include"usercancel.h"


void savecancel(usercancel_t* head4)    //保存删除用户记录链表
{
	usercancel_t* p4=head4->prev;
	FILE* fp=fopen("./doc/usercancelDB.txt","w");
	while(p4 !=head4)
	{
		fwrite(&(p4->data),LEN6,1,fp);
		p4=p4->prev;
	}
	fclose(fp);
}

void loadcancel(usercancel_t* head4)     //加载删除用户记录链表
{
	cancel_t data={0};
	int res=0;
	FILE* fp=fopen("./doc/usercancelDB.txt","r");
	if(fp==0)
	{
		return;
	}
	while(1)
	{
		res=fread(&data,LEN6,1,fp);
		if(res==0)
		{
			break;
		}
		usercancel_t* newNode=calloc(1,LEN7);
		newNode->data=data;
		newNode->next=head4->next;
		head4->next->prev=newNode;
		newNode->prev=head4;
		head4->next=newNode;
	}
	fclose(fp);
}

usercancel_t* init4()       //删除用户记录链表节点
{
	usercancel_t* head4=calloc(1,LEN7);
	head4->next=head4;
	head4->prev=head4;
	return head4;
}

void freecancel(usercancel_t* head4)     //释放删除用户记录链表节点
{
	usercancel_t* p4=head4->next;
	usercancel_t* temp=head4;
	while(p4 !=head4)
	{
		temp=p4;
		p4=p4->next;
		free(temp);
	}
	free(head4);
}
