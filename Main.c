#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct sKisiNo {
    char Kisi[MAX];
    struct sKisiNo *next;
} tKisi; //kisi düğümü

typedef struct sVagon {
    char Vagon[MAX];
    tKisi *firstKisi;
    struct sVagon *next;
} tVagon; //vagon düğümü

/*VAGON EKLEYEN FONKSİYON*/

void addVagon (tVagon **first, char *Vagon) {
    
    tVagon *temp = malloc (sizeof (*temp));
    strcpy (temp->Vagon, Vagon);
    temp->next = *first;
    *first = temp;
}

/*KİŞİ EKLEYEN FONKSİYON*/

tKisi * addKisi (tVagon *first, char *Kisi, int kNo) {

    tKisi *temp = malloc (sizeof (*temp));
    strcpy (temp->Kisi, Kisi);
    temp->next = first->firstKisi;
    first->firstKisi = temp;
    return temp->next;
}

/*YAZDIRMA FONKSİYONU*/

void display (tVagon *currVagon) {
    int i=20;
    while (currVagon != NULL) {

        printf ("%d. %s :\n", i, currVagon->Vagon);
        i--;

        int j=10;
        tKisi *currKisi = currVagon->firstKisi;

        while (currKisi != NULL) {
            printf ("   %d. Koltuk : %s\n", j, currKisi->Kisi);
            currKisi = currKisi->next;
            j--;
        }
        
        currVagon = currVagon->next;
    }
}

/*ANA FONKSİYON*/

int main () {
    tVagon *firstVagon = NULL;

    for (int i = 1; i <= 20; i++)
    {
        addVagon (&firstVagon, "Vagon ");
        
        for (int j = 1; j <= 10; j++)
        {
            addKisi (firstVagon, " Seyda Gundogdu" ,j);
        }
        
    }
    display(firstVagon);

    return 0;
}