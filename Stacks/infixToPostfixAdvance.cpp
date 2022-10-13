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

int operatorPrecedenceIn(char op)
{
    if(op=='+' || op=='-')
    {
        return 2;
    }
    else if(op=='*' || op=='/')
    {
        return 4;
    }
    else if(op=='^')
    {
        return 5;
    }
    else if(op=='(')
    {
        return 0;
    }
    else
    {
        return 9;
    }
}

int operatorPrecedenceOut(char op)
{
    if(op=='+' || op=='-')
    {
        return 1;
    }
    else if(op=='*' || op=='/')
    {
        return 3;
    }
    else if(op=='^')
    {
        return 6;
    }
    else if(op=='(')
    {
        return 7;
    }
    else if(op==')')
    {
        return 0;
    }
    else
    {
        return 8;
    }
}

string infixToPostfix(string exp)
{
    string postfix="";
    int i=0;
    while(exp[i]!='\0')
    {
        if(top && operatorPrecedenceOut(exp[i])<operatorPrecedenceIn(top->data))
        {
            // cout<<"Top Data"<<top->data<<endl;
            // cout<<"Out:"<<operatorPrecedenceOut(exp[i])<<" ";
            // cout<<"In:"<<operatorPrecedenceIn(top->data)<<endl;
            
            postfix+=pop();
            //<<postfix<<i<<endl;
        }
        else if(top && operatorPrecedenceOut(exp[i])==operatorPrecedenceIn(top->data))
        {
            pop();
            i++;
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