#include<bits/stdc++.h>

using namespace std;
  class node {
        public:
        int data;
        node *next;
  };
class Stack:public node
{       public:
        node *top = NULL;
        node* createNode (int data) {
        node *ptr = new node;
        ptr->data = data;
        ptr->next = NULL;
                return ptr;
  }
 void push(int data) {
        node *temp, *ptr = createNode(data);
        if (top == NULL) {
                top = ptr;
                return;
        }
        temp = top;
        ptr->next = temp;
        top = ptr;
  }
  int pop() {
        int data;
        node *temp;
        if (top == NULL)
                return -1;
        data = top->data;
        temp = top;
        top = temp->next;
        free (temp);
        return (data);
  }
 void intial()
   {
        char str[100];
        int i, flag = 0, data = 0;
        cout<<"\nEnter ur expression:";
        cin>>str;
        for (i = 0; i < strlen(str); i++)
      {

                if (str[i] == '(' || str[i] == '{' || str[i] == '[')
                  {
                                push(str[i]);
                                continue;
                  }
                if (str[i] == ')' || str[i] == '}' || str[i] == ']')
                  {

                        data = pop();
                        if ((str[i] == ')' && data != '(') || data == -1 || (str[i] == '}' && data != '{') || (str[i] == ']' && data != '['))
                        {
                              flag = 1;
                              break;
                        }

                }
        }

        if (flag == 1 || top != NULL)
                cout<<"\nNot a balanced expression\n";
        else
                cout<<"\nBALANCED EXPRESSION\n";
      }
   };
 int main()
 {      Stack s;
        s.intial();
        return 0;
}
