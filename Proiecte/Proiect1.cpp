#include <iostream>
#include <iomanip>

#define MAXGRADE 0
#define MINGRADE 11

using namespace std;

int main()
{
    int numberOfStudents = 20, studentGrade;
    int minGrade = MINGRADE, maxGrade = MAXGRADE, gradeGap;
    // nota cu care se compara
    int refGrade = 7;
    // numarul de note mai mici, mai mari sau egale cu nota reper
    int lessThan = 0, greaterThan = 0, equal = 0;
    // numarul de studenti cu nota peste 5 (reusita) si peste 8(calitate)
    int countPerformance = 0, countQuality = 0;
    float academicPerformancePercent, qualityPercent;
    float avgMark = 0.0f;
    int countEminenti = 0, countProeminenti = 0, countMediocri = 0, countRestantieri = 0;
    cout << "Proiect Nr.1 elaborat de Cojocari Dmitri" << endl;
    cout << "Tema: Notele studentilor" << endl;
    // do
    // {
    //     cout << "Indica numarul de studenti: ";
    //     cin >> numberOfStudents;
    // } while ((numberOfStudents < 1) || (numberOfStudents > 20));
    // cout << "Introduceti nota pentru comparatie: ";
    // cin >> refGrade;
    // cout << "Introduceti notele studentilor: " << endl;

    // prelucram notele studentilor
    for (int i = 1; i <= numberOfStudents; i++)
    {
        do
        {
            // studentGrade = ((i + 1) % 2) + 9;
            studentGrade = rand() % 7 + 4;
            cout << setw(4) << studentGrade;
            // cout << "Nota studentului " << i << " = ";
            // cin >> studentGrade;
        } while (studentGrade < 0 || studentGrade > 100);
        if (studentGrade < minGrade)
            minGrade = studentGrade;
        if (studentGrade > maxGrade)
            maxGrade = studentGrade;
        avgMark += studentGrade;
        if (studentGrade < refGrade)
            lessThan++;
        else if (studentGrade > refGrade)
            greaterThan++;
        else
            equal++;
        // calculam numarul de studenti cu nota >=5 pentru reusita
        if (studentGrade >= 5)
            countPerformance++;
        // nota >= 8 -> pentru procentul calitatii
        if (studentGrade >= 8)
            countQuality++;

        if (studentGrade >= 9)
        {
            countEminenti++;
        }
        else if (studentGrade == 8)
        {
            countProeminenti++;
        }
        else if (studentGrade >= 5 && studentGrade <= 7)
        {
            countMediocri++;
        }
        else
        {
            countRestantieri++;
        }
    }
    cout << "\n";

    // Decalajul -> diferenta dintre nota maxima si minima
    gradeGap = maxGrade - minGrade;

    // media notelor
    avgMark = (float)(avgMark / numberOfStudents);

    // procentul reusitei si calitatii
    academicPerformancePercent = (float)(countPerformance * 100 / numberOfStudents);
    qualityPercent = (float)(countQuality * 100 / numberOfStudents);

    cout << "1.\t Nota maxima: " << maxGrade << endl;
    cout << "\t Nota minima este: " << minGrade << endl;
    cout << "2.\t Decalajul: " << gradeGap << endl;
    cout << "3.\t Media notelor: " << setprecision(3) << avgMark;
    cout << "\n4.\t Numarul de studenti cu nota mai mare decat " << refGrade << ": " << greaterThan << endl;
    cout << "\t Numarul de studenti cu nota mai mica decat " << refGrade << ": " << lessThan << endl;
    cout << "\t Numarul de persoane cu nota " << refGrade << ": " << equal << endl;
    cout << "5. \t Procentul reusitei: " << setprecision(4) << academicPerformancePercent << "%";
    cout << "\n\t Procentul calitatii: " << setprecision(4) << qualityPercent << "%";
    cout << "\nEminenti: " << countEminenti;
    cout << "\nProeminenti: " << countProeminenti;
    cout << "\nMediocri: " << countMediocri;
    cout << "\nRestantieri: " << countRestantieri;
    return 0;
}

// clasificare
// eminenti -> intre 9 si 10
// proeminenti -> 8
// mediocri -> intre 5 si 7
// restantieri -> sub 5