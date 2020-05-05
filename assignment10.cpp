#include <iostream>
#include <conio.h>
using namespace std;

template <class type>
struct Node
{
    type data;
    Node* link;

    Node(type x)
    {
    data = x;
    link = NULL;
    }
};
template <class T>
class Stack
{
private:
    Node<T>* top;

public:
    Stack()
    {
    top = NULL;
    }

    void push(T x)
    {
    Node<T>* temp = new Node<T>(x);

    if(top == NULL)
        top = temp;
    else {
        temp->link = top;
        top = temp;
    }
    }

    bool pop(T& x)
    {
    if(top == NULL)
        return false;
    else {
        x = top->data;
        Node<T>* temp = top;
        top = top->link;
        delete temp;
        return true;
    }
    }

    bool peek(T& x)
    {
    if(top == NULL)
        return false;
    else {
        x = top->data;
        return true;
    }
    }

    void print()
    {
    Stack<T> s;
    T k;

    while(pop(k)) {
        cout << k;
        s.push(k);
    }

    while(s.pop(k))
        push(k);
    }

    ~Stack()
    {
    T k;
    while(pop(k))
        ;
    }
};

class solver
{
private:
    char* postfix;
    int postfixSize;
    char* variables;
    int varNum;
    double* varValue;

    bool isHigher(char a, char b)
    {
    int x, y;

    if(a == '(')
        return false;

    if((a == '+') || (a == '-'))
        x = 1;
    else
        x = 2;

    if((b == '+') || (b == '-'))
        y = 1;
    else
        y = 2;

    return (x >= y);
    }

public:
    solver(char A[], int e)
    {
    postfixSize = 0;
    varNum = 0;
    postfix = new char[e];
    variables = new char[e];
    varValue = new double[e];
    Stack<char> op;
    char cur, temp;
    bool found;

    for(int i = 0; i < e; i++)
    {
        cur = A[i];

        switch(cur)
        {

        case '(':
        op.push(cur);
        break;

        case '+':
        case '-':
        case '*':
        case '/':
        if(op.peek(temp))
            while(isHigher(temp, cur)) {
            op.pop(temp);
            postfix[postfixSize++] = temp;
            if(!op.peek(temp))
                break;
            }

        op.push(cur);
        break;

        case ')':
        op.peek(temp);
        while(temp != '(') {
            op.pop(temp);
            postfix[postfixSize++] = temp;
            op.peek(temp);
        }
        op.pop(temp);
        break;

        default:
        postfix[postfixSize++] = cur;

        found = false;

        for(int u = 0; u < varNum; u++)
            if(cur == variables[u])
            found = true;

        if(!found)
            variables[varNum++] = cur;

        break;
        }

}

    while(op.pop(temp))
        postfix[postfixSize++] = temp;

    postfix[postfixSize] = '\0';
    }

    void printPostfix()
    {
    cout << "Postfix results: " << postfix << endl;
    }

    void solvePostFix()
    {
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
            varValue[i]=variables[i]-'0';
        }
    }
    Stack<double> ans;
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
};

int main()
{
    char c;
    char infix[100];
    int size = 0;
    cout << "Enter an infix expression with (.) at the end: \n";
    cin >> c;
    while(c != '.')
    {
    infix[size++] = c;
    cin >> c;
    }
    solver k(infix, size);
    k.printPostfix();
    k.solvePostFix();
    cout << "\n\n";
    return 0;
}
