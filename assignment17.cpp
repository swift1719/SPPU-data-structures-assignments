#include<bits/stdc++.h>
using namespace std;
void linearsearch()
{
    int arr[100], i, num, n, c=0, pos;
    cout<<"Enter the array size : ";
    cin>>n;
    cout<<"Enter Array Elements : ";
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number to be search : ";
    cin>>num;
    for(i=0; i<n; i++)
    {
        if(arr[i]==num)
        {
            c=1;
            pos=i+1;
            break;
        }
    }
    if(c==0)
    {
        cout<<"Number not found..!!";
    }
    else
    {
        cout<<num<<" found at position "<<pos;
    }}
void binarysearch()
{

    int n, i, arr[50], search, first, last, middle;
    cout<<"Enter the array size : ";
    cin>>n;
    cout<<"Enter Array Elements(NOTE:IN SORTED ORDER) : ";
    for (i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter a number to find :";
    cin>>search;
    first = 0;
    last = n-1;
    middle = (first+last)/2;
    while (first <= last)
    {
        if(arr[middle] < search)
        {
            first = middle + 1;

        }
        else if(arr[middle] == search)
        {
            cout<<search<<" found at location "<<middle+1<<"\n";
            break;
        }
        else
        {
             last = middle - 1;
        }
        middle = (first + last)/2;
    }
    if(first > last)
    {
        cout<<"Not found! "<<search<<" is not present in the list.";
    }
}
void sentinelsearch()
{
    int arr[100],i, num, n;
    cout<<"Enter the array size : ";
    cin>>n;
    cout<<"Enter Array Elements : ";
    for( i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number to be search : ";
    cin>>num;
    int last = arr[n-1];
arr[n-1] = num;
 i = 0;
while(arr[i]!=num)
{
    i++;
}
arr[n-1] = last;
if( (i < n-1) || (num == arr[n-1]) )
{
    cout << " Found at "<<i+1;
}
else
{
    cout << " Not Found";
}
}
int fibo(int j)
{
    if(j==0)
        return 0;
    if(j==1)
        return 1;
    else
        return ((fibo(j-1))+(fibo(j-2)));
}

void fibSearch()
{       int arr[100],num,n,i;
    int f1,f2,j,mid;
    j=1;
        cout<<"Enter the array size : ";
    cin>>n;
    cout<<"Enter Array Elements :(NOTE:IN SORTED ORDER) ";
    for( i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number to be search : ";
    cin>>num;
    while(fibo(j)<=n)
        j++;


    f1=fibo(j-2);
    f2=fibo(j-3);
    mid=n-f1+1;

    while(num!=arr[mid])
    {
        if(num>arr[mid])
        {
            if(f1==1)
                break;
            mid=mid+f2;
            f1=f1-f2;
            f2=f2-f1;
        }
        else
        {
            if(f2==0)
                break;
            mid=mid-f2;
            int temp=f1-f2;
            f1=f2;
            f2=temp;
        }
    }
    if(arr[mid]==num)
        cout<<"found at:"<<mid+1;
    else
            cout<<"Not found";
}
int main()
{
    int ch;
    char c;
    for(;;)
    {
    cout<<"\n1.LINEAR SEARCH\n2.BINARY SEARCH\n3.SENTINEL SEARCH\n4.FIBBONACCI SEARCH\n5->EXIT";
    cout<<"\nENTER YOUR CHOICE:";
    cin>>ch;
    switch(ch)
    {
        case 1:
        linearsearch();
        break;
        case 2:
        binarysearch();
          break;
        case 3:
          sentinelsearch();
           break;
        case 4:
           fibSearch();
           break;
        case 5:
            exit(0);
              break;
        default:cout<<"WRONG CHOICE";
    }
    }
return 0;
}
