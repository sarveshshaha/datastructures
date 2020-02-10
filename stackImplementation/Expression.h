#ifndef EXPRESSION_H_
#define EXPRESSION_H_
/*
#include<iostream>
#include<string.h>

using namespace std;

class Member
{
	private:
	char ch;
	Member* Next;

	public:
	void setCharacter(char);
	void setNext();
	void setNext(Member*);

	char getCharacter();
	Member* getNext();
};

void Member :: setCharacter(char c)
{
	ch=c;
}

void Member :: setNext()
{
	Next=new Member;
}

void Member :: setNext(Member* nxt)
{
	Next=nxt;
}

char Member :: getCharacter()
{
	return ch;
}

Member* Member :: getNext()
{
	return Next;
}

class Stack
{
	public:
	int count=-1,sp=-1;
	char tp,tmp;
	Member* start=NULL;
	Member* temp;
	Member* ptr;
	Member* traverse;

	void push(char);
	char pop();
	char top();
	bool isFull();
	bool isEmpty();
};

void Stack :: push(char c)
{
	if(count==-1)
	{
		start=new Member;
		temp=start;
		temp->setCharacter(c);
		temp->setNext(NULL);
		count++;
		tp=c;
	}
	else
	{
		temp->setNext();
		temp=temp->getNext();
		temp->setCharacter(c);
		temp->setNext(NULL);
		count++;
		tp=c;
	}
}

char Stack :: pop()
{
	if(count==0)
	{
		return start->getCharacter();
		start=NULL;
		count--;
		tp='\0';
	}

	else
	{
		tmp=temp->getCharacter();

		ptr=start->getNext();
		traverse=start;

		while(ptr!=NULL)
		{
			ptr=ptr->getNext();
			traverse=traverse->getNext();
		}

		traverse->setNext(NULL);
		temp=traverse;

		tp=temp->getCharacter();

		count--;

		return tmp;
	}
}

char Stack :: top()
{
	return tp;
}

bool Stack :: isFull()
{
	if(count==19)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Stack :: isEmpty()
{
	if((start==NULL)||count==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/
#endif /* EXPRESSION_H_ */
