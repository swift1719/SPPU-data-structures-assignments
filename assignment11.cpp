#include<bits/stdc++.h>
using namespace std;
class node{
    public:
     char a;
     node *next;
     node()
     {
        a='0';
        next=NULL;
     }
};

class nodestring{
    public:
        string a;
        nodestring *next;
        nodestring(){
            a=" ";
            next=NULL;
        }
};

class Stackstring{
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
        if(top==NULL)   return 1;
        else        return 0;
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
        if(top==NULL)   return 1;
        else        return 0;
    }
};
string input()
{
    string s="",x;
    int c=1;
            while(c)
            {   c=0;
                cout<<"\nEnter an Expression-";cin>>s;
                for(int i=0;i<s.size();i++){
                if((s[i]<'0' || s[i]>'9')&&(s[i]<'a' || s[i]>'z')&&s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='('&&s[i]!=')')
                        {c=1; break;}
                }
                if(c)   cout<<"\nInvalid Expression, Enter a valid Expression.\n";
            }
            return s;
}
void infix_to_postfix()
{
    string s;
    s=input();
    int i=0;
    string a="";
    Stack st;
    while(i<s.size()){
        if((s[i]>='0' && s[i]<='9')||(s[i]>='a' && s[i]<='z'))
             a+=s[i];
        else if(s[i]=='*' || s[i]=='/' || s[i]=='(')
             st.push(s[i]);
        else if(s[i]==')')
             while(st.dis()!='(') {a+=st.pop(); st.pop();}
        else
        {
              while(!st.empty() && st.dis()!='(')
                a+=st.pop(); st.push(s[i]);
      }
        if(i==s.size()-1)
        {
            while(!st.empty())
                 {a+=st.pop();}
        }
        i++;
    }
    cout<<"\nThe Infix Expression ("<<s<<") in PostFix Expression is-"<<a;s=a;
}

bool isOperator(char x)
{
    switch (x) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}
void postfix_to_prefix()
{
    string s;
    s=input();
    int i=0;
    string a="";
    Stackstring st1;
    int length=s.size();


    for(int i=0; i<length; i++)
    {
     if(isOperator(s[i]))
     {
          string op1 = st1.top1();
            st1.pop();
            string op2 = st1.top1();
            st1.pop();

            string temp= s[i] + op2 + op1 ;
            st1.push(temp);
         }

    else{
        st1.push(string(1,s[i]));
    }
    }
    cout<<"\nThe postfix Expression ("<<s<<") in Prefix Expression is-"<<st1.top1();
}

void postfix_to_infix()
{
    string s;
    s=input();
    Stackstring st1;
    int length=s.size();


    for(int i=0; i<length; i++)
    {
     if(isOperator(s[i]))
     {
          string op1 = st1.top1();
            st1.pop();
            string op2 = st1.top1();
            st1.pop();

            string temp='('+op2+s[i]+op1+')';
            st1.push(temp);
         }

    else{
        st1.push(string(1,s[i]));
    }
    }
    cout<<"\nThe postfix Expression ("<<s<<") in inFix Expression is-"<<st1.top1();
}
void prefix_to_infix()
{
    string s;
    s=input();
    Stackstring st1;
    int length=s.size();
      for (int i = length - 1; i >= 0; i--)
      {
         if (isOperator(s[i]))
         {
             string op1 = st1.top1();   st1.pop();
             string op2 = st1.top1();   st1.pop();

             string temp = "(" + op1 + s[i] + op2 + ")";
             st1.push(temp) ;
           }
           else {
            st1.push(string(1, s[i]));
           }
      }
        cout<<"\nThe pretfix Expression ("<<s<<") in inFix Expression is-"<<st1.top1();
}

void prefix_to_postfix()
{
    string s;
    s=input();
    Stackstring st1;
    int length=s.size();
      for (int i = length - 1; i >= 0; i--)
      {
         if (isOperator(s[i]))
         {
             string op1 = st1.top1();   st1.pop();
             string op2 = st1.top1();   st1.pop();

             string temp = "(" + op1 + op2 + s[i] + ")";
             st1.push(temp) ;
           }
           else {
            st1.push(string(1, s[i]));
           }
      }
        cout<<"\nThe pretfix Expression ("<<s<<") in postFix Expression is-"<<st1.top1();
}

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}
void infix_to_prefix()
{
    string s;
    s=input();
    Stack opt;
    Stackstring opr;
    int length=s.size();

    for(int i=0;i<length;i++)
    {
        if(s[i]=='(') opt.push(s[i]);
        else if(s[i]==')'){
            while(!opt.empty()&&opt.top1() !='('){
                string op1=opr.top1(); opr.pop();
                string op2=opr.top1(); opr.pop();
                char op=opt.top1(); opt.pop();
                string temp=op+op2+op1;
                opr.push(temp);
              }
             opt.pop();
          }
        else if (!isOperator(s[i])) {
            opr.push(string(1, s[i]));
          }
        else{
            while(!opt.empty() &&  getPriority(s[i])<=getPriority(opt.top1()))
            {
             string op1=opr.top1(); opr.pop();
                string op2=opr.top1(); opr.pop();
                char op=opt.top1(); opt.pop();
                string temp=op+op2+op1;
                opr.push(temp);
            } opt.push(s[i]);
        }
      }
    while(!opt.empty()){
        string op1=opr.top1(); opr.pop();
        string op2=opr.top1(); opr.pop();
        char op=opt.top1(); opt.pop();
        string temp=op+op2+op1;
        opr.push(temp);
    }
     cout<<"\nThe prefix Expression ("<<s<<") in postFix Expression is-"<<opr.top1();
}

int main()
{
    int ch=1;
    for(;;)
    {
        cout<<"\nPRESS:\n1.for infix to postfix \n2.for postfix to prefix \n3.for postfix to infix \n4.for prefix to infix \n5.for prefix to postfix\n6.for infix to prefix\n7.TO exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1: infix_to_postfix();
                    break;
            case 2: postfix_to_prefix();
                    break;
            case 3: postfix_to_infix();
                    break;
            case 4: prefix_to_infix();
                    break;
            case 5: prefix_to_postfix();
                    break;
            case 6: infix_to_prefix();
                    break;
            case 7: return 0;
            default: cout<<"\nEnter a Valid Choice.";
        }
    }
    return 0;
}
