#include<iostream>

using namespace std;

class Search
{
	private:
	int* students;
	int no;

	public:
	void getnostudents();
	void setstudents();
	void linearsearch(int);
	void sentinelsearch(int);
	void binarysearch(int);
	void displayallstudents();
};

void Search :: getnostudents()
{
	cout<<"\nEnter The Total Number Of Students Who Attended The Training Program : \n";
	cin>>no;

	students=new int[no];
}

void Search :: setstudents()
{
	for(int i=0;i<no;i++)
	{
		cout<<"\nEnter Roll Number Of The Student : \n";
		cin>>students[i];
	}
}

void Search :: linearsearch(int v)
{
	int i=0;

	while((students[i]!=v)&&(i<no))
	{
		i++;
	}

	if(students[i]==v)
	{
		cout<<"\nRoll Number "<<v<<" Attended The Training Program !!!\n";
		cout<<"Position Is : "<<i+1<<"\n";
	}
	else
	{
		cout<<"\nRoll Number "<<v<<" Did Not Attend The Training Program !!!\n";
	}
}

void Search :: sentinelsearch(int v)
{
	int l=students[no-1];
	students[no-1]=v;

	int i=0;

	if(l==v)
	{
		cout<<"\nRoll Number "<<v<<" Attended The Training Program !!!\n";
		cout<<"Position Is : "<<no<<"\n";
	}
	else
	{
		while(students[i]!=v)
		{
			i++;
		}

		if(i<no-1)
		{
			cout<<"\nRoll Number "<<v<<" Attended The Training Program !!!\n";
			cout<<"Position Is : "<<i+1<<"\n";
		}
		else
		{
			cout<<"\nRoll Number "<<v<<" Did Not Attend The Training Program !!!\n";
		}
	}
}

void Search :: binarysearch(int v)
{
	int start=0;
	int end=no;

	if(students[(no-1)/2]>v)
	{
		end=(no-1)/2;

		int i=start;

		while((students[i]!=v)&&(i<end))
		{
			i++;
		}

		if(students[i]==v)
		{
			cout<<"\nRoll Number "<<v<<" Attended The Training Program !!!\n";
			cout<<"Position Is : "<<i+1<<"\n";
		}
		else
		{
			cout<<"\nRoll Number "<<v<<" Did Not Attend The Training Program !!!\n";
		}
	}
	else if(students[(no-1)/2]<v)
	{
		start=((no-1)/2)+1;

		int i=start;

		while((students[i]!=v)&&(i<end))
		{
			i++;
		}

		if(students[i]==v)
		{
			cout<<"\nRoll Number "<<v<<" Attended The Training Program !!!\n";
			cout<<"Position Is : "<<i+1<<"\n";
		}
		else
		{
			cout<<"\nRoll Number "<<v<<" Did Not Attend The Training Program !!!\n";
		}
	}
	else if(students[(no-1)/2]==v)
	{
		cout<<"\nRoll Number "<<v<<" Attended The Training Program !!!\n";
		cout<<"Position Is : "<<((no-1)/2)+1<<"\n";
	}
}

void Search ::displayallstudents()
{
	cout<<"\nThe Students Of The Class Are : \n";
	for(int i=0;i<no;i++)
	{
		cout<<"\nRoll Number : "<<students[i]<<"\n";
	}
}

int main()
{
	int op1=1,op2=0,val=0;
	Search s;

	do
	{
		cout<<"\nEnter The Data Of Students Of The Class : \n(Note : If You Want To Perform Binary Search, Enter Data In Ascending Form)\n";
		s.getnostudents();
		s.setstudents();

		do
		{
			cout<<"\nEnter The Roll Number Of The Student You Want To Search ?\n";
			cin>>val;

			cout<<"\nWhich Type Of Search Do You Want To Perform ?\n1 : Linear Search\n2 : Sentinel Search\n3 : Binary Search\n";
			cin>>op2;

			switch(op2)
			{
				case 1:
				s.linearsearch(val);
				break;

				case 2:
				s.sentinelsearch(val);
				break;

				case 3:
				s.binarysearch(val);
				break;
			}

			cout<<"\nDo You Want To Search For Another Student ?\n1 : Yes\n0 : No\n";
			cin>>op2;

			if(op2==0)
			{
				cout<<"\nDo You Want To Search For Students In A New Class ?\n1 : Yes\n0 : No\n";
				cin>>op1;
			}

			if(op1==0)
			{
				cout<<"\nThank You For Using The Program !!!\n";
			}
		}while(op2!=0);
	}while(op1!=0);

	return 0;
}
