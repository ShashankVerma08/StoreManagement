// purchase
void pur()
{
	int i,n,amt=0,bill=0;
	item s;//object of class item
	Number no;//object of class Number
	int BillNumber=no.ReadBillNo();
	again://label
	int j=0,k=0;
	showu();//function call
	cout<<"\n\nEnter Product ID of Product You Want To Purchase : ";
	cin>>n;
	fstream f("item.dat",ios::binary|ios::in|ios::out);//read and write to file
	f.read((char *)&s,sizeof(s));
	while(f)
	{
		if(s.compare(n)==1)
		{
			f.seekg(k*sizeof(s),ios::beg);
			s.purchase(amt,BillNumber);
			f.write((char*)&s,sizeof(s));
			j++;
		}
	f.read((char*)&s,sizeof(s));
	k++;
	}
	if(j==0)
		cout<<"\n\nProduct ID Does Not Exist ";
	bill+=amt;
	getch();
	cout<<"\n\nDo You want To Purchase More (y/n) : ";
	char ch=getch();
	if(ch=='y'||ch=='Y')
		goto again;
	showbill(BillNumber);//function call
	no.SetBillNo();

}
