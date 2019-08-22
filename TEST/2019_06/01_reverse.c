#include <stdio.h>

typedef struct AckList_t {
    int a;
    struct ActList *next;
}ActList;

int main(int argc, char *argv[])
{
    
    return 0;
}

ActList* ReverseList2(ActList* head)
{
    //ActList* temp=new ActList;
    if(NULL==head|| NULL==head->next) return head;    //少于两个节点没有反转的必要。
    ActList* p;
    ActList* q;
    ActList* r;
    p = head;
    q = head->next;
    head->next = NULL; //旧的头指针是新的尾指针，next需要指向NULL
    while(q){
        r = q->next; //先保留下一个step要处理的指针
        q->next = p; //然后p q交替工作进行反向
        p = q;
        q = r;
    }
    head=p; // 最后q必然指向NULL，所以返回了p作为新的头指针
    return head;
}

ActList *reverse(ActList * head)
{
    Actlist *cur = NULL;
    ActList *prev = NULL;
    ActList *n = NULL;
    if (NULL == head || NULL == head->next)
    {
        return head;
    }

    prev = head;
    cur = head->next;
    head->next = NULL;

    while(cur)
    {
        n = cur->next;
        cur->ntxt = prev;
        prev = cur;
        cur = n;
    }
    head = prev;

    return head;
}
