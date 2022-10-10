#include<iostream>
using namespace std;

class polynomial;

class term
{
    public:
        int coefficient;
        int exponent;
        friend istream & operator>>(istream &in,polynomial &p);
        friend ostream & operator<<(ostream &out,const polynomial &p);
        friend polynomial operator+(polynomial &p);
};

class polynomial
{
    private:
        int elements;
        term *T;
    public:
        polynomial(int n)
        {
            elements=n;
            T=new term[elements];
        }

        polynomial operator+(polynomial &p)
        {
            polynomial psum(elements+p.elements);
            int i,j,k;
            i=j=k=0;
            while(i<elements && j<p.elements)
            {
                if(T[i].exponent<p.T[j].exponent)
                {
                    psum.T[k++]=T[i++];
                }
                else if(T[i].exponent>p.T[j].exponent)
                {
                    psum.T[k++]=p.T[j++];
                }
                else
                {
                    psum.T[k]=T[i];
                    psum.T[k++].coefficient=T[i++].coefficient+p.T[j++].coefficient;
                }
            }

            while(i<elements)
            {
                psum.T[k++]=T[i++];
            }

            while(j<p.elements)
            {
                psum.T[k++]=p.T[j++];
            }

            psum.elements=k;

            return psum;
        }
        friend istream & operator>>(istream &in,polynomial &p);
        friend ostream & operator<<(ostream &out,const polynomial &p);
        ~polynomial()
        {
            delete []T;
        }
};

istream & operator>>(istream &in,polynomial &p)
{
    cout<<"Enter coefficient and exponents: "<<endl;
    for(int i=0;i<p.elements;i++)
    {
        in>>p.T[i].coefficient;
        in>>p.T[i].exponent;
    }
    return in;
}

ostream & operator<<(ostream &out,const polynomial &p)
{
    out<<"The expression is: "<<endl;
    for(int i=p.elements-1;i>=0;i--)
    {
        out<<p.T[i].coefficient<<"x^"<<p.T[i].exponent<<" ";
        if(i!=0)
        {
            out<<"+";
        }
    }
    out<<endl;
    return out;
}

int main()
{
    polynomial p(2);
    polynomial p2(3);
    cin>>p;
    cin>>p2;
    cout<<p;
    cout<<p2;
    polynomial p3=p+p2;
    cout<<p3;
    return 0;
}