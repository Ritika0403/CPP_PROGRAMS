#include<iostream>
using namespace std;

class metres;
class distances
{
	int  inch;
	float feet;
	public:
		friend class metres;
		distances()
		{
			inch=0;
			feet=0.0;
		}
		distances(int x)
		{
			inch=x;
		}
		distances(float y)
		{
			feet=y;
		}
		distances(int x,float y)
		{
			inch=x;
			feet=y;
		}
		distances( distances &ob)
		{
			feet=ob.feet;
			cout<<"Fired"<<" ";
			inch=ob.inch;
		}
		friend istream& operator>>(istream& in,distances& ob);
		friend ostream& operator<<(ostream& out,distances& ob);
		distances operator+(distances ob)
		{
			distances res;
			res.inch=inch+ob.inch;
			res.feet=feet+ob.feet;	
			return res;
		}
		
		friend void operator>(distances ob,metres ob1);
					
		operator metres();
			
};

istream& operator>>(istream& in,distances& ob)
{
	in>>ob.feet;
	in>>ob.inch;
	return in;
}

ostream& operator<<(ostream& out,distances& ob)
{
	out<<ob.feet;
	out<<"\n";
	out<<ob.inch;
	out<<"\n";
	return out;
}



class metres
{
	float m,cm;
	public:
		friend class distances;
		metres()
		{
		}
		metres(float x)
		{
			m=x;

		}	
		metres(int x,int y)
		{
			m=x;
			cm=y;
		}
		metres(const metres&  ob)
		{
			m=ob.m;
			cm=ob.cm;
		}
		void display()
		{
			cout<<"Metre"<<m;
		}
		friend istream& operator>>(istream& in ,metres& ob);
		friend ostream& operator<<(ostream& out,metres& ob);
		friend void operator>(distances ob,metres ob1);
};

 istream& operator>>(istream& in ,metres& ob)
{
	in>>ob.m;
	in>>ob.cm;
	return in;
}
 ostream& operator<<(ostream& out ,metres& ob)
{
	out<<ob.m;
	out<<"\n";
	out<<ob.cm;
	out<<"\n";
	return out;
}
void operator>(distances ob,metres ob1)
{
	 float r=ob.feet+(ob.inch/12);
	float x=r*0.305;
	float y=ob1.m+(ob1.cm/100);
	if(x>y)
		cout<<"feet is greater";
	else	
		cout<<"Metre is greater";
}

distances::operator metres()
{
	float r=feet+(inch/12);
	float x=r*0.305;
	//cm=inch*2.54;
	return x;
}
	

			

int main()
{
	distances a,b;
	cin>>a;
	cin>>b;
	cout<<"Output";
	cout<<a;
	cout<<b;
	distances c;
	c=a+b;
	distances d=c;
	cout<<d;
	cout<<endl;
	metres ob1=(metres) c;
	ob1.display();
	cout<<"Enter feet and inches"<<endl;
	float f;
	int i;
	cin>>f>>i;
	distances ob2;
	ob2=f;
	distances ob3;
	ob3=i;
	cout<<"result"<<endl;
	//cout<<ob2;
	cout<<ob3;
	cout<<"Enter in metre and cm"<<endl;
	metres ob;
	cin>>ob;
	c>ob;
}	
	





