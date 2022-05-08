#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <stdio.h>

#define LMAX 121

using namespace std;

int NumarCuvinte(char sir[]);
int CuvinteMinuscule(char sir[]);
int CuvinteLitera(char sir[], char lit);
int NumarCuvinte();
int CuvinteMinuscule();
int CuvinteLitera(char lit);
int TransferCuvinteLitera(char lit);
int EliminaCuvinteLitera(char lit);
void PreviewFisier(char nume[]);

int main()
{
    int optiune, nr;
    char fraza[LMAX] = "Dumitru este prieten cu Mihai, Mihai prieteneste cu Corina, rezulta...";
    do
    {
        system("cls");
        cout << "Proiect nr.5 elaborat de Cojocari Dmitri" << endl;
        cout << "Tema: Notele studentilor (tabele)" << endl;
        cout << "1. Numarul de cuvinte" << endl;
        cout << "2. Cuvantul de lungime maxima" << endl;
        cout << "3. Contin orice vocala o singura data din fraza" << endl;
        cout << "4. Numarul de cuvinte dintr-un fisier" << endl;
        cout << "5. Cuvantul de lungime maxima din fisier" << endl;
        cout << "6. Contin orice vocala o singura data din fisier" << endl;
        cout << "7. Transfer cuvant cu lungime maxima in alt fiser" << endl;
        cout << "8. Eliminarea cuvintelor din fisier" << endl;
        cout << "0. Iesire" << endl;
        cout << "\n\n\t Alege o optiune de la 0 la 8 -> ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            cout << "Fraza initiala\n";
            puts(fraza);
            nr = NumarCuvinte(fraza);
            cout << "In total sunt " << nr << " cuvinte";
            break;
        case 2:
            cout << "Fraza initiala\n";
            puts(fraza);
            nr = CuvinteMinuscule(fraza);
            cout << "In total sunt " << nr << " cuvinte cu litere minuscule";
            break;
        case 3:
            break;
        case 4:
            PreviewFisier("proba5.txt");
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        }
        _getch();
    } while (optiune);
    return 0;
}

int NumarCuvinte(char sir[])
{
    int nr = 0;
    char *cuvant, copia[LMAX];
    strcpy(copia, sir);
    if ((cuvant = strtok(copia, " ,.!?\n\t:")) == NULL)
        return 0;
    nr++;
    while ((cuvant = strtok(NULL, " ,.!?\n\t:")) != NULL)
        nr++;
    return nr;
}

int CuvinteMinuscule(char sir[])
{
    int nr = 0;
    char *cuvant, copia[LMAX];
    strcpy(copia, sir);
    if ((cuvant = strtok(copia, " ,.!?\n\t:")) == NULL)
        return 0;
    nr++;
    while ((cuvant = strtok(NULL, " ,.!?\n\t:")) != NULL)
        nr++;
    return nr;
}

int CuvinteLitera(char sir[], char lit)
{
    int nr = 0;
    char *cuvant, copia[LMAX];
    strcpy(copia, sir);
    if ((cuvant = strtok(copia, " ,.!?\n\t:")) == NULL)
        return 0;
    nr++;
    while ((cuvant = strtok(NULL, " ,.!?\n\t:")) != NULL)
        nr++;
    return nr;
}

int NumarCuvinte()
{
    return 1;
}

int CuvinteMinuscule()
{
    return 1;
}

int CuvinteLitera(char lit)
{
    return 1;
}

int TransferCuvinteLitera(char lit)
{
    return 1;
}

int EliminaCuvinteLitera(char lit)
{
    return 1;
}

void PreviewFisier(char nume[])
{
    FILE *f;
    char sir[LMAX];
    f = fopen(nume, "r");
    while (fgets(sir, LMAX - 1, f) != NULL)
    {
        cout << sir;
    }
    fclose(f);
}