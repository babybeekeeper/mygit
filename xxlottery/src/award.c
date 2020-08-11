#include"award.h"

void autobonus(){	
	srand(time(0));
	int i = 0;
	char ch = 0;
	int data = 0;
	struct termios org_opts;
	struct termios new_opts;
	tcgetattr(STDIN_FILENO,&org_opts);
	new_opts = org_opts;
	new_opts.c_lflag &=~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL); 
	//printf("按回车开始开奖\n");
	printf("__-__-__-__-__-__-__");
	while(1){
		ch = getch();
		if(ch==10){break;}
	}
	printf("\033[18D");
	fflush(stdout);
	tcsetattr(0,TCSANOW,&new_opts);
	for(i=0;i<1000;i++){
		data = rand()%100;
		if(data<10){
			printf("\b");
		}else{
			printf("\b\b");
		}
		printf("%d",data);
		fflush(stdout);
		usleep(1000);
	}
	for(int j=0;j<6;j++)
	{
		printf("-__");
		fflush(stdout);
		for(i=0;i<1000;i++){
			data = rand()%100;
			if(data<10){
				printf("\b");
			}else{
				printf("\b\b");
			}
			printf("%d",data);
			fflush(stdout);
			usleep(1000);
		}
	}
	tcsetattr(STDIN_FILENO,TCSANOW,&org_opts);
	//while(1);
}


