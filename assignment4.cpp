#include<iostream>
using namespace std;
#include<stdlib.h>
class matrix
{
	int m,n,i,j,sd,a[100][100];
public:
	void initial();
	void display();
	void search();

};
void matrix::initial()
{
	cout<<"enter no. of rows and columns:";
	cin>>m>>n;
	cout<<"\nEnter matrix elements: ";
	for(i=0;i<m;i++)
	{
			for(j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
	}
}
void matrix::display()
{
	cout<<"\n";
	for(i=0;i<m;i++)
	{
			for(j=0;j<n;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
	}

}
void matrix::search()
{
	int k,l,x,z,min,max;
	sd=0;
	cout<<"\n";
	for(i=0;i<m;i++)
	{	
		min=a[i][0];
		max=-1;
		for(j=0;j<n;j++)
		{
			if(a[i][j]<min)
			{
				min=a[i][j];
			}			
		}
		
		k=0;
		while(k<n)
		{
			if(a[i][k]==min)
			{
				x=i;
				z=k;
				for(l=0;l<m;l++)
				{
					if(a[l][k]>max)
					{
						max=a[l][k];
					}	
				}
				if(max==min)
				{
					sd++;
					cout<<"\nSADDLE point is present at "<<i<<k<<" position and saddle point is ";
					cout<<a[x][z]<<" ";
									
				}
			}
			k++;
		}
	}
if(sd==0)
{
	cout<<"\nMATRIX has no SADDLE point\n";
}

}
int main()
{
	matrix saddle;
	saddle.initial();
	saddle.display();
	saddle.search();
	

return 0;
}
