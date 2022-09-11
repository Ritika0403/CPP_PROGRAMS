#include<iostream>
using namespace std;

class Array
{
    int* arr;
    int size;

    public:
        Array();
        Array(int size);
        Array operator+(Array temp);
        Array operator-(Array temp);
        Array operator*(Array temp);
        friend ostream& operator<<(ostream& out,const Array& ob);
        friend istream& operator>>(istream& in, const Array& ob);

};

int main()
{
    int size1;
    cout<<"Enter the size of the array";
    cin>>size1;

    Array a1(size1);
    Array a2(size1);
    Array res(size1);
    Array res1(size1);
    Array res2(size1);
    

    cin>>a1;
    cout<<"A1 INPUT OVER"<<endl;
    cin>>a2;
     cout<<"A2 INPUT OVER"<<endl;
    res=a1+a2;
    cout<<"After addition"<<endl;
    cout<<res;
    res1=a1-a2;
    cout<<"After substraction"<<endl;
    cout<<res1;
    res2=a1*a2;
    cout<<"After multiplication"<<endl;
    cout<<res2;
    return 0;
}

Array::Array()
{
    size=5;
    arr=new int[size];
}

Array::Array (int size)
{
    arr=new int [size];
    this->size=size;
}

istream& operator>>(istream& in,const Array& ob)
{
   
    for(int i=0;i<ob.size;i++)
    {
        in>>ob.arr[i];
    }
    return in;
}


ostream& operator<<(ostream& out,const Array& ob)
{
    out<<"The elements are:"<<endl;
    for(int i=0;i<ob.size;i++)
    {
        out<<ob.arr[i]<<" ";
    }
    return out;
}


Array Array::operator+(Array temp)
{
    Array res(this->size);
    for(int i=0; i<temp.size; i++)
    {
        res.arr[i]=this->arr[i]+temp.arr[i];
    }
    return res;
}

Array Array::operator-(Array temp)
{
    Array res1(this->size);
    for(int i=0; i<temp.size; i++)
    {
        res1.arr[i]=this->arr[i]-temp.arr[i];
    }
    return res1;
}


Array Array::operator*(Array temp)
{
    Array res2(this->size);
    for(int i=0; i<temp.size; i++)
    {
        res2.arr[i]=this->arr[i]*temp.arr[i];
    }
    return res2;
}

