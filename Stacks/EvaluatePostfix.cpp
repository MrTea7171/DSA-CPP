#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int element)
{
    struct node *p=new node;
    p->data=element;
    p->next=top;
    top=p;
}

char pop()
{
    struct node *p=top;
    top=p->next;
    int x=p->data;
    delete p;
    return x;
}

bool isOperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
    {
        return false;
    }

    return true;
}

int EvaluatePostfix(string exp)
{
    for(int i=0;exp[i]!='\0';i++)
    {
        if(isOperand(exp[i]))
        {
            push(exp[i]-'0');
        }
        else
        {
            int x1=pop();
            int x2=pop();

            switch(exp[i])
            {
                case '+':
                    push(x1+x2);
                    break;
                case '-':
                    push(x2-x1);
                    break;
                case '*':
                    push(x1*x2);
                    break;
                case '/':
                    push(x2/x1);
                    break;
            }
        }
    }

    return pop();
}

int main()
{
    string exp;
    getline(cin,exp);
    cout<<EvaluatePostfix(exp);
    return 0;
}