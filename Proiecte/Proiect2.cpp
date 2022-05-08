#include <iostream>
#include <math.h>
#include <time.h>

#define NMAX 1000000
#define MAXIM(a, b) ((a) > (b)) ? (a) : (b)

using namespace std;

long sumDivisors(long n)
{
    long s = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            s += i;
            if (n / i != i)
            {
                s += n / i;
            }
        }
    }
    return s;
}

bool isPerfect(long n)
{
    if (n <= 1)
        return false;
    return (n == sumDivisors(n));
}

void printPerfectNumbers(long a, long b)
{
    if (a > b)
    {
        cout << "Interval gresit. Marginea inferioara este mai mare decat marginea superioara";
        return;
    }
    cout << "Numerele perfecte din intervalul [" << a << ";" << b << "] sunt: ";
    for (long long i = a; i <= b; i++)
    {
        if (isPerfect(i))
        {
            cout << i << " ";
        }
    }
}

void printFirstNPerfectNumbers(long nr)
{
    if (nr <= 0)
        return;
    cout << "Primele " << nr << " numere perfecte: ";
    long i = 1;
    while (nr > 0)
    {
        if (isPerfect(i))
        {
            cout << i << " ";
            nr--;
        }
        i++;
    }
}

int isAmicable(int start, int end)
{
    int amicable = 0;
    for (int i = start; i <= end; i++)
    {
        for (int j = end; j >= start; j--)
        {
            if ((sumDivisors(i) == j) && (sumDivisors(j) == i) && (i != j)) // fara ultima conditie va returna aceeasi pereche de numere
            {
                cout << i << " si " << j << " sunt amicable\n";
                amicable++;
                break;
            }
        }
    }
    return amicable;
}

int main()
{
    cout << "Proiect nr. 2 elaborat de Cojocari Dmitri";
    cout << "\nTema : Numere perfecte";
    long long n;
    long nr;
    cout << "\nIntroduceti n = ";
    cin >> n;
    isPerfect(n) ? cout << n << " este un numar perfect" : cout << n << " nu este un numar perfect";
    long a, b;
    cout << "\nMarginea inferioara a intervalului precautat: ";
    cin >> a;
    cout << "Marginea superioara a intervalului precautat: ";
    cin >> b;
    printPerfectNumbers(a, b);
    cout << "\nIntroduceti numarul de numere perfecte dorite : ";
    cin >> nr;
    clock_t start = clock();
    printFirstNPerfectNumbers(nr);
    clock_t end = clock();
    double cpuUsedTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\nFunctia s-a executat " << cpuUsedTime << " secunde";
    cout << "\n";
    int k = isAmicable(a, b);
    cout << isAmicable(a, b);
    return 0;
}

bool isAmicable1(int start, int end)
{
    bool amicable = false;
    for (int i = start; i <= end; i++)
    {
        for (int j = end; j >= start; j--)
        {
            if ((sumDivisors(i) == j) && (sumDivisors(j) == i) && (i != j)) // fara ultima conditie va returna aceeasi pereche de numere
            {
                cout << i << " si " << j << " sunt amicable\n";
                amicable = true;
                break;
            }
        }
    }
    if (amicable)
    {
        return true;
    }
    else
    {
        cout << "Nu au fost gasite numere amicabile in intervalul [" << start << ";" << end << " " << endl;
        return false;
    }
}