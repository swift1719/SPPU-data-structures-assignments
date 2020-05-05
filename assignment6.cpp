#include<bits/stdc++.h>
#define max 20
using namespace std;
class Matrix
{
    int r,c,a[10][10],q[10][10],i,j,d,n,b[max][3];
    int k=1;
public:
    int intial();
    void display();
    void sparserea();
    void sparsematrix();
    void sparsedisplay();
    void sparsetranspose();
    void sparsefasttranspose();
    void add(Matrix);
};
int Matrix::intial()
{
    char ch;
label:
    cout<<"\nENTER NO. OF ROWS AND COLUMNS:\n";
    cin>>r>>c;
    if(r<=0||c<=0)
    {
        cout<<"\nINALID MATRIX PLEASE GIVE VALID ORDER\n";
        goto label;
    }
    cout<<"\nENTER THE MATRIX ELEMENT:\n";
label1:
    d=0;
    for(i=0; i<r; i++)
    {    for(j=0; j<c; j++)
        {
            cin>>a[i][j];
            if(a[i][j]!=0)
            {
                d=d+1;
            }
        }
	}
    if(d<=(r*c)/2)
        cout<<"\nIT IS A SPARSE MATRIX\n";
    else
    {
        cout<<"\nIT IS NOT A SPARSE MATRIX \n";
        cout<<"\nDO YOU WANT TO ENTER MATRIX ELEMENT AGAIN(y/n)?\n";
        cin>>ch;
        if(ch=='y'||ch=='Y')
        {
            cout<<"\n*****PLEASE ENTER THE MATRIX ELEMENT AGAIN:\n";
            goto label1;
        }
        else
            exit(0);
    }


}
void Matrix::display()
{
    cout<<"\nMATRIX:\n";
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout <<"\n";

    }
}
void Matrix::sparsematrix()
{
	k=1;
    b[0][0]=r;
    b[0][1]=c;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
    b[0][2]=k-1;
}
void Matrix::sparsedisplay()
{
    cout<<"\nSPARSE MATRIX IS:\n";
    n=b[0][2];
    for(i=0; i<=n; i++)
        cout<<b[i][0]<<" "<<b[i][1]<<" "<<b[i][2]<<"\n";

}
void Matrix::sparsetranspose()
{
    int c[max][3];
    c[0][0]=b[0][1];
    c[0][1]=b[0][0];
    c[0][2]=b[0][2];
    n=b[0][2];
    cout<<"\nTRANSPOSE OF SPARSE MATRIX IS:\n";
   cout<<c[0][0]<<" "<<c[0][1]<<" "<<c[0][2]<<"\n";
    for(i=0; i<b[0][1]; i++)
        for(j=1; j<=n; j++)
            if(i==b[j][1])
            {
                  c[k][0]=i;
                  c[k][1]=b[j][0];
                  c[k][2]=b[j][2];
                  cout<<c[k][0]<<" "<<c[k][1]<<" "<<c[k][2]<<"\n";
                  k++;
            }
}
void Matrix::sparsefasttranspose()
{
    int c[max][3],total[max],index[max],l,col;
     c[0][0]=b[0][1];
    c[0][1]=b[0][0];
    c[0][2]=b[0][2];
    n=b[0][2];
    cout<<"\nFAST TRANSPOSE OF SPARSE MATRIX IS:\n";
    for(i=0;i<b[0][1];i++)
    total[i]=0;
    for(i=1;i<=n;i++)
    {
        col=b[i][1];
        total[col]++;
    }
    index[0]=1;
    for(i=1;i<n;i++)
        index[i]=index[i-1]+total[i-1];
    for(i=1;i<=n;i++)
    {
        col=b[i][1];
        l=index[col];
        index[col]++;
        c[l][0]=b[i][1];
        c[l][1]=b[i][0];
        c[l][2]=b[i][2];
    }
    for(i=0;i<=n;i++)
         cout<<c[i][0]<<" "<<c[i][1]<<" "<<c[i][2]<<"\n";
}
void Matrix::add(Matrix l)
{
     if(r!=l.r&&c!=l.c)
      cout<<"\n***SPARSE MATRIX CANNOT BE ADDED***";
    else
    {
        for (i = 0; i <r; i++)
         for (j = 0; j <c; j++)
             q[i][j]=a[i][j]+l.a[i][j];
        cout<<"\nADDITION OF MATRIX:\n";
          for (i = 0; i <r; i++)
         {  for (j = 0; j <c; j++)
           {cout<<q[i][j]<<" ";}
                cout <<"\n" ;}
    }
     k=1;
    b[0][0]=r;
    b[0][1]=c;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            if(q[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=q[i][j];
                k++;
            }
    b[0][2]=k-1;
      cout<<"\nADDITION OF SPARSE MATRIX IS:\n";
    n=b[0][2];
    for(i=0; i<=n; i++)
        cout<<b[i][0]<<" "<<b[i][1]<<" "<<b[i][2]<<"\n";
}
int main()
{
    Matrix m,n;
    m.intial();
    m.display();
    m.sparsematrix();
    m.sparsedisplay();
    m.sparsetranspose();
    m.sparsefasttranspose();
    n.intial();
    n.display();
    n.sparsematrix();
    n.sparsedisplay();
    n.sparsetranspose();
    n.sparsefasttranspose();
    m.add(n);
    return 0;
}
