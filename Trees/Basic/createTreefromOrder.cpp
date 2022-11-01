#include<iostream>
#include<stdlib.h>
#include<unordered_map>
using namespace std;

struct treeNode
{
    struct treeNode *lchild, *rchild;
    int data;
};

int searchIndex(int inorder[],int start, int end, int curr)
{
    // cout<<"Start:"<<start<<endl;
    // cout<<"End:"<<end<<endl;
    // cout<<"Value:"<<end<<endl;
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
}

struct treeNode* createTreePre(int preOrder[],int inOrder[],int start,int end)
{
    if(start>end)
        return NULL;

    static int idx=0;
    int curr=preOrder[idx];
    idx++;
    struct treeNode *node=new treeNode;
    node->data=curr;

    if(start==end)
    {
        node->lchild=NULL;
        node->rchild=NULL;
        return node;
    }

    int pos=searchIndex(inOrder,start,end,curr);
    //cout<<pos<<endl;

    node->lchild=createTreePre(preOrder,inOrder,start,pos-1);
    node->rchild=createTreePre(preOrder,inOrder,pos+1,end);

    return node;
    
}

struct treeNode* createTreePreMap(int preOrder[],int inOrder[],int start,int end, unordered_map<int,int>& inOrderMap)
{
    if(start>end)
        return NULL;

    static int idx=0;
    int curr=preOrder[idx];
    idx++;
    struct treeNode *node=new treeNode;
    node->data=curr;

    if(start==end)
    {
        node->lchild=NULL;
        node->rchild=NULL;
        return node;
    }

    int pos=inOrderMap[curr];

    node->lchild=createTreePreMap(preOrder,inOrder,start,pos-1,inOrderMap);
    node->rchild=createTreePreMap(preOrder,inOrder,pos+1,end,inOrderMap);

    return node;
    
}

struct treeNode* createTreePost(int postOrder[],int inOrder[],int start,int end)
{
    if(start>end)
        return NULL;

    static int idx=end;
    int curr=postOrder[idx];
    idx--;
    struct treeNode *node=new treeNode;
    node->data=curr;

    if(start==end)
    {
        node->lchild=NULL;
        node->rchild=NULL;
        return node;
    }

    int pos=searchIndex(inOrder,start,end,curr);
    //cout<<pos<<endl;

    node->rchild=createTreePost(postOrder,inOrder,pos+1,end);
    node->lchild=createTreePost(postOrder,inOrder,start,pos-1);

    return node;
    
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
    int preOrder[]={1,2,4,5,3};
    int inOrder[]={4,2,5,1,3};
    int postOrder[]={4,5,2,3,1};

    unordered_map <int,int> inOrderMap;

    for(int i=0;i<5;i++)
    {
        inOrderMap[inOrder[i]]=i;
    }

    //struct treeNode *root=createTreePre(preOrder,inOrder,0,4);
    //struct treeNode *root=createTreePost(postOrder,inOrder,0,4);
    struct treeNode *root=createTreePreMap(preOrder,inOrder,0,4,inOrderMap);
    inOrderDisplay(root);
}