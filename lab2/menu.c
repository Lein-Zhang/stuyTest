#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void cmd_help();
void cmd_info();
void cmd_time();
void cmd_add();
void cmd_sub();
void cmd_mul();
void cmd_div();
void cmd_exit();


int main()
{
	char cmd[64];
	printf("This is a program ,please input a command\n");
	printf("*********COMMAND LIST**************\nhelp	info	time	add\nsub	mul	div	exit\n");
	printf("***********************************\n\n");
	while(1)
	{
		scanf("%s",cmd);
		if(strcmp(cmd,"help")==0)
		{ cmd_help();}
		else if(strcmp(cmd,"info")==0)
		{cmd_info();}
		else if(strcmp(cmd,"time")==0)
		{cmd_time();}
		else if(strcmp(cmd,"add")==0)
		{cmd_add();}
		else if(strcmp(cmd,"sub")==0)
		{cmd_sub();}
		else if(strcmp(cmd,"mul")==0)
		{cmd_mul();}
		else if(strcmp(cmd,"div")==0)
		{cmd_div();}
		else if(strcmp(cmd,"exit")==0)
		{cmd_exit();}
		else
			printf("The command is not in the scale,please input the command again\n\n");
	
	}
}
void cmd_help(void)
{
	printf("------------------------------\n");
	printf("help --> display command function\n");
	printf("info --> display version number\n");
	printf("time --> display system time\n");
	printf("add  --> two nuber of addition\n");
	printf("sub  --> two nuber of subtraction\n");
	printf("mul  --> two nuber of multiplication\n");
	printf("div  --> two nuber of division\n");
	printf("exit --> exit system\n");
	printf("------------------------------\n");
}


void cmd_info(void)
{
	printf("The version number is V1.0\n\n");
}
void cmd_time(void)
{
	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	printf("The current time is :%s\n",asctime(timeinfo));
}
void cmd_add(void)
{
	printf("Please input two number\n");
	float a,b;
	scanf("%f %f",&a,&b);
	printf("%g + %g = %g\n\n",a,b,a+b);
}

void cmd_sub(void)
{
	printf("Please input two number\n");
	float a,b;
	scanf("%f %f",&a,&b);
	printf("%g - %g = %g\n\n",a,b,a-b);
}
void cmd_mul(void)
{
	printf("Please input two number\n");
	float a,b;
	scanf("%f %f",&a,&b);
	printf("%g * %g = %g\n\n",a,b,a*b);
}
void cmd_div(void)
{
	printf("Please input two number\n");
	float a,b;
	scanf("%f %f",&a,&b);
	printf("%g / %g = %g\n\n",a,b,a/b);
}
void cmd_exit(void)
{
	printf("exit system!\n");
	exit(0);	
}

























