template <typename T>
struct node
{
    T data;
    struct node * next;
};

template <typename T>
class Queue
{
    private:
        struct node <T> *front=NULL;
        struct node <T> *rear=NULL;
    
    public:
        bool isEmpty()
        {
            return (!front)?true:false;
        }

        bool isFull()
        {
            struct node<T> *t=new node<T>;
            return (!t)?true:false;
        }

        void enqueue(T x)
        {
            if(!isFull())
            {
                struct node<T> *t=new node<T>;
                t->data=x;
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

            }

        }

        T dequeue()
        {
            if(!isEmpty())
            {
                struct node<T> *t=front;
                front=front->next;

                T x=t->data;
                delete t;
                return x;
            }
        }

        T peek()
        {
            if(!isEmpty())
            {
                return front->data;
            }
        }

        void display()
        {
            if(!isEmpty())
            {
                struct node<T> *t=front;
                
                while(t)
                {
                    cout<<t->data<<endl;
                    t=t->next;
                }
            }
        }


};
