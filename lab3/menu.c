#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
int cmdHelp();
int cmdVersion();
int cmdTime();
int cmdAdd();
int cmdSub();
int cmdMul();
int cmdDiv();
int cmdExit();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM   10

/*menu program*/
static tDataNode head[]=
{
    {"help","display command function",cmdHelp,&head[1]},
    {"version", "display version number",cmdVersion,&head[2]},
    {"time","display system time",cmdTime,&head[3]},
    {"add","two nuber of addition",cmdAdd,&head[4]},
    {"sub","two nuber of subtraction",cmdSub,&head[5]},
    {"mul","two nuber of multiplication",cmdMul,&head[6]},
    {"div","two nuber of division",cmdDiv,&head[7]},
    {"exit","exit system",cmdExit,NULL}
};

int main()
{
/*cmd line begins*/
    while(1)
    {
    char cmd[CMD_MAX_LEN];
    printf("please input a cmd number >");
    scanf("%s",cmd);
    tDataNode *p=FindCmd(head,cmd);
    if(p==NULL)
    {
        printf("This is a wrong cmd!\n");
        continue;
    }
    if(p->handler!=NULL)
    {
        p->handler();
    }
    }

}

int cmdHelp()
{
    showAllCmd(head);
    return 0;
}
int cmdVersion()
{
    printf("menu Version v2.0!\n");
    return 0;
}
int cmdTime()
{
    printf("This is time cmd!\n");
    return 0;
}
int cmdAdd()
{
    printf("This is add cmd!\n");
    return 0;
}
int cmdSub()
{
    printf("This is sub cmd!\n");
    return 0;
}
int cmdMul()
{
    printf("This is Mul cmd!\n");
    return 0;
}
int cmdDiv()
{
    printf("This is div cmd!\n");
    return 0;
}
int cmdExit()
{
    printf("This is exit cmd!\n");
    exit(0);
    return 0;
}





































