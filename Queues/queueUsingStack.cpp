#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class stack
{
    private:
        struct node *first=NULL;
        int lenght=0;

    public:

    bool isEmpty()
    {
        if(first==NULL)
        {
            return true;
        }
        return false;
    }

    void push(int x)
    {
        struct node *t=new node;
        t->data=x;
        t->next=first;
        first=t;
    }

    int pop()
    {
        if(!isEmpty())
        {
            struct node *t=first;
            int x=t->data;
            first=first->next;
            delete t;
            return x;
        }
    }

    void display()
    {
        if(!isEmpty())
        {
            struct node *t=first;
            while (t)
            {
                cout<<t->data<<endl;
                t=t->next;
            }
            
        }
    }

    void reverse()
    {
        struct node *t=first;
        struct node *r=first;
        struct node *q=first->next;
        while(q)
        {
            t=q;
            q=q->next;
            t->next=r;
            r=t;
        }
        first->next=NULL;
        first=t;

    }

};

class queue
{
    private:
        stack s1,s2;
    public:
        bool isEmpty()
        {
            if(s1.isEmpty() && s2.isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
                return true;
            }
            return false;
        }

        void enqueue(int x)
        {
            s1.push(x);
        }

        int dequeue()
        {
            if(s2.isEmpty())
            {
                if(s1.isEmpty())
                {
                    cout<<"Queue is Empty";
                    return -1;
                }
                else
                {
                    while(!s1.isEmpty())
                    {
                        s2.push(s1.pop());
                    }
                }
            }
            
            s2.pop();
        }

        void display()
        {
            if(s1.isEmpty() && s2.isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
            }
            else
            {
                s2.display();
                s1.reverse();
                s1.display();
                s1.reverse();
            }
        }


};

int main()
{
    queue q;
    int op;

    while(true)
    {
        cout<<endl<<endl<<"------------Queue Program------------"<<endl;
        cout<<"What would you like to do?"<<endl;
        cout<<"1.Enqueue"<<endl<<"2.Dequeue"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
        cin>>op;
        switch(op)
        {
            case 1:
                int x;
                cout<<"Enter Element: ";
                cin>>x;
                q.enqueue(x);
                break;
            case 2:
                cout<<q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"Invalid Input"<<endl;
        }
    }
    return 0;
}