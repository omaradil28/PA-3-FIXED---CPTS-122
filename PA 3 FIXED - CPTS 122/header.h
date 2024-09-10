#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#include <conio.h>
#endif
#include <string.h>
#include <stdbool.h>
#define SIZEOFBUFFER 50


typedef struct duration
{
	unsigned int seconds;
	unsigned int minutes;
} Duration;

typedef struct record
{
	char artist[50];
	char album[50];
	char name[50];
	char genre[50];
	Duration length;
	int plays;
	int rate;
}Record;

typedef struct node
{
	Record data;
	struct node* pNext;
	struct node* pPrev;
}Node;


int menu();

Node* createNode(Record record);

bool insertAtFront(Node** pList, Record record);

void load(int num, Node** plist);

void store(Node* list);

void display(Node* list);

void insert(Node** list);

void delete(Node* list);

int edit(int num, Node* list); 

void sort(Node** list);

void rate(Node* list);

void play(Node* list);

void shuffle(Node* list);

void exit_(Node* list);

