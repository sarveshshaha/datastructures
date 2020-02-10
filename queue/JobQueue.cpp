/*
#include<iostream>
#include<string.h>

using namespace std;

class Member
{
	private:
	char JobName[50];
	Member* Next=NULL;

	public:
	void setJobName(char[]);
	void setNext();
	void setNext(Member*);

	char* getJobName();
	Member* getNext();
};

void Member :: setJobName(char nm[])
{
	strcpy(JobName,nm);
}

void Member :: setNext()
{
	Next=new Member;
}

void Member :: setNext(Member* nxt)
{
	Next=nxt;
}

char* Member :: getJobName()
{
	return JobName;
}

Member* Member :: getNext()
{
	return Next;
}

class SinglyLinkedList
{
	public:
	int n;
	int count=0;

	Member* startofqueue=NULL;
	Member* temp=NULL;
	Member* ptr=NULL;
	Member* front=NULL;
	Member* rear=NULL;

	public:
	void addJob();
	void completeJob();
	void getRear();
	void getFront();
	void showCount();
};

void SinglyLinkedList :: addJob()
{
	char n[50];

	if(startofqueue==NULL)
	{
		startofqueue=new Member;

		temp=startofqueue;

		cout<<"\nEnter Name Of The Job :\n";
		cin>>n;
		temp->setJobName(n);

		rear=startofqueue;

		count++;
	}
	else
	{
		temp->setNext();
		temp=temp->getNext();

		cout<<"\nEnter Job Name :\n";
		cin>>n;
		temp->setJobName(n);

		front=temp;

		count++;
	}
}

void SinglyLinkedList :: completeJob()
{
	char n[50];

	ptr=startofqueue;

	if(startofqueue==NULL)
	{
		cout<<"\nNo Jobs Are Lined Up In The Queue !!!\n";
	}
	else
	{
		if(front==rear)
		{
			strcpy(n,temp->getJobName());
			front=NULL;
			rear=NULL;
			startofqueue=NULL;
			count--;
			cout<<"\nThe Job Completed is : \n"<<n<<"\n";
		}
		else
		{
			while(ptr->getNext()!=temp)
			{
				ptr=ptr->getNext();
			}

			strcpy(n,temp->getJobName());

			ptr->setNext(NULL);
			temp=ptr;
			front=ptr;
			count--;

			cout<<"\nThe Job Completed is : \n"<<n<<"\n";
		}
	}
}

void SinglyLinkedList :: getRear()
{
	if(front==rear)
	{
		cout<<"\nThere is Only One Job Lined Up Which Is : \n"<<rear->getJobName()<<"\n";
	}
	else
	{
		cout<<"\nThe Last Job In The Queue Is : \n"<<rear->getJobName()<<"\n";
	}
}

void SinglyLinkedList :: getFront()
{
	if(front==rear)
	{
		cout<<"\nThere is Only One Job Lined Up Which Is : \n"<<front->getJobName()<<"\n";
	}
	else
	{
		cout<<"\nThe First Job In The Queue Is : \n"<<front->getJobName()<<"\n";
	}
}

void SinglyLinkedList :: showCount()
{
	cout<<"\nThe Number Of Jobs Lined Up Is : \n"<<count<<"\n";
}

int main()
{
	SinglyLinkedList sll1;

	int op1=0;

	do
	{
		cout<<"\nWhich Operation Do You Want To Perform ?\n1 : Add Job\n2 : Complete Job\n3 : Display Last Job In Queue\n4 : Display First Job In Queue\n5 : Get The Number Of Jobs In The Queue\n6 : Exit\n";
		cin>>op1;

		switch(op1)
		{
			case 1:
			sll1.addJob();
			break;

			case 2:
			sll1.completeJob();
			break;

			case 3:
			sll1.getRear();
			break;

			case 4:
			sll1.getFront();
			break;

			case 5:
			sll1.showCount();
			break;

			case 6:
			cout<<"\nThank You For Using The Program !!!\n";
		}
	}while(op1!=6);

	return 0;
}
*/
