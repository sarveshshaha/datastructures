#include<iostream>
#include<string.h>

using namespace std;

class Member
{
	private:
	char ch;
	Member* Next=NULL;

	public:
	void setoptr(char);
	void setNext();
	void setNext(Member*);

	char getoptr();
	Member* getNext();
};

void Member :: setoptr(char c)
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

char Member :: getoptr()
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
		temp->setoptr(c);
		count++;
		tp=c;
	}
	else
	{
		temp->setNext();
		temp=temp->getNext();
		temp->setoptr(c);
		count++;
		tp=c;
	}
}

char Stack :: pop()
{
	if(count==0)
	{
		tmp=start->getoptr();
		count--;
		tp='\0';
		return tmp;
	}

	else
	{
		tmp=temp->getoptr();

		traverse=start;

		for(int i=1;i<count;i++)
		{
			traverse=traverse->getNext();
		}

		traverse->setNext(NULL);
		temp=traverse;

		tp=traverse->getoptr();

		count--;

		return tmp;
	}
}

char Stack :: top()
{
	tmp=temp->getoptr();
	return tmp;
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
	if(count==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Expression
{
	public:
	Stack exp;
	string postfix="";
	char infix[100];

	bool isOperand(char);
	bool isOperator(char);
	int getPriority(char);
	void value();
	void convert();
};

bool Expression :: isOperand(char opnd)
{
	if(!(isOperator(opnd))&&(opnd!='(') &&(opnd != ')'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Expression :: isOperator(char optr)
{
    if ((optr=='+')||(optr=='-')||(optr =='*')||(optr=='/')||(optr=='^'))
    {
        return true;
    }
    else
    {
    	return false;
    }
}

int Expression :: getPriority(char op)
{
	if(op=='^')
	{
		return 3;
	}
	else if((op=='*')||(op=='/'))
	{
		return 2;
	}
	else if((op=='+')||(op=='-'))
	{
		return 1;
	}
	return 0;
}

void Expression :: convert()
{
	char *cPtr=infix;

	for(unsigned int i=0;i<strlen(infix);i++)
	{
		if(isOperand(*cPtr))
		{
			postfix+=*cPtr;
		}
		else if(isOperator(*cPtr))
		{
			while((!exp.isEmpty())&&(exp.top()!='(')&&(this->getPriority(exp.top())>this->getPriority(*cPtr)))
			{
				postfix+=exp.pop();
			}

			if((!exp.isEmpty())&&(this->getPriority(exp.top())==this->getPriority(*cPtr)))
			{
				postfix+=exp.pop();
			}

			exp.push(*cPtr);
		}
		else if(*cPtr=='(')
		{
			exp.push(*cPtr);
		}
        else if(*cPtr == ')')
        {
            while (!exp.isEmpty())
            {
                if(exp.top()=='(')
                {
                	exp.pop();
                	break;
                }

                postfix+=exp.pop();
            }
        }

        cPtr++;
    }

    while(!exp.isEmpty())
    {
        postfix+=exp.pop();
    }
}

void Expression :: value()
{
	Stack vall;
	int v1,v2,val;
	char cval;
	char cpostfix[postfix.size()+1];

	strcpy(cpostfix,postfix.c_str());

	char* sPtr=cpostfix;

	for(unsigned int i=0;i<postfix.size();i++)
	{
		if(isOperand(*sPtr))
		{
			vall.push(*sPtr);
		}
		else if(isOperator(*sPtr))
		{
			v2=int(vall.pop())-48;
			//cout<<"\nV2 Is:"<<v2;
			v1=int(vall.pop())-48;
			//cout<<"\nV1 Is:"<<v1;

			switch(*sPtr)
			{
				case '+':
				val=v1+v2;
				cval=val+48;
				vall.push(cval);
				break;

				case '-':
				val=v1-v2;
				cval=val+48;
				vall.push(cval);
				break;

				case '*':
				val=v1*v2;
				cval=val+48;
				vall.push(cval);
				break;

				case '/':
				val=v1/v2;
				cval=val+48;
				vall.push(cval);
				break;

				case '^':
				val=v1^v2;
				cval=val+48;
				vall.push(cval);
				break;
			}
		}

		sPtr++;
	}

	val=int(vall.pop())-48;
	cout<<"\nThe Value Of The Expression Is : \n"<<val;
}

int main()
{
	Expression e;

	cout<<"\nEnter The Infix Expression To Be Converted : \n";
	cin>>e.infix;

	e.convert();

	cout<<"\nThe Postfix String Is : \n";
	cout<<e.postfix<<"\n";

	e.value();

	return 0;
}

