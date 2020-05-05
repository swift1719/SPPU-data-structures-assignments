#include<bits/stdc++.h>
using namespace std;
#define M 100


class dequeue{
	int a[2*M],front, last;
   public:
   	dequeue(){
   		front=last=-1;
   	}
   	void insert_front(){
   		int n;
         if(front==0)   {cout<<"\n\n  !! Dequeue if Full !! Delete From Front to add at Front !!";return;}
   		cout<<"\n Enter a Number to Insert at the Front - ";cin>>n;
   		if(front==-1)   front=last=100,a[front]=n;
         else            a[--front]=n;
   	}
      void insert_last(){
         int n;
         if(last==2*M-1)  {cout<<"\n\n  !! Dequeue if Full !! Delete From Last to add at Last !!";return;}
         cout<<"\n Enter a Number to Insert at the last - ";cin>>n;
         if(front==-1)   front=last=100,a[last]=n;
         else            a[++last]=n;  
      }
      void delete_front(){
         if(front==-1)  {cout<<"\n\n  !! Dequeue if Empty !! Insert Numbers to Delete !!";return;}
         else if(front==last)   cout<<"\n\n  "<<a[front]<<" Deleted",front=-1,last=-1;
         else  cout<<"\n\n  "<<a[front++]<<" Deleted";
      }
      void delete_last(){
         if(front==-1)  {cout<<"\n\n  !! Dequeue if Empty !! Insert Numbers to Delete !!";return;}
         else if(front==last)   cout<<"\n\n  "<<a[front]<<" Deleted",front=-1,last=-1;
         else  cout<<"\n\n  "<<a[last--]<<" Deleted";
      }
      void display(){
         cout<<"\n Dequeue -> ";
         for(int i=front;i<=last;i++)  cout<<a[i]<<' ';
         if(front==-1)   cout<<" (No Element)";
      }
};

int main(){
	int ch=1;
   dequeue d;
   while(ch){
      cout<<"\t\t\t        MENU:Queue operations\n\t\t\t";
      cout<<"       ------------------------------\n";
      cout<<"\n  Choose an Operation to Perform on Dequeue\n  1. Insert Front\n  2. Insert Last\n  3. Delete Front\n  4. Delete Last\n  0. Exit\n\n  Enter your Choice (0-4) - ";
      cin>>ch;
      switch(ch){
         case  1: d.insert_front(); d.display(); break;
         case  2: d.insert_last(); d.display(); break;
         case  3: d.delete_front(); d.display(); break;
         case  4: d.delete_last(); d.display(); break;
         case  0: cout<<"\n\n\n\t\t\t!! Exiting !!\n\n\n";break;
         default: cout<<"\n\n !! Enter a Valid Choice !!";
      }
   }
	return 0;
}
