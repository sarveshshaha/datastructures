/*
 * Matrix.h
 *
 *  Created on: Aug 16, 2016
 *      Author: PRESIDENTTEAM
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include<iostream>

using namespace std;

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

	/*Matrix()
	{
		mat=new int[50][50];
	}*/
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

#endif /* MATRIX_H_ */
