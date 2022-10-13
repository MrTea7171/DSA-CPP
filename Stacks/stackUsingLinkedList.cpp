#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *top;

bool isEmpty()
{
    if(top==NULL)
    {
        cout<<"Stack is Empty";
        return true;
    }
    return false;
}

bool isFull()
{
    node *t=new node;
    if(t==NULL)
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
        struct node *p=new node;
        cout<<"Enter Element to be Pushed:"<<endl;
        cin>>p->data;
        p->next=top;
        top=p;
    }
}

int pop()
{
    if(!isEmpty())
    {
        struct node *p=top;
        top=p->next;
        int x=p->data;
        delete p;
        return x;
    }
}

int peek()
{
    if(!isEmpty())
    {
        int position;
        cout<<"Enter postion to find:"<<endl;
        cin>>position;
        struct node *p=top;
        while(p && position)
        {   
            position--;
            p=p->next;
        }
        if(position!=0 || p==NULL)
        {
            cout<<"Position is invalid"<<endl;
            return -9999;
        }
        else
        {
            return p->data;
        }
        
    }
}

int stackTop()
{
    if(!isEmpty())
    {
        return top->data;
    }
    return -1;
}

void display()
{
    if(!isEmpty())
    {
        struct node *p=top;
        while(p)
        {
            cout<<p->data<<endl;
            p=p->next;
        }
    }
}

int main()
{
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