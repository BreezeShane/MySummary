#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    int num;
    struct Link *p;
} Node;
Node *CreateLink();
void PrintLink(Node*);
void SearchNum (Node *,int);
int SearchIndex(Node *,int);
int Insert(Node *,int,int);
void DeleteIndex(Node *,int);


int main(){
    Node *head = CreateLink();
    PrintLink(head);
    int x = 0;
    printf("输入想查询的数值：\n");
    scanf("%d",&x);
    SearchNum(head,x);
    printf("输入想查询的序号：\n");
    scanf("%d",&x);
    SearchIndex(head,x);
    int index;
    printf("输入想插入的结点和数值：\n");
    scanf("%d%d",&index,&x);
    Insert(head,index,x);
    PrintLink(head);
    printf("输入想删除的结点：\n");
    scanf("%d",&index);
    DeleteIndex(head,index);
    PrintLink(head);
    return 0;
}


void PrintLink(Node *head){
    Node *cp = head->p;
    while (cp->p != NULL){
        printf("%-3d",cp->num);
        cp = cp->p;
    }
    putchar('\n');
}
Node *CreateLink(){
    int a[] = {21, 3, 15, 27, 11, 18};
    Node *head = NULL;
    if ((head = (Node *)malloc(sizeof(Node))) == NULL){
        printf("Memory alloc failed!\n");
        return NULL;
    }
    Node *cp = NULL;
    if ((cp = (Node *)malloc(sizeof(Node))) == NULL){
        printf("Memory alloc failed!\n");
        return NULL;
    }
    head->p = cp;
    head->num = 0;
    for (int i = 0; i < 6; ++i) {
        cp->num = a[i];
        if ((cp->p = (Node *)malloc(sizeof(Node))) == NULL){
            printf("Memory alloc failed!\n");
            return NULL;
        }
        cp = cp->p;
        head->num++;
    }
    cp->p = NULL;
    return head;
}
void SearchNum (Node *head,int x){
    Node *tp = head->p;
    int i = 1;
    while (tp->num != x && tp->p != NULL){
        tp = tp->p;
        i++;
    }
    if (tp->num == x){
        printf("Its index is %d\n",i);
    } else{
        printf("404 !\n");
    }
}
int SearchIndex(Node *head,int index){
    if (index > head->num){
        printf("404 !\n");
        return 0;
    }
    Node *tp = head->p;
    int i = 1;
    while (i < index && tp->p != NULL){
        tp = tp->p;
        i++;
    }
    printf("Index %d Num is %d\n",index,tp->num);
    return 1;
}
int Insert(Node *head,int index,int x){
    if (index > head->num){
        printf("Failed to insert! \n"
               "Because the link has only %d nodes!\n",head->num);
        return 0;
    }
    Node *cp = head;
    for (int i = 0; i < index; ++i) {
        cp = cp->p;
    }
    Node *tp1 = cp,* tp2 = NULL;
    cp = cp->p;
    if ((tp2 = (Node *)malloc(sizeof(Node))) == NULL){
        printf("Memory alloc failed!");
        return EOF;
    }
    tp2->num = x;
    tp2->p = cp;
    tp1->p = tp2;
    head->num++;
    return 0;
}
void DeleteIndex(Node *head,int index){
    if (index > head->num){
        printf("404 !\n");
        return;
    }
    Node *deltp = head->p,*pretp = head;
    int i = 1;
    while (i < index && deltp->p != NULL){
        pretp = pretp->p;
        deltp = deltp->p;
        i++;
    }
    pretp->p = deltp->p;
    free(deltp);
    head->num--;
}