#include<iostream>
using namespace std;

struct Queue
{
    int size,front,rear;
    int *arr;
}*q=NULL;

void createQueue()
{
    q=new Queue();
    cout<<"Enter Queue Size:"<<endl;
    cin>>q->size;
    q->arr=new int[++q->size];
    q->front=q->rear=0;
    cout<<q->front<<q->rear;
}

bool queueEmpty()
{
    if(q->front==q->rear)
    {
        cout<<"Queue is Empty"<<endl;
        return true;
    }
    return false;
}

bool queueFull()
{
    if((q->rear+1)%q->size==q->front)
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
        cout<<"Enter Element to be inserted:"<<endl;
        q->rear=(q->rear+1)%q->size;
        cin>>q->arr[q->rear];
    }
}

int dequeue()
{
    if(!queueEmpty())
    {
        q->front=(q->front+1)%q->size;;
        return q->arr[q->front];
    }

    return -9999;
}

int first()
{
    if(!queueEmpty())
    {
        return q->arr[q->front+1];
    }

    return -9999;
}

int last()
{
    if(!queueEmpty())
    {
        return q->arr[q->rear];
    }

}

void display()
{
    if(!queueEmpty())
    {
        for(int i=q->front+1;i!=(q->rear+1)%q->size;i=(i+1)%q->size)
        {
            cout<<q->arr[i]<<endl;
        }
    }
}

int main()
{
    createQueue();
    int op;
    while(true)
    {
        cout<<endl<<endl<<"------------Queue Program------------"<<endl;
        cout<<"What would you like to do?"<<endl;
        cout<<"1.Enqueue"<<endl<<"2.Dequeue"<<endl<<"3.Display"<<endl<<"4.front"<<endl<<"5.Last"<<endl<<"6.isEmpty"<<endl<<"7.isFull"<<endl<<"8.Exit"<<endl;
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