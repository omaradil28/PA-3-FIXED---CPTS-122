#include "header.h"

void insert_test()
{
	Node* list = NULL;
	Record record;

	const char* artist = "Perry, Katy";
	const char* album = "Witness";
	const char* name = "Chained to the Rhythm";
	const char* genre = "pop";
	int minutes = 4;
	int seconds = 36;
	int plays = -1;
	int rate = 6;

	strcpy(record.artist, artist);
	
	strcpy(record.album, album);
	
	strcpy(record.name, name);
	
	strcpy(record.genre, genre);

	if (minutes > 0)
	{
		record.length.minutes = minutes;
	}
	else
	{
		printf("Minutes not stored\n");
	}

	if (seconds > 0)
	{
		record.length.seconds = seconds;
	}
	else
	{
		printf("Seconds not stored\n");
	}

	if (plays > 0)
	{
		record.plays = plays;
	}
	else
	{
		printf("Plays not stored\n");
	}

	if (rate > 0 && rate < 6)
	{
		record.rate = rate;
	}
	else
	{
		printf("Rate not stored\n");
	}

	insertAtFront(list, record);
	system("cls");

}

void delete_test()
{
	Node* list = NULL;
	Record record;

	strcpy(record.artist, "Perry, Katy");
	strcpy(record.album, "Witness");
	strcpy(record.name, "Chained to the Rhythm");
	strcpy(record.genre, "pop");
	record.length.minutes = 4;
	record.length.seconds = 36;
	record.plays = 3;
	record.rate = 5;

	system("cls");
	insertAtFront(&list, record);

	Node* cur = list;
	Node* prev = NULL;

	while (cur != NULL)
	{
		if (strcmp(cur->data.name, record.name) == 0)
		{
			if (prev == NULL)
			{
				list = cur->pNext;
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
		if (strcmp(cur->data.name, record.name) != 0)
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

void shuffle_test()
{
	//Not sure how to do shuffle
	int num = 0;
	char *names[3] = { "The Motto", "Stay Stay Stay", "Trust" };
	Node* temp = NULL;
	do
	{
		Record record;
		strcpy(record.name, names[num]);
		num++;
		insertAtFront(&temp, record);
	} while (num != 3);

	while (temp != NULL)
	{
		printf("%s\n", temp->data.name);
		temp = temp->pNext;
	}

}