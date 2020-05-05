#include<iostream>
#include<stdlib.h>
using namespace std;
void scanArray(int x[],int s)
{
    int i;
    for(i=0;i<s;i++)
    {
        cin>>x[i];
    }
}
int bunion(int x[],int k,int z[],int l,int m)
{
    int i,h,j,flag,v=0;
    int u[m];
    for(i=0;i<k;i++)
    {
        u[i]=x[i];
        v++;
    }
    for(j=0;j<l;j++)
    {
        flag=0;
        for(h=0;h<k;h++)
        {
            if(z[j]==u[h])
            {
                flag=1;
            }
        }
        if(flag==0)
        {
             u[v]=z[j];
             v++;
        }
    }
    for(i=0;i<v;i++)
    {
        cout<<u[i]<<" ";
    }
    return v;
}
void onlyone(int x[],int k,int z[],int l)
{
    int i,j,flag,v=0;
    for(i=0;i<k;i++)
    {
        flag=0;
        for(j=0;j<l;j++)
        {
            if(x[i]==z[j])
            {
                flag=1;
                v++;
            }
        }
        if(v==k)
        {
            cout<<"zero\n";
        }
        else if(flag==0)
        {
            cout<<x[i]<<" ";
        }

    }
}
int main()
{
    int n,choice,cr,one,two,three,four,bd;
    cout<<"ENTER total no. of students: \n";
    cin>>n;
    cout<<"ENTER no. of students playing cricket: \n";
    cin>>cr;
    cout<<"ENTER no. of students playing basketball: \n";
    cin>>bd;
    int a[cr],b[bd];
    cout<<"ENTER roll no. of students playing cricket: ";
    scanArray(a,cr);
    cout<<"\nENTER the roll no. of students playing badminton: ";
    scanArray(b,bd);
    for(;;)
    {

    cout<<"\n****************MENU***************";
    cout<<"\n1. student playing cricket and badminton both";
    cout<<"\n2. student playing only cricket";
    cout<<"\n3. students playing only basketball";
    cout<<"\n4. no. of students who neither play cricket nor badminton ";
    cout<<"\n5.EXIT \n";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"\nONE selected\n";
        one=bunion(a,cr,b,bd,n);
         break;
    case 2:
        cout<<"\nTWO selected\n";
        onlyone(a,cr,b,bd);
        break;
    case 3:
        cout<<"\nTHREE selected\n";
        onlyone(b,bd,a,cr);
        break;
    case 4:
        cout<<"\nFOUR selected\n";
        four=one;
        cout<<n-four<<" students\n";
        break;
    case 5:
        exit(0);
    }
    }
return 0;
}
