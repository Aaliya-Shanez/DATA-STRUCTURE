#include<stdio.h>
#include<stdlib.h>
#define size 10
int q [size];
int rear=0,front=0;
void insertq(int item)
{
int r1=rear;
r1=(r1+1)%size;
if(r1==front)
printf("queue is full");
else
{
rear=r1;
q[rear]=item;
}
}
int deleteq(int *status)
{
if(front==rear){
printf("queue is empty");
*status=0;
}
else
{
front=(front+1)%size;
*status=1;
return q[front];
}
}
int searchq(int item)
{
int t;
t=front;
t=(t+1)%size;
while(t!=rear&&q[t]!=item)
t=(t+1)%size;
if(q[t]==item)
return t+1;
else
return 0;
}
void main()
{
int item,opt,ans,status;
do{
printf("\n 1.insert\n");
printf("\n 2.delete \n");
printf("\n 3.search \n");
printf("\n 4.exit \n");
printf("\n option :");

scanf("%d",&opt);
switch(opt)
{
case 1: printf("data:");
scanf("%d",&item);
insertq(item);
printf("inserted %d",item);
break;
case 2:item=deleteq(&status);
if (status==1)
printf("deleted %d",item);
break;
case 3:printf("no to search:");
scanf("%d",&item);
ans=searchq(item);
if(ans==0)
printf("not found");
else
printf("found at %d position",ans);
break;
case 4:exit(0);
}
}
while(1);
}
