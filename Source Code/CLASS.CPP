//class
class item
{
	private:
		int id,price,cp,stock;
		float profit;
		char name[50],unit[10];
	public:
		void enter(int z)//function definition
		{
			Number n;
			if(z==1)
				id=n.ReadItemNo();
			cout<<"\n\nEnter Product Details\n\nProduct id : "<<id;
			cout<<"\n\nEnter Product Name : ";cin>>name;
			cout<<"\nEnter Unit Of Product : ";cin>>unit;
			cout<<"\nEnter Cost Price of Product : ";cin>>cp;
			cout<<"\nEnter Selling Price of Product : ";cin>>price;
			pro();
			cout<<"\nEnter Current Stock ";cin>>stock;
			cout<<"\n\nNew Product "<<name<<" Added in Stock ";
			if(z==1)
				n.SetItemNo();
		}
		void pro()//function definition
		{
			profit=((price-cp)*(100/cp));
			cout<<"\t\tProfit : "<<profit<<" %\n";
		}
		void showu()//function definition
		{
			cout<<setw(7)<<id<<setw(17)<<name<<setw(10)<<price<<setw(17)<<stock<<" "<<unit;
		}
		void showad()//function defintion
		{
			cout<<setw(4)<<id<<setw(10)<<name<<setw(10)<<cp<<setw(10)<<price<<setw(10)<<profit<<setw(7)<<stock<<" "<<unit;
		}
		int compare(int n)//function defintion
		{
			if(n==id)
				return 1;
			else
				return 2;
		}
		void order(int n)//function definition
		{
			int j;
			if(n==1)
				{
					cout<<"\nEnter Amount of "<<name<<" to be Reodered : ";
					cin>>j;
					stock+=j;
					cout<<"\n"<<j<<" "<<unit<<" "<<name<<" Reordered . Updated Stock :"<<stock<<" "<<unit;
					getch();
				}
		}
		void purchase(int &amt, int z)//function definition
		{
			int qty;
			cout<<"\n Enter Qty. of "<<name<<" you want to purchase : ";
			cin>>qty;
			if(qty<=stock)
			{
				cout<<"\n\nYou want to purchase "<<qty<<" "<<unit<<" of "<<name<<" at price "<<price;
				amt=qty*price;
				cout<<"\n\nTotal Amount : "<<amt;
				cout<<"\n\nConfirm Purchase (y/n) : ";
				char ch=getch();
				if(ch=='y' || ch=='Y')
				{
					stock-=qty;
					cout<<"\n"<<qty<<" "<<unit<<" of "<<name<<" Purchased ";
					makebill(qty,z);
				}
				else
				{
					cout<<" Purchase CANCELLED ";
					amt=0;
				}
			}
			else
			{
				cout<<"\n"<<qty<<" "<<unit<<" "<<name<<" is not available in stock ";
				cout<<"\n\nKindly order Less than "<<qty<<" "<<unit<<" or Visit Later ";
				amt=0;
			}
		}
		void makebill(int Qty,int z)//function definition
		{

			ofstream f("bill.dat",ios::binary|ios::app);//write to file
			struct B
			{
				int billno;
				char Name[50],Unit[20];
				int Qty;
				float Price,Amount;
			};
			B bill;
			bill.billno=z;
			strcpy(bill.Name,name);
			bill.Qty=Qty;
			bill.Price=price;
			bill.Amount=Qty*price;
			strcpy(bill.Unit,unit);
			f.write((char*)&bill,sizeof(bill));
			getch();
			f.close();
		}

};


