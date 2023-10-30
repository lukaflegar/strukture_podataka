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
int dodajIza(pozicija p);
int dodajIspred(pozicija p);
int sort(pozicija p);
int uDat(pozicija p);
int cDat();


int main()
{
	struct osoba Head;
	Head.next = NULL;
	char izbor;
	while (1) {
		printf("Unesi P(unos na pocetak), K(unos na kraj), I(ispis), T(trazi po prezimenu), A(unos iza), C(unos ispred), D(unos liste u datoteku), E(citaj listu iz datoteke), S(sortiraj po prezimenu), B(brisi), X(izlaz)\n");
		scanf(" %c", &izbor);

		if (izbor == 'P' || 'p')
			unosP(&Head);
		else if (izbor == 'I' || 'i')
			ispis(Head.next);
		else if (izbor == 'K' || 'k')
			unosK(&Head);
		else if (izbor == 'T' || 't')
			traziPrez(Head.next);
		else if (izbor == 'B' || 'b')
			brisi(&Head);
		else if (izbor == 'A' || 'a')
			dodajIza(&Head);
		else if (izbor == 'C' || 'c')
			dodajIspred(&Head);
		else if (izbor == 'S' || 's')
			sort(&Head);
		else if (izbor == 'D' || 'd')
			uDat(Head.next);
		else if (izbor == 'E' || 'e')
			cDat();
		else if (izbor == 'X' || 'x')
			break;
		else
			printf("Nisi unio ispravno slovo!\n");
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
int unosK(pozicija p)
{
	while (p->next != NULL)
	{
		p = p->next;
	}
	pozicija q = NULL;
	q = (pozicija)malloc(sizeof(struct osoba));
	if (q == NULL)
	{
		printf("Neuspjesna alokacija memorije!\n");
		return 1;
	}
	printf("Unesi ime osobe:");
	scanf(" %s", q->ime);
	printf("Unesi prezime osobe:");
	scanf(" %s", q->prezime);
	printf("Unesi godinu rodenja osobe:");
	scanf("%d", &q->god);

	q->next = p->next;
	p->next = q;
	return 0;
}
int traziPrez(pozicija p)
{
	char prez[30];
	printf("Unesi prezime osobe koju zelis pronaci:\n");
	scanf(" %s", &prez);
	while (p != NULL && strcmp(prez, p->prezime) != 0)
	{
		p = p->next;
	}
	if (p == NULL)
		printf("Ne postoji osoba pod tim prezimenom\n");
	else
		printf("Adresa trazene osobe je: %p\n", p);
	return 0;
}

int brisi(pozicija p)
{
	pozicija pret = NULL;
	char prez[30];
	printf("Unesi prezime osobe koju zelis izbrisati:\n");
	scanf(" %s", &prez);
	while (p->next != NULL && strcmp(prez, p->prezime) != 0)
	{
		pret = p;
		p = p->next;
	}
	if (pret != NULL && strcmp(prez, p->prezime) == 0)
	{
		p = pret->next;
		pret->next = p->next;
		free(p);
	}
	return 0;
}
int dodajIza(pozicija p)
{
	pozicija novi = NULL;
	novi = (pozicija)malloc(sizeof(struct osoba));
	if (novi == NULL)
	{
		printf("Neuspjesna alokacija memorije!\n");
		return 1;
	}
	printf("Unesi ime osobe:");
	scanf(" %s", novi->ime);
	printf("Unesi prezime osobe:");
	scanf(" %s", novi->prezime);
	printf("Unesi godinu rodenja osobe:");
	scanf("%d", &novi->god);
	char prez[30];
	printf("Unesi prezime osobe iza koje zelis dodati novu:\n");
	scanf(" %s", &prez);
	while (p->next != NULL && strcmp(prez, p->prezime) != 0)
	{
		p = p->next;
	}
	novi->next = p->next;
	p->next = novi;
	/*if (p->next == NULL && strcmp(prez, p->prezime) == 0)
	{
		p->next = novi;
		novi->next = NULL;
	}
	else
	{
		novi->next = p->next;
		p->next = novi;
	}*/
	return 0;
}
int dodajIspred(pozicija p)
{
	pozicija novi = NULL;
	pozicija pret = NULL;
	novi = (pozicija)malloc(sizeof(struct osoba));
	if (novi == NULL)
	{
		printf("Neuspjesna alokacija memorije!\n");
		return 1;
	}
	printf("Unesi ime osobe:");
	scanf(" %s", novi->ime);
	printf("Unesi prezime osobe:");
	scanf(" %s", novi->prezime);
	printf("Unesi godinu rodenja osobe:");
	scanf("%d", &novi->god);
	char prez[30];
	printf("Unesi prezime osobe ispred koje zelis dodati novu:\n");
	scanf(" %s", &prez);
	pret = p;
	while (p->next != NULL && strcmp(prez, p->prezime) != 0)
	{
		pret = p;
		p = p->next;
	}
	if (p->next != NULL)
	{
		novi->next = p;
		pret->next = novi;
	}
	/*if (p -> next != NULL) //ako u while petlji stavim strcmp(prez, p->next->prezime) != 0 onda mi ne treba pret i ovako bih modificirala
	{
		novi->next = p->next;
		p->next = novi;
	}*/
	return 0;
}
int sort(pozicija p)
{
	pozicija q = NULL;
	pozicija prev_q = NULL;
	pozicija temp = NULL;
	pozicija end = NULL;
	while (p->next != end)
	{
		prev_q = p;
		q = p->next;
		while (q->next != end)
		{
			if (strcmp(q->prezime, q->next->prezime) > 0)
			{
				temp = q->next;
				prev_q->next = temp;
				q->next = temp->next;
				temp->next = q;

				q = temp;
			}

			prev_q = q;
			q = q->next;
		}
		end = q;
	}
	ispis(p->next);
	return 0;
}
int uDat(pozicija p)
{
	FILE* fp = NULL;
	fp = fopen("osobe.txt", "w");
	if (fp == NULL)
	{
		printf("Greska u otvaranju datoteke!\n");
		return 1;
	}
	while (p != NULL)
	{
		fprintf(fp, "%s\t %s\t %d\t\n", p->ime, p->prezime, p->god);
		p = p->next;
	}
	fclose(fp);
	return 0;
}
int cDat()
{
	char dat[30];
	int b = 0;
	struct osoba Head;
	Head.next = NULL;
	pozicija p = &Head;
	pozicija q = NULL;

	printf("Unesite ime datoteke iz koje zelite ucitati listu:\n");
	scanf(" %s", &dat);
	FILE* fp = NULL;
	fp = fopen(dat, "r");
	if (fp == NULL)
	{
		printf("Greska u otvaranju datoteke!\n");
		return 1;
	}

	while (!feof(fp))
	{
		if (fgetc(fp) == '\n')
			b++;
	}
	rewind(fp);
	if (b != 0)
	{
		for (int i = 0; i < b; i++) {
			q = (pozicija)malloc(sizeof(struct osoba));
			if (q == NULL)
			{
				printf("Neuspjesna alokacija memorije!\n");
				return 1;
			}
			fscanf(fp, "%s %s %d", q->ime, q->prezime, &q->god);
			q->next = p->next;
			p->next = q;
			p = p->next;
		}
	}
	fclose(fp);
	ispis(Head.next);
	return 0;
}