// customer menu
void customer()
{
	top://label
	cout<<"Menu :\n1.Purchase Item\n2.Show All Product\n3.View Bill\n4.Back To Main Menu\n";
	int i;
	i=getch();
	switch(i)
	{
		case 49:
			pur();
			break;
		case 50:
			showu();
			break;
		case 51:
			bill();
			break;
		case 52:
			menu();
			break;
		default:
			cout<<"\nWrong Option :(";
	}
	getch();
	goto top;
}

	