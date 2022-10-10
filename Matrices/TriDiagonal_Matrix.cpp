#include<iostream>
using namespace std;

class TriDiagonal
{
    private:
        int *A;
        int n;
    public:
        TriDiagonal()
        {
            n=2;
            A=new int[2];
        }
        TriDiagonal(int n)
        {
            this->n=n;
            A=new int[n];
        }
        int index(int i, int j)
        {
            return (1+j-i)*(n-1)+j-1;
        }
        void Set(int i,int j,int x)
        {
            if(abs(i-j)<=1)
            {
                A[index(i,j)]=x;
            }
        }
        int Get(int i,int j)
        {
            if(abs(i-j)<=1)
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
                    if(abs(i-j)<=1)
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
        ~TriDiagonal()
        {
            delete []A;
        }
};

int main()
{
    TriDiagonal d(4);
    d.Set(1,1,1);
    d.Set(1,2,2);
    d.Set(2,1,3);
    d.Set(2,2,4);
    d.Set(2,3,5);
    d.Set(3,2,6);
    d.Set(3,3,7);
    d.Set(3,4,8);
    d.Set(4,3,9);
    d.Set(4,4,10);
    d.Display();
    cout<<d.Get(1,1)<<endl;
    cout<<d.Get(3,3)<<endl;
    return 0;
}