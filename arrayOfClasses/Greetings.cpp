#include<iostream>

using namespace std;

class Student
{
	public:
	int prn;
	int dd;
	int mm;

	public:
	void setStudentInfo();
	void displayStudentInfo();
	void swapStudent(Student&);
};

void Student :: setStudentInfo()
{
	int p,d,m;

	cout<<"\nEnter The PRN No. Of The Student : \n";
	cin>>p;
	this->prn=p;

	cout<<"\nEnter The Date Of Birth (dd) Of The Student : \n";
	cin>>d;
	this->dd=d;

	cout<<"\nEnter The Month Of Birth (mm) Of The Student : \n";
	cin>>m;
	this->mm=m;
}

void Student :: displayStudentInfo()
{
	cout<<"\nThe PRN No. Of The Student Is : \n";
	cout<<prn;

	cout<<"\nThe Date Of Birth (dd) Of The Student Is : \n";
	cout<<dd;

	cout<<"\nThe Month Of Birth (mm) Of The Student : \n";
	cout<<mm;

	cout<<"\n";
}

void Student :: swapStudent(Student &s)
{
	int tprn,tdd,tmm;

	tprn=prn;
	tdd=dd;
	tmm=mm;

	prn=s.prn;
	dd=s.dd;
	mm=s.mm;

	s.prn=tprn;
	s.dd=tdd;
	s.mm=tmm;
}

class Division
{
	private:
	Student* d;

	public:
	int n=0,ifsort=0,ifmerge=0;
	void getno();
	void getno(int);
	void setDivision();
	void displayDivision();
	void sortDivision();
	void mergeDivision(Division,Division);
	void greet();
};

void Division :: getno()
{
	cout<<"\nEnter The Number Of Students In The Division : \n";
	cin>>n;
	d=new Student[n];
}

void Division :: getno(int no)
{
	d=new Student[no];
}

void Division :: setDivision()
{
	for(int i=0;i<n;i++)
	{
		d[i].setStudentInfo();
	}
}

void Division :: displayDivision()
{
	cout<<"\nThe Division's Information Is : \n";

	for(int i=0;i<n;i++)
	{
		d[i].displayStudentInfo();
	}

	cout<<"\n";
}

void Division :: sortDivision()
{
	ifsort=1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d[j].mm>d[j+1].mm)
			{
				d[i].swapStudent(d[j]);
			}
			else if(d[j].mm==d[j+1].mm)
			{
				if(d[j].dd>d[j+1].dd)
				{
					d[j].swapStudent(d[j+1]);
				}
			}
		}
	}

	cout<<"\nThe Sorted Division Is : \n";
	this->displayDivision();
}

void Division :: mergeDivision(Division d1,Division d2)
{
	ifmerge=1;

	this->n=d1.n+d2.n;
	this->getno(n);

	int i=0;
	int first=0;
	int second=0;

	while((first<d1.n)&&(second<d2.n))
	{
		if(d1.d[first].mm<d2.d[second].mm)
		{
			d[i].prn=d1.d[first].prn;
			d[i].mm=d1.d[first].mm;
			d[i].dd=d1.d[first].dd;
			i++;
			first++;
		}
		else if(d1.d[first].mm==d2.d[second].mm)
		{
			if(d1.d[first].dd<d2.d[second].dd)
			{
				d[i].prn=d1.d[first].prn;
				d[i].mm=d1.d[first].mm;
				d[i].dd=d1.d[first].dd;
				i++;
				first++;
			}
			else if(d1.d[first].dd==d2.d[second].dd)
			{
				d[i].prn=d1.d[first].prn;
				d[i].mm=d1.d[first].mm;
				d[i].dd=d1.d[first].dd;
				i++;
				first++;
			}
			else if(d1.d[first].dd>d2.d[second].dd)
			{
				d[i].prn=d2.d[second].prn;
				d[i].mm=d2.d[second].mm;
				d[i].dd=d2.d[second].dd;
				i++;
				second++;
			}
		}
		else if(d1.d[first].mm>d2.d[second].mm)
		{
			d[i].prn=d2.d[second].prn;
			d[i].mm=d2.d[second].mm;
			d[i].dd=d2.d[second].dd;
			i++;
			second++;
		}
	}

	if(first!=(d1.n))
	{
		for(int j=first;j<d1.n;j++)
		{
			d[i].prn=d1.d[first].prn;
			d[i].mm=d1.d[first].mm;
			d[i].dd=d1.d[first].dd;
			i++;
			first++;
		}
	}

	if(second!=(d2.n))
	{
		for(int j=second;j<d2.n;j++)
		{
			d[i].prn=d2.d[second].prn;
			d[i].mm=d2.d[second].mm;
			d[i].dd=d2.d[second].dd;
			i++;
			second++;
		}
	}

	cout<<"\nMerged Division Is : \n";
	this->displayDivision();
	cout<<"\n";
}

void Division :: greet()
{
	int f1,f2;
	int cnt=0;
	int m,date;

	cout<<"\nEnter Today's Date(dd) : \n";
	cin>>date;

	cout<<"\nEnter Today's Month(mm) : \n";
	cin>>m;

	if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))
	{
		if(date<25)
		{
			for(int i=0;i<n;i++)
			{
				if((d[i].mm==m)&&(d[i].dd-date<7))
				{
					cout<<"\nHappy Birthday To : \n";
					d[i].displayStudentInfo();
					cnt++;
				}
			}
		}
		else
		{
			if(m!=12)
			{
				f1=31-date;

				for(int i=0;i<n;i++)
				{
					if((d[i].mm==m)&&(d[i].dd-date>=date))
					{
						cout<<"\nHappy Birthday To : \n";
						d[i].displayStudentInfo();
						cnt++;
					}
					else if((d[i].mm==m+1)&&(d[i].dd<f1))
					{
						cout<<"\nHappy Birthday To : \n";
						d[i].displayStudentInfo();
						cnt++;
					}
				}
			}
			else
			{
				f1=31-date;
				f2=1;

				for(int i=0;i<n;i++)
				{
					if((d[i].mm==m)&&(d[i].dd-date>=date))
					{
						cout<<"\nHappy Birthday To : \n";
						d[i].displayStudentInfo();
						cnt++;
					}
					else if((d[i].mm==f2)&&(d[i].dd<f1))
					{
						cout<<"\nHappy Birthday To : \n";
						d[i].displayStudentInfo();
						cnt++;
					}
				}
			}
		}
	}
	else
	{
		if(date<24)
		{
			for(int i=0;i<n;i++)
			{
				if((d[i].mm==m)&&(d[i].dd-date<7))
				{
					cout<<"\nHappy Birthday To : \n";
					d[i].displayStudentInfo();
					cnt++;
				}
			}
		}
		else
		{
			if(m!=2)
			{
				f1=30-date;

				for(int i=0;i<n;i++)
				{
					if((d[i].mm==m)&&(d[i].dd-date>=date))
					{
						cout<<"\nHappy Birthday To : \n";
						d[i].displayStudentInfo();
						cnt++;
					}
					else if((d[i].mm==m+1)&&(d[i].dd<f1))
					{
						cout<<"\nHappy Birthday To : \n";
						d[i].displayStudentInfo();
						cnt++;
					}
				}
			}
			else
			{
				f1=28-date;

				for(int i=0;i<n;i++)
				{
					if((d[i].mm==m)&&(d[i].dd-date>=date))
					{
						cout<<"\nHappy Birthday To : \n";
						d[i].displayStudentInfo();
						cnt++;
					}
					else if((d[i].mm==m+1)&&(d[i].dd<f1))
					{
						cout<<"\nHappy Birthday To : \n";
						d[i].displayStudentInfo();
						cnt++;
					}
				}
			}
		}
	}

	if(cnt==0)
	{
		cout<<"nThere Are No Birthdays Within 7 Days !!!\n";
	}
}

int main()
{
	int n,op1=1,op2=1;
	Division d1;
	Division d2;
	Division d3;

	do
	{
		cout<<"\nEnter The Information Of Division 1 : \n";
		d1.getno();
		d1.setDivision();

		cout<<"\nEnter The Information Of Division 2 : \n";
		d2.getno();
		d2.setDivision();

		do
		{
			cout<<"\nWhich Operation Do You Want To Perform ? \n1 : Sort Division\n2 : Merge Division\n3 : Greetings\n4 : Display Divisions\n5 : Work On Different Data\n6 : Exit\n";
			cin>>op2;

			switch(op2)
			{
				case 1:
				cout<<"\nWhich Division Do You Want To Sort ? 1 OR 2 \n";
				cin>>n;
				if(n==1)
				{
					d1.sortDivision();
				}
				else if(n==2)
				{
					d2.sortDivision();
				}
				break;

				case 2:
				if((d1.ifsort==1)&&(d2.ifsort==1))
				{
					d3.mergeDivision(d1,d2);
				}
				else
				{
					cout<<"\nPlease Sort Both The Divisions First !!!\n";
				}
				break;

				case 3:
				if(d3.ifmerge==1)
				{
					d3.greet();
				}
				else
				{
					cout<<"\nPlease Merge The Divisions First !!!\n";
				}
				break;

				case 4:
				cout<<"\nWhich Division Do You Want To Display ? 1 OR 2 \n";
				cin>>n;
				if(n==1)
				{
					d1.displayDivision();
				}
				else if(n==2)
				{
					d2.displayDivision();
				}
				break;

				case 5:
				cout<<"\nNow, You Will Be Taken To The New Data Of The Divisions !!!\n";
				break;

				case 6:
				op1=6;
				cout<<"\nThank You For Using The Program !!!\n";
				break;
			}
		}while((op2!=5)&&(op2!=6));
	}while(op1!=6);
}
