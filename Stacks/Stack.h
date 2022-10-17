#ifndef MRTEA_STACKS
#define MRTEA_STACKS

class StackBox
{
    private:
        template <typename T>
        struct stackNode
        {
            T data;
            struct stackNode<T> *next;
        };

    public:
        template <typename T>
        class Stack
        {
            private:
                struct stackNode<T> *top=NULL;
            
            public:

                bool isEmpty()
                {
                    return (!top)?true:false;
                }

                bool isFull()
                {
                    struct stackNode<T> *t=new stackNode<T>;
                    return (!t)?true:false;
                }

                void push(T newData)
                {
                    if(!isFull())
                    {
                        struct stackNode<T> *enterystackNode=new stackNode<T>;
                        enterystackNode->data=newData;
                        if(top)
                        {
                            enterystackNode->next=top;
                            top=enterystackNode;
                        }
                        else
                        {
                            enterystackNode->next=NULL;
                            top=enterystackNode;
                        }
                    }
                }

                T pop()
                {
                    if(!isEmpty())
                    {
                        struct stackNode<T> *onTop=top;
                        top=top->next;
                        T onTopData=onTop->data;
                        delete onTop;
                        return onTopData;
                    }
                }

                T peek()
                {
                    if(!isEmpty())
                    {
                        return top->data;
                    }
                }
        };
};

#endif

