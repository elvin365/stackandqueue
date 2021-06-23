#include "stdio.h"
#include "stdlib.h"

struct Node
{
	int Value;
	Node* next;
};

Node* Push_Stack(Node *Head, int value)
{
	Node* a = (Node*)malloc(sizeof(Node));
	a->Value = value;
	a->next = Head;
	return a;
}

Node* Push_Queue(Node* Head, int value)
{
	Node* a = (Node*)malloc(sizeof(Node));
	a->Value = value;
	a->next = NULL;

	if (!Head)
		return a;

	Node *last = Head;
	//for (; last->next != NULL; last = last->next);
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = a;
	return Head;
}

int Pop(Node **a)
{
	if ((*a) == NULL)
		return NULL;
	int value = (*a)->Value;

	Node *del = *a;

	(*a) = (*a)->next;

	free(del);

	return value;

}
Node* Pop1(Node* head)
{
	if (head == NULL)
		return NULL;
	Node* k = head;
	head = head->next;
	free(k);
	return head;
}

void Show(Node *Head)
{
	for (; Head != NULL; Head = Head->next)
	{
		printf("%d \n", Head->Value);
	}
}

int main()
{

	Node *a = NULL, *b = NULL;

	for (int i = 0; i < 10; i++)
	{
		a = Push_Stack(a, i);
		b = Push_Queue(b, i);
	}

	printf("\nSTACK\n");
	Show(a);

	printf("\nQUEUE\n");
	Show(b);
	//Node* f=a;
	Node* f = b;
	for (int i = 0; i < 3; i++)
	{
	//Pop(&a);
	//	f=Pop1(f);
		f = Pop1(f);
	}

//	printf("\nSTACK\n");
//	Show(f);

	printf("\nQUEUE\n");
	Show(f);

	system("PAUSE");
	return 0;
}