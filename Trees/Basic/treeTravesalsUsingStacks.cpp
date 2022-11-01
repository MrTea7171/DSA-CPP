#include<iostream>
using namespace std;
#include "../../Queues/Queue.h"
#include "../../Stacks/Stack.h"

struct treeNode
{
    int data;
    struct treeNode *lchild,*rchild;
};

class binaryTree
{
    private:
        struct treeNode *root=NULL;
        QueueLine::Queue<treeNode *> q;
    public:
        bool isEmpty()
        {
            return !root;
        }

        bool isFull()
        {
            struct treeNode *t=new treeNode;
            return !t;
        }

        void insert(int x)
        {
            if(x==-1)
            {
                q.dequeue();
                return;
            }
            struct treeNode *newNode=new treeNode;
            newNode->data=x;
            newNode->lchild=newNode->rchild=NULL;
            q.enqueue(newNode);

            if(isEmpty())
            {
                root=newNode;
                cout<<"Node entered on root."<<endl;
            }
            else
            {
                struct treeNode *activeNode=q.peek();
                if(!activeNode->lchild)
                {
                    activeNode->lchild=newNode;
                    cout<<"Node entered on left of :"<<activeNode->data<<endl;
                }
                else
                {
                    activeNode->rchild=newNode;
                    cout<<"Node entered on right of :"<<activeNode->data<<endl;
                    q.dequeue();
                }
            }
        }

        void preOrderDisplay()
        {
            if(!isEmpty())
            {
                struct treeNode *displayNode=root;
                StackBox::Stack<struct treeNode *> treeStack;
                while(displayNode || !treeStack.isEmpty())
                {
                    if(displayNode)
                    {
                        cout<<displayNode->data<<endl;
                        treeStack.push(displayNode);
                        displayNode=displayNode->lchild;
                    }
                    else
                    {
                        displayNode=treeStack.pop()->rchild;
                    }
                }
            }

        }

        void inOrderDisplay()
        {
            if(!isEmpty())
            {
                struct treeNode *displayNode=root;
                StackBox::Stack<struct treeNode *> treeStack;
                while(displayNode || !treeStack.isEmpty())
                {
                    if(displayNode)
                    {
                        treeStack.push(displayNode);
                        displayNode=displayNode->lchild;
                    }
                    else
                    {
                        displayNode=treeStack.pop();
                        cout<<displayNode->data<<endl;
                        displayNode=displayNode->rchild;
                    }
                }
            }
        }

        void postOrderDisplay()
        {
                if(!isEmpty())
                {
                    struct treeNode *displayNode=root;
                    StackBox::Stack<struct treeNode *> treeStack;
                    while(displayNode || !treeStack.isEmpty())
                    {
                        if(displayNode)
                        {
                            treeStack.push(displayNode->rchild);
                            treeStack.push(displayNode);
                            displayNode=displayNode->lchild;
                        }
                        else
                        {
                            displayNode=treeStack.pop();
                            if(treeStack.peek()==displayNode->rchild)
                            {
                                struct treeNode *temp=treeStack.pop();
                                treeStack.push(displayNode);
                                displayNode=temp;
                            }
                            else
                            {
                                cout<<displayNode->data<<endl;
                                displayNode=NULL;
                            }
                            
                        }
                    }
                }
        }

        void LevelOrderTraversal()
        {
            if(!isEmpty())
            {
                QueueLine::Queue<struct treeNode*> treeList;
                cout<<root->data<<endl;
                treeList.enqueue(root);

                while(!treeList.isEmpty())
                {
                    struct treeNode *displayNode= treeList.dequeue();
                    if(displayNode->lchild)
                    {
                        cout<<displayNode->lchild->data<<endl;
                        treeList.enqueue(displayNode->lchild);
                    }
                    if(displayNode->rchild)
                    {
                        cout<<displayNode->rchild->data<<endl;
                        treeList.enqueue(displayNode->rchild);
                    }
                }
            }
        }
};

int main()
{   
    binaryTree b;
    b.insert(5);
    b.insert(15);
    b.insert(25);
    b.insert(-1);
    b.insert(35);
    b.insert(45);
    b.preOrderDisplay();
    b.inOrderDisplay();
    //b.postOrderDisplay();
    //b.LevelOrderTraversal();
    return 0;
}