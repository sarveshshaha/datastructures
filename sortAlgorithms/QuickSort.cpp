#include<iostream>

using namespace std;

class Sort
{
	private:
	float* students;
	int* roll;

	public:
	int no;
	void getnostudents();
	void setstudents();
	int partition(int,int);
	void quicksort(int,int);
	void swap(float&,float&);
	void swap(int&,int&);
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

int Sort :: partition(int low,int high)
{
	int pivot = students[high];
	int i=(low-1);

	for(int j=low;j<=high-1;j++)
	{
		if(students[j]>=pivot)
		{
			i++;
			swap(students[i],students[j]);
			swap(roll[i],roll[j]);
		}
	}

	swap(students[i+1],students[high]);
	swap(roll[i+1],roll[high]);

	return (i + 1);
}

void Sort :: quicksort(int low,int high)
{
	if (low<high)
	{
		int pi=partition(low,high);

		quicksort(low,pi-1);
		quicksort(pi+1,high);
    }
}

void Sort :: swap(float &v1,float &v2)
{
	float tp;

	tp=v1;
	v1=v2;
	v2=tp;
}

void Sort :: swap(int &v1,int &v2)
{
	int tr;

	tr=v1;
	v1=v2;
	v2=tr;
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
	int op=1;
	Sort s;

	do
	{
		cout<<"\nEnter The Data Of The Students Of The Class : \n";
		s.getnostudents();
		s.setstudents();

		s.quicksort(0,(s.no)-1);

		s.displayallstudents();

		cout<<"\nDo You Want To Sort Another Class ?\n1 : Yes\n0 : No";
		cin>>op;

		if(op==0)
		{
			cout<<"\nThank You For using The Program !!!\n";
		}
	}while(op==1);

	return 0;
}
