#include "header.h"

int menu()
{
	int num = 0;
	printf("Welcome to Music Manager!\nPlease choose one of the following numbers:\n\n");
	printf("(1). Load\n");
	printf("(2). Store\n");
	printf("(3). Display\n");
	printf("(4). Insert\n");
	printf("(5). Delete\n");
	printf("(6). Edit\n");
	printf("(7). Sort\n");
	printf("(8). Rate\n");
	printf("(9). Play\n");
	printf("(10). Shuffle\n");
	printf("(11). Test\n");
	printf("(12). Exit\n\n");

	printf("Selection: ");
	scanf("%d", &num);

	return num;
}

Node* createNode(Record record)
{
	Node* newNode = malloc(sizeof(Node));
	if (newNode != NULL)
	{
		memcpy(&(newNode->data), &record, sizeof(Record)); //Copies the data from record to the node byte by byte
		newNode->pPrev = newNode->pNext = NULL; //Makes sure pPrev / pNext is set to NULL
	}
	return newNode;
}

bool insertAtFront(Node** pList, Record record)
{
	bool success = false;
	Node* newNode = createNode(record);

	if (newNode != NULL) //If not null, it means it was correctly allocated
	{
		success = true;
		if (*pList != NULL) //Checks to see if theres data in the list
		{
			(*pList)->pPrev = newNode; //Links current node to the new node
			newNode->pNext = *pList;
		}
		*pList = newNode;
	}
	return success;
}

void load(int num, Node** pList)
{
	FILE* file = fopen("music.csv", "r");
	Record record;
	int i = 0;
	static int first = 1;
	if (first)
	{
		while (!feof(file))
		{
			char line[200];
			fgets(line, 200, file);

			if (line[0] == '"')
			{
				strncpy(record.artist, strtok(line, "\""), 50);
				//strncpy(record.artist, strtok(NULL, "\""), 50);
			}
			else
			{
				strncpy(record.artist, strtok(line, ","), 50);
			}

			strncpy(record.album, strtok(NULL, ","), 50);
			strncpy(record.name, strtok(NULL, ","), 50);
			strncpy(record.genre, strtok(NULL, ","), 50);
			record.length.minutes = atoi(strtok(NULL, ":"));
			record.length.seconds = atoi(strtok(NULL, ","));
			record.plays = atoi(strtok(NULL, ","));
			record.rate = atoi(strtok(NULL, "\n"));

			static int first = 1;


			insertAtFront(pList, record);

		}
		first = 0;
	}
	if (num == 1)
	{
		int j = 0;
		while (j != 2)
		{
			printf("Load Menu\n\n");
			printf("Loading");
			Sleep(500);
			system("cls");
			printf("Load Menu\n\n");
			printf("Loading.");
			Sleep(500);
			system("cls");
			printf("Load Menu\n\n");
			printf("Loading..");
			Sleep(500);
			system("cls");
			printf("Load Menu\n\n");
			printf("Loading...");
			Sleep(500);
			system("cls");

			j++;
		}
		printf("Load Menu\n\nLoading Successful!");
		printf("\n(Press any button to continue)");
		_getch();
		system("cls");
	}
	fclose(file);
}

void store(Node* list)
{
	FILE* write = fopen("music.csv", "w");
	while (list != NULL)
	{
		fprintf(write, "(%s), %s, %s, %s, %d:%d, %d, %d\n", list->data.artist, list->data.album, list->data.name, list->data.genre, list->data.length.minutes, list->data.length.seconds, list->data.plays, list->data.rate);
		list = list->pNext;
	}

	int j = 0;
	while (j != 1)
	{
		printf("Store Menu\n\n");
		printf("Storing");
		Sleep(500);
		system("cls");
		printf("Store Menu\n\n");
		printf("Storing.");
		Sleep(500);
		system("cls");
		printf("Store Menu\n\n");
		printf("Storing..");
		Sleep(500);
		system("cls");
		printf("Store Menu\n\n");
		printf("Storing...");
		Sleep(500);
		system("cls");

		j++;
	}
	printf("Store Menu\n\nMusic has been stored successfully!");
	printf("\n(Press any button to continue)");
	_getch();
	system("cls");
}

void display(Node* list)
{
	int choice = 0;
	int choice2 = 0;

	do
	{
		printf("Display Menu\n\n1. Print All Records\n2. Print all records that match an artist\n3. Exit\n\n(Choose the number associated with your choice)\nSelection:");
		scanf("%d", &choice);
		Node* temp = list;
		Node* temp2 = list;

		if (choice > 3 || choice < 1)
		{
			printf("\nInvalid choice. Please try again.\n(Press any button to continue)");
			_getch();
			system("cls");
		}

		if (choice == 1)
		{
			system("cls");
			int num = 1;
			printf("Display Menu\n\n");
			while (temp != NULL)
			{
				printf("%d: (%s), %s, %s, %s, %d:%d, %d, %d\n", num, temp->data.artist, temp->data.album, temp->data.name, temp->data.genre, temp->data.length.minutes, temp->data.length.seconds, temp->data.plays, temp->data.rate);
				temp = temp->pNext;
				num++;
			}
			printf("\n\n(Press any button to continue)");
			_getch();
			system("cls");
		}
		else if (choice == 2)
		{
			system("cls");
			char* artists[100];
			int index = 0;
			int count = 0;
			bool shouldInsert;
			
			
				
				printf("Display Menu\n\Please choose one of the artists to display their records:\n\n");

				while (temp != NULL)
				{

					char* name = &(temp->data.artist[0]);
					shouldInsert = true;
					while (index < count && shouldInsert)
					{
						if (strcmp(name, artists[index]) == 0)
						{
							shouldInsert = false;
						}
						index++;
					}
					index = 0;
					if (shouldInsert)
					{
						printf("%d. %s\n", count + 1, name);
						artists[count] = name;
						++count;
					}
					temp = temp->pNext;
				}


				printf("\nSelection: ");
				scanf("%d", &choice2);

			printf("\n");
			int count2 = 0;
			while (temp2 != NULL)
			{
				if (strcmp(artists[choice2 - 1], temp2->data.artist) == 0)
				{
					count2++;
					printf("%d: (%s), %s, %s, %s, %d:%d, %d, %d\n", count2, temp2->data.artist, temp2->data.album, temp2->data.name, temp2->data.genre, temp2->data.length.minutes, temp2->data.length.seconds, temp2->data.plays, temp2->data.rate);
				}
				temp2 = temp2->pNext;
			}
			printf("\n(Press any button to continue)");
			_getch();
			system("cls");
		}

	} while (choice != 3);
	system("cls");
}

void insert(Node** list)
{
	char artist[50];
	char album[50];
	char name[50];
	char genre[50];

	int minutes = 0;
	int seconds = 0;
	int plays = 0;
	int rate = 0;
	Record record;

	printf("Record Insertion Menu\n\nPlease enter the following information to create a new record:\n\n1. Artist\n2. Album\n3. Song Title\n4. Genre\n5. Minutes Length\n6. Seconds Length\n8. Number of Plays\n9. Rating");
	printf("\n\n(Press any button to continue)");
	_getch();
	system("cls");

	printf("Artist Name: ");
	scanf("%s", &artist);
	printf("\n");
	strcpy(record.artist, artist);
	system("cls");

	printf("Album Name: ");
	scanf("%s", &album);
	printf("\n");
	strcpy(record.album, album);
	system("cls");

	printf("Song Title: ");
	scanf("%s", &name);
	printf("\n");
	strcpy(record.name, name);
	system("cls");

	printf("Genre Name: ");
	scanf("%s", &genre);
	printf("\n");
	strcpy(record.genre, genre);
	system("cls");
	do
	{
		printf("Time in Minutes: ");
		scanf("%d", &minutes);
		printf("\n");
		record.length.minutes = minutes;
		system("cls");
	} while (minutes < 0);

	do
	{
		printf("Time in Seconds: ");
		scanf("%d", &seconds);
		printf("\n");
		record.length.seconds = seconds;
		system("cls");
	} while (seconds < 0);

	do
	{
		printf("Number of Plays: ");
		scanf("%d", &plays);
		printf("\n");
		record.plays = plays;
		system("cls");
	} while (plays < 0);

	do
	{
		printf("Rating Number (1-5): ");
		scanf("%d", &rate);
		printf("\n");
		record.rate = rate;
		system("cls");
	} while (rate > 5 || rate < 1);

	insertAtFront(list, record);
	system("cls");
}

void delete(Node** list)
{
	Node* temp = *list;

	Node* cur = *list;
	Node* prev = NULL;
	printf("Delete Menu\n\n");
	int num = 1;

	while (temp != NULL)
	{
		printf("%d: (%s), %s, %s, %s, %d:%d, %d, %d\n", num, temp->data.artist, temp->data.album, temp->data.name, temp->data.genre, temp->data.length.minutes, temp->data.length.seconds, temp->data.plays, temp->data.rate);
		temp = temp->pNext;
		num++;
	}
	printf("\nPlease enter the song title associated with the record you would like to delete.\nTitle: ");
	
	char deleted[SIZEOFBUFFER];

		int word;

		while ((word = getchar()) != '\n' && word != EOF);

		fgets(deleted, sizeof(deleted), stdin);

		deleted[strcspn(deleted, "\n")] = '\0';

		if (deleted[0] == '\0')
			return;

		while (cur != NULL)
		{
			if (strcmp(cur->data.name, deleted) == 0)
			{
				if (prev == NULL)
				{
					*list = cur->pNext;
				}
				else
				{
					prev->pNext = cur->pNext;
				}
				printf("The following record has been deleted:\n(%s), %s, %s, %s, %d:%d, %d, %d\n", cur->data.artist, cur->data.album, cur->data.name, cur->data.genre, cur->data.length.minutes, cur->data.length.seconds, cur->data.plays, cur->data.rate);
				printf("\n(Press any button to continue)");
				_getch();
				system("cls");
				free(cur);
				return;
			}
			if (strcmp(cur->data.name, deleted) != 0)
			{
				printf("\nThis song does not match any records\n");
				printf("\n(Press any button to continue)");
				_getch();
				system("cls");
				return;
			}
			prev = cur;
			cur = cur->pNext;
		}
}

int edit(int num, Node* list)
{
	int choice = 0;
	int choice2 = 0;
	int count = 0;
	do
	{
		printf("Edit Menu\n\n");
		Node* temp = list;
		Node* temp2 = list;
		Node* temp3 = list;
		Node* temp4 = list;
		Node* temp5 = list;

		Node* store = list;
		int aspect = 0;
		char artist[100],
			album[100],
			title[100],
			genre[100];
		int minute = 0,
			seconds = 0,
			plays = 0,
			rate = 0;

		char* artists[100];
		char* songname[100];
		int index = 0,
			count = 0,
			count1 = 0;
		bool shouldInsert;

		printf("Please choose one of the artists to display their records:\n\n");

		while (temp != NULL)
		{
			char* name = &(temp->data.artist[0]);
			shouldInsert = true;
			while (index < count && shouldInsert)
			{
				if (strcmp(name, artists[index]) == 0)
				{
					shouldInsert = false;
				}
				index++;
			}
			index = 0;
			if (shouldInsert)
			{
				printf("%d. %s\n", count + 1, name);
				artists[count] = name;
				++count;
			}
			temp = temp->pNext;
		}

		printf("\n%d. Exit", count + 1);
		printf("\n\nSelection: ");
		scanf("%d", &choice2);

		if (choice2 == count + 1)
		{
			break;
		}
		printf("\n");
		if (choice2 < count + 1 && choice2 > 0)
		{
			int count2 = 0;
			while (temp2 != NULL)
			{
				if (strcmp(artists[choice2 - 1], temp2->data.artist) == 0)
				{
					count2++;
				}
				temp2 = temp2->pNext;
			}
			if (count2 == 1)
			{
				while (temp3 != NULL)
				{
					if (strcmp(artists[choice2 - 1], temp3->data.artist) == 0)
					{

						system("cls");
						count2++;
						do
						{
							printf("%d: (%s), %s, %s, %s, %d:%d, %d, %d\n\n", count2 - 1, temp3->data.artist, temp3->data.album, temp3->data.name, temp3->data.genre, temp3->data.length.minutes, temp3->data.length.seconds, temp3->data.plays, temp3->data.rate);

							printf("Which aspect of the record would you like to edit? (1-8)\n\n1. Artist\n2. Album\n3. Title\n4. Genre\n5. Minute Length\n6. Second Length\n7. Plays\n8. Rating\n9. Exit\n\nSelection: ");
							scanf("%d", &aspect);

							if (aspect == 1)
							{
								printf("Enter Artist Name: ");
								scanf("%s", &artist);

								strcpy(temp3->data.artist, artist);
								system("cls");
								printf("Record Edited!\n\n%d: (%s), %s, %s, %s, %d:%d, %d, %d\n\n", count2 - 1, temp3->data.artist, temp3->data.album, temp3->data.name, temp3->data.genre, temp3->data.length.minutes, temp3->data.length.seconds, temp3->data.plays, temp3->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");

							}
							else if (aspect == 2)
							{
								printf("Enter Album Name: ");
								scanf("%s", &album);

								strcpy(temp3->data.album, album);
								system("cls");
								printf("Record Edited!\n\n%d: (%s), %s, %s, %s, %d:%d, %d, %d\n\n", count2 - 1, temp3->data.artist, temp3->data.album, temp3->data.name, temp3->data.genre, temp3->data.length.minutes, temp3->data.length.seconds, temp3->data.plays, temp3->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 3)
							{
								printf("Enter Title Name: ");
								scanf("%s", &title);

								strcpy(temp3->data.name, title);
								system("cls");
								printf("Record Edited!\n\n%d: (%s), %s, %s, %s, %d:%d, %d, %d\n\n", count2 - 1, temp3->data.artist, temp3->data.album, temp3->data.name, temp3->data.genre, temp3->data.length.minutes, temp3->data.length.seconds, temp3->data.plays, temp3->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 4)
							{
								printf("Enter Genre Name: ");
								scanf("%s", &genre);

								strcpy(temp3->data.genre, genre);
								printf("%s", temp->data.genre);
								_getch();
								system("cls");
								printf("Record Edited!\n\n%d: (%s), %s, %s, %s, %d:%d, %d, %d\n\n", count2 - 1, temp3->data.artist, temp3->data.album, temp3->data.name, temp3->data.genre, temp3->data.length.minutes, temp3->data.length.seconds, temp3->data.plays, temp3->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 5)
							{
								printf("Enter Minute Length: ");
								scanf("%d", &minute);

								temp3->data.length.minutes = minute;
								system("cls");
								printf("Record Edited!\n\n%d: (%s), %s, %s, %s, %d:%d, %d, %d\n\n", count2 - 1, temp3->data.artist, temp3->data.album, temp3->data.name, temp3->data.genre, temp3->data.length.minutes, temp3->data.length.seconds, temp3->data.plays, temp3->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 6)
							{
								printf("Enter Seconds Length: ");
								scanf("%d", &seconds);

								temp3->data.length.seconds = seconds;
								system("cls");
								printf("Record Edited!\n\n%d: (%s), %s, %s, %s, %d:%d, %d, %d\n\n", count2 - 1, temp3->data.artist, temp3->data.album, temp3->data.name, temp3->data.genre, temp3->data.length.minutes, temp3->data.length.seconds, temp3->data.plays, temp3->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 7)
							{
								printf("Enter Number of Plays: ");
								scanf("%d", &plays);

								temp3->data.plays = plays;
								system("cls");
								printf("Record Edited!\n\n%d: (%s), %s, %s, %s, %d:%d, %d, %d\n\n", count2 - 1, temp3->data.artist, temp3->data.album, temp3->data.name, temp3->data.genre, temp3->data.length.minutes, temp3->data.length.seconds, temp3->data.plays, temp3->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 8)
							{
								printf("Enter New Rating: ");
								scanf("%d", &rate);

								temp3->data.rate = rate;
								system("cls");
								printf("Record Edited!\n\n%d: (%s), %s, %s, %s, %d:%d, %d, %d\n\n", count2 - 1, temp3->data.artist, temp3->data.album, temp3->data.name, temp3->data.genre, temp3->data.length.minutes, temp3->data.length.seconds, temp3->data.plays, temp3->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect > 9 || aspect < 1)
							{
								printf("\nInvalid choice. Please try again.\n(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 9)
							{
								break;
							}
						} while (aspect > 9 || aspect < 1);
						system("cls");
					}
					temp3 = temp3->pNext;
				}
			}
			else if (count2 > 1)
			{
				int song = 0;
				int number = 0;
				do
				{
					number = 0;
					while (temp4 != NULL)
					{
						if (strcmp(artists[choice2 - 1], temp4->data.artist) == 0)
						{
							number++;
							printf("%d: (%s), %s, %s, %s, %d:%d, %d, %d\n", number, temp4->data.artist, temp4->data.album, temp4->data.name, temp4->data.genre, temp4->data.length.minutes, temp4->data.length.seconds, temp4->data.plays, temp4->data.rate);
							char* songn = &(temp4->data.name[0]);
							songname[count1] = songn;
							++count1;

						}
						temp4 = temp4->pNext;
					}

					printf("\nWhich record would you like to edit?\nSelection: ");
					scanf("%d", &song);

				} while (song > number || song < 1);

				while (temp5 != NULL)
				{
					if (strcmp(songname[song - 1], temp5->data.name) == 0)
					{
						system("cls");
						count2++;
						do
						{
							printf("Record Edited!\n\n(%s), %s, %s, %s, %d:%d, %d, %d\n\n", temp5->data.artist, temp5->data.album, temp5->data.name, temp5->data.genre, temp5->data.length.minutes, temp5->data.length.seconds, temp5->data.plays, temp5->data.rate);

							printf("Which aspect of the record would you like to edit? (1-8)\n\n1. Artist\n2. Album\n3. Title\n4. Genre\n5. Minute Length\n6. Second Length\n7. Plays\n8. Rating\n9. Exit\n\nSelection: ");
							scanf("%d", &aspect);

							if (aspect == 1)
							{
								printf("Enter Artist Name: ");
								scanf("%s", &artist);

								strcpy(temp5->data.artist, artist);
								system("cls");
								printf("Record Edited!\n\n(%s), %s, %s, %s, %d:%d, %d, %d\n\n", temp5->data.artist, temp5->data.album, temp5->data.name, temp5->data.genre, temp5->data.length.minutes, temp5->data.length.seconds, temp5->data.plays, temp5->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");

							}
							else if (aspect == 2)
							{
								printf("Enter Album Name: ");
								scanf("%s", &album);

								strcpy(temp5->data.album, album);
								system("cls");
								printf("Record Edited!\n\n(%s), %s, %s, %s, %d:%d, %d, %d\n\n", temp5->data.artist, temp5->data.album, temp5->data.name, temp5->data.genre, temp5->data.length.minutes, temp5->data.length.seconds, temp5->data.plays, temp5->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 3)
							{
								printf("Enter Title Name: ");
								scanf("%s", &title);

								strcpy(temp5->data.name, title);
								system("cls");
								printf("Record Edited!\n\n(%s), %s, %s, %s, %d:%d, %d, %d\n\n", temp5->data.artist, temp5->data.album, temp5->data.name, temp5->data.genre, temp5->data.length.minutes, temp5->data.length.seconds, temp5->data.plays, temp5->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 4)
							{
								printf("Enter Genre Name: ");
								scanf("%s", &genre);

								strcpy(temp5->data.genre, genre);
								printf("%s", temp->data.genre);
								_getch();
								system("cls");
								printf("Record Edited!\n\n(%s), %s, %s, %s, %d:%d, %d, %d\n\n", temp5->data.artist, temp5->data.album, temp5->data.name, temp5->data.genre, temp5->data.length.minutes, temp5->data.length.seconds, temp5->data.plays, temp5->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 5)
							{
								printf("Enter Minute Length: ");
								scanf("%d", &minute);

								temp5->data.length.minutes = minute;
								system("cls");
								printf("Record Edited!\n\n(%s), %s, %s, %s, %d:%d, %d, %d\n\n", temp5->data.artist, temp5->data.album, temp5->data.name, temp5->data.genre, temp5->data.length.minutes, temp5->data.length.seconds, temp5->data.plays, temp5->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 6)
							{
								printf("Enter Seconds Length: ");
								scanf("%d", &seconds);

								temp5->data.length.seconds = seconds;
								system("cls");
								printf("Record Edited!\n\n(%s), %s, %s, %s, %d:%d, %d, %d\n\n", temp5->data.artist, temp5->data.album, temp5->data.name, temp5->data.genre, temp5->data.length.minutes, temp5->data.length.seconds, temp5->data.plays, temp5->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 7)
							{
								printf("Enter Number of Plays: ");
								scanf("%d", &plays);

								temp5->data.plays = plays;
								system("cls");
								printf("Record Edited!\n\n(%s), %s, %s, %s, %d:%d, %d, %d\n\n", temp5->data.artist, temp5->data.album, temp5->data.name, temp5->data.genre, temp5->data.length.minutes, temp5->data.length.seconds, temp5->data.plays, temp5->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 8)
							{
								printf("Enter New Rating: ");
								scanf("%d", &rate);

								temp5->data.rate = rate;
								system("cls");
								printf("Record Edited!\n\n(%s), %s, %s, %s, %d:%d, %d, %d\n\n", temp5->data.artist, temp5->data.album, temp5->data.name, temp5->data.genre, temp5->data.length.minutes, temp5->data.length.seconds, temp5->data.plays, temp5->data.rate);
								printf("(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect > 9 || aspect < 1)
							{
								printf("\nInvalid choice. Please try again.\n(Press any button to continue)");
								_getch();
								system("cls");
							}
							else if (aspect == 9)
							{
								break;
							}
						} while (aspect > 9 || aspect < 1);
						system("cls");
					}
					temp5 = temp5->pNext;
				}
			}

		}
		else if (choice2 < 1 || choice2 > count + 1)
		{
			printf("Invalid choice. Please try again.\n(Press any button to continue)");
			_getch();
			system("cls");
		}

	} while (choice2 != count + 1);

	system("cls");
}

void sort(Node** list)
{
	int choice = 0;
	do
	{
		Node* temp = list;
		printf("Sort Menu\nHow would you like your records sorted?\n\n1. Sort based on Artist (A-Z)\n2. Sort based on Album Title (A-Z)\n3. Sort based on rating (1-5)\n4. Sort based on times played (largest-smallest)\n\n5. Exit\n\nSelection: ");
		scanf("%d", &choice);

		if (choice == 1)
		{
			system("cls");
			Node* temp = *list;
			Node* cur = NULL;
			Record rec;
			int num = 1;

			printf("Sort Menu\nArtist Alphabetical Order:\n\n");
			while (temp != NULL)
			{
				cur = temp->pNext;
				while (cur != NULL)
				{
					if (strcmp(temp->data.artist, cur->data.artist) > 0)
					{
						rec = temp->data;
						temp->data = cur->data;
						cur->data = rec;
					}
					cur = cur->pNext;
				}
				printf("%d: (%s), %s, %s, %s, %d:%d, %d, %d\n", num, temp->data.artist, temp->data.album, temp->data.name, temp->data.genre, temp->data.length.minutes, temp->data.length.seconds, temp->data.plays, temp->data.rate);
				num++;
				temp = temp->pNext;
			}
			printf("\n(Press any button to continue)");
			_getch();
			system("cls");
		}
		else if (choice == 2)
		{
			system("cls");
			Node* temp = *list;
			Node* cur = NULL;
			Record rec;
			int num = 1;

			printf("Sort Menu\nAlbum Alphabetical Order:\n\n");
			while (temp != NULL)
			{
				cur = temp->pNext;
				while (cur != NULL)
				{
					if (strcmp(temp->data.album, cur->data.album) > 0)
					{
						rec = temp->data;
						temp->data = cur->data;
						cur->data = rec;
					}
					cur = cur->pNext;
				}
				printf("%d: (%s), %s, %s, %s, %d:%d, %d, %d\n", num, temp->data.artist, temp->data.album, temp->data.name, temp->data.genre, temp->data.length.minutes, temp->data.length.seconds, temp->data.plays, temp->data.rate);
				num++;
				temp = temp->pNext;
			}
			printf("\n(Press any button to continue)");
			_getch();
			system("cls");
		}
		else if (choice == 3)
		{
			system("cls");
			Node* temp = *list;
			Node* cur = NULL;
			Record rec;
			int num = 1;

			printf("Sort Menu\nNumerical Rating Order (1-5):\n\n");
			while (temp != NULL)
			{
				cur = temp->pNext;
				while (cur != NULL)
				{
					if (temp->data.rate > cur->data.rate)
					{
						rec = temp->data;
						temp->data = cur->data;
						cur->data = rec;
					}
					cur = cur->pNext;
				}
				printf("%d: (%s), %s, %s, %s, %d:%d, %d, %d\n", num, temp->data.artist, temp->data.album, temp->data.name, temp->data.genre, temp->data.length.minutes, temp->data.length.seconds, temp->data.plays, temp->data.rate);
				num++;
				temp = temp->pNext;
			}
			printf("\n(Press any button to continue)");
			_getch();
			system("cls");
		}
		else if (choice == 4)
		{
			system("cls");
			Node* temp = *list;
			Node* cur = NULL;
			Record rec;
			int num = 1;

			printf("Sort Menu\nNumerical Plays Order (Largest - Smallest):\n\n");
			while (temp != NULL)
			{
				cur = temp->pNext;
				while (cur != NULL)
				{
					if (temp->data.plays < cur->data.plays)
					{
						rec = temp->data;
						temp->data = cur->data;
						cur->data = rec;
					}
					cur = cur->pNext;
				}
				printf("%d: (%s), %s, %s, %s, %d:%d, %d, %d\n", num, temp->data.artist, temp->data.album, temp->data.name, temp->data.genre, temp->data.length.minutes, temp->data.length.seconds, temp->data.plays, temp->data.rate);
				num++;
				temp = temp->pNext;
			}
			printf("\n(Press any button to continue)");
			_getch();
			system("cls");
		}
		else if (choice > 5 || choice < 1)
		{
			printf("\nInvalid choice. Please try again.\n(Press any button to continue)");
			_getch();
			system("cls");
		}
	} while (choice != 5);
	system("cls");
}

void rate(Node* list)
{
	int choice = 0;
	int exit2 = 0;
	int rate = 0;
	do
	{
		int exit1 = 0;
		Node* temp = list;
		Node* temp1 = list;
		int num = 1;
		printf("Rate Menu\n\nPlease choose the number corresponding with the song you'd like to rate:\n\n");
		while (temp != NULL)
		{
			printf("%d: (%s), %s, %s, %s, %d:%d, %d, %d\n", num, temp->data.artist, temp->data.album, temp->data.name, temp->data.genre, temp->data.length.minutes, temp->data.length.seconds, temp->data.plays, temp->data.rate);
			temp = temp->pNext;
			num++;
			exit1++;
		}
		exit1 = num;
		exit2 = exit1;
		printf("\n%d: Exit", exit1);
		printf("\n\nSelection: ");
		scanf("%d", &choice);

		if (choice > exit1 || choice < 1)
		{
			printf("\nInvalid number. Try again\n(Press any button to continue)");
			_getch();
			system("cls");
		}
		else
		{
			num = 1;
			while (temp1 != NULL)
			{
				if (num == choice)
				{
					do
					{
						system("cls");
						printf("(%s), %s, %s, %s, %d:%d, %d, %d\n", temp1->data.artist, temp1->data.album, temp1->data.name, temp1->data.genre, temp1->data.length.minutes, temp1->data.length.seconds, temp1->data.plays, temp1->data.rate);
						printf("\nCurrent Rating: %d\n", temp1->data.rate);
						printf("\nWhat would you like your new rating to be (1-5)?\nSelection: ");
						scanf("%d", &rate);
						if (rate < 1 || rate > 5)
						{
							printf("\nInvalid number. Try again\n(Press any button to continue)");
							_getch();
						}
						else
						{
							temp1->data.rate = rate;
							system("cls");
							printf("Rating Successfully Changed!\n");
							printf("(%s), %s, %s, %s, %d:%d, %d, %d\n", temp1->data.artist, temp1->data.album, temp1->data.name, temp1->data.genre, temp1->data.length.minutes, temp1->data.length.seconds, temp1->data.plays, temp1->data.rate);
							printf("\n(Press any button to continue)");
							_getch();
							system("cls");
							break;
						}
					} while (rate < 6 || rate > 0);

				}
				temp1 = temp1->pNext;
				num++;
			}
		}
	} while (choice != exit2);
	system("cls");
}

void play(Node* list)
{
	int num = 1,
		userchoice = 0;

	Node* pCur = list;
	while (pCur != NULL) {
		printf("%d: (% s), % s\n", num, pCur->data.artist, pCur->data.name);
		pCur = pCur->pNext;
		num++;
	}
	printf("\n\nWhich song would you like to start from?\nSong Selection:");
	scanf("%d", &num);
	userchoice = num;
	system("cls");

	while (num != 1 && list != NULL)
	{
		list = list->pNext;
		num--;
	}

	while (list != NULL) {
		printf("%d: (%s), %s", userchoice, list->data.artist, list->data.name);
		list = list->pNext;
		Sleep(1000);
		system("cls");
		userchoice++;
	}
}

void shuffle(Node* list)
{
	srand(time(0));
	printf("Shuffle Menu\n\nMusic will be played in a randomized order!\n\n(Press any button to continue)");

	system("cls");
	Node* temp = list;

	int count = 0,
		random = 0;
	bool check;
	while (temp != NULL)
	{
		temp = temp->pNext;
		count++;
	}
	int arr[100];
	int tracker = 0;


	while (tracker < count && tracker < 100)
	{
		random = rand() % count + 1;
		check = true;
		for (int i = 0; i < count; i++)
		{
			if (arr[i] == random)
			{
				check = false;
				break;
			}
		}

		if (check)
		{
			arr[tracker] = random;
			tracker++;
		}
	}

	for (int i = 0; i < tracker+1; i++)
	{
		Node* temp1 = list;
		int numero = 0;
		int counter = 0;
		numero = arr[i];
		while (temp1 != NULL)
		{
			counter++;
			if (numero == counter)
			{
				printf("Song %d:\n%d: %s - %s", i+1, numero, temp1->data.artist, temp1->data.name);
				Sleep(1000);
				system("cls");
			}
			
			temp1 = temp1->pNext;
		}
	}
}

void exit_(Node* list)
{

	FILE* write = fopen("music.csv", "w");
	while (list != NULL)
	{
		fprintf(write, "(%s), %s, %s, %s, %d:%d, %d, %d\n", list->data.artist, list->data.album, list->data.name, list->data.genre, list->data.length.minutes, list->data.length.seconds, list->data.plays, list->data.rate);
		list = list->pNext;
	}

	fclose(write);
	printf("Goodbye!");

}

void test()
{
	int num = 0;
		printf("Test Menu\n\n1. Insert\n2. Delete\n3. Shuffle\nSelection: ");
		scanf("%d", &num);
		
		if (num == 1)
		{
			insert_test();
			system("cls");
		}
		else if (num == 2)
		{
			delete_test();
			system("cls");
		}
		else if (num == 3)
		{
			shuffle_test();
			system("cls");
		}

}

