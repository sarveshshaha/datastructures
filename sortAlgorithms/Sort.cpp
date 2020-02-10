/*
#include<iostream>

using namespace std;

class Sort
{
	private:
	float* students;
	int* roll;
	int no;

	public:
	void getnostudents();
	void setstudents();
	void selectionsort();
	void bubblesort();
	void insertionsort();
	void displayallstudents();
};

void Sort :: getnostudents()
{
	cout<<"\nEnter The Total Number Of Students Who Attended The Exam : \n";
	cin>>no;

	students=new float[no];
	roll=new int[no];
}

void Sort :: setstudents()
{
	for(int i=0;i<no;i++)
	{
		cout<<"\nEnter The Roll Number Of The Student : \n";
		cin>>roll[i];
		cout<<"\nEnter Percentage Of The Student : \n";
		cin>>students[i];
	}
}

void Sort :: selectionsort()
{
	int tmp;
	float tp;
	int tr;

	for(int i=0;i<no-1;i++)
	{
		tmp=i;

		for(int j=i+1;j<no;j++)
		{
			if(students[j]>students[tmp])
			{
				tmp=j;
			}
		}

		if(tmp!=i)
		{
			tp=students[i];
			students[i]=students[tmp];
			students[tmp]=tp;

			tr=roll[i];
			roll[i]=roll[tmp];
			roll[tmp]=tr;
		}
	}
}

void Sort :: bubblesort()
{
	int check=1;
	float tp;
	int tr;

	for(int i=0;(i<no)&&(check==1);i++)
	{
		check=0;

		for(int j=0;j<no-1;j++)
		{
			if(students[j]<students[j+1])
			{
				check=1;

				tp=students[j];
				students[j]=students[j+1];
				students[j+1]=tp;

				tr=roll[j];
				roll[j]=roll[j+1];
				roll[j+1]=tr;
			}
		}
	}
}

void Sort :: insertionsort()
{
	float tp;
	int tr;

	for(int i=1;i<=no-1;i++)
	{
		tp=students[i];
		tr=roll[i];

		int j=i-1;

		while((tp>students[j])&&(j>=0))
		{
			students[j+1]=students[j];
			roll[j+1]=roll[j];
			j=j-1;
		}

		students[j+1]=tp;
		roll[j+1]=tr;
	}
}

void Sort ::displayallstudents()
{
	cout<<"\nThe Ranking Of The Class Is As Follows : \n";
	for(int i=0;i<no;i++)
	{
		cout<<"\nRank "<<i+1<<" : Roll Number : "<<roll[i]<<" : Percentage : "<<students[i]<<"\n";
	}
}

int main()
{
	int op=4;
	Sort s;

	do
	{
		cout<<"\nEnter The Information Of The Students Of The Class : \n";
		s.getnostudents();
		s.setstudents();

		cout<<"\nWhich Operation Do You Want To Perform ?\n1 : Selection Sort\n2 : Bubble Sort\n3 : Insertion sort\n";
		cin>>op;

		switch(op)
		{
			case 1:
			s.selectionsort();
			s.displayallstudents();
			break;

			case 2:
			s.bubblesort();
			s.displayallstudents();
			break;

			case 3:
			s.insertionsort();
			s.displayallstudents();
			break;

			default:
			cout<<"\nWrong Option Entered !!!\n";
		}

		cout<<"\nDo You Want To Get The Ranking Of Another Class ?\n1 : Yes\n0 : No\n";
		cin>>op;
		if(op==0)
		{
			cout<<"\nThank You For using The Program !!!\n";
		}
	}while(op!=0);

	return 0;
}
*/
