#include<iostream>
#include<string.h>

using namespace std;

class Student
{
	private:
	int roll_no;
	Student* next;
	Student* previous;

	public:
	void setRoll(int);
	void setnext();
	void setnext(Student*);
	void setprevious();
	void setprevious(Student*);

	int getRoll();
	Student* getnext();
	Student* getprevious();
};

void Student :: setRoll(int r)
{
	roll_no=r;
}

void Student :: setnext()
{
	next=new Student;
}

void Student :: setnext(Student* n)
{
	next=n;
}

void Student :: setprevious()
{
	previous=new Student;
}

void Student :: setprevious(Student* p)
{
	previous=p;
}

int Student :: getRoll()
{
	return roll_no;
}

Student* Student :: getnext()
{
	return next;
}

Student* Student :: getprevious()
{
	return previous;
}

class DBLLButVanilla
{
	public:
	int count=0;

	Student* start=NULL;;
	Student* temp;
	Student* ptr;

	void createSet();
	void createSet(DBLLButVanilla);
	void displaySet();
	void eitherSet(DBLLButVanilla,DBLLButVanilla);
	void bothSet(DBLLButVanilla,DBLLButVanilla);
	void onlySet(DBLLButVanilla,DBLLButVanilla);
	void neitherSet(DBLLButVanilla,DBLLButVanilla,DBLLButVanilla);
};

void DBLLButVanilla :: createSet()
{
	int op=0,roll=0;

	cout<<"\nDo You Want To Add A Member ? \n1 : Yes\n0 : No\n";
	cin>>op;

	if(op==1)
	{
		start=new Student;
		count++;
		start->setprevious(NULL);

		temp=start;
		ptr=start;

		cout<<"\nEnter The Roll Number Of The Student : \n";
		cin>>roll;
		temp->setRoll(roll);

		cout<<"\nDo You Want To Add Another Member ? \n1 : Yes\n0 : No\n";
		cin>>op;

		while(op==1)
		{
			temp->setnext();
			temp=temp->getnext();
			temp->setprevious(ptr);

			cout<<"\nEnter The Roll Number Of The Student : \n";
			cin>>roll;
			temp->setRoll(roll);

			ptr=temp;
			count++;

			cout<<"\nDo You Want To Add Another Member ? \n1 : Yes\n0 : No\n";
			cin>>op;
		}

		temp->setnext(NULL);
	}
}

void DBLLButVanilla :: createSet(DBLLButVanilla m)
{
	if(m.start!=NULL)
	{
		int op=0,roll=0;

		cout<<"\nDo You Want To Add A Member ? \n1 : Yes\n0 : No\n";
		cin>>op;

		if(op==1)
		{
			start=new Student;
			temp=start;
			ptr=start;

			while(op==1)
			{
				int check=0;

				cout<<"\nEnter The Roll Number Of The Student : \n";
				cin>>roll;

				m.temp=m.start;

				for(int i=0;i<m.count;i++)
				{
					check=0;

					if(m.temp->getRoll()==roll)
					{
						check=1;
						break;
					}
					else
					{
						m.temp=m.temp->getnext();
					}
				}

				if(check==1)
				{
					ptr=temp;
					temp->setRoll(roll);
					temp->setnext();
					temp=temp->getnext();
					temp->setprevious(ptr);
					count++;
				}
				else
				{
					cout<<"\nThis Student Does Not Belong To This Class !!!\n";
				}

				cout<<"\nDo You Want To Add Another Member ? \n1 : Yes\n0 : No\n";
				cin>>op;
			}

			ptr->setnext(NULL);
		}
	}
	else
	{
		cout<<"\nThere Are No Students In This Division !!!\n";
	}
}

void DBLLButVanilla :: displaySet()
{
	if(start==NULL)
	{
		cout<<"\nNo One Likes It !!!\n";
	}
	else
	{
		temp=start;
		ptr=start;

		while(temp->getnext()!=NULL)
		{
			cout<<"\nRoll Number Is : "<<temp->getRoll();
			temp=temp->getnext();
		}

		cout<<"\nRoll Number Is : "<<temp->getRoll();
		cout<<"\n";
	}
}

void DBLLButVanilla :: eitherSet(DBLLButVanilla v,DBLLButVanilla b)
{
	if((v.start!=NULL)&&(b.start!=NULL))
	{
		start=new Student;
		start->setprevious(NULL);
		temp=start;
		ptr=start;

		v.temp=v.start;
		b.temp=b.start;

		for(int i=0;i<v.count;i++)
		{
			ptr=temp;
			temp->setRoll(v.temp->getRoll());
			temp->setnext();
			temp=temp->getnext();
			temp->setprevious(ptr);
			v.temp=v.temp->getnext();
			count++;
		}

		for(int j=0;j<b.count;j++)
		{
			int check=0,k=0;
			v.temp=v.start;

			for(k=0;k<v.count;k++)
			{
				if(v.temp->getRoll()!=b.temp->getRoll())
				{
					check++;
				}

				v.temp=v.temp->getnext();
			}

			if(check==k)
			{
				ptr=temp;
				temp->setRoll(b.temp->getRoll());
				temp->setnext();
				temp=temp->getnext();
				temp->setprevious(ptr);
				count++;
			}

			b.temp=b.temp->getnext();
		}

		ptr->setnext(NULL);
	}
}

void DBLLButVanilla :: bothSet(DBLLButVanilla v,DBLLButVanilla b)
{
	start=new Student;
	start->setprevious(NULL);
	temp=start;
	ptr=start;

	v.temp=v.start;
	b.temp=b.start;

	for(int i=0;i<v.count;i++)
	{
		b.temp=b.start;

		for(int j=0;j<b.count;j++)
		{
			if(v.temp->getRoll()==b.temp->getRoll())
			{
				ptr=temp;
				temp->setRoll(b.temp->getRoll());
				temp->setnext();
				temp=temp->getnext();
				temp->setprevious(ptr);
				count++;
				b.temp=b.temp->getnext();
				break;
			}
			else
			{
				b.temp=b.temp->getnext();
			}
		}

		v.temp=v.temp->getnext();
	}

	ptr->setnext(NULL);
}

void DBLLButVanilla :: onlySet(DBLLButVanilla v,DBLLButVanilla b)
{
	start=new Student;
	start->setprevious(NULL);
	temp=start;
	ptr=start;

	v.temp=v.start;
	b.temp=b.start;

	for(int i=0;i<v.count;i++)
	{
		int check=0;
		b.temp=b.start;

		for(int j=0;j<b.count;j++)
		{
			if(v.temp->getRoll()!=b.temp->getRoll())
			{
				check++;
			}

			b.temp=b.temp->getnext();
		}

		if(check==b.count)
		{
			ptr=temp;
			temp->setRoll(v.temp->getRoll());
			temp->setnext();
			temp=temp->getnext();
			temp->setprevious(ptr);
			count++;
			v.temp=v.temp->getnext();
		}
		else
		{
			v.temp=v.temp->getnext();
		}
	}

	ptr->setnext(NULL);
}

void DBLLButVanilla :: neitherSet(DBLLButVanilla v,DBLLButVanilla b,DBLLButVanilla m)
{
	if((v.start!=NULL)&&(b.start!=NULL))
	{
		start=new Student;
		start->setprevious(NULL);
		temp=start;
		ptr=start;

		m.temp=m.start;

		for(int i=0;i<m.count;i++)
		{
			int check=0;
			v.temp=v.start;
			b.temp=b.start;

			for(int j=0;j<v.count;j++)
			{
				if(m.temp->getRoll()!=v.temp->getRoll())
				{
					check++;
					v.temp=v.temp->getnext();
				}
				else
				{
					v.temp=v.temp->getnext();
				}
			}

			for(int j=0;j<b.count;j++)
			{
				if(m.temp->getRoll()!=b.temp->getRoll())
				{
					check++;
					b.temp=b.temp->getnext();
				}
				else
				{
					b.temp=b.temp->getnext();
				}
			}

			if(check==(v.count+b.count))
			{
				ptr=temp;
				temp->setRoll(m.temp->getRoll());
				temp->setnext();
				temp=temp->getnext();
				temp->setprevious(ptr);
				count++;
				m.temp=m.temp->getnext();
			}
			else
			{
				m.temp=m.temp->getnext();
			}
		}

		ptr->setnext(NULL);

	}
}

int main()
{
	DBLLButVanilla Div,But,Van,either,both,onlyvan,onlybut,neither;
	int op1=1,op2=1;

	do
	{
		cout<<"\nEnter The Entire Division : \n";
		Div.createSet();

		cout<<"\nEnter The Information Of Students Who Like Vanilla Ice Cream : \n";
		Van.createSet(Div);

		cout<<"\nEnter The Information Of Students Who Like Butterscotch Ice Cream : \n";
		But.createSet(Div);

		do
		{
			cout<<"\nWhich Operation Do You Want To Perform ? \n1 : Display Original Sets\n2 : Get Students Who Like Either Vanilla Or ButterScotch\n"
					"3 : Get Students Who Like Both Vanilla And Butterscotch\n4 : Get Students Who Like Only Vanilla\n5 : Get Students Who Like Only "
					"Butterscotch\n6 : Get Students Who Like Neither Vanilla Nor Butterscotch\n7 : Enter Different Sets\n8 : Exit\n";
			cin>>op2;

			switch(op2)
			{
				case 1:
				cout<<"\nEntire Division Is : \n";
				Div.displaySet();
				cout<<"\nOriginal Set Of Students Who Like Vanilla Ice Cream Is : \n";
				Van.displaySet();
				cout<<"\nOriginal Set Of Students Who Like Butterscotch Ice Cream Is : \n";
				But.displaySet();
				break;

				case 2:
				cout<<"\nStudents Who Like Either Vanilla Or Butterscotch Ice Cream Are : \n";
				either.eitherSet(Van,But);
				either.displaySet();
				break;

				case 3:
				cout<<"\nStudents Who Like Both Vanilla And Butterscotch Ice Cream Are : \n";
				both.bothSet(Van,But);
				both.displaySet();
				break;

				case 4:
				cout<<"\nStudents Who Like Only Vanilla Ice Cream Are : \n";
				onlyvan.onlySet(Van,But);
				onlyvan.displaySet();
				break;

				case 5:
				cout<<"\nStudents Who Like Only Butterscotch Ice Cream Are : \n";
				onlybut.onlySet(But,Van);
				onlybut.displaySet();
				break;

				case 6:
				cout<<"\nStudents Who Like Neither Vanilla Nor Butterscotch Ice Cream Are : \n";
				neither.neitherSet(Van,But,Div);
				neither.displaySet();
				break;

				case 7:
				op2=8;
				break;

				case 8:
				cout<<"\nThank You For Using The Program !!!\n";
				op1=0;
				break;
			}

		}while(op2!=8);
	}while(op1!=0);

	return 0;

}
