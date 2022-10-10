#include<iostream>
using namespace std;

//Array Defination
struct Array
{
    int arr[10];
    int size;
    int lenght;
};

//Array Display
void Display(const struct Array *A)
{
    cout<<"Elements in array are: "<<endl;
    for(int i=0;i<A->lenght;i++)
    {
        cout<<A->arr[i]<<" ";
    }
    cout<<endl;
}

//Array Append
void Append(struct Array *A,int x)
{
    if(A->lenght<A->size)
    {
        A->arr[A->lenght++]=x;
    }
}

//Array Insert
void Insert(struct Array *A,int index,int x)
{
    if(A->lenght<A->size && index>=0 && index<A->lenght)
    {
       for(int i=A->lenght;i>index;i--)
       {
            A->arr[i]=A->arr[i-1];
       }
       A->arr[index]=x;
       A->lenght++;
    }
}

//Array Delete
void Delete(struct Array *A,int index)
{
    if(A->lenght<A->size && index>=0 && index<=A->lenght)
    {
       for(int i=index;i<A->lenght-1;i++)
       {
            A->arr[i]=A->arr[i+1];
       }
       A->lenght--;
    }
}

int lSearch(struct Array *A,int key)
{
    for(int i=0;i<A->lenght;i++)
    {
        if(A->arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}

/*
    
//Non Recursive
int bSearch(struct Array *A,int low,int high,int x)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(A->arr[mid]==x)
        {
            return mid;
        }
        else if(A->arr[mid]<x)
        {
            low=mid+1;;
        }
        else if(A->arr[mid]>x)
        {
            high=mid-1;;
        }

    }
    return -1;
}
*/

int bSearch(struct Array *A,int low,int high,int x)
{
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(A->arr[mid]==x)
        {
            return mid;
        }
        else if(A->arr[mid]<x)
        {
            return bSearch(A,mid+1,high,x);
        }
        else if(A->arr[mid]>x)
        {
            return bSearch(A,low,mid-1,x);
        }

    }
    return -1;
}

void Reverse(struct Array *A)
{
    int B[A->lenght];
    for(int i=0,j=A->lenght-1;j>=0;j--,i++)
    {
        B[i]=A->arr[j];
    }
    for(int i=0;i<A->lenght;i++)
    {
        A->arr[i]=B[i];
    }
}

void Reverse2(struct Array *A)
{
    for(int i=0,j=A->lenght-1;i<j;j--,i++)
    {
        int temp=A->arr[i];
        A->arr[i]=A->arr[j];
        A->arr[j]=temp;
    }
}

int main()
{
    struct Array A1={{5,10,15,20,25},10,5};
    Append(&A1,30);
    Insert(&A1,2,12);
    Display(&A1);
    Delete(&A1,6);
    Display(&A1);
    cout<<lSearch(&A1,25)<<endl;
    cout<<lSearch(&A1,30)<<endl;
    cout<<bSearch(&A1,0,A1.lenght-1,25)<<endl;
    cout<<bSearch(&A1,0,A1.lenght-1,30)<<endl;
    Reverse2(&A1);
    Display(&A1);
    return 0;
}