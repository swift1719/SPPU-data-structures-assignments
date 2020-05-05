#include<iostream>
#include<stdlib.h>
using namespace std;
class student
{
    int a[100];
    float avg,s=0;
    int n,i;
public:
    void initialize(void);
    void average();
    void maxmin();
	void absent();
	void fre();
};
void student::initialize(void)
{
    cout<<"ENTER total no. of students:";
    cin>>n;
    cout<<"\nenter marks of students:\n NOTE:if a student is absent provide -1 as marks\n";
    for(i=0;i<n;i++)
	{
		cout<<i+1<<":";
		cin>>a[i];
	}
}
void student::average()
{
    for(i=0;i<n;i++)
    {
		if(a[i]!=-1)
	   		s+=a[i];
	}
    avg=(s/n);
    cout<<"\naverage marks of students:"<<avg<<"\n";
}
void student::maxmin()
{
	int max=0,min=100;
	for(i=0;i<n;i++)
	{
		if(a[i]>=max && a[i]!=-1)
			max=a[i];
		if(a[i]<min && a[i]!=-1)
			min=a[i];
	}
cout<<"\nHighest score:"<<max<<"\nLowest score:"<<min<<"\n";
}
void student::absent()
{
	int j,c=0;
	cout<<"\nLIST OF ABSENT STUDENTS:\nroll no.:";
	for(j=0;j<n;j++)
	{
		if(a[j]==-1)
		{
			cout<<j+1<<" ";
			c++;
		}
	}
	if(c==0)
	{
		cout<<"\nNO ABSENTEES\n";
	}
}
void student::fre()
{
	int g[101]={0};
	for(i=0;i<n;i++)
	{
		g[a[i]]++;
	}
	int max=0,d=0;
	for(i=0;i<101;i++)
	{
		if(g[i]>max)
		{
			max=g[i];
			d=i;
		}
	}
cout<<"\nmost frequent marks:"<<d<<"\n";
}

int main()
{
   int ch;
   student marks;
   marks.initialize();

for(;;)
{
	cout<<"\nPRESS:\n1.for average marks of students\n2.for highest and lowest marks\n3.for marks scored by most of the students\n4.for list of students who were absent for the test\n5.to EXIT\n ";
	cin>>ch;
	switch(ch)
	{
		case 1: marks.average();
				break;
		case 2: marks.maxmin();
				break;
		case 3: marks.fre();
				break;
		case 4: marks.absent();
				break;
		case 5: exit(0);

	}
}
    return 0;
}
