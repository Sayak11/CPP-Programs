#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prv;
};

void create(struct node **h)
{
    int n,i;
    printf("How many elements you want to enter: ");
    scanf("%d",&n);
    struct node *ptr=NULL;
    for(i=0;i<n;i++)
    {
        struct node *cur=(struct node *)malloc(sizeof(struct node));
        cur->data=rand()%10;
        cur->next=NULL;
        cur->prv=NULL;

        if(*h==NULL)
        {
            *h=cur;
            ptr=cur;
        }
        else 
        {
            cur->prv=ptr;
            ptr->next=cur;
            ptr=cur;
        }
    }

} 

void display(struct node *h)
{
    struct node *ptr;
    printf("Linked list: ");
    for(ptr=h;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d\t",ptr->data);
    }
}

void reverse_display(struct node *h)
{
    struct node *ptr=NULL;
    struct node *cur=NULL;
    printf("Reverse linked list: ");
    for(ptr=h;ptr->next!=NULL;ptr=ptr->next)
    {
    }
    for(cur=ptr;cur!=NULL;cur=cur->prv)
    {
        printf("%d\t",cur->data);
    }
}

void insert(struct node **h,int x,int p)
{   
    struct node *cur;
    struct node *ptr;
    cur=(struct node *)malloc(sizeof(struct node));
    cur->data=x;
    cur->next=NULL;
    cur->prv=NULL;
    if(*h==NULL)
    {
        *h=cur;
    }
    else if(p==0)
    { 
        cur->next=*h;
        (*h)->prv=NULL;
        *h=cur;
    }
    else
    {
         ptr=*h;
       int i=1;
       while(i<p && ptr->next!=NULL)
       {
           ptr=ptr->next;
           i++;
       }
       if(ptr->next==NULL)
       {
           cur->prv=ptr;
           ptr->next=cur;
       }
       else
       {
           cur->prv=ptr;
           cur->next=ptr->next;
           ptr->next->prv=cur;
           ptr->next=cur;
           
       }   
    }
}

void del(struct node **h,int p)
{
    if(*h==NULL)
    {
        printf("EMP");
    }
    else
    {
        struct node *ptr=*h;
        int i=1;
        while(i<p && ptr->next!=NULL)
        {
            ptr=ptr->next;
            i++;
        }
        if(ptr==NULL)
        {
            printf("NO LIST\n");
        }
        else if(ptr==*h &&ptr->next==NULL)
        {
            *h==NULL;
            free(ptr);
        }
        else if(ptr==*h)
        {
            *h=ptr->next;
            ptr->next->prv=NULL;
            free(ptr);
        }
        else if(ptr->next==NULL)
        {
            ptr->prv->next=NULL;
            free(ptr);
        }
        else
        {
            ptr->prv->next=ptr->next;
            ptr->next->prv=ptr->prv;
            free(ptr);
        }
    }
}

int main()
{
    struct node *head=NULL;
    create(&head);
    display(head);
    printf("\n");
    reverse_display(head);
    printf("\n");
    insert(&head,6,4);
    display(head);
    printf("\n");
    del(&head,3);
    display(head);

    return 0;
}