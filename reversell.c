#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
static int count=0;
struct node
{
    int data;
    struct node *next;
};
struct node *new,*head,*temp,*ptemp,*prev,*supnxt,*current;

struct node *newnode(int x)
{
    struct node *n= (struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    return n;
}

void create(int x)
{
    new=newnode(x);
    if(head==NULL)
    {
        head=temp=new;
    }
    else
    {
        temp->next=new;
        temp=new;
    }
}

void reverse()
{
     prev=NULL;  
    current=supnxt=head;
    
    while(supnxt!=NULL)
    {
        supnxt=current->next;
        current->next=prev;
        prev=current;
        current=supnxt;
     
    
    }
    head=prev;
    
   
}
void display()
{
    temp=head;
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;/* code */
    }
    
}
void main()
{
    int x,y,ch,key;
    do
    {
    
    printf("ENTER 1.TO create\n2.to search \n3.display");
    scanf("%d",&y);
    switch (y)
    {
    case 1:
            printf("ENTER THE DATA ");
            scanf("%d",&x);
            create(x);
        break;
    case 2:
            reverse();
            break;
    case 3:
            display();
            break;
    default:
        break;
    
    }
    printf("PRESS 1 TO REPEAT");
    scanf("%d",&ch);
    }while (ch==1);
}