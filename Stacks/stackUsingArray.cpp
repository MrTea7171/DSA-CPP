#include<iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *s;
}*st=NULL;

void createStack()
{
    st=new stack();
    cout<<"Enter Stack Size:"<<endl;
    cin>>st->size;
    st->s=new int[st->size];
    st->top=-1;
}

bool isEmpty()
{
    if(st->top==-1)
    {
        cout<<"Stack is Empty";
        return true;
    }
    return false;
}

bool isFull()
{
    if(st->top==st->size-1)
    {
        cout<<"Stack is Full";
        return true;
    }
    return false;
}

void push()
{
    if(!isFull())
    {
        int element;
        cout<<"Enter Element to be Pushed:"<<endl;
        cin>>element;
        st->s[++st->top]=element;
    }
}

int pop()
{
    if(!isEmpty())
    {
        st->top--;
        return st->s[st->top+1];
    }
}

int peek()
{
    if(!isEmpty())
    {
        int position;
        cout<<"Enter postion to find:"<<endl;
        cin>>position;
        if(((st->top)-position)>-1)
        {
            return st->s[st->top-position];
        }
        cout<<"Position is invalid"<<endl;
        return -9999;
    }
}

int stackTop()
{
    if(!isEmpty())
    {
        return st->s[st->top];
    }
    return -1;
}

void display()
{
    if(!isEmpty())
    {
        for(int i=st->top;i>=0;i--)
        {
            cout<<st->s[i]<<endl;
        }
    }
}

int main()
{
    createStack();
    int op;
    while(true)
    {
        cout<<endl<<endl<<"------------Stack Program------------"<<endl;
        cout<<"What would you like to do?"<<endl;
        cout<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Display"<<endl<<"4.Peek"<<endl<<"5.StackTop"<<endl<<"6.isEmpty"<<endl<<"7.isFull"<<endl<<"8.Exit"<<endl;
        cin>>op;
        switch(op)
        {
            case 1:
                push();
                break;
            case 2:
                cout<<pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout<<peek();
                break;
            case 5:
                cout<<stackTop();
                break;
            case 6:
                isEmpty();
                break;
            case 7:
                isFull();
                break;
            case 8:
                exit(0);
                break;
            default:
                cout<<"Invalid Input"<<endl;
        }
    }
    return 0;
}