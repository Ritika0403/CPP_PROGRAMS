#include <iostream>

using namespace std;

class sparse
{
    int **a;
    int m,n;
    public:
        sparse(int m,int n)
        {
            this->m=m;
            this->n=n;
            a=new int*[m];
            for(int i=0;i<m;i++)
            {
                a[i]=new int[n];
            }
        }
        
        sparse operator+(sparse ob)
        {
           // sparse temp(ob.m,ob.n);
            for(int i=0;i<ob.m;i++)
            {
                for(int j=0;j<ob.n;j++)
                    this->a[i][j]=ob.a[j][i];
            }
            return *this;
        }
        
        void input()
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    cin>>a[i][j];
            }    
        }
        
        void display()
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    cout<<a[i][j];
                cout<<endl;    
            }
        }
        
        void check()
        {
            int size = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (a[i][j] != 0)
                        size++;
 
    
            int ar[3][size];
 
   
             int k = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (a[i][j] != 0)
                    {
                    ar[0][k] = i;
                    ar[1][k] = j;
                    ar[2][k] = a[i][j];
                    k++;
                    }
 
            for (int i=0; i<3; i++)
            {
            for (int j=0; j<size; j++)
                cout <<" "<< ar[i][j];
             cout <<"\n";
            }
        }
        
    
};

int main()
{
    int m,n;
    cout<<"Enter the size";
    cin>>m>>n;
    sparse a(m,n);
    a.input();
   
    a.check();
    
}
    
    
    
    
    
    

