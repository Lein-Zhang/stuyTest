
typedef struct DataNode
{
    char*    cmd;
    char*    desc;
    int      (*handler)();
    struct   DataNode *next;
}tDataNode;

/*find a cmd in the linklist and return the datanode point*/
tDataNode* FindCmd(tDataNode* head,char* cmd);
/*show all cmd in linklist*/
int showAllCmd(tDataNode* head);
