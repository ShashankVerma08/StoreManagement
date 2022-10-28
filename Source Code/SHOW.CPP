//show
void showu()
{
	item t;
	ifstream f("item.dat",ios::binary);//read from the file
	cout<<setw(5)<<"Item ID"<<setw(17)<<"Product Name"<<setw(10)<<"Price"<<setw(22)<<"Stock Available\n";
	while(f.read((char*)&t,sizeof(t)))
	{
		t.showu();
		cout<<endl;
	}
}
void showad()
{
	item t;
	ifstream f("item.dat",ios::binary);//read from the file
	cout<<setw(4)<<"ID"<<setw(10)<<"Name"<<setw(10)<<"Cost"<<setw(10)<<"Price"<<setw(10)<<"Profit%"<<setw(11)<<"In Stock"<<setw(10)<<"Min Qty"<<setw(15)<<"Reorder Qty\n\n" ;
	while(f.read((char*)&t,sizeof(t)))
	{
		t.showad();
		cout<<endl;
	}
}