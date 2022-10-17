#include<iostream>
using namespace std;
#include "../Queues/Queue.h"

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

        void preOrderDisplay(struct treeNode *t)
        {
            if(t)
            {
                cout<<t->data<<endl;
                preOrderDisplay(t->lchild);
                preOrderDisplay(t->rchild);
            }
        }

        void inOrderDisplay(struct treeNode *t)
        {
            if(t)
            {
                inOrderDisplay(t->lchild);
                cout<<t->data<<endl;
                inOrderDisplay(t->rchild);
            }
        }

        void postOrderDisplay(struct treeNode *t)
        {
            if(t)
            {
                postOrderDisplay(t->lchild);
                postOrderDisplay(t->rchild);
                cout<<t->data<<endl;
            }
        }

        int countAllNodes(struct treeNode *currentNode)
        {
            if(!currentNode)
                return 0;
            int x,y;
            x=countAllNodes(currentNode->lchild);
            y=countAllNodes(currentNode->rchild);
            return x+y+1;
        }

        int countAllTwoDegreeNodes(struct treeNode *currentNode)
        {
            if(!currentNode)
                return 0;
            int x,y;
            x=countAllTwoDegreeNodes(currentNode->lchild);
            y=countAllTwoDegreeNodes(currentNode->rchild);
            if(currentNode->lchild && currentNode->rchild)
                return x+y+1;
            else
                return x+y;
        }

        int countAllLeafNodes(struct treeNode *currentNode)
        {
            if(!currentNode->lchild && !currentNode->rchild)
                return 1;
            int x,y;
            x=countAllLeafNodes(currentNode->lchild);
            y=countAllLeafNodes(currentNode->rchild);
            return x+y;
        }

        int treeHeight(struct treeNode *currentNode)
        {
            if(!currentNode)
                return 0;
            int x,y;
            x=treeHeight(currentNode->lchild);
            y=treeHeight(currentNode->rchild);
            return x>y?x+1:y+1;
        }

        

    public:
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

            if(!root)
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

        void display()
        {
            preOrderDisplay(root);
            cout<<endl;
            inOrderDisplay(root);
            cout<<endl;
            postOrderDisplay(root);
        }

        int countAll()
        {
            return countAllNodes(root);
        }

        int countDegreeTwo()
        {
            return countAllTwoDegreeNodes(root);
        }

        int countLeafs()
        {
            return countAllLeafNodes(root);
        }

        int getHeight()
        {
            return treeHeight(root);
        }

};

int main()
{   
    binaryTree b;
    b.insert(5);
    b.insert(15);
    b.insert(25);
    b.insert(35);
    b.insert(45);
    //b.display();
    //cout<<"Count of all Nodes: "<<b.countAll()<<endl;
    //cout<<"Count of all two degree nodes: "<<b.countDegreeTwo()<<endl;
    //cout<<"Count all leaf nodes:"<<b.countLeafs()<<endl;
    cout<<"TreeHeight: "<<b.getHeight()<<endl;
    return 0;
}