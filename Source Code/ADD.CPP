// add new product
#include<iostream>
#include<fstream>
void add()
{
	item t;
	ofstream f("item.dat",ios::app|ios::binary);//write into the file in binary mode
	t.enter(1);//calling the enter function with the arguement
	f.write((char*)&t,sizeof(t));
	f.close();
}