#include<iostream>

using namespace std;

class Member
{
	public:
	char Name[100];
	char PRN[10];
	Member* Next;
};

class SinglyLinkedList
{
	public:
	int n;

	Member* Principal;
	Member* temp;
	Member* ptr;

	public:
	void createList();
	void display();
};

void SinglyLinkedList::createList()
{
	Principal=new Member;

	temp=Principal;

	cout << "Enter the no. of Records:";
	cin >> n;

	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter Name Of The Member : ";
		cin>>temp->Name;

		cout<<"\nEnter PRN Of The Member : ";
		cin>>temp->PRN;

		temp->Next=new Member;

		temp=temp->Next;
	}

	temp->Next = NULL;
}

void SinglyLinkedList::display()
{
	cout<<Principal->Name<<endl;

	ptr = Principal->Next;

 	while((ptr->Next) != NULL)
	{
		cout<<ptr->Name<<endl;
		cout<<ptr->PRN<<endl;
		ptr=ptr->Next;
	}
}

int main()
{
	SinglyLinkedList sll;

	sll.createList();
	sll.display();

	return 0;
}
