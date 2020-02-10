#include<iostream>
#include<string.h>

using namespace std;

class Pizza
{
	private:
	int bake[10];
	int front=-1;
	int rear=-1;
	int count=0;

	public:
	void addPizza(int);
	int deliverPizza();
	void gettotalpizzas();
	void showMenu(int,int);
	int viewLastPizza();
	int viewFirstPizza();
};

void Pizza :: addPizza(int p)
{
	if(((rear+1)%10)==front)
	{
		cout<<"\nThe Ovens Are Full, Please Wait Until A Pizza Is Delivered !!!\n";
	}
	else
	{
		if(rear==-1)
		{
			rear=front=0;
			bake[front]=p;
			count++;
		}
		else if((rear!=-1))
		{
			rear=(rear+1)%10;
			bake[rear]=p;
			count++;
		}
	}
}

int Pizza :: deliverPizza()
{
	int tmp;

	if(front==(-1))
	{
		cout<<"\nAll Pizzas have Already Been Delivered !!!\n";
		return 0;
	}
	else
	{
		tmp=bake[front];

		if(rear==front)
		{
			rear=-1;
			front=-1;
		}
		else
		{
			front=(front+1)%10;
		}

		count--;

		return tmp;
	}
}

void Pizza ::gettotalpizzas()
{
	cout<<"\nThe Total Number Of Pizzas Yet To Be Delivered Are : \n"<<count<<"\n";
}

void Pizza :: showMenu(int p1,int p2)
{
	int type=0;
	int v1=200,v2=300,v3=400,v4=500,v5=600;
	int nv1=250,nv2=350,nv3=450,nv4=550,nv5=650;

	if(p1==1)
	{
		cout<<"\nWhich Pizza Do You Prefer ?\n1 : Veg\n2 : Non Veg\n";
		cin>>type;

		switch(type)
		{
			case 1:
			cout<<"\n11 : Margherita : "<<v1<<"\n12 : Farmhouse : "<<v2<<"\n13 : Country Special : "<<v3<<"\n14 : 5 Pepper : "<<v4<<"\n15 : Chef's Veg Wonder : "<<v5<<"\n";
			break;

			case 2:
			cout<<"\n21 : Cheese And BBQ Chicken : "<<nv1<<"\n22 : Chicken Fiesta : "<<nv2<<"\n23 : Chicken Mexicana : "<<nv3<<"\n24 : Chicken Lovers : "<<nv4<<"\n25 : Chef's Non Veg Wonder : "<<nv5<<"\n";
			break;
		}
	}
	else if((p1==2)&&(p2!=0))
	{
		switch(p2)
		{
			case 11:
			cout<<"\nMargherita Has Been Delivered !!!\nCost Of Pizza Is : "<<v1<<"\n";
			break;

			case 12:
			cout<<"\nFarmhouse Has Been Delivered !!!\nCost Of Pizza Is : "<<v2<<"\n";
			break;

			case 13:
			cout<<"\nCountry Special Has Been Delivered !!!\nCost Of Pizza Is : "<<v3<<"\n";
			break;

			case 14:
			cout<<"\n5 Pepper Has Been Delivered !!!\nCost Of Pizza Is : "<<v4<<"\n";
			break;

			case 15:
			cout<<"\nChef's Veg Wonder Has Been Delivered !!!\nCost Of Pizza Is : "<<v5<<"\n";
			break;

			case 21:
			cout<<"\nCheese And BBQ Chicken Has Been Delivered !!!\nCost Of Pizza Is : "<<nv1<<"\n";
			break;

			case 22:
			cout<<"\nChicken Fiesta Has Been Delivered !!!\nCost Of Pizza Is : "<<nv2<<"\n";
			break;

			case 23:
			cout<<"\nChicken Mexicana Has Been Delivered !!!\nCost Of Pizza Is : "<<nv3<<"\n";
			break;

			case 24:
			cout<<"\nChicken Lovers Has Been Delivered !!!\nCost Of Pizza Is : "<<nv4<<"\n";
			break;

			case 25:
			cout<<"\nChef's Non Veg Wonder Has Been Delivered !!!\nCost Of Pizza Is : "<<nv5<<"\n";
			break;
		}
	}
	else if(p1==3)
	{
		switch(p2)
		{
			case 11:
			cout<<"\nMargherita !!!\nCost Of Pizza Is : "<<v1<<"\n";
			break;

			case 12:
			cout<<"\nFarmhouse !!!\nCost Of Pizza Is : "<<v2<<"\n";
			break;

			case 13:
			cout<<"\nCountry Special !!!\nCost Of Pizza Is : "<<v3<<"\n";
			break;

			case 14:
			cout<<"\n5 Pepper !!!\nCost Of Pizza Is : "<<v4<<"\n";
			break;

			case 15:
			cout<<"\nChef's Veg Wonder !!!\nCost Of Pizza Is : "<<v5<<"\n";
			break;

			case 21:
			cout<<"\nCheese And BBQ Chicken !!!\nCost Of Pizza Is : "<<nv1<<"\n";
			break;

			case 22:
			cout<<"\nChicken Fiesta !!!\nCost Of Pizza Is : "<<nv2<<"\n";
			break;

			case 23:
			cout<<"\nChicken Mexicana !!!\nCost Of Pizza Is : "<<nv3<<"\n";
			break;

			case 24:
			cout<<"\nChicken Lovers !!!\nCost Of Pizza Is : "<<nv4<<"\n";
			break;

			case 25:
			cout<<"\nChef's Non Veg Wonder !!!\nCost Of Pizza Is : "<<nv5<<"\n";
			break;
		}
	}
}

int Pizza ::viewFirstPizza()
{
	int tmp;

	if(front==(-1))
	{
		cout<<"\nAll Pizzas have Already Been Delivered !!!\n";
		return 0;
	}
	else
	{
		cout<<"\nServing Up Next : \n";
		tmp=bake[front];
		return tmp;
	}
}

int Pizza ::viewLastPizza()
{
	int tmp;

	if(front==(-1))
	{
		cout<<"\nAll Pizzas have Already Been Delivered !!!\n";
		return 0;
	}
	else if(front==rear)
	{
		cout<<"\nOnly One Pizza Delivery Is Remaining, Which Is : \n";
		tmp=bake[rear];
		return tmp;
	}
	else
	{
		cout<<"\nLast Pizza To Be Delivered Is : \n";
		tmp=bake[rear];
		return tmp;
	}
}

int main()
{
	Pizza pizza;
	int op=0;
	int piz;

	do
	{
		cout<<"\nWhich Operation Do You Want To Perform ?\n1 : Display Menu\n2 : Book Pizza\n3 : Deliver Pizza\n4 : Get Number Of Pizzas Yet To Be Delivered\n5 : Get Next Pizza To Be Delivered\n6 : Get Last Pizza to Be Delivered\n7 : Exit\n";
		cin>>op;

		switch(op)
		{
			case 1:
			pizza.showMenu(1,1);
			break;

			case 2:
			cout<<"\nEnter Your Choice : \n";
			cin>>piz;
			pizza.addPizza(piz);
			break;

			case 3:
			piz=pizza.deliverPizza();
			pizza.showMenu(2,piz);
			break;

			case 4:
			pizza.gettotalpizzas();
			break;

			case 5:
			piz=pizza.viewFirstPizza();
			pizza.showMenu(3,piz);
			break;

			case 6:
			piz=pizza.viewLastPizza();
			pizza.showMenu(3,piz);
			break;

			case 7:
			cout<<"\nThank You For Visiting Our Pizza Parlor !!!\n";
		}
	}while(op!=7);

	return 0;
}


