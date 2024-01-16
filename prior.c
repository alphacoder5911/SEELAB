#include<stdio.h>
#include<stdlib.h>
#define max 3
int qu1[max];
int qu2[max];
int qu3[max];
int f1=-1,r1=-1;
int f2=-1,r2=-1;
int f3=-1,r3=-1;
int enqueue(int x);
void dequeue();
void display();
int enqueue(int x)
{
    if(f1==-1 && r1==-1)
    {
        f1=r1=0;
        qu1[r1]=x;

    }
    else if((r1+1)%max==f1)
    {
        if(f2==-1 && r2==-1)
        {
            f2=r2=0;
            qu2[r2]=x;
        }
        else if((r2+1)%max==f2)
        {
        if(f3==-1 && r3==-1)
        {
            f3=r3=0;
            qu3[r3]=x;

        }
        else if((r3+1)%max==f3)
        {
            printf("queues are  full");
            
        }
        else
        {
            r3=(r3+1)%max;
            qu3[r3]=x;
        }
        }
        else
        {
            r2=(r2+1)%max;
            qu2[r2]=x;
        }

    }
    else 
    {
        r1=(r1+1)%max;
        qu1[r1]=x;
    }
}
void dequeue()
{
    if(f1==r1)
    {
        printf("deleted element %d",f1);
                f1=-1;
                r1=-1;

    }
    else if(f1==-1 && r1==-1)
    {
        if(f2==r2)
        {
            printf("DEQUEUED ELEMENT %d",f2);
            f2=r2=-1;
        }
        else if(f2==1 && r2==-1)
        {
            if(f3==r3)
            {
                printf("DEQUEUED ELEMENT %d",f3);
                f3=r2=-1;
            }
            else
            {
                printf("dq element %d",f3);
                f3=(f3+1)%max;
            }
        }
    }
}
void display()
{
    int i=f1;
    while(i!=r1)
    {
        printf("%d\n",qu1[i]);
        i=(i+1)%max;
    }
    printf("%d\n",qu1[r1]);
    int j=f2;
    while(j!=r2)
    {
        printf("%d\n",qu2[j]);
        j=(j+1)%max;

    }
  printf("%d\n",qu2[r2]);
    int k=f3;
    while (k!=r3)
    {
        printf("%d\n",qu3[k]);
        k=(k+1)%max;
    }
     printf("%d\n",qu3[r3]);
    
}

main()
{
    int x,y,ch;
    do
    {
    
    printf("ENTER 1.TO ENQUEUE\n2.to display");
    scanf("%d",&y);
    switch (y)
    {
    case 1:
            printf("ENTER THE DATA ");
            scanf("%d",&x);
            enqueue(x);
        break;
    case 2:
            display();
            break;
    default:
        break;
    
    }
    printf("PRESS 1 TO REPEAT");
    scanf("%d",&ch);
    }while (ch==1);
    
    
}