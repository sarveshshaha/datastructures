#include<iostream>
#include<string.h>

using namespace std;

class Member
{
	private:
	char Name[50];
	char PRN[10];
	Member* Next;

	public:
	void setName(char[]);
	void setPRN(char[]);
	void setNext();
	void setNext(Member*);

	char* getName();
	char* getPRN();
	Member* getNext();
};

void Member :: setName(char nm[])
{
	strcpy(Name,nm);
}

void Member :: setPRN(char p[])
{
	strcpy(PRN,p);
}

void Member :: setNext()
{
	Next=new Member;
}

void Member :: setNext(Member* nxt)
{
	Next=nxt;
}

char* Member :: getName()
{
	return Name;
}

char* Member :: getPRN()
{
	return PRN;
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

	Member* Principal=NULL;
	Member* temp=NULL;
	Member* ptr=NULL;

	public:
	void createList();
	void displayList();
	void addMember();
	void deleteMember();
	void showCount();
	void concatenateList(SinglyLinkedList,SinglyLinkedList);
	void recursiveReverse(Member*);
};

void SinglyLinkedList :: createList()
{
	char n[50];
	char p[10];
	int op=0;

	Principal=new Member;

	temp=Principal;

	cout<<"\nEnter Name Of The Principal : ";
	cin>>n;
	temp->setName(n);

	count++;

	cout<<"\nDo You Want To Add Any Elements ?\n0 : No\n1 : Yes";
	cin>>op;

	if(op==1)
	{
		temp->setNext();
		temp=temp->getNext();

		do
		{
			cout<<"\nEnter Name Of The Member : ";
			cin>>n;
			temp->setName(n);

			cout<<"\nEnter PRN Of The Member : ";
			cin>>p;
			temp->setPRN(p);

			temp->setNext();

			temp=temp->getNext();

			count++;

			cout<<"\nDo You Want To Add Any Elements ?\n0 : No\n1 : Yes";
			cin>>op;
		}while(op==1);

		cout<<"\nEnter Name Of The Secretary : ";
		cin>>n;
		temp->setName(n);
		temp->setNext(NULL);
		count++;
	}
	else
	{
		temp->setNext();
		temp=temp->getNext();

		cout<<"\nEnter Name Of The Secretary : ";
		cin>>n;
		temp->setName(n);
		temp->setNext(NULL);
		count++;
	}
}

void SinglyLinkedList :: displayList()
{
	if(Principal==NULL)
	{
		cout<<"\nPlease Create The Pinnacle Group First !!!\n";
	}
	else
	{
		cout<<"\nThe Principal Is :\n";
		cout<<Principal->getName();

		ptr = Principal->getNext();

		for(int i=1;i<count-1;i++)
		{
			cout<<"\nThe Member Is : \n";
			cout<<"Name : "<<ptr->getName()<<"\n";
			cout<<"PRN : "<<ptr->getPRN()<<"\n";
			ptr=ptr->getNext();
		}

		if(Principal->getNext()!=NULL)
		{
			cout<<"\nThe Secretary Is :\n";
			cout<<ptr->getName()<<"\n";
		}
	}
}

void SinglyLinkedList :: addMember()
{
	int op;
	int check=0;
	char n[50];
	char p[10];

	cout<<"\nDo You Want To Change The Principal OR The Secretary ?\n1 : Principal\n2 : Secretary\n0 : None\n";
	cin>>op;

	if(op==1)
	{
		Member* pri=new Member;

		cout<<"\nThe Previous Principal Will Now Be Made A Member !!!\n";
		cout<<"\nEnter The PRN Of The Previous Principal : \n";
		cin>>p;
		Principal->setPRN(p);

		cout<<"\nEnter The Name Of The New Principal : \n";
		cin>>n;

		pri->setName(n);
		pri->setNext(Principal);
		Principal=pri;

		count++;
	}
	else if(op==2)
	{
		temp=Principal;
		Member* sec=new Member;

		while(temp->getNext()!=NULL)
		{
			temp=temp->getNext();
		}

		cout<<"\nThe Previous Secretary Will Now Be Made A Member !!!\n";
		cout<<"\nEnter The PRN Of The Previous Secretary : \n";
		cin>>p;
		temp->setPRN(p);

		cout<<"\nEnter The Name Of The New Secretary : \n";
		cin>>n;
		sec->setName(n);
		sec->setNext(NULL);

		temp->setNext(sec);

		count++;
	}
	else if(op==0)
	{
		cout<<"\nAfter Which Member You Want To Add The Element : \n";
		cin>>n;

		temp=Principal;

		while((strcmp(temp->getName(),n))!=0)
		{
			temp=temp->getNext();

			if(temp->getNext()==NULL)
			{
				break;
			}
		}

		if(strcmp(temp->getName(),n)==0)
		{
			check=1;
		}

		if(check==1)
		{
			Member* m=new Member;

			cout<<"\nEnter The Name Of The New Member : \n";
			cin>>n;
			cout<<"\nEnter The PRN Of The New Member : \n";
			cin>>p;

			m->setName(n);
			m->setPRN(p);

			m->setNext(temp->getNext());
			temp->setNext(m);

			count++;
		}
		else
		{
			cout<<"\nNo Match Found !!!\n";
		}
	}
}

void SinglyLinkedList :: deleteMember()
{
	int check=0;
	char n[50];

	cout<<"\nWhich Member You Want To Delete : \n";
	cin>>n;

	temp=Principal;
	ptr=temp->getNext();

	if(strcmp(temp->getName(),n)==0)
	{
		cout<<"\nYou Are Deleting The Principal ! The Next Member Will Be Made The Principal ! \n";
		Principal=Principal->getNext();
		temp=Principal;
		count--;
	}
	else
	{
		while(strcmp(ptr->getName(),n)!=0)
		{
			temp=temp->getNext();
			ptr=ptr->getNext();

			if(ptr->getNext()==NULL)
			{
				break;
			}
		}

		if(strcmp(ptr->getName(),n)==0)
		{
			check=1;
		}

		if(check==1)
		{
			if((ptr->getNext())!=NULL)
			{
				cout<<"\nThe Member Has Been Deleted !!!\n";
				temp->setNext(ptr->getNext());
				count--;
			}
			else
			{
				cout<<"\nYou Are Deleting The Secretary ! The Previous Member Will Be Made The Secretary !!! \n";
				temp->setNext(NULL);
				count--;
			}
		}
		else
		{
			cout<<"\nMember Not Found !!!\n";
		}

	}
}

void SinglyLinkedList :: showCount()
{
	cout<<"\nThe Number Of Members Including The Principal And Secretary Is : \n"<<count<<"\n";
}

void SinglyLinkedList :: concatenateList(SinglyLinkedList sl1,SinglyLinkedList sl2)
{
	sl1.temp=sl1.Principal;
	sl2.temp=sl2.Principal;

	Principal=new Member;
	temp=new Member;

	Principal=sl1.Principal;
	temp=Principal;
	count++;

	for(int i=1;i<sl1.count;i++)
	{
		temp=temp->getNext();
	}

	temp->setNext(sl2.Principal);

	count=sl1.count+sl2.count;

}

void SinglyLinkedList :: recursiveReverse(Member* ptr)
{
	if(ptr->getNext()!=NULL)
	{
		recursiveReverse(ptr->getNext());
	}
	cout<<"\nThe Member Is : ";
	cout<<"\nName : "<<ptr->getName();
	if(ptr->getPRN()!=NULL)
	{
		cout<<"\nPRN : "<<ptr->getPRN()<<"\n";
	}
}

int main()
{
	SinglyLinkedList sll1,sll2,sll3;
	;
	int op1=0,op2=0;

	do
	{
		cout<<"\nWhich Operation Do You Want To Perform ?\n1 : Create Group\n2 : Display Group\n3 : Add Member\n4 : Delete Member\n5 : Get The Number Of Members\n6 : Concatenate The Groups\n7 : Recursive Reverse\n8 : Exit";
		cin>>op1;

		switch(op1)
		{
			case 1:
			cout<<"\nFor Which Group You Want To Perform The Operation ?\n1/2\n";
			cin>>op2;
			if(op2==1)
			{
				sll1.createList();
			}
			else if(op2==2)
			{
				sll2.createList();
			}
			else
			{
				cout<<"\nThere Are Only 2 Groups, 1 and 2 !!!\n";
			}
			break;

			case 2:
			cout<<"\nFor Which Group You Want To Perform The Operation ?\n1/2\n";
			cin>>op2;
			if(op2==1)
			{
				sll1.displayList();
			}
			else if(op2==2)
			{
				sll2.displayList();
			}
			else
			{
				cout<<"\nThere Are Only 2 Groups, 1 and 2 !!!\n";
			}
			break;

			case 3:
			cout<<"\nFor Which Group You Want To Perform The Operation ?\n1/2\n";
			cin>>op2;
			if(op2==1)
			{
				sll1.addMember();
			}
			else if(op2==2)
			{
				sll2.addMember();
			}
			else
			{
				cout<<"\nThere Are Only 2 Groups, 1 and 2 !!!\n";
			}
			break;

			case 4:
			cout<<"\nFor Which Group You Want To Perform The Operation ?\n1/2\n";
			cin>>op2;
			if(op2==1)
			{
				sll1.deleteMember();
			}
			else if(op2==2)
			{
				sll2.deleteMember();
			}
			else
			{
				cout<<"\nThere Are Only 2 Groups, 1 and 2 !!!\n";
			}
			break;

			case 5:
			cout<<"\nFor Which Group You Want To Perform The Operation ?\n1/2\n";
			cin>>op2;
			if(op2==1)
			{
				sll1.showCount();
			}
			else if(op2==2)
			{
				sll2.showCount();
			}
			else
			{
				cout<<"\nThere Are Only 2 Groups, 1 and 2 !!!\n";
			}
			break;

			case 6:
			sll3.concatenateList(sll1,sll2);
			sll3.displayList();
			break;

			case 7:
			cout<<"\nFor Which Group You Want To Perform The Operation ?\n1/2\n";
			cin>>op2;
			if(op2==1)
			{
				sll1.ptr=sll1.Principal;
				sll1.recursiveReverse(sll1.ptr);
			}
			else if(op2==2)
			{
				sll2.ptr=sll2.Principal;
				sll2.recursiveReverse(sll2.ptr);
			}
			else
			{
				cout<<"\nThere Are Only 2 Groups, 1 and 2 !!!\n";
			}
			break;

			case 8:
			cout<<"\nThank You For Using The Program !!!\n";
		}
	}while(op1!=8);

	return 0;
}
