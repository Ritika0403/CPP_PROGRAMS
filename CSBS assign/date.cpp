#include<iostream>
using namespace std;

class date
{
    int current_date;
    int month;
    int year;
    

        public:
            date();
            void input();
            date operator+(int days);
            date operator-(int x);
            int operator-(date );
            void display();
};

date::date()
{
    current_date = 0;
    month = 0;
    year = 0;
    
}
 
void date::input()
{
    cout<<"enter the  date in the format date month year"<<endl;
    cin>>current_date>>month>>year;
    
    
}
date date::operator+(int days)
{   
    date new_date;
    current_date = current_date+days;
    if(month ==2)
    {
        if(current_date>28)
        {
            month = month + 1;
            current_date =  current_date - 28;
        }
        else    
            current_date = current_date;
    }
    else if(month == 1||month == 3||month == 5||month == 7||month == 8||month == 10)
    {
            if(current_date>31 )
            {
                month = month +1;
                current_date =  current_date - 31;
                
            }
            else    
            current_date = current_date;

    }
    else if(month == 12)
    {
        if(current_date>31)
        {
            current_date =  current_date - 31;
            month = 1;
            year = year+1;
        }
    }
    else if(month == 4||month == 6||month == 9||month == 11)
    {
        if(current_date>30 )
            {
                month = month +1;
                current_date =  current_date - 30;
            }
            else    
            current_date = current_date;
    }
}

date date ::operator-(int x)
{
    if(current_date<x)
    {
        if(month == 2||month == 4||month == 6||month == 9||month == 11)
        {
            current_date = 31 + (current_date - x);
            month = month-1;

        }
        else if(month == 5||month == 7||month == 8||month == 10||month  == 12)
        {
            current_date = 31 + current_date - x;
        }
        else if(month ==1)
        {
            current_date = 31 + current_date  - x;
            month = 12;
            year = year-1;
        }
        else if(month  == 3)
        {
            current_date = 28 + (current_date - x);
            month = month -1;
        }
    }
    else
    {
        current_date = current_date - x;
    }
}
int date::operator-(date ob )
{
    int d,m,y;
    if(this->current_date > ob.current_date && this->month > ob.month  )
    {
        d =  current_date - ob.current_date ;
        
    }
    else if (this->current_date <=ob.current_date && (this->month -ob.month)==0)
    {
        d =  ob.current_date - current_date ;
    }
    else 
    {
        d= 30+( ob.current_date-current_date ) ;
    }
    return d;
}
void date:: display()
{
    cout<<current_date<<"/"<<month<<"/"<<year<<endl;
}
int main()
{
    // date ob;
    // ob.input();
    // cout<<"The current date is "<<endl;
    // ob.display();
    // cout<<"enter the number of days you want to add"<<endl;
    // int days; 
    // cin>>days;
    // cout<<endl;
    // cout<<"the new date is"<<endl;
    // ob.operator+(days);
    // ob.display();
    // cout<<"For substracting the days "<<endl;
    // //cout<<"enter a new date "<<endl;
    // date ob2;
    // ob2.input();
    // int x;
    // cout<<"enter the number of days you want to substract"<<endl;
    // cin>>x;
    // ob2.operator-(x);
    // cout<<"the new date is"<<endl;
    // ob2.display();
    date ob3,ob4;
    cout<<"enter the two dates for the difference"<<endl;
    ob3.input();
    ob4.input();
    int d=ob3-ob4;
    cout<<"the days gap are"<<d;
    return 0;
    
}