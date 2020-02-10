/*
#include<iostream>
#include<string.h>

using namespace std;

class node
{
	char name[10];
	int prn;
	node* next;

	public:
	char* getname()
	{
	return name;
	}
	int getprn()
	{
	return prn;
	}
	node* getnext(){
	return next;
	}
	void setname(char n[])
	{
	strcpy(name,n);
	}
	void setprn(int p)
	{
	prn=p;
	}
	void setnext(node* n)
	{
	next=n;
	}

};

class list
{
node* start;
public:
list(){start=NULL;}
node* create(int,char[]);
void addbeg();
void addlas();
void addpos();
void display();
void del(int);
void count();
void insstud();
void concat(list l1);
void search();
node* ret_start();
void rev_display(node*);
};

node* list::create(int prn,char name[])
{
node *temp=new node;

if(temp==NULL)
	{
cout<<"/nmemory is not allocated";
return 0;
	}
else  {

temp->setname(name);
temp->setprn(prn);
temp->setnext(NULL);
return temp;
	}
}
void list::addbeg ()
{
char name[10];
int prn;
cout<<"\nenter prn and name:";
cin>>prn>>name;
node* temp,*p;
temp=create(prn,name);
temp->setnext(NULL);

if(start==NULL)
{
start=temp;
start->setnext(NULL);
}

else{
temp->setnext(start);
start=temp;
}

}

void list::addlas()
{
char name[10];
int prn;
cout<<"\nenter prn and name:";
cin>>prn>>name;

node *temp,*p;
temp=create(prn,name);

temp->setnext(NULL);

if(start!=NULL)
	{
p=start;
while(p->getnext()!=NULL)
{
p=p->getnext();
}
temp->setnext(NULL);
p->setnext(temp);
}

else{
start=temp;
}
}

///////////////////////////////////////////
void list::addpos()
{
node *temp,*p;
char name[10];
int prn,prn1;
p=start;
if(p==NULL)
{cout<<"\nlink is empty";}
else{
cout<<"\n enter after which prn add";
cin>>prn1;

int flag=0;
while(p!=NULL)
{
	if(p->getprn()!=prn1)
		{
			p=p->getnext();
		}
	else{
			cout<<"\nenter prn and name of student to be add:";
			cin>>prn>>name;
			temp=create(prn,name);

			temp->setnext(p->getnext());
			p->setnext(temp);
			flag=1;
			break;
		}      //else term
}           ///wHIle

	if(flag==0)
	{cout<<"\nwrong prn";}


}
}	// funct term
///////////////////////////////////////////////////////////

void list:: display()

{

 node* temp;

if(start==NULL)
	{
cout<<"EMPTE list";
return;
	}
int i=1;
temp=start;
cout<<"\nlist is";
cout<<"\n\n"<<" sr no  prn     name\n";
while(temp!=NULL)
	{
cout<<"\n  "<<i<<"     "<<temp->getprn()<<"        "<<temp->getname();
temp=temp->getnext();
i++;
	}

}


////////////////////////////////////////////////// delete
void list::del(int n)
{
int prn1;
int flag=0;
node* trav,*prev;
trav=start;
if(trav==NULL)
{cout<<"\nNO items are present to delete";    }
else{

if(n==2)
			{
cout<<"\nwhich student prn to be delete";
cin>>prn1;

while(trav!=NULL)
{
	flag=0;
	if(trav->getprn()==prn1)
	{
		if(trav==start)
		{

		start=trav->getnext();
		delete trav;
		flag=1;
		}
	else{
		prev->setnext(trav->getnext());
		trav->setnext(NULL);
		delete (trav);
		flag=1;
		}

		break;
	}
else{
prev=trav;
trav=trav->getnext();
    }

	}                         /// while termn


if(flag==0)
	{
cout<<"PRN IS not present in list";
	}

}               /// for if n=2

if(n==1)
{
	if(trav==start)
		{
		start=trav->getnext();
		delete trav;
		}
}				////// for if n=1

if(n==3)
{
	while(trav->getnext()!=NULL)
	{
	prev=trav;
	trav=trav->getnext();
	}
	prev->setnext(NULL);
	delete trav;
}

}   		////else term.

}
////////////////////////////////////////////////////////////

void list::count()
{

int ct=0;

 node* p;

 p=start;
 if(p==NULL)
 {cout<<"\ntotal members is ZERO";}
else{
 while(p!=NULL)
		{
	p=p->getnext();
	ct++;
		}
	cout<<"total members are = "<<ct	;
	}

}

////////////////////////////////////////////////////////
void list::insstud()

{
int prn;
char name[10];
node* p;
node* temp;
p=start;
while((p->getnext())->getnext()!=NULL)
{
p=p->getnext();
}
cout<<"\nenter prn and name  of stud to be add";
cin>>prn>>name;
temp=create(prn,name);
temp->setnext(p->getnext());
p->setnext(temp);

}

void list::concat(list l1)
{

node* temp;
temp=start;

if(temp==NULL)
{
start=l1.start;
}
else{
while(temp->getnext()!=NULL)
		{
		temp=temp->getnext();
		}

temp->setnext(l1.start);
	}
}

/////////////////////////////////////////////////////////

node* list::ret_start()
{
return start;
}
void list::rev_display(node* temp)
{

	if(temp!=NULL)
	{
	rev_display(temp->getnext());
	cout<<"\n  "<<temp->getprn()<<"        "<<temp->getname();

	}

}




//////////////////////////////////////////////////////////

  void list::search()
 {
 int prn1,flag;
 node* temp;
 cout<<"\nenter prn to be search";
 cin>>prn1;
 temp=start;
 if(temp==NULL)
 {cout<<"\nemptyr list";}
 else{
 int k=1;
 while(temp!=NULL)
 {

 if(temp->getprn()==prn1)
 {
 cout<<"\nprn is found in position "<<k;
	flag=1;
 break;
 }
 k++;
 temp=temp->getnext();
 }

 if(flag!=1)
 cout<<"\nPrn is not found";
 }


  }
////////////////////////////////////////////////////////////////////////////////////////////////////////
//int main()
{


int ch;
list l;

do{

cout<<"\n\nenter choice";

cout<<"\n1.create\n2.INSERT\n3.DELETE\n4.DISPLAY\n5.COUNT MEMBERS\n6.concatenate\n7.REVERSE\n8.search\n9.EXIT";
cin>>ch;

switch(ch)
{



case 1:
{
int m;
cout<<"\nenter president information";
l.addbeg();


cout<<"\n\nentre total no of student";
cin>>m;

for(int i=0;i<m;i++)
	{
l.addlas();
	}

cout<<"\nenter secretory information";
l.addlas();
break;
}
case 2:
{
int n;
cout<<"\n1.president\n2.student\n3.secretory\n4.after prn";
cin>>n;
switch(n)
{
case 1:
	{
			int n;
			cout<<"\n1.delete first president and add new\n2.add first president into student";
			cin>>n;
			if(n==1)
				{

					l.del(n);
					l.addbeg();
				}
			if(n==2)
				{

					l.addbeg();
				}
			break;
	}
case 2:
  {
l.insstud();
break;
  }
case 3:
	{
			int n;
			cout<<"\n1.delete first secretory and add new\n2.add first secretory into student";
			cin>>n;
		if(n==1)
			{
			l.del(3);
			l.addlas();

			}
		if(n==2)
			{
				l.addlas();
			}
	break;
	}
case 4:
	{
	l.addpos();
	break;
	}

}
break;
}
case 3:          /////////  for delete
{
int n;
cout<<"\n1.president\n2.student\n3.secretory";
cin>>n;

if(n==1)
{
l.del(n);
}
if(n==2)
{
l.del(n);
}
if(n==3)
{
l.del(n);
}
break;
}


case 4:												////   display					/////
{
l.display();
break;
}

case 5:											///   count
{
l.count();
break;
}
case 6:{										/// conactenate
list l1;
int n;
cout<<"\n div A is";
l.display();
cout<<"\n enter no of student in div B";
cin>>n;
for(int i=0;i<n;i++)
{
l1.addlas();
}
cout<<"\n div B is";
l1.display();
l.concat(l1);


break;
}

case 7:																//////reverse
{
node* temp;
temp=l.ret_start();
cout<<"\n\n prn      name";
l.rev_display(temp);

break;
}

case 8:
{

l.search();
break;
}
case 9:
{break;}
}          /// switch
}while(ch!=9);




cout<<"\n\n////////  THANK YOU     ////////\n";

return 0;
}
*/
