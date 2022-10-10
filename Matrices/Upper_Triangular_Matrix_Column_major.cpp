#include<iostream>
using namespace std;

class UpperTriangular
{
    private:
        int *A;
        int n;
    public:
        UpperTriangular()
        {
            n=2;
            A=new int[3];
        }
        UpperTriangular(int n)
        {
            this->n=n;
            int sum=(n*(n+1))/2;
            A=new int[sum];
        }
        int index(int i,int j)
        {
            return ((j*(j-1))/2)+i-1;
        }
        void Set(int i,int j,int x)
        {
            if(i<=j)
            {
                A[index(i,j)]=x;
            }
        }
        int Get(int i,int j)
        {
            if(i<=j)
            {
                return A[index(i,j)];
            }
            return 0;
        }
        void Display()
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i<=j)
                    {
                        cout<<A[index(i,j)]<<" ";
                    }
                    else
                    {
                        cout<<0<<" ";
                    }
                }
                cout<<endl;
            }
        }
        ~UpperTriangular()
        {
            delete []A;
        }
};

int main()
{
    UpperTriangular d(3);
    d.Set(1,1,1);
    d.Set(2,2,2);
    d.Set(2,3,3);
    d.Set(3,3,4);
    d.Set(1,2,5);
    d.Set(1,3,6);
    d.Display();
    cout<<d.Get(3,3)<<endl;
    cout<<d.Get(1,3)<<endl;
    return 0;
}