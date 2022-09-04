#include<iostream>
using namespace std;

class Array
{
    int  *arr;
    int size;

    public:
        Array();
        Array(int size);
        void input();
        void display();
        Array add(Array temp);

};

int main()
{
    int size1;
    cout<<"Enter the size of the array";
    cin>>size1;

    Array a1(size1);
    Array a2(size1);
    Array res(size1);

    a1.input();
    cout<<"A1 INPUT OVER"<<endl;
    a2.input();
    cout<<"A2 INPUT OVER"<<endl;
    res=a1.add(a2);
    res.display();
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

void Array::input()
{
    for(int i=0;i<5;i++)
    {
        cout<<"Enter";
        cin>>arr[i];
    }
}

void Array::display()
{
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
        
    }
}

Array Array::add(Array temp)
{
    Array res(this->size);
    for(int i=0; i<temp.size; i++)
    {
        res.arr[i]=this->arr[i]+temp.arr[i];
    }
    return res;
}
