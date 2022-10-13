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

bool isBalanced(string exp)
{
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        {
            push(exp[i]);
        }
        else if(exp[i]==')')
        {
            if(isEmpty())
            {
                return false;
            }
            else if(pop()+1!=exp[i])
            {
                return false;
            }
        }
        else if(exp[i]=='}'||exp[i]==']')
        {
            if(isEmpty())
            {
                return false;
            }
            else if(pop()+2!=exp[i])
            {
                return false;
            }
        }
    }

    if(isEmpty())
    {
        return true;
    }

    return false;
}

int main()
{
    string exp;
    cout<<"Enter String to be Tested: [(),[],{}]"<<endl;
    getline(cin,exp);
    cout<<isBalanced(exp)<<endl;
    return 0;
}