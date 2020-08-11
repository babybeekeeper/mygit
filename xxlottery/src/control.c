#include"control.h"
/*
	功能输入数据信息，终端的缓存显示关闭，返回输入的数据
*/
char getch()
{  
		char c=0; 
		struct termios org_opts;//形容终端的结构体，这个结构体中能够完善的描述终端所有属性
		struct termios new_opts;
		int res=0;  
		res=tcgetattr(STDIN_FILENO, &org_opts);
		//获取终端所有数据信息后，存入org_opts中
		assert(res==0);
		memcpy(&new_opts, &org_opts, sizeof(org_opts));
		//将org_opts中所有内容拷贝给new_opts
		new_opts.c_lflag &=~(ICANON | ECHO | ECHOE | ECHOK | ECHONL |ECHOPRT  | ECHOKE | ICRNL); 
		//将new_opts中关于终端的缓存以及显示全都关闭
		tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
		//使用更改后的new_opts去设置标注输入流
		c=getchar();  
		res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
		//使用原来的终端信息恢复当前终端
		assert(res==0);  
		return c;  
}


/*
	function:验证码
	return:正确返回1，否则返回0
*/
int identifyCode(void)
{
	char array[100]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	char a[5]="";
	char b[5]="";
	while(1)
	{
		//得到验证码
		srand(time(NULL));
		a[0] = array[rand()%26];
		a[1] = array[rand()%26+26];
		a[2] = array[rand()%10+52];
		a[3] = array[rand()%10+52];
		a[4] = '\0';
		printf("验证码:");
		printf("\033[4;31;47m%s\033[0m\n",a);
		printf("请输入验证码（Esc强制退回）：");
		scanf("%5s",b);
		while('\n'!=getchar());

		if(strcmp(a,b) != 0)
		{
			printf("\033[10C验证码错误，请重新输入！\n");
			if(b[0]==27)
			{
				return 0;
			}
		}
		else
		{
			return 1;
		}
	}
	return 1;
}

/*
	findname:查重姓名
*/
userlink_t* findname(userlink_t* head1,char* name)
{
	userlink_t* p=head1->next;
	while(p !=head1)
	{
		if(strcmp(p->data.name,name)==0)
		{
			return p;
		}
		p=p->next;
	}
	return head1;
}

/*
	getstr:输入密码置*
*/
char* getstr(char* str)
{
	char ch = 0;
	int i = 0;
	while(1){
		ch = getch();
		if(ch=='\n'){
			str[i] = 0;
			printf("\n");
			break;
		}else if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
			printf("*");
			fflush(stdout);
			str[i] = ch;
			i++;
		}else if(ch == 127 && i>0){
			printf("\b \b");
			i--;
		}
	}
	return str;
}

/*
	regist:注册账号
*/
int regist(userlink_t* head1)
{
	system("clear");
	printf("\033[3B");
	printf("你正在注册账号\n");
	printf("\033[2B");
	printf("*******************************************\n");
	userlink_t* p=head1;
	char ch=0;
	char name[12]={0};
	char passwd1[20]={0};
	char passwd2[20]={0};
	char passwd3[20]={0};
	char passwd4[20]={0};
	printf("输入q退出\n");
	printf("输入其他继续:");
	scanf("%c",&ch);
	while(getchar()!=10);
	if(ch=='q')
	{
		printf("退出\n");
		printf("*******************************************\n");
		sleep(2);
		return 0;
	}
	printf("请输入注册的账号（限于12位):");
	scanf("%s",name);
	while(getchar()!=10);
	int i=strlen(name);
	if(i>12)
	{
		printf("账号超过限制\n");
		printf("请重新输入\n");
		printf("*******************************************\n");
		return 0;
	}
	if(strcmp(name,"admin")==0 || strcmp(name,"notary")==0)
	{
		printf("非法注册");
		printf("*******************************************\n");
		return 0;
	}
	userlink_t* temp=findname(head1,name);
	if(temp != head1)
	{
		printf("此账号已存在，请重新输入\n");
		printf("*******************************************\n");
		return 0;
	}
	printf("请输入密码:");
	getstr(passwd3);
	strcpy(passwd1,passwd3);
	printf("请确认密码:");
	getstr(passwd4);
	strcpy(passwd2,passwd4);
	if(strcmp(passwd1,passwd2) != 0)
	{
		printf("密码不一致，请重新输入\n");
		printf("*******************************************\n");
		return 0;
	}
	while(p->next != head1)
	{
		p=p->next;
	}
	userlink_t* newNode=calloc(1,LEN);
	strcpy(newNode->data.name,name);
	strcpy(newNode->data.passwd,passwd1);
	p->next=newNode;
	head1->prev=newNode;
	newNode->prev=p;
	newNode->next=head1;
	newNode->data.id=newNode->prev->data.id+1;
	printf("注册成功\n");
	printf("*******************************************\n");
	goback();
	return 1;
}

/*
	login:登录
*/
int login(userlink_t* head1,userlottery_t* head2,issuelink_t* head3,usercancel_t* head4)
{
	char name[20]={0};
	char passwd[20]={0};
	char passwd1[20]={0};
	while(1)
	{
		printf("\033[3B");
		printf("请输入你的账号:");
		scanf("%s",name);
		while(getchar()!=10);
		int i=strlen(name);
		if(i>6)
		{
			printf("账号超过六位数\n");
			sleep(2);
			return 0;
		}
		printf("请输入密码:");
		strcpy(passwd,getstr(passwd1));
		int temp=identifyCode();
		if(temp!=1)
		{
			return 0;
		}
		if(strcmp(name,"admin")==0 )
		{
			if(strcmp(passwd,"12345")==0)
			{
				printf("管理员登录成功\n");
				return 1;
			}
			else
			{
				printf("密码错误\n");
				return 0;
			}
		}
		if(strcmp(name,"worker")==0 )
		{
			if(strcmp(passwd,"12345")==0)
			{
				printf("公证人员登录成功\n");
				return 2;
			}
			else
			{
				printf("密码错误");
				return 0;
			}
		}
		userlink_t* p=head1->next;
		p=findname(head1,name);
		if(p==head1)
		{
			printf("该账户不存在");
			sleep(2);
			return 0;
		}
		if(strcmp((p->data.passwd),passwd)==0)
		{
			printf("用户登陆成功\n");
			sleep(1);
			userlot(head1,p,head2,head3,head4);
			return 3;
		}
		else
		{
			printf("密码错误\n");
			sleep(2);
			return 0;
		}
	}
}


//退出函数
void goback()
{
	char c=0;
	while(c !='q')
	{
		printf("输入q退出:");
		scanf("%c",&c);
		while(getchar() !=10);
	}	
}


