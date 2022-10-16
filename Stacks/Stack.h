template <typename T>
struct node
{
    T data;
    struct node<T> *next;
};

template <typename T>
class Stack
{
    private:
        struct node<T> *top=NULL;
    
    public:

        bool isEmpty()
        {
            return (!top)?true:false;
        }

        bool isFull()
        {
            struct node<T> *t=new node<T>;
            return (!t)?true:false;
        }

        void push(T newData)
        {
            if(!isFull())
            {
                struct node<T> *enteryNode=new node<T>;
                enteryNode->data=newData;
                if(top)
                {
                    enteryNode->next=top;
                    top=enteryNode;
                }
                else
                {
                    enteryNode->next=NULL;
                    top=enteryNode;
                }
            }
        }

        T pop()
        {
            if(!isEmpty())
            {
                struct node<T> *onTop=top;
                top=top->next;
                T onTopData=onTop->data;
                delete onTop;
                return onTopData;
            }
        }
};
