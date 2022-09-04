#include<iostream>
using namespace std;

class Matrix
{
    int **m1;
    int r,c;

    public:
        Matrix();
        Matrix(int r,int c);
        void input();
        void display();
        Matrix add(Matrix temp);

};

int main()
{
    int r1,c1;
    cout<<"Enter the rows and columns of the Matrix";
    cin>>r1>>c1;

    Matrix a1(r1,c1);
    Matrix a2(r1,c1);
    Matrix res(r1,c1);

    a1.input();
    cout<<"A1 INPUT OVER"<<endl;
    a2.input();
    cout<<"A2 INPUT OVER"<<endl;
    res=a1.add(a2);
    res.display();
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

void Matrix::input()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<"Enter";
            cin>>m1[i][j];
        }
    }
}

void Matrix::display()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<m1[i][j]<<" ";
        }  
        cout<<endl;      
    }
}

Matrix Matrix::add(Matrix temp)
{
    Matrix res(this->r,this->c);
    for(int i=0; i<temp.r; i++)
    {
        for(int j=0;j<temp.c ;j++)
        {
            res.m1[i][j]=this->m1[i][j]+temp.m1[i][j];
        }
    }
    return res;
}

