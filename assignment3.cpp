#include<iostream>
#include<stdlib.h>
using namespace std;
class matrix
{
    int r,c,i,j;
    int a[100][100];
public:
    void intial();
    void display();
    void uppert();
    void diagonalsum();
    void transpose();
    void add(matrix m);
    void sub(matrix m);
    void mul(matrix m);

};
void matrix::intial()
{
    cout<<"enter size of matrix:";
    cin>>r>>c;
    cout<<"\nEnter matrix elements:";
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
         cin>>a[i][j];
}
void matrix::display()
{

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void matrix::uppert()
{
    int flag=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=0 && i>j)
                flag=1;
        }
    }
    if(flag==0)
        cout<<"\nMatrix is upper triangular ";
    else
        cout<<"\nMatrix is not upper triangular";
}
void matrix::diagonalsum()
{
    int sum=0;
    if(r!=c)
    {
        cout<<"\nDiagonal elements not exists\n";
    }
    else
    {
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(i==j)
                    sum+=a[i][j];
            }
        }
    cout<<"\nSum of diagonal elements:"<<sum<<"\n";
    }
}
void matrix::transpose()
{
    for(j=0;j<c;j++)
    {
        for(i=0;i<r;i++)
        {
                cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void matrix::add(matrix m)
{
    int b[r][c];
    if(r!=m.r || c!=m.c)
    {
        cout<<"\n INVALID operation\n";
    }
    else if(r==m.r && c==m.c)
    {
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                b[i][j]=a[i][j]+m.a[i][j];
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}
void matrix::sub(matrix m)
{
    int b[r][c];
    if(r!=m.r || c!=m.c)
    {
        cout<<"\n INVALID operation\n";
    }
    else if(r==m.r && c==m.c)
    {
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                b[i][j]=a[i][j]-m.a[i][j];
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}
void matrix::mul(matrix m)
{
    if(c!=m.r)
    {
        cout<<"\n INVALID as columns of 1st matrix not equal to rows of 2nd\n";
    }
    else
    {
        int b[r][m.c];
            for(i=0;i<r;i++)
            {
                for(j=0;j<m.c;j++)
                {   b[i][j]=0;
                    for(int k=0;k<c;k++)
                    {
                        b[i][j]+=(a[i][k]*m.a[k][j]);
                    }
                }
            }
            cout<<"MATRIX MULTIPLICATION:";
            for(i=0;i<r;i++)
            {
                for(j=0;j<m.c;j++)
                {
                    cout<<b[i][j]<<" ";
                }
                cout<<"\n";
            }
    }
}

int main()
{
    matrix m1,m2;
    m1.intial();
    m1.display();
    m1.uppert();
    m1.diagonalsum();
    m1.transpose();
    m2.intial();
    m2.display();
    cout<<"\n";
    m1.add(m2);
    cout<<"\n";
    m1.sub(m2);
    cout<<"\n";
    m1.mul(m2);
    return 0;
}
