#include<bits/stdc++.h>
using namespace std;

class node
{ public:
    string s;
    node *next;
};
class Queue:public node
{ public:
    node*front,*rear;
    Queue()
    {
        front=NULL;
        rear=NULL;
    }
    void enqueue();
    void dequeue();
    void display();
};
void Queue::enqueue()
{   node *temp;
    string d;
    temp=new node;
    if(temp == NULL)
    {
        cout<<"\nOVERFLOW";
        return;
    }
    else
    {
    cout<<"Enter the job:";
    cin>>d;
    temp->s =d;
    temp->next=NULL;
    if(front==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
    }
}
void Queue::dequeue()
{
    node *temp;
    if(front==NULL)
    {
        cout<<"\nNo job to delete";
        return;
    }
    else
    {
        temp=front;
        front=front->next;
        delete temp;
        cout<<"\nDELETED\n";
    }
}
void Queue::display()
{
    node *temp;
    if(front==NULL)
    {
        cout<<"\nEmpty";
        return;
    }
    temp=front;
    cout<<"\nQUEUE IS:";
    while(temp!=NULL)
    {
        cout<<temp->s<<" ";
        temp=temp->next;
    }
}
int main()
{
    Queue q1;
    int ch;
    char c;
    for(;;)
    {
     cout<<"\nPRESS :"<<endl;
     cout<<"1.to add a job\n2.to delete a job\n3.to display the queue\n4.to exit\n";
     cin>>ch;
     switch(ch)
     {
      case 1:
      q1.enqueue();
       break;
      case 2:
      q1.dequeue();
      break;
      case 3:
      q1.display();
      break;
      case 4:exit(0);
      break;
      default:cout<<"wrong choice:";
     }
    }
    return 0;
}
