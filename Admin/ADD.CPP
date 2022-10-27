// add new product
#include<iostream>
#include<fstream>
void add()
{
	item t;
	ofstream f("item.dat",ios::app|ios::binary);
	t.enter(1);
	f.write((char*)&t,sizeof(t));
	f.close();
}