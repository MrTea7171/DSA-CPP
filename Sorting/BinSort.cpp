#include<bits/stdc++.h>
using namespace std;

struct node{
    int value;
    struct node* next;
};

int main()
{
    //Make Array get Largest
    int arr[]={6,8,3,10,15,6,9,12,6,3};
    int maxValue=*max_element(arr,arr+9);

    //Make Bins and Initialize
    struct node** bins= new node*[maxValue];

    for(int i=0;i<maxValue;i++)
    {
        bins[i]=NULL;
    }

    //Sort in Bins
    for(int i=0;i<10;i++)
    {
        struct node* newData= new node;
        newData->value=arr[i];
        newData->next=NULL;

        if(!bins[arr[i]])
        {
            bins[arr[i]]=newData;
        }
        else
        {
            struct node* lastData=bins[arr[i]];
            while(lastData->next)
            {
                lastData=lastData->next;
            }
            lastData->next=newData;
        }
        
    }

    //Collect from Bins
    int j=0;
    for(int i=0;i<maxValue;i++)
    {
        if(bins[i])
        {
            struct node* lastData=bins[i];
            while(lastData)
            {
                arr[j++]=lastData->value;
                struct node* temp=lastData;
                lastData=lastData->next;
                delete temp;
            }
        }
    }

    //Display final Array
    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}