// to create Back up of the file 
void backup()
{
	item t;//object of the class item 
	char ch;
	cout<<"\n\n1.To Backup Data\n2.To Retrieve Backup Data\n";
	ch=getch();
	if(ch=='1')
	{
		ifstream org("item.dat",ios::binary);//read the file 
		ofstream copy("backup.dat",ios::binary);//write to file
		while(org.read((char*)&t,sizeof(t)))
		{
			copy.write((char*)&t,sizeof(t));
		}
		cout<<"\n\nFile Backed Up ";
		org.close();
		copy.close();
	}
	else if(ch=='2')
	{
		ifstream back("backup.dat",ios::binary);//read the file
		ofstream dest("item.dat",ios::binary);//write to file
		while(back.read((char*)&t,sizeof(t)))
		{
			dest.write((char*)&t,sizeof(t));
		}
		cout<<"\n\nData Retrieved ";
		dest.close();
		back.close();
	}
	else
		cout<<"\n\n Invalid Input ..\try again";
		getch();
}
		

	