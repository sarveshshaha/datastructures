#include<iostream>
#include "Matrix.h"

using namespace std;
/*
class Matrix
{
	private:
	int mat[50][50];
	int row;
	int col;

	public:
	void insertmat();
	void displaymat();
	void addmat(Matrix);
	void submat(Matrix);
	void mulmat(Matrix);
	void transpose();
	void diagadd();
	void uptri();
	void lowtri();

};

void Matrix :: insertmat()
{
	cout<<"\nEnter The No. Of Rows and Columns For The Matrix : \n";
	cin>>row;
	cin>>col;

	cout<<"\n Enter The Elements of Matrix : \n";

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>mat[i][j];
		}
	}
}

void Matrix :: displaymat()
{
	cout<<"\nThe Matrix Is : \n";

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
}



void Matrix :: addmat(Matrix m)
{
	Matrix add;

	if((row==m.row)&&(col==m.col))
	{
		add.row=row;
		add.col=col;

		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				add.mat[i][j]=mat[i][j]+m.mat[i][j];
			}
		}
	}

	cout<<"\nThe Addition of Two Matrices is : \n";
	add.displaymat();
}



void Matrix :: submat(Matrix m)
{
	Matrix sub;

	if((row==m.row)&&(col==m.col))
	{
		sub.row=row;
		sub.col=col;

		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{

				sub.mat[i][j]=mat[i][j]-m.mat[i][j];
			}
		}
	}

	cout<<"\nThe Subtraction of Two Matrices is : \n";
	sub.displaymat();
}


void Matrix :: mulmat(Matrix m)
{
	Matrix mul;

	mul.row=row;
	mul.col=col;

	if(col==m.row)
	{
		for(int i=0;i<this->row;i++)
		{
			for(int j=0;j<m.col;j++)
			{
				for(int k=0;k<this->col;k++)
				{
					mul.mat[i][j]=mul.mat[i][j]+(this->mat[i][k]*m.mat[k][j]);
				}
			}
		}

	}

	cout<<"\n The Multiplication of Two Matrices is : \n";
	mul.displaymat();
}

void Matrix :: transpose()
{
	Matrix trans;

	trans.row=row;
	trans.col=col;

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			trans.mat[i][j]=mat[j][i];
			cout<<"\n";
		}
	}

	cout<<"\nThe Transpose of Given Matrix is : \n";
	trans.displaymat();
}

void Matrix :: diagadd()
{
	int diagsum;

	for(int i=0;i<row;i++)
	{
		diagsum+=mat[i][i];
	}
	cout <<"\nThe Sum of the Diagonal elements of Matrix is : \n"<<diagsum;
}

void Matrix :: uptri()
{
	int flag=0;

	for (int i=1;i<row;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(mat[i][j]!=0)
			{
				flag=1;
				break;
			}

		}

		if(flag==1)
		{
			break;
		}
	}

	if (flag == 0)
	{
		cout<<"\nThe Matrix is an Upper Triangular Matrix. \n";
	}
	else
	{
		cout<<"The Matrix is NOT an Upper Triangular Matrix. \n";
	}
}

void Matrix :: lowtri()
{
	int flag=0;

	for (int i=0;i<row;i++)
	{
		for (int j=1;j<i;j++)
		{
			if(mat[i][j]!=0)
			{
				flag=1;
				break;
			}

		}

		if(flag==1)
		{
			break;
		}
	}

	if (flag==0)
	{
		cout<<"\nThe Matrix is a Lower Triangular Matrix.\n";
	}
	else
	{
		cout<<"\nThe Matrix is NOT a Lower Triangular Matrix.\n";
	}
}
*/
int main()
{
	int op=0,ch=0;

	Matrix m1,m2;

	m1.insertmat();
	m2.insertmat();

	do
	{
		cout<<"\nEnter the Choice Of Operation : ";
		cout<<"\n1.Add\n2.Subtract\n3.Multiply\n4.Transpose\n5.Summation of Diagonal Elements\n6.Upper Triangular\n7.Lower Triangular\n8.Exit";
		cin>>op;

		switch(op)
		{

			case 1:
				m1.addmat(m2);
				break;


			case 2:
				m1.submat(m2);
				break;


			case 3:
				m1.mulmat(m2);
				break;

			case 4:
				cout<<"\n Which Matrix You Want The Transpose Of (1 OR 2) : \n";
				cin>>ch;
				if(ch==1)
				{
					m1.transpose();
				}
				else if(ch==2)
				{
					m2.transpose();
				}
				else
				{
					cout<<"\nWrong Option Entered !!!\n";
				}
				break;

			case 5:
				cout<<"\n Which Matrix You Want The Sum Of Diagonals Of (1 OR 2) : \n";
				cin>>ch;

				if(ch==1)
				{
					m1.diagadd();
				}
				else if(ch==2)
				{
					m2.diagadd();
				}
				else
				{
					cout<<"\nWrong Option Entered !!!\n";
				}

				break;

			case 6:
				cout<<"\n Which Matrix You Want To Check If It Is Upper Triangular Or Not (1 OR 2) : \n";
				cin>>ch;

				if(ch==1)
				{
					m1.uptri();
				}
				else if(ch==2)
				{
					m2.uptri();
				}
				else
				{
					cout<<"\nWrong Option Entered !!!\n";
				}

				break;

			case 7:
				cout<<"\n Which Matrix You Want To Check If It Is Lower Triangular Or Not (1 OR 2) : \n";
				cin>>ch;

				if(ch==1)
				{
					m1.lowtri();
				}
				else if(ch==2)
				{
					m2.lowtri();
				}
				else
				{
					cout<<"\nWrong Option Entered !!!\n";
				}

				break;

			case 8:
				cout<<"\nThank You For Using The Program.\n";
				break;

			default:
				cout<<"\n Wrong Option Entered.\n";
		}

	} while(op!=8);

return 0;
}
