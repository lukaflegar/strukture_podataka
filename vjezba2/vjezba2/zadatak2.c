#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct osoba* pozicija;
struct osoba {
	char ime[30];
	char prezime[30];
	int god;
	pozicija next;
};

int unosP(pozicija p);
int ispis(pozicija p);
int unosK(pozicija p);
int traziPrez(pozicija p);
int brisi(pozicija p);


int main()
{
	struct osoba Head;
	Head.next = NULL;
	char izbor;
	while (1) {
		printf("Unesi 1(unos na pocetak), 2(ispis)\n");
		scanf("%d",&izbor);
		if (izbor == 1)
			unosP(&Head);
		else if (izbor == 2)
			ispis(Head.next);
		
		else
			printf("Nisi unio ispravan broj!\n");
	}
	return 0;
}
int unosP(pozicija p)
{
	pozicija q = NULL;
	q = (pozicija)malloc(sizeof(struct osoba));
	if (q == NULL)
	{
		printf("Neuspjesna alokacija memorije!\n");
		return 1;
	}

	printf("Unesi ime osobe:");
	scanf("%s", q->ime);
	printf("Unesi prezime osobe:");
	scanf("%s", q->prezime);
	printf("Unesi godinu rodenja osobe:");
	scanf("%d", &q->god);

	q->next = p->next;
	p->next = q;
	return 0;
}
int ispis(pozicija p)
{
	while (p != NULL)
	{
		printf("%s %s %d \n", p->ime, p->prezime, p->god);
		p = p->next;
	}
	return 0;
}

