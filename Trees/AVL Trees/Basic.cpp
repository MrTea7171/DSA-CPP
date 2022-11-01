#include<iostream>
using namespace std;

struct treeNode
{
    struct treeNode *lchild, *rchild;
    int data;
    int height;

}*root=NULL;

int NodeHeight(struct treeNode *p)
{
    int hl=0;
    int hr=0;
    if(p && p->lchild)
    {
        hl=p->lchild->height;
    }
    if(p && p->rchild)
    {
        hl=p->rchild->height;
    }

    if(hl>hr)
    {
        return hl+1;
    }
    else
    {
        return hr+1;
    }
    
}

struct treeNode* LLRotation(struct treeNode *p)
{
    struct treeNode *pl=p->lchild;
    struct treeNode *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(p==root)
    {
        root=pl;
    }

    return pl;
}

struct treeNode* RRRotation(struct treeNode *p)
{
    struct treeNode *pr=p->rchild;
    struct treeNode *prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);

    if(p==root)
    {
        root=pr;
    }

    return pr;
}

struct treeNode* LRRotation(struct treeNode *p)
{
    struct treeNode *pl=p->lchild;
    struct treeNode *plr=pl->rchild;


    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);

    if(p==root)
    {
        root=plr;
    }

    return plr;
}

struct treeNode* RLRotation(struct treeNode *p)
{
    struct treeNode *pr=p->rchild;
    struct treeNode *prl=pr->lchild;

    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;

    prl->lchild=p;
    prl->rchild=pr;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);

    if(p==root)
    {
        root=prl;
    }

    return prl;
}

int BalanceFactor(struct treeNode *p)
{
    int hl=0;
    int hr=0;
    if(p && p->lchild)
    {
        hl=p->lchild->height;
    }
    if(p && p->rchild)
    {
        hr=p->rchild->height;
    }

    return hl-hr;
}

struct treeNode* NodeUpdate(struct treeNode *node)
{
    node->height=NodeHeight(node);

    if(BalanceFactor(node)==2 && BalanceFactor(node->lchild)==1)
    {
        return LLRotation(node);
    }
    else if(BalanceFactor(node)==2 && BalanceFactor(node->lchild)==-1)
    {
        return LRRotation(node);
    }
    else if(BalanceFactor(node)==-2 && BalanceFactor(node->rchild)==-1)
    {
        return RRRotation(node);
    }
    else if(BalanceFactor(node)==-2 && BalanceFactor(node->rchild)==1)
    {
        return RLRotation(node);
    }
    else if(BalanceFactor(node)==2)
    {
        return LLRotation(node);
    }
    else if(BalanceFactor(node)==-2)
    {
        return RRRotation(node);
    }
    

    return node;
}

struct treeNode *insertNode(struct treeNode *node,int key)
{
    if(node==NULL)
    {
        struct treeNode *newNode=new treeNode;
        newNode->data=key;
        newNode->height=1;
        newNode->lchild=newNode->rchild=NULL;
        return newNode;
    }
    if(key<node->data)
    {
        node->lchild=insertNode(node->lchild,key);
    }
    else
    {
        node->rchild=insertNode(node->rchild,key);
    }

    

    return NodeUpdate(node);

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
        if((Node->lchild->height)>(Node->rchild->height))
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

    return NodeUpdate(Node);
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

int main()
{
    root=insertNode(root,30);
    insertNode(root,10);
    insertNode(root,40);
    insertNode(root,5);
    insertNode(root,20);
    cout<<root->data<<endl;
    deleteNode(root,40);
    cout<<root->data<<endl;
    return 0;
}