#include<iostream>
#include<math.h>
using namespace std;
class Line;
class Triangle;
class Vertex
{
    float x,y;
    public:
        Vertex();
        Vertex(int,int);
        friend class Line;
        friend class Triangle;
};
class Line
{
    Vertex A,B;
    public:
        Line();
        friend class Vertex;
        void input();
        void display();
        void distances();
        void slope();
};
class Triangle
{
    Vertex a,b,c;
    public:
        friend class Vertex;
        Triangle();
        void input();
        void findarea();
};
Vertex::Vertex()
{
    x = 0;
    y = 0;
}
Vertex::Vertex(int a, int b)
{
    x = a;
    y = b;
}
Line::Line()
{
    A.x = 0;
    A.y = 0;
    B.x = 0;
    B.y = 0;
}
void Line:: input()
{
    cout<<"Enter the x and y coordinates of starting point"<<endl;
    cin>>A.x>>A.y;
    cout<<"Enter the x and y coordinates of ending point"<<endl;
    cin>>B.x>>B.y;
}
void Line::display()
{
    cout<<"Starting point"<<endl;
    cout<<"X coordinate is: "<<A.x<<" & Y coordinate is: "<<A.y<<endl;
    cout<<"Ending point"<<endl;
    cout<<"X coordinate is: "<<B.x<<" & Y coordinate is: "<<B.y<<endl;
}
void Line:: distances()
{
    float dis;
    //dis = sqrt(((A.x-B.x)(A.x-B.x))+((A.y-B.y)(A.y-B.y)));
    cout<<"The distance is: "<<dis<<endl;
}
void Line::slope()
{
    float y;
    y = (B.y-A.y)/(B.x-A.x);
    cout<<"The slope of the line is: "<<y<<endl;
}
Triangle::Triangle()
{
    a.x = 0,a.y = 0,b.x = 0,b.y = 0,c.x = 0,c.y = 0;
}
void Triangle::input()
{
cout<<"Enter the first vertex"<<endl;
    cin>>a.x>>a.y;
    cout<<"Enter the second vertex"<<endl;
    cin>>b.x>>b.y;
    cout<<"Enter the third vertex"<<endl;
    cin>>c.x>>c.y;
}
void Triangle::findarea()
{
    float area;
    area = ((a.x*(b.y-c.y))+(b.x*(c.y-a.y))+(c.x*(a.y-b.y)))/2;
    cout<<"Area is : "<<area<<endl;
}
int main()
{
    Line ob;
    ob.input();
    ob.slope();
    ob.distances();
    ob.display();
    Triangle ob1;
    ob1.input();
    ob1.findarea();

   return 0;
}