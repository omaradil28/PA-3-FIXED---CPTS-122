#include"header.h"

int main()
{
	Node* pList = NULL;
	Record music[100];


	int menu_num = 0,
		finish = 0,
		exit = 0,
		count = 0;
	int edit_n = 0;
	load(menu_num, &pList); //USE THIS IF YOU DONT WANT TO LOAD EVERYTIME YOU RUN THE CODE

	do
	{
		menu_num = menu();
		system("cls");

		if (menu_num == 1)
		{
			load(menu_num, &pList);
		}
		else if (menu_num == 2)
		{
			store(pList);
		}
		else if (menu_num == 3)
		{
			display(pList);
		}
		else if (menu_num == 4)
		{
			insert(&pList);
		}
		else if (menu_num == 5)
		{
			delete(&pList);
		}
		else if (menu_num == 6)
		{
			edit(menu_num, pList);
		}
		else if (menu_num == 7)
		{
			sort(&pList);
		}
		else if (menu_num == 8)
		{
			rate(pList);
		}
		else if (menu_num == 9)
		{
			play(pList);
		}
		else if (menu_num == 10)
		{
			shuffle(pList);
		}
		else if (menu_num == 11)
		{
			test();
		}
		count++;
	} while (menu_num != 12);

	exit_(pList);


	return 0;
}