#include<iostream>
using namespace std;
#include "../../Stacks/Stack.h"

struct treeNode
{
    int data;
    struct treeNode *lchild,*rchild;
}*root=NULL;

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


void generateTree(int arr[],int n)
{
    int i=0;
    StackBox::Stack<struct treeNode *> st;

    struct treeNode *newNode=new treeNode;
    newNode->data=INT8_MAX;
    newNode->lchild=newNode->rchild=NULL;
    st.push(newNode);

    if(!root)
    {
        root=new treeNode;
        root->data=arr[i++];
        root->lchild=root->rchild=NULL;
    }
    struct treeNode *currentNode=root;
    while(i<n)
    {
        if(currentNode->data>arr[i])
        {
            st.push(currentNode);
            struct treeNode *newNode=new treeNode;
            newNode->data=arr[i++];
            newNode->lchild=newNode->rchild=NULL;
            currentNode->lchild=newNode;
            currentNode=newNode;
        }
        else if(currentNode->data<arr[i] && arr[i]<st.peek()->data)
        {
            struct treeNode *newNode=new treeNode;
            newNode->data=arr[i++];
            newNode->lchild=newNode->rchild=NULL;
            currentNode->rchild=newNode;
            currentNode=newNode;
        }
        else
        {
            currentNode=st.pop();
        }
    }
}

int main()
{
    //int preOrder[]={30,20,10,15,25,40,50,45};
    int preOrder[]={5,3,2,4,1,6,7,8};
    generateTree(preOrder,8);
    display();
    return 0;
}