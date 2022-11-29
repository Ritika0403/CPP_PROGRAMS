#include <iostream>
using namespace std;

class fraction
{
    private:
    int n,d;
    fraction reduce()
    {
        int gcd=0;
        fraction temp;
        for(int i=1;i<=n;i++)
            {
                if(n%i==0 && d%i==0)
                    gcd=i;
            }
            temp.n=n/gcd;
            temp.d=d/gcd;
            return temp;
    }
    
    
    public:
        fraction()
        {
            n=0;
            d=0;
        }
        void input()
        {
            cout<<"Enter ";
            cin>>n>>d;
        }
        fraction operator+(fraction ob)
        {
            
           fraction temp;
           int i,x,y,gcd;
            x=(n*ob.d)+(ob.n*d);
            y=d*ob.d;
            temp.n=x;
            temp.d=y;
            temp=temp.reduce();
            return temp;
        }
        
        fraction operator-(fraction ob)
        {
           fraction temp;
           int i,x,y,gcd;
            x=(n*ob.d)-(ob.n*d);
            y=d*ob.d;
           for(i=1;i<=x;i++)
            {
                if(x%i==0 && y%i==0)
                    gcd=i;
            }
            temp.n=x/gcd;
            temp.d=y/gcd;
            return temp;
        }
        
        fraction operator*(fraction ob)
        {
           fraction temp;
           int i,x,y,gcd;
            x=n*ob.n;
            y=d*ob.d;
           for(i=1;i<=x;i++)
            {
                if(x%i==0 && y%i==0)
                    gcd=i;
            }
            temp.n=x/gcd;
            temp.d=y/gcd;
            return temp;
        }
        
        
        void display()
        {
            cout<<n<<"/"<<d<<endl;
        }
};


int main()
{
    fraction a,b;
    a.input();
    b.input();
    
    fraction c=a+b;
   
    c.display();
    fraction d=a-b;
    d.display();
    fraction e=a*b;
    e.display();
    
}
