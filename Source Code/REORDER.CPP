//reorder function
void reorder()
{
	int i,n,k=0,j=0;
	item s;//object of item class
	
	showad();//function call
	cout<<"\n\nEnter Product ID of Product To be Reorder : ";
	cin>>n;
	fstream f("item.dat",ios::binary|ios::in|ios::out);//read and write to file
	f.read((char *)&s,sizeof(s));
	while(f)
	{
		if(s.compare(n)==1)
		{
			f.seekg(k*sizeof(s),ios::beg);
			s.order(1);
			f.write((char*)&s,sizeof(s));
			j++;
		}
	f.read((char*)&s,sizeof(s));
	k++;
	}
	if(j==0)
		cout<<"\n\nProduct ID Does Not Exist ";
f.close();
}
