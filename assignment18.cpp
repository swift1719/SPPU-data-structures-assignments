#include<bits/stdc++.h>
using namespace std;
class ar
{
    int *a=NULL;

public:

    void ip(int n);
    void display(int n);
    void ssort(int n);
    void insertionSort(int s);
    void bubbleSort(int s);
    void shellSort(int s);
};
void ar::ip(int n)
{
    a=new int[n];
  int i;
  cout<<"\n Enter array elements: \n";
  for(i =0 ; i < n; i++)
    cin>>a[i];
}

void ar::display(int n)
{
  int i;
  cout<<endl;
  for(i =0 ; i<n; i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
void ar::ssort(int n)
{
  int i, j;
  int mini;
  int temp;

  for(i =0; i < n-1 ;i++)
  {
    mini = i;
    for(j = i+1; j < n ;j++)
    {
      if(a[j] < a[mini])
      {
        mini = j;
      }
    }
    if(i != mini)
    {
      temp = a[i];
      a[i] = a[mini];
      a[mini] = temp;
    }
  }
}
void ar::insertionSort(int s)
{
  int i, j;
  int current;

  for(i = 1; i < s; i++)
  {
    current = a[i];

    for(j=i-1; j>=0 && current<a[j] ;j--)
    {
        a[j+1] = a[j];
    }
    a[j+1] = current;

  }

}
void ar::bubbleSort(int s)
{
  int i, j;
  int temp;

  for(i=s-1; i>0; i--)
  {
    for(j =0; j < i; j++)
    {
      if(a[j] > a[j+1])
      {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }

}
void ar::shellSort(int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
}

int main()
{
  int s,ch;
  label1:
  cout<<"Enter size of the array:";
  cin>>s;
  if(s<1)
  {
      cout<<"\nEnter valid input!!!\n";
      goto label1;
  }
  ar b;
  b.ip(s);
  b.display(s);
  cout<<"SORTING"<<endl;
  for(;;)
  {
      cout<<"\nPRESS:\n1.for SELECTION SORT\n2.for INSERTION SORT\n3.for BUBBLE SORT\n4.SHELL SORT\n5.to EXIT";
      cin>>ch;
      switch(ch)
      {
        case 1:
            b.ssort(s);
            cout<<"\nSORTED ARRAY IS: ";
            b.display(s);
            break;
        case 2:
            b.insertionSort(s);
            cout<<"\nSORTED ARRAY IS: ";
            b.display(s);
            break;
        case 3:
            b.bubbleSort(s);
            cout<<"\nSORTED ARRAY IS: ";
            b.display(s);
            break;
        case 4:
            b.shellSort(s);
            cout<<"\nSORTED ARRAY IS: ";
            b.display(s);
            break;
        case 5:
            exit(0);
      }
  }
  return 0;
}
