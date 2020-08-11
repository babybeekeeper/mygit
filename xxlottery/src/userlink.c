#include"userlink.h"
void saveuser(userlink_t* head1)   //保存用户链表
{
	userlink_t* p=head1->next;
	FILE* fp=fopen("./doc/userlinkDB.txt","w");
	while(p !=head1)
	{
		fwrite(&(p->data),LEN1,1,fp);
		p=p->next;
	}
	fclose(fp);
}

void loaduser(userlink_t* head1)      //加载用户链表
{
	userlink_t* p=head1;
	user_t data={0};
	int res=0;
	while(p->next != head1)
	{
		p=p->next;
	}
	FILE* fp=fopen("./doc/userlinkDB.txt","r");
	if(fp==0)
	{
		return;
	}
	while(1)
	{
		res=fread(&data,LEN1,1,fp);
		if(res==0)
		{
			break;
		}
		userlink_t* newNode=calloc(1,LEN);
		newNode->data=data;
		newNode->next=head1;
		p->next=newNode;
		newNode->prev=p;
		head1->prev=newNode;
		p=p->next;
	}
	fclose(fp);
}

userlink_t* init1()    //用户链表节点
{
	userlink_t* head1=calloc(1,LEN);
	head1->next=head1;
	head1->prev=head1;
	return head1;
}

void free_user(userlink_t* head1)    //释放用户链表节点
{
	userlink_t* p1=head1->next;
	userlink_t* temp=head1;
	while(p1 !=head1)
	{
		temp=p1;
		p1=p1->next;
		free(temp);
	}
	free(head1);
}

