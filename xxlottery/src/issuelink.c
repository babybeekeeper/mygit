#include"issuelink.h"

void saveissue(issuelink_t* head3)     //保存彩票链表
{
	issuelink_t* p=head3->prev;
	FILE* fp=fopen("./doc/issuelinkDB.txt","w");
	while(p!=head3)
	{
		fwrite(&(p->data),LEN4,1,fp);
		p=p->prev;
	}
	fclose(fp);
}

void loadissue(issuelink_t* head3)			//加载彩票链表
{
	issue_t data={0};
	int res=0;
	FILE* fp=fopen("./doc/issuelinkDB.txt","r");
	if(fp==0)
	{
		return;
	}
	while(1)
	{
		res=fread(&data,LEN4,1,fp);
		if(res==0)
		{
			break;
		}
		issuelink_t* newNode=calloc(1,LEN5);
		newNode->data=data;
		newNode->next=head3->next;
		head3->next->prev=newNode;
		newNode->prev=head3;
		head3->next=newNode;
	}
	fclose(fp);
}

issuelink_t* init3()    //彩票链表节点
{
	issuelink_t* head3=calloc(1,LEN5);
	head3->next=head3;
	head3->prev=head3;
	return head3;
}


void freeissue(issuelink_t* head3)     //释放彩票节点
{
	issuelink_t* p3=head3->next;
	issuelink_t* temp=head3;
	while(p3 !=head3)
	{
		temp=p3;
		p3=p3->next;
		free(temp);
	}
	free(head3);
}
