#include <iostream>

using namespace std;

class Sport
{
	private:
	int no=0;
	int count=0;
	int* roll_no=NULL;

	public:
	void displayGroup();
	void setGroup();
	void onlyGroup(Sport*);
	void bothGroup(Sport*);
	void neitherGroup(Sport*,Sport*);
	void eitherGroup(Sport*,Sport*);
};

void Sport :: setGroup()
{
	cout<<"\nEnter The Total Number Of Students :\n";
	cin>>no;

	cout<<"\nEnter The Roll Numbers Of Students :\n";

	roll_no=new int[no];

	for(int i=0;i<no;i++)
	{
		cout<<"\nRoll Number : \n";
		cin>>roll_no[i];
	}
}

void Sport :: displayGroup()
{
	cout<<"\nThe Students Are :\n";
	for(int i=0;i<no;i++)
	{
		cout<<"\nRoll Number : ";
		cout<<roll_no[i];
	}
}

void Sport :: onlyGroup(Sport* b)
{
	for(int i=0;i<no;i++)
	{
		int count=0;

		for(int j=0;j<b->no;j++)
		{
			if(roll_no[i]!=b->roll_no[j])
			{
				count++;
			}
		}

		if(count==b->no)
		{
			cout<<"\nRoll Number : ";
			cout<<roll_no[i];
		}
	}
}

void Sport :: bothGroup(Sport* c)
{
	for(int i=0;i<no;i++)
	{
		for(int j=0;j<c->no;j++)
		{
			if(roll_no[i]==c->roll_no[j])
			{
				cout<<"\nRoll Number : ";
				cout<<roll_no[i];
				break;
			}
		}
	}
}

void Sport :: neitherGroup(Sport* c,Sport* b)
{
	int count=0;
	int* temp=new int[no];

	for(int i=0;i<no;i++)
	{
		int j=0,count2=0;

		for(j=0;j<c->no;j++)
		{
			if((roll_no[i]!=c->roll_no[j]))
			{
				count2++;
			}
		}

		if(count2==j)
		{
			temp[count]=roll_no[i];
			count++;
		}
	}

	for(int i=0;i<count;i++)
	{
		int j=0,count3=0;

		for(j=0;j<b->no;j++)
		{
			if((temp[i]!=b->roll_no[j]))
			{
				count3++;
			}
		}

		if(count3==j)
		{
			cout<<"\nRoll Number : ";
			cout<<temp[i];
		}
	}
}

void Sport :: eitherGroup(Sport* c,Sport* b)
{
	for(int i=0;i<c->no;i++)
	{
		cout<<"\nRoll Number : ";
		cout<<c->roll_no[i];
	}

	for(int j=0;j<b->no;j++)
	{
		int k=0,count=0;

		for(k=0;k<c->no;k++)
		{
			if(b->roll_no[j]!=c->roll_no[k])
			{
				count++;
			}
		}

		if(count==k)
		{
			cout<<"\nRoll Number : ";
			cout<<b->roll_no[j];
		}
	}
}

int main()
{
	Sport* all=new Sport;
	Sport* cricket=new Sport;
	Sport* badminton=new Sport;

	int op=1,op1=1;

	do
	{
		all->setGroup();

		cout<<"\nEnter Data For Students Who Play Cricket : \n";
		cricket->setGroup();

		cout<<"\nEnter Data For Students Who Play Badminton : \n";
		badminton->setGroup();

		do
		{
			cout<<"\nWhich Operation Do You Want To Perform ?\n0 : Perform Operations On New Data\n1 : Students Who Play Only Cricket\n2 : Students Who Play Only Badminton\n3 : Students Who Play Both Cricket And Badminton\n4 : Students Who Play Neither Cricket Nor Badminton\n5 : Students Who Play Either Cricket Or Badminton\n6 : Display Entire Division\n7 : Exit From Program\n";
			cin>>op1;

			switch(op1)
			{
				case 0:
				op1=0;
				break;

				case 1:
				cout<<"\nThe Students Who Only Play Cricket Are : ";
				cricket->onlyGroup(badminton);
				break;

				case 2:
				cout<<"\nThe Students Who Only Play Badminton Are : ";
				badminton->onlyGroup(cricket);
				break;

				case 3:
				cout<<"\nThe Students Who Play Both Cricket And Badminton Are : ";
				cricket->bothGroup(badminton);
				break;

				case 4:
				cout<<"\nThe Students Who Play Neither Cricket Nor Badminton Are : ";
				all->neitherGroup(cricket,badminton);
				break;

				case 5:
				cout<<"\nThe Students Who Play Either Cricket Or Badminton Are : ";
				all->eitherGroup(cricket,badminton);
				break;

				case 6:
				cout<<"\nStudents Are : \n";
				all->displayGroup();
				break;

				case 7:
				cout<<"\nThank You For Using The Program !!!\n";
				op1=0;
				op=0;
			}
		}while(op1!=0);

	}while(op!=0);

	return 0;
}





