#include<stdio.h>
#include<stdlib.h>
static int count=0;
struct node
{
    int data;
    struct node *next;
};
struct node *new,*head,*temp;

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

void search(int key)
{
    if(head==NULL)
    {
        printf("LIST IS EMPTY ");
    }
    else
    {
        int i;
        i=0;
        temp=head;
        while(temp->next!=NULL)
        {
            int dat=temp->data;
            if(dat==key)
            {
                printf("ELEMENT FOUND AT POSITON %d",i);
                return;
            }
           i++;
            temp=temp->next;
        }
        //IF THE ELEMENT WAS NOT FOUND THEN RETURN IN THE LINE 50 WILL NOT BE EXECUTED THEREFORE CREATION A NEW NODE AND ADDIN THE VALUE
        new=newnode(key);
        temp->next=new;
        temp=new;
        printf("new node %d added ",temp->data);
       
    }
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
            printf("ENTER THE KEY ELEMENT TO BE SEARCHED");\
            scanf("%d",&key);
            search(key);
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