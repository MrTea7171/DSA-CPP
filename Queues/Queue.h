#ifndef MRTEA_QUEUES
#define MRTEA_QUEUES
class QueueLine
{
    private:
        template <typename T>
        struct queueNode
        {
            T data;
            struct queueNode * next;
        };

    public:
        template <typename T>
        class Queue
        {
            private:
                struct queueNode <T> *front=NULL;
                struct queueNode <T> *rear=NULL;
            
            public:
                bool isEmpty()
                {
                    return (!front)?true:false;
                }

                bool isFull()
                {
                    struct queueNode<T> *t=new queueNode<T>;
                    return (!t)?true:false;
                }

                void enqueue(T x)
                {
                    if(!isFull())
                    {
                        struct queueNode<T> *t=new queueNode<T>;
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
                        struct queueNode<T> *t=front;
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
                        struct queueNode<T> *t=front;
                        
                        while(t)
                        {
                            cout<<t->data<<endl;
                            t=t->next;
                        }
                    }
                }

                int size()
                {
                    if(!isEmpty())
                    {
                        int x=0;
                        struct queueNode<T> *t=front;
                        
                        while(t)
                        {
                            x++;
                            t=t->next;
                        }
                        return x;
                    }

                    return 0;
                }


        };
};
#endif