#include<iostream>
using namespace std;

struct treeNode
{
    int data;
    struct treeNode *lchild, *rchild;
};

class BinarySearchTree
{
    private:
        struct treeNode *root=NULL;

        struct treeNode * insert(struct treeNode *Node,int x)
        {
            if(!Node)
            {
                struct treeNode *newNode=new treeNode;
                newNode->lchild=newNode->rchild=NULL;
                newNode->data=x;
                return newNode;
            }

            if(x>Node->data)
            {
                Node->rchild=insert(Node->rchild,x);
            }
            else if (x<Node->data)
            {
                Node->lchild=insert(Node->lchild,x);
            }

            return Node;
        }

        void inorderDisplay(struct treeNode *Node)
        {
            if(Node)
            {
                inorderDisplay(Node->lchild);
                cout<<Node->data<<endl;
                inorderDisplay(Node->rchild);
            }
        }

        int searchNode(struct treeNode *Node,int x)
        {
            if(!Node)
            {
                return 0;
            }

            if(Node->data==x)
            {
                return 1;
            }

            if(x>Node->data)
            {
                searchNode(Node->rchild,x);
            }
            else if (x<Node->data)
            {
                searchNode(Node->lchild,x);
            }
        }

        int height(struct treeNode *Node)
        {
            if(!Node)
            {
                return 0;
            }
            
            int x=height(Node->lchild);
            int y=height(Node->rchild);
            if(x>y)
            {
                return x+1;
            }
            else
            {
                return y+1;
            }
        }

        struct treeNode *preOrder(struct treeNode *Node)
        {
            if(!Node->rchild)
            {
                return Node;
            }
            return preOrder(Node->rchild);
        }

        struct treeNode *postOrder(struct treeNode *Node)
        {
            if(!Node->lchild)
            {
                return Node;
            }
            return postOrder(Node->lchild);
        }

        struct treeNode *deleteNode(struct treeNode *Node,int x)
        {
            if(!Node)
            {
                return NULL;
            }
            if(Node->lchild==NULL && Node->rchild==NULL)
            {
                if(Node==root)
                {
                    root=NULL;
                }
                delete Node;
                return NULL;
            }
            if(x>Node->data)
            {
                Node->rchild=deleteNode(Node->rchild,x);
            }
            else if (x<Node->data)
            {
                Node->lchild=deleteNode(Node->lchild,x);
            }
            else
            {
                struct treeNode *q;
                if(height(Node->lchild)>height(Node->rchild))
                {
                    q=preOrder(Node->lchild);
                    Node->data=q->data;
                    Node->lchild=deleteNode(Node->lchild,q->data);
                }
                else
                {
                    q=postOrder(Node->rchild);
                    Node->data=q->data;
                    Node->rchild=deleteNode(Node->rchild,q->data);
                }
            }

            return Node;
        }

    public:
        void insertNode(int x)
        {
            root=insert(root,x);
        }

        void display()
        {
            inorderDisplay(root);
        }

        int search(int x)
        {
            searchNode(root,x);
        }

        int deleteTreeNode(int x)
        {
            deleteNode(root,x);
        }
};

int main()
{
    BinarySearchTree bst;
    // bst.insertNode(20);
    // bst.insertNode(30);
    // bst.insertNode(10);
    // bst.insertNode(5);
    // bst.insertNode(15);
    // bst.insertNode(25);
    // bst.insertNode(35);
    int arr[]={50,15,62,5,20,58,91,3,8,37,60,24};
    for(int x:arr)
    {
        bst.insertNode(x);
    }
    bst.display();
    // bst.deleteTreeNode(15);
    // cout<<endl<<endl;
    // bst.display();
    //cout<<bst.search(12)<<endl;

    return 0;
}