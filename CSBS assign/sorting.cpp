#include <iostream>
using namespace std;
class Sorting
{
private:
    int *ar;
    int size;

public:
    Sorting()
    {
      
        cout << "Enter the size" << endl;
        cin >> size;
        ar = new int[size];
    }
    Sorting (Sorting &s)
    {
        size=s.size;
        ar=new int(s.size);
        for(int i=0;i<size;i++)
        {
          this->ar[i]=s.ar[i];
        }
    }
    Sorting& operator=(Sorting &ob)
    {
        size=ob.size;
        ar=new int[size];
        for(int i=0;i<size;i++)
        {
            ar[i]=ob.ar[i];
        }
        return *this;
    }
    void input()
    {
        int i;
        cout << "enter the array elements" << endl;
        for (i = 0; i < size; i++)
        {
            cin >> (ar[i]);
        }
    }
    void sort()
    {
        int i = 0,j;
        for (i = 0; i < size ; i++)
        {
            for (j = 0; j < size - 1 - i; j++)
            {
                if (ar[j] > ar[j + 1])
                {
                    int temp = ar[j];
                    ar[j] = ar[j + 1];
                    ar[j + 1] = temp;
                }
            }
        }
    }

    void display()
    {
        cout<<"The sorted array is:"<<endl;
        int i = 0;
        for (i = 0; i < size; i++)
            cout << ar[i] << endl;
    }
};
int main()
{
    Sorting s;
    s.input();
    Sorting s1;
    s1=s;//shallow copy
  
    s.sort(); 
    s.display();
    s1.display();
    return 0;
}

