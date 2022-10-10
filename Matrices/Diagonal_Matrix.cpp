#include<iostream>
using namespace std;

class Diagonal
{
    private:
        int *A;
        int n;
    public:
        Diagonal()
        {
            n=2;
            A=new int[2];
        }
        Diagonal(int n)
        {
            this->n=n;
            A=new int[n];
        }
        void Set(int i,int j,int x)
        {
            if(i==j)
            {
                A[i-1]=x;
            }
        }
        int Get(int i,int j)
        {
            if(i==j)
            {
                return A[i-1];
            }
            return 0;
        }
        void Display()
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==j)
                    {
                        cout<<A[i]<<" ";
                    }
                    else
                    {
                        cout<<0<<" ";
                    }
                }
                cout<<endl;
            }
        }
        ~Diagonal()
        {
            delete []A;
        }
};

int main()
{
    Diagonal d(5);
    d.Set(1,1,1);
    d.Set(2,2,2);
    d.Set(3,3,3);
    d.Set(4,4,4);
    d.Set(5,5,5);
    d.Display();
    cout<<d.Get(1,1)<<endl;
    cout<<d.Get(3,3)<<endl;
    return 0;
}