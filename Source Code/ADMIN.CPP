//admin
void admin()
{
	//change();
	password();//calling password function
	top://label
	cout<<"Menu :\n1.Add New Item\n2.Show All Product\n3.Delete Product\n4.Modify Product\n5.Reorder Product\n6.Change Password\n7.Back To Main Menu\n";
	int i;
	i=getch();
	switch(i)
	{
		case 49:
			add();
			break;
		case 50:
			showad();
			break;
		case 51:
			del();
			break;
		case 52:
			modify();
			break;
		case 53:
			reorder();
			break;
		case 54:
			change();
			break;
		case 55:
			menu();
			break;
		default:
			cout<<"\nWrong Option :(";
	}
	getch();
	goto top;
}
