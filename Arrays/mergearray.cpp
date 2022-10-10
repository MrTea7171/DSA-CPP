#include<iostream>
using namespace std;

//Array Defination
struct Array
{
    int arr[20];
    int size;
    int lenght;
};

struct Array* Merge(struct Array* A,struct Array* B)
{
    struct Array *C;
    int i,j,k;
    i=j=k=0;
    while(i<A->lenght && j<B->lenght)
    {
        if(A->arr[i]<=B->arr[j])
        {
            C->arr[k++]=A->arr[i++];
        }
        else
        {
            C->arr[k++]=B->arr[j++];
        }
    }
    while(i<A->lenght)
    {
        C->arr[k++]=A->arr[i++];
    }

    while(j<B->lenght)
    {
        C->arr[k++]=B->arr[j++];
    }

    C->lenght=A->lenght+B->lenght;
    return C;
}

struct Array* Union(struct Array* A,struct Array* B)
{
    struct Array *C;
    int i,j,k;
    i=j=k=0;
    while(i<A->lenght && j<B->lenght)
    {
        if(A->arr[i]<B->arr[j])
        {
            C->arr[k++]=A->arr[i++];
        }
        else if(A->arr[i]==B->arr[j])
        {
            C->arr[k++]=A->arr[i++];
            j++;
        }
        else
        {
            C->arr[k++]=B->arr[j++];
        }
    }
    while(i<A->lenght)
    {
        C->arr[k++]=A->arr[i++];
    }

    while(j<B->lenght)
    {
        C->arr[k++]=B->arr[j++];
    }

    C->lenght=k;
    return C;
}

struct Array* Intersection(struct Array* A,struct Array* B)
{
    struct Array *C;
    int i,j,k;
    i=j=k=0;
    while(i<A->lenght && j<B->lenght)
    {
        if(A->arr[i]==B->arr[j])
        {
            C->arr[k++]=A->arr[i++];
            j++;
        }
        else if(A->arr[i]<B->arr[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    C->lenght=k;
    return C;
}

struct Array* Differance(struct Array* A,struct Array* B)
{
    struct Array *C;
    int i,j,k;
    i=j=k=0;
    while(i<A->lenght && j<B->lenght)
    {
        if(A->arr[i]<B->arr[j])
        {
            C->arr[k++]=A->arr[i++];
        }
        else if(A->arr[i]==B->arr[j])
        {
            i++;
            j++;
        }
        else
        {
            C->arr[k++]=B->arr[j++];
        }
    }
    while(i<A->lenght)
    {
        C->arr[k++]=A->arr[i++];
    }

    while(j<B->lenght)
    {
        C->arr[k++]=B->arr[j++];
    }

    C->lenght=k;
    return C;
}

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
int main()
{
    struct Array A1={{5,10,15,20,25},10,5};
    struct Array B1={{3,5,7,10,12,15},10,6};
    struct Array *C1=Differance(&A1,&B1);
    Display(C1);
    return 0;
}