struct B
{
		int billno;
		char Name[50],Unit[20];
		int Qty;
		float Price,Amount;

};
int no()
{
		B t;int i=0,billno;
			fstream f("bill.dat",ios::binary|ios::in|ios::out);
			cout<<"\n\n "<<sizeof(t);
			f.seekg((-6),ios::end);
			f.read((char*)&t,sizeof(t));
			if(t.billno<1 || t.billno>1000)
				billno=1;
			else
				billno=(t.billno+1);
			f.close();
			return billno;
}
void showbill(int BillNumber)
{
	B b;
	int Final=0;
	int k=1;
	ifstream f("bill.dat",ios::binary);
	cout<<"Here 's Your Bill ";
	cout<<"\n\n*******************************************************************************";
	cout<<setw(42)<<"\n"<<"CSS Shop\n";
	cout<<setw(40)<<"\n"<<"TIN No. 123456789";
	cout<<"\n\n Bill Number : "<<BillNumber;
	cout<<"\n--------------------------------------------------------------------------------";
	cout<<"\nS. No."<<"\t"<<"Name"<<"\t\t"<<"Qty"<<"\t"<<"Price"<<"\t"<<"Amount";
	cout<<"\n--------------------------------------------------------------------------------";
	while(f.read((char*)&b,sizeof(b)))
	{
		if(BillNumber==b.billno)
		 {
			cout<<"\n"<<k<<"\t"<<b.Name<<"\t"<<b.Qty<<" "<<b.Unit<<"\t"<<b.Price<<"\t"<<b.Amount<<"\n";
			Final+=b.Amount;
			k++;
		 }
	}
	cout<<"--------------------------------------------------------------------------------";
	cout<<"\n"<<"Total"<<"\t"<<Final;
	cout<<"\n--------------------------------------------------------------------------------";
	cout<<"\n"<<setw(40)<<"Thank You "<<"\n"<<setw(43)<<"Plz Visit Again ";
	cout<<"\n********************************************************************************";
	f.close();
}
void bill()
{
	cout<<"Enter Bill Number ";
	int n,k=0;;
	cin>>n;
	ifstream f("bill.dat",ios::binary);
	B b;
	while(f.read((char*)&b,sizeof(b)))
	{
		if(n==b.billno)
		 {
			k++;
		 }
	}
	if(k!=0)
		showbill(n);
	else
		cout<<" Bill No. Does Not Exist ";
	getch();
}





