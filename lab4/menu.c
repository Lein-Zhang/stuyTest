#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
#define CMD_MAX_LEN 128
#define CMD_DESC_LEN 1024
#define CMD_NUM 10

typedef struct DataNode
{
    tLinkTableNode *pNext;
    char *cmd;
    char *desc;
    int (*handler)();
}tDataNode;

tDataNode * findCmd(tLinkTable *head,char *cmd)
{
    tDataNode *pNode =(tDataNode *)GetLinkTableHead(head);
    while(pNode!=NULL)
    {
        if(strcmp(pNode->cmd,cmd)== 0)
        {
         return pNode;
        }
        pNode=(tDataNode *)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return NULL;
}

int help();
int quit();

int showAllCmd(tLinkTable* head)
{
    tDataNode* pNode=(tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
    printf("%s - %s\n",pNode->cmd,pNode->desc);
    pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return 0;
}

int initMenuData(tLinkTable** ppLinkTable)
{
    *ppLinkTable=CreateLinkTable();
    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="help";
    pNode->desc= "Menu List";
    pNode->handler=help;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    pNode=(tLinkTableNode*)malloc(sizeof(tLinkTableNode));
    pNode->cmd="Version";
    pNode->desc="Menu Program V1.0";
    pNode->handler=NULL;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    pNode=(tLinkTableNode*)malloc(sizeof(tLinkTableNode));
    pNode->cmd="quit";
    pNode->desc= "Quit from Menu Program V1.0";
    pNode->handler=quit;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    return 0;
}
tLinkTable *head=NULL;
int main()
{
    initMenuData(&head);
    char cmd[CMD_MAX_LEN];
    while(1)
    {
        printf("Please input a cmd >");
        scanf("%s",&cmd);
        tDataNode *p = findCmd(head,cmd);
        if(p==NULL)
        {
             printf("This is a wrong cmd!\n");
             continue;
        }
        printf("%s - %s\n",p->cmd,p->desc);
        if(p->handler!=NULL)
        {
         p->handler();
        }
    }
    return 0;
}

int help()
{
    showAllCmd(head);
    return 0;
}
int quit()
{
    exit(0);
    return 0;
}









