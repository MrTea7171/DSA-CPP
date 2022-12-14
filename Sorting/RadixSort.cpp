#include<bits/stdc++.h>
using namespace std;

struct node{
    int value;
    struct node* next;
};

int getMaxValue(int arr[],int n)
{
    int maxValue=*max_element(arr,arr+n);
    return trunc(log10(maxValue)) + 1;
}


void insertBin(struct node* addNode,int value)
{
    while(addNode->next)
    {
        addNode=addNode->next;
    }
      
    struct node* newData=new node;
    newData->value=value;
    newData->next=NULL;
    addNode->next=newData;
}

int deleteBin(int arr[], struct node* currentNode, int index)
{
    while(currentNode)
    {
        arr[index++]=currentNode->value;
        struct node* temp=currentNode;
        currentNode=currentNode->next;
        delete temp;
    }
    return index;
}

int main()
{
    //Make Array and get max no of digits in array
    int arr[]={237,146,259,152,163,42,36,62};
    int n=8;
    int length=getMaxValue(arr,n);

    //Make Bins from 0 to 9
    struct node** bins= new node*[10];

    for(int i=0;i<10;i++)
    {
        bins[i]=NULL;
    }

    int divider=1;
    for(int i=0;i<length;i++)
    {
        // cout<<"Start Here"<<endl;
        for(int j=0;j<n;j++)
        {
            int  binIndex=(arr[j]/divider)%10;
            if(bins[binIndex])
            {
                insertBin(bins[binIndex],arr[j]);
            }
            else
            {
                struct node* newData=new node;
                newData->value=arr[j];
                newData->next=NULL;
                bins[binIndex]=newData;
            }
        }

        int index=0;
        for(int j=0;j<10;j++)
        {
            if(bins[j])
            {
                // cout<<"Delete Here"<<endl;
                index= deleteBin(arr,bins[j],index);
                bins[j]=NULL;
            }
        }
        divider*=10;
    }

    //Display final Array
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}