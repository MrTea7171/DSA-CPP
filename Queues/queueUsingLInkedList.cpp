#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
}*front=NULL,*rear=NULL;

bool queueEmpty()
{
    if(front==NULL)
    {
        cout<<"Queue is Empty"<<endl;
        return true;
    }
    return false;
}

bool queueFull()
{
    struct node *t=new node;
    if(t==NULL)
    {
        cout<<"Queue is Full"<<endl;
        return true;
    }

    return false;
}

void enqueue()
{
    if(!queueFull())
    {
        struct node *t=new node;
        t->next=NULL;
    
        if(front==NULL)
        {
            front=rear=t;
        }
        else
        {
            rear->next=t;
            rear=t;
        }
        
        cout<<"Enter Element to be inserted:"<<endl;
        cin>>rear->data;
    }
}

int dequeue()
{
    if(!queueEmpty())
    {
        struct node *t=front;
        front=front->next;
        int x=t->data;
        delete t;
        return x;
    }

    return -9999;
}

int first()
{
    if(!queueEmpty())
    {
        return front->data;
    }

    return -9999;
}

int last()
{
    if(!queueEmpty())
    {
        return rear->data;
    }

}

void display()
{
    if(!queueEmpty())
    {
        cout<<"Elements in queue are:"<<endl;
        struct node *t=front;
        while ((t))
        {
            cout<<t->data<<endl;
            t=t->next;
        }
    }
}

int main()
{
    int op;
    while(true)
    {
        cout<<endl<<endl<<"------------Queue Program------------"<<endl;
        cout<<"What would you like to do?"<<endl;
        cout<<"1.Enqueue"<<endl<<"2.Dequeue"<<endl<<"3.Display"<<endl<<"4.First"<<endl<<"5.Last"<<endl<<"6.isEmpty"<<endl<<"7.isFull"<<endl<<"8.Exit"<<endl;
        cin>>op;
        switch(op)
        {
            case 1:
                enqueue();
                break;
            case 2:
                cout<<dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout<<first();
                break;
            case 5:
                cout<<last();
                break;
            case 6:
                queueEmpty();
                break;
            case 7:
                queueFull();
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