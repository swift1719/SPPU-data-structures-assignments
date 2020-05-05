#include<iostream>
#include<stdlib.h>
using namespace std;
class pclub
{
public:
    class node
    {
    public:
        int prn;
        string name;
        node *next;
    }*head,*temp,*current,*node1;
    pclub()
    {
        head=NULL;
    }
    void append(int num,string nam)
    {
        if(head==NULL)
        {
            head=new node;
            head->prn=num;
            head->name=nam;
            head->next=NULL;
        }
        else
        {
            current=head;
            while(current->next!=NULL)
            {
                current=current->next;
            }
            temp=new node;
            temp->prn=num;
            temp->name=nam;
            temp->next=NULL;
            current->next=temp;
        }
    }
    void addbeg(int num,string nam)
    {
        temp=new node;
        temp->prn=num;
        temp->name=nam;
        temp->next=head;
        head=temp;
    }
    void addend(int num,string nam)
    {
        current=head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        temp=new node;
        temp->prn=num;
        temp->name=nam;
        temp->next=NULL;
        current->next=temp;
    }
    void display()
    {
        cout<<"\nMembers of the club:";
        current=head;
        while(current!=NULL)
        {
            if(current==head)
            {
                cout<<"\n("<<current->prn<<","<<current->name<<")--> PRESIDENT";
                current=current->next;
            }
            else if(current->next==NULL)
            {
                cout<<"\n("<<current->prn<<","<<current->name<<")--> SECRETARY";
                current=current->next;
            }
            else
            {
                cout<<"\n("<<current->prn<<","<<current->name<<")";
                current=current->next;
            }
        }
    }
    void displayreverse(node *p)
    {
        if (p == NULL)
            return;
        displayreverse(p->next);
        if(p==head)
        {
            cout<<"\n("<<p->prn<<","<<p->name<<")--> PRESIDENT";

        }
        else if(p->next==NULL)
        {
            cout<<"\n("<<p->prn<<","<<p->name<<")--> SECRETARY";
        }
        else
        {
            cout<<"\n("<<p->prn<<","<<p->name<<")";
        }
    }
    void del(int num)
    {
        current=head;
        if(current->prn==num)
        {
            head=current->next;
            delete current;
            cout<<"\nDELETED";
            return;
        }
        temp=current;
        while(current!=NULL)
        {
            if(current->prn==num)
            {
                temp->next=current->next;
                delete current;
                cout<<"\nDELETED";
                return;
            }
            temp=current;
            current=current->next;
        }
         cout<<"\nElement "<<num<<" not found"<<endl;
    }
    void count()
    {
        int c=0;
        current=head;
        while(current!=NULL)
        {
            c++;
            current=current->next;
        }
        cout<<"\nThere are "<<c<<" elements in the list."<<endl;
    }
    node* gethead()
    {
        return head;
    }
    void concatenate(node *a,node *b)
    {
            if (a->next == NULL)
                a->next = b;
            else
                concatenate(a->next,b);
    }
    ~pclub()
    {
        current=head;
        if(head=NULL)
        {
            return;
        }
        while(head!=NULL)
        {
            while(current!=NULL)
            {
                current=head->next;
                delete head;
                head=current;
            }
        }
    }
};
int main()
{
    pclub s,s1;
    int i,z;
    int x,ch,select,acc;
    string na;
    cout<<"\n***PINNACLE CLUB***";
    for(;;)
    {
        label:
        cout<<"\nPRESS:\n1.to add a member\n2.to delete a member\n3.to display a member\n4.to display in reverse order\n5.to display total members in club\n6.to concatenate two lists of members\n7.to exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\nPRESS:\n1.to accept request\nELSE press any key to delete:";
                    cin>>acc;
                    if(acc==1)
                    {
                        cout<<"\nPRESS:\n1.to president\n2.to add member\n";
                        cin>>select;
                        switch(select)
                        {
                            case 1:
                                cout<<"\nENTER PRN:";
                                cin>>x;
                                cout<<"ENTER name:";
                                cin>>na;
                                s.addbeg(x,na);
                                break;
                            case 2:
                                cout<<"\nENTER PRN:";
                                cin>>x;
                                cout<<"ENTER name:";
                                cin>>na;
                                s.append(x,na);
                                break;
                            /*case 3:
                                cout<<"\nENTER PRN:";
                                cin>>x;
                                cout<<"ENTER name:";
                                cin>>na;
                                if(s.head==NULL)
                                {
                                    s.append(x,na);
                                    break;
                                }
                                s.addend(x,na);
                                break;*/
                        }
                    }
                    else
                        goto label;
                    break;
            case 2:
                if(s.head==NULL)
                {
                    cout<<"no members in club\n";
                    break;
                }
                cout<<"\ENTER a PRN to delete:";
                cin>>x;
                s.del(x);
                break;
            case 3:
                if(s.head==NULL)
                {
                    cout<<"no members in club\n";
                    break;
                }
                s.display();
                break;
            case 4:
                if(s.head==NULL)
                {
                    cout<<"no members in club\n";
                    break;
                }
                cout<<"\nMEMBER LIST in REVERSE order:";
                s.displayreverse(s.head);
                break;
            case 5:
                if(s.head==NULL)
                {
                    cout<<"no members in club\n";
                    break;
                }
                s.count();
                break;
            case 6:
                cout<<"\nENTER no. of members in second list:";
                    cin>>z;
                    if(z<1)
                    {
                        cout<<"ENTER a valid input\n";
                        break;
                    }
                    for(i=0;i<z;i++)
                    {

                        cout<<"\nENTER PRN:";
                        cin>>x;
                        cout<<"ENTER name:";
                        cin>>na;
                        s1.append(x,na);
                    }
                        s.display();
                break;
            case 7:
                exit(0);
            default:
                cout<<"Wrong choice\n";
        }
    }
    return 0;
}
