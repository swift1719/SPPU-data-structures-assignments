#include<bits/stdc++.h>
using namespace std;
class node
{public:
	int priority;
	string job;
    node *next;
};
class Q:public node
{ public:
    node *front,*rear;
    Q()
    {
        front=rear=NULL;
    }
     void enq(string,int);
     void deq();
     void dis();
};
void Q::enq(string item,int priority)
{
	node *temp,*q;
	temp=new node;
	temp->job=item;
	temp->priority=priority;
	if( front==NULL || priority<front->priority )
	{
		temp->next=front;
		front=temp;
	}
	else
	{
		q=front;
		while(q->next!=NULL && q->next->priority<=priority)
			q=q->next;
		temp->next=q->next;
		q->next=temp;
	}
}
void Q::deq()
{
	node *temp;
	if(front==NULL)
		cout<<"Underflow\n";
	else
	{
		temp=front;
	   cout<<"\nDeleted "<<temp->job;
		front=front->next;
		delete temp;
	}
}
void Q::dis()
{
	node *start;
	start = front;
	if(front==NULL)
		cout<<"\nQueue is empty";
	else
	{
		cout<<"Queue is :\n";
		while(start!=NULL)
		{
			cout<<"Priority:"<<start->priority<<"  job:"<<start->job;
			start= start->next;
            cout<<"\n";
		}
	}
}

int main()
{    Q q1;
	int ch,pr;
	string j;
	for(;;)
	{
	    cout<<"\nPRESS:"<<endl;
		cout<<"1.to add\n";
		cout<<"2.to remove\n";
		cout<<"3.to display queue\n";
		cout<<"4.To EXIT\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Job: ";
				cin>>j;
				cout<<"Priority: ";
				cin>>pr;
				q1.enq(j,pr);
				break;
			case 2:
				q1.deq();
				break;
			case 3:
				q1.dis();
				break;
			case 4:exit(0);
			     break;
            default :
				cout<<"Invalid choice\n";
		}
    }

	return 0;
}
