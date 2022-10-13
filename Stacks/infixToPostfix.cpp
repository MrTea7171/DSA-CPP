#include<iostream>
using namespace std;

struct node
{
    char data;
    struct node *next;
}*top=NULL;

bool isEmpty()
{
    if(top==NULL)
    {
        return true;
    }
    return false;
}

void push(char element)
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
    char x=p->data;
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

int operatorPrecedence(char op)
{
    if(op=='+' || op=='-')
    {
        return 1;
    }
    else if(op=='*' || op=='/')
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

string infixToPostfix(string exp)
{
    string postfix="";
    int i=0;
    while(exp[i]!='\0')
    {
        if(top && operatorPrecedence(exp[i])<=operatorPrecedence(top->data))
        {
            postfix+=pop();
        }
        else
        {
            push(exp[i++]);
        }
    }

    while(top)
    {
        postfix+=pop();
    }

    return postfix;

}

int main()
{
    string exp;
    getline(cin,exp);
    cout<<infixToPostfix(exp);
    return 0;
}