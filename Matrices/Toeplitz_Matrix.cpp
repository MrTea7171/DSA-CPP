#include<iostream>
using namespace std;

class Toeplitz
{
    private:
        int *A;
        int n;
    public:
        Toeplitz()
        {
            n=2;
            A=new int[2];
        }
        Toeplitz(int n)
        {
            this->n=n;
            A=new int[n];
        }
        int index(int i, int j)
        {
            if(i<=j)
            {
                return j-i;
            }
            else
            {
                return n-1+i-j;
            }
        }
        void Set(int i,int j,int x)
        {
            A[index(i,j)]=x;
        }
        int Get(int i,int j)
        {
            return A[index(i,j)];
        }
        void Display()
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    cout<<A[index(i,j)]<<" ";
                }
                cout<<endl;
            }
        }
        ~Toeplitz()
        {
            delete []A;
        }
};

int main()
{
    Toeplitz d(4);
    d.Set(1,1,1);
    d.Set(1,2,2);
    d.Set(1,3,3);
    d.Set(1,4,4);
    d.Set(2,1,5);
    d.Set(3,1,6);
    d.Set(4,1,7);
    d.Display();
    cout<<d.Get(1,1)<<endl;
    cout<<d.Get(2,3)<<endl;
    return 0;
}