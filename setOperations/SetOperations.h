/*

#ifndef SETOPERATIONS_H_
#define SETOPERATIONS_H_

class SetOperations {
};

#endif /* SETOPERATIONS_H_ */

#include <iostream>

using namespace std;

class Sport
{
	private:
	int count=0;
	int* roll_no=NULL;

	public:
	void createGroup();
	void displayGroup();
};

void Sport :: createGroup()
{
	int i=0;
	int op;

	do
	{
		cout<<"\nEnter The Roll Number :\n";
		cin>>roll_no[i];
		cout<<"\nDo You Want To Add Another Student ?\n1:Yes\n0:N0\n";
		cin>>op;
		count++;
	}while(op!=0);
}

void Sport :: displayGroup()
{
	cout<<"\nThe Students Are :\n";
	for(int i=0;i<count;i++)
	{
		cout<<roll_no[i];
	}
}

int main()
{
	Sport all;
	Sport cricket;
	Sport badminton;

	cout<<"\nEnter The Roll Numbers Of All Students :\n";
	all.createGroup();

	all.displayGroup();


}





