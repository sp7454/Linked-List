#include <stdio.h> 
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL;
void insert(int a[],int n){
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    
    first->data=a[0];
    first->next=NULL;
    last=first;
    
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
       last=t;
    }
    
}
void display(struct node *p){
    printf("The Elements are: \n");
    while(p!=NULL){
        if(p->next==NULL) printf("%d->NULL\n",p->data);
       else printf("%d->",p->data);
        p=p->next;
    }
}
void max(struct node *p){
    int m=-65535;
    while(p){
        if(p->data>m) m=p->data;
        p=p->next;
    }
    printf("Max=%d",m);
}
void rdisplay(struct node *p1){
    
    if(p1!=NULL){
      //  printf("%d",p1->data);
        rdisplay(p1->next);
        printf("%d ",p1->data);
    }
    
}
void search(struct node *p,int k){
    int c=1;
    while(p!=NULL){
        if(p->data==k){
            printf("position = %d\n",c);
        }
        p=p->next;
        c++;
    }
    if(p==0){ printf("Element not found\n"); }
   
}
void insertfirst(struct node *p,int x){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=first;
    first=t;
}
void insertmiddle(struct node *p,int pos,int x){
    int i;
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    for(i=0;i<pos-1;i++){
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
}
void insertlast(struct node *p,int x){
     struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    while(p!=0){
        if(p->next==NULL){
            p->next=t;
            t->next=NULL;
        }
        p=p->next;
    }
}
void delfirst(struct node *p){
    first=p->next;
    free(p);
}
void delmiddle(struct node *p,int pos){
   struct node *q;
    for(int i=0;i<pos-1;i++){
        q=p;
        p=p->next;
    }
    q->next=p->next;
    free(p);
    
}
void delend(struct node *p){
     struct node *q=NULL;
    while(p->next!=NULL){
       q=p;
        p=p->next;
    }
    q->next=NULL;
    free(p);
}
int main() {
    int a[100],n,i;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    insert(a,n);
    display(first);
    printf("The Elements in Reverse Order are: \n");
    rdisplay(first);
    printf("\n");
    max(first);
    printf("\n");
    printf("element to be searched:\n");
    int k; scanf("%d",&k);
    search(first,k);
    insertfirst(first,52);
    insertmiddle(first,3,65);
    insertlast(first,89);
    display(first);
    delfirst(first);
    display(first);
   delmiddle(first,3);
   display(first);
   delend(first);
    display(first);
    return 0;
}
