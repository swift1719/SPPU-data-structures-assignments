#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
     char a;
     node *next;
     node()
     {
        a='0';
        next=NULL;
     }
};

class nodestring
{
    public:
        string a;
        nodestring *next;
        nodestring()
        {
            a=" ";
            next=NULL;
        }
};

class Stackstring
{
    nodestring* top;
   public:
    Stackstring()
    {
        top=NULL;
    }
    string top1()
    {
        return top->a;
    }
    void push(string x)
    {
        nodestring * temp=new nodestring;
        temp->a=x;
        temp->next=top;
        top=temp;
    }
    string pop()
    {
        string c=top->a;
        top=top->next;
        return c;
    }
    string dis()
    {
        return (top->a);
    }
    int isempty()
    {
        if(top==NULL)
            return 1;
        else
            return 0;
    }
};
class Stack
{
    node* top;
public:
    Stack()
    {
        top=NULL;
    }
    char top1()
    {
        return top->a;
    }
    void push(char x)
{
    node * temp=new node;
    temp->a=x;
    temp->next=top;
    top=temp;
}
char pop()
{
    char c=top->a;
    top=top->next;
    return c;
}
char dis()
{
    return (top->a);
}
int empty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
    }
};
string input()
{
    string s="",x;
    int c=1;
    while(c)
    {   c=0;
        cout<<"\nEnter an Expression-";cin>>s;
        for(int i=0;i<s.size();i++)
        {
        if((s[i]<'0' || s[i]>'9')&&(s[i]<'a' || s[i]>'z')&&s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='('&&s[i]!=')')
        {
            c=1;
            break;
        }
        }
        if(c)   cout<<"\nInvalid Expression, Enter a valid Expression.\n";
    }
    return s;
}
void postfix()
{
    string s;
    s=input();
    int i=0;
    string a="";
    Stack st;
    while(i<s.size())
    {
        if((s[i]>='0' && s[i]<='9')||(s[i]>='a' && s[i]<='z'))
             a+=s[i];
        else if(s[i]=='*' || s[i]=='/' || s[i]=='(')
             st.push(s[i]);
        else if(s[i]==')')
             while(st.dis()!='(') {a+=st.pop(); st.pop();}
        else
        { while(!st.empty() && st.dis()!='(') a+=st.pop(); st.push(s[i]); }
        if(i==s.size()-1)
        {
            while(!st.empty())
                 {a+=st.pop();}
        }
        i++;
    }
    cout<<"\nPostFix Expression is: "<<a;
    s=a;
    int i, count = 0;
    char cur;
    double x, y, z;
    int flag=0;
    for(i = 0; i < varNum; i++)
    {
        if(variables[i]<58 &&variables[i]>46)
            flag=1;
    }
    if(flag==0)
    {
    cout << "Enter the corresponding values for each of the following variable: \n";
    for(i = 0; i < varNum; i++)
    {
        cout << variables[i] << " = ";
        cin >> varValue[i];
    }
    }
    else if(flag==1)
    {
      for(i = 0; i < varNum; i++)
        {
            varValue[i]=s[i]-'0';
        }
    }
    for(i = 0; i < postfixSize; i++)

{
        cur = postfix[i];
        switch(cur)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        ans.pop(y);
        ans.pop(x);
        if(cur == '+')
            z = x + y;
        else if(cur == '-')
            z = x - y;
        else if(cur == '*')
            z = x * y;
        else
            z = x / y;

        ans.push(z);
        break;

        default:
        ans.push(varValue[count++]);
        }
    }
    ans.pop(z);
    cout << "ans: " << z << endl;
    }
int main()
{
    int ch=1;
    for(;;)
    {
        cout<<"\nPRESS:\n1.for infix to postfix \n2.for postfix expression valuation \n3.To exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1: postfix();
                    break;
            case 2: postfix_evaluation();
                    break;
            case 3: return 0;
            default: cout<<"\nEnter a Valid Choice.";
        }
    }
    return 0;
}
