#include<iostream>
using namespace std;
#include "../../Stacks/Stack.h"
#include "../../Queues/Queue.h"

struct treeNode
{
    int data;
    struct treeNode *lchild, *rchild;
};

class BinarySearchTree
{
    private:
        struct treeNode *root=NULL;

    public:
        BinarySearchTree(int x)
        {
            struct treeNode *newNode=new treeNode;
            newNode->data=x;
            newNode->lchild=newNode->rchild=NULL;
            root=newNode;
        }
        void insertNode(int x)
        {
            struct treeNode *currentNode=root;
            struct treeNode *prevNode=root;

            while(currentNode)
            {
                prevNode=currentNode;
                if(x>currentNode->data)
                {
                    currentNode=currentNode->rchild;
                }
                else
                {
                    currentNode=currentNode->lchild;
                }
            }

            struct treeNode *newNode=new treeNode;
            newNode->data=x;
            newNode->lchild=newNode->rchild=NULL;
            if(prevNode->data>x)
            {
                cout<<"Added in left of:"<<prevNode->data<<endl;
                prevNode->lchild=newNode;
            }
            else
            {
                cout<<"Added in right of:"<<prevNode->data<<endl;
                prevNode->rchild=newNode;
            }
            
        }

        void display()
        {
            struct treeNode *displayNode=root;
            StackBox::Stack<struct treeNode *> st;
            while(displayNode || !st.isEmpty())
            {
                if(displayNode)
                {
                    st.push(displayNode);
                    displayNode=displayNode->lchild;
                }
                else
                {
                    displayNode=st.pop();
                    cout<<displayNode->data<<" ";
                    displayNode=displayNode->rchild;
                }
            }
        }

        struct treeNode * search(int x)
        {
            struct treeNode *currentNode=root;

            while(currentNode)
            {
                if(x==currentNode->data)
                {
                    return currentNode;
                }
                else if(x>currentNode->data)
                {
                    currentNode=currentNode->rchild;
                }
                else
                {
                    currentNode=currentNode->lchild;
                }
            }

            return NULL;
            
        }

        int height()
        {
            if(root==NULL)
            {
                return 0;
            }

            int height=0;
            QueueLine::Queue<struct treeNode *> q;
            q.enqueue(root);

            while(!q.isEmpty())
            {
                height++;
                int size=q.size();
                while(size>0)
                {
                    size--;
                    struct treeNode *currentNode=q.dequeue();
                    if(currentNode->lchild)
                    {
                        q.enqueue(currentNode->lchild);
                    }
                    if(currentNode->rchild)
                    {
                        q.enqueue(currentNode->rchild);
                    }
                }
            }
            return height;
        }

        int subHeight(struct treeNode *node)
        {
            if(node==NULL)
            {
                return 0;
            }

            int height=0;
            QueueLine::Queue<struct treeNode *> q;
            q.enqueue(node);

            while(!q.isEmpty())
            {
                height++;
                int size=q.size();
                while(size>0)
                {
                    size--;
                    struct treeNode *currentNode=q.dequeue();
                    if(currentNode->lchild)
                    {
                        q.enqueue(currentNode->lchild);
                    }
                    if(currentNode->rchild)
                    {
                        q.enqueue(currentNode->rchild);
                    }
                }
            }
            return height;
        }

        struct treeNode * preOrder(struct treeNode *Node)
        {
            while(Node->rchild)
            {
                Node=Node->rchild;
            }
            return Node;
        }

        struct treeNode * postOrder(struct treeNode *Node)
        {
            while(Node->lchild)
            {
                Node=Node->lchild;
            }
            return Node;
        }

        struct treeNode *searchParentNode(int x)
        {
            struct treeNode *currentNode=root;
            struct treeNode *parentNode=root;
            while(currentNode)
            {
                if(x==currentNode->data)
                {
                    return parentNode;
                }
                parentNode=currentNode;
                if(x>currentNode->data)
                {
                    currentNode=currentNode->rchild;
                }
                else
                {
                    currentNode=currentNode->lchild;
                }
            }

            return NULL;
        }

        int deleteNode(int x)
        {
            while (true)
            {
                struct treeNode *deleteNode=search(x);
                if(!deleteNode)
                {
                    return 0;
                }
                if(deleteNode->lchild==NULL && deleteNode->rchild==NULL)
                {
                    if(deleteNode==root)
                    {
                        root=NULL;
                    }
                    else
                    {
                        struct  treeNode * ParentNode=searchParentNode(x);
                        if(ParentNode->lchild==deleteNode)
                        {
                            ParentNode->lchild=NULL;
                        }
                        else
                        {
                            ParentNode->rchild=NULL;
                        }
                    }
                    cout<<deleteNode->data<<" is deleted"<<endl;
                    delete deleteNode;
                    return 1;
                }
                struct treeNode * replaceValue;
                if(subHeight(deleteNode->lchild)>subHeight(deleteNode->rchild))
                {
                    replaceValue=preOrder(deleteNode->lchild);
                }
                else
                {
                    replaceValue=postOrder(deleteNode->rchild);
                }

                deleteNode->data=replaceValue->data;
                x=replaceValue->data;

            }
    
        }
};

int main()
{
    BinarySearchTree bst(20);
    bst.insertNode(30);
    bst.insertNode(10);
    bst.insertNode(5);
    bst.insertNode(15);
    bst.insertNode(25);
    bst.insertNode(35);

    cout<<endl<<endl;
    bst.display();

    cout<<endl<<endl;
    bst.deleteNode(15);

    cout<<endl<<endl;
    bst.display();


    return 0;
}