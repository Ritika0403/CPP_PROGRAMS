#include<iostream>
using namespace std;

class Matrix
{
    int **m1;
    int r,c;

    public:
        Matrix();
        Matrix(int r,int c);
        Matrix operator+(Matrix temp);
        Matrix operator-(Matrix temp);
        Matrix operator*(Matrix temp);
        friend ostream& operator<<(ostream& out,const Matrix& ob);
        friend istream& operator>>(istream& in, const Matrix& ob);

};

int main()
{
    int r1,c1;
    cout<<"Enter the rows and columns of the Matrix";
    cin>>r1>>c1;

    Matrix a1(r1,c1);
    Matrix a2(r1,c1);
    Matrix res(r1,c1);
    Matrix res1(r1,c1);
    Matrix res2(r1,c1);

    cin>>a1;
    cout<<"A1 INPUT OVER"<<endl;
    cin>>a2;
    cout<<"A2 INPUT OVER"<<endl;
    res=a1+(a2);
    cout<<"After addition"<<endl;
    cout<<res;
    res1=a1-a2;
    cout<<"After substraction"<<endl;
    cout<<res1;
    res2=a1*a2;
    cout<<"After Multiplication"<<endl;
    cout<<res2;
    
    return 0;
}

Matrix::Matrix()
{
    r=3;
    c=3;
   m1=new (int*);c;
    for(int i=0;i<r;i++)
    {
        m1[i]=new int[c];
    }
}

Matrix::Matrix (int r,int c)
{
    m1=new (int*);c;
    for(int i=0;i<r;i++)
    {
        m1[i]=new int[c];
    }
    this->r=r;
    this->c=c;
}

istream& operator>>(istream& in,const Matrix& ob)
{
   
    for(int i=0;i<ob.r;i++)
    {
        for(int j=0;j<ob.c;j++)
             in>>ob.m1[i][j];
    }
    return in;
}


ostream& operator<<(ostream& out,const Matrix& ob)
{
    out<<"The elements are:"<<endl;
   for(int i=0;i<ob.r;i++)
    {
        for(int j=0;j<ob.c;j++)
             out<<ob.m1[i][j]<<" ";
        out<<endl;     
    }
    return out;
}


Matrix Matrix::operator+(Matrix temp)
{
    Matrix res(this->r,this->c);
    for(int i=0;i<temp.r;i++)
    {
        for(int j=0;j<temp.c;j++)
    {
        res.m1[i][j]=this->m1[i][j]+temp.m1[i][j];
    }
    }
    return res;
}

Matrix Matrix::operator-(Matrix temp)
{
    Matrix res1(this->r,this->c);
    for(int i=0;i<temp.r;i++)
    {
        for(int j=0;j<temp.c;j++)
    {
        res1.m1[i][j]=this->m1[i][j]-temp.m1[i][j];
    }
    }
    return res1;
}


Matrix Matrix::operator*(Matrix temp)
{
    Matrix res2(this->r,this->c);
    for(int i=0;i<temp.r;i++)
    {
        for(int j=0;j<temp.c;j++)
    {
        res2.m1[i][j]=this->m1[i][j]*temp.m1[i][j];
    }
    }
    return res2;
}