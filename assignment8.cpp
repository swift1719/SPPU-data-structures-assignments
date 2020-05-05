#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct node
{
    char flag;
    node *next;
    node *prev;
};

struct hnode
{
    node *next;
    int cnt;
};

class cinema
{
    hnode *head[11];
    node *temp,*t1,*p;
    int n,i,j;
   public:
    cinema()
    {
     for(i=1;i<=10;i++)
     {
      head[i]=new hnode;
          head[i]->next= NULL;
      head[i]->cnt=0;
     }
     temp=t1=p=NULL;
     n=i=j=0;
    }

    void create();
    void show();
    int book(int);
    int cancel(int);
};



int cinema::book(int r)
{

  temp=head[r]->next;
  int m;
  m=head[r]->cnt;
  if(m==7)
  {
   cout<<"\nNo seat available in this row..";
   return 0;
  }
  else
  {
   int seat,cnt=0,sn;
       label9:
    cout<<"\nEnter the seat no.: ";
    cin>>sn;
    if(sn>7 || sn<1)
    {
        cout<<"INVALID SELECTION!!!\nCHOOSE AGAIN";
        goto label9;
    }
    seat=sn-1;
   while(temp->next!=head[r]->next)
   {
    if(cnt!=seat)
    {
     cnt++;
     temp=temp->next;
    }
    else
    {
     if(temp->flag=='_')
     {
      temp->flag='*';
      head[r]->cnt=head[r]->cnt+1;
        break;
     }
    }
   }
 }
 if((temp->next==head[r]->next))
 {
  if(temp->flag=='_')
  {
   temp->flag='*';
   head[r]->cnt=head[r]->cnt+1;
  }
 }
 return 1;
}

int cinema::cancel(int r)
{
  temp=head[r]->next;
  int m;
  m=head[r]->cnt;
  if(m==0)
  {
   cout<<"\nNO such seat available in this row for cancel..";
   return 0;
  }
  else
  {
   int seat,cnt=0,sn;
       la:
       label3:
    cout<<"\nEnter the seat no.: ";
    cin>>sn;
    if(sn>7 || sn<1)
    {
        cout<<"INVALID SELECTION!!!\nCHOOSE AGAIN";
        goto label3;
    }
    seat=sn-1;
   while(temp->next!=head[r]->next)
   {
    if(cnt!=seat)
    {
     cnt++;
     temp=temp->next;
    }
    else
    {
     if(temp->flag=='*')
     {
      temp->flag='_';
      head[r]->cnt=head[r]->cnt-1;
        break;
     }
     else
     {
         cout<<"INVALID SELECTION!!!\nCHOOSE AGAIN";
        goto la;
     }
    }
   }
 }
 if((temp->next==head[r]->next))
 {
  if(temp->flag=='*')
  {
   temp->flag='_';
   head[r]->cnt=head[r]->cnt-1;
  }
 }
 return 1;
}


void cinema::create()
{
    node *f1;
    for(i=1;i<=10;i++)
    {
        p = new node;
        p->flag='_';
        p->next=NULL;
        p->prev=NULL;
        if(head[i]->next==NULL)
        {
         head[i]->next= p;
         p->prev=p;
         p->next=p;
        }


            temp=head[i]->next;
            f1=temp;
            for(j=1;j<=6;j++)
            {
                t1=new node;
                t1->flag='_';

                t1->next=f1;
                temp->next=t1;
                t1->prev=temp;
                f1->prev=t1;
                temp=t1;
            }

     }

}


void cinema::show()
{
    cout<<"\nSEAT availability\n";

    for(i=1;i<=10;i++)
    {
        temp=head[i]->next;
		cout<<" ";
        while(temp->next!=head[i]->next)
        {
         cout<<" "<<temp->flag<<" ";
         temp=temp->next;
        }
        if(temp->next==head[i]->next)
        {
         cout<<" "<<temp->flag<<" ";
        }
        cout<<"\n\n";
    }
}

int main()
{
    cinema c;
    int row,n,am,ch;
    c.create();
cout<<"\t!!!WELCOME TO CINEMA!!!"<<endl;
for(;;)
{
    cout<<"PRESS:\n1.to BOOK\n2.to show availability\n3.to CANCEL\n4.to EXIT"<<endl;
    cin>>ch;
    switch(ch)
    {
     case 1:
        c.show();
        lab1:
        cout<<"SELECT row to book seat:";
            cin>>row;
        if(row<1 || row>10)
        {
            cout<<"\nINVALID SELECTION!!\nCHOOSE AGAIN..";
            goto lab1;
        }
        am=c.book(row);
        if(am!=0)
        {
         c.show();
         cout<<"\nBOOKED!!!\n";
        }
        else
        {
         cout<<"\nTry BOOKING in other row\n";
        }
                break;
         case 2:
        c.show();
                break;
         case 3:
        c.show();
        lab:
        cout<<"\nEnter the row number to cancel ticket: ";
        cin>>row;
        if(row<1 || row>10)
        {
            cout<<"\nINVALID SELECTION!!\nCHOOSE AGAIN..";
            goto lab;
        }
        am=c.cancel(row);
        if(am!=0)
        {
         c.show();
         cout<<"\nCANCELLED\n";
        }
        else
        {
         cout<<"\ENTER CORRECT SEAT TO CANCEL BOOKING\n";
        }
                break;
         case 4:
            exit(0);
    }
}
    return 0;
}
