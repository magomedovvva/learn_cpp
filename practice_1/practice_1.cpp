//practice_1_var_2_Магомедова_Карина_БББО-05-22
#include <iostream>
#include<windows.h>
using namespace std;
struct Date {
    unsigned short int day;
    unsigned short int month;
    unsigned short int year;
};
struct Record {
    char type[5];
    char route[5];
    double km;
    int min;
    struct Date date;
};
void line() {
    cout.width(100 + 1); cout.fill('-'); cout << "-" << endl;
}
void CorrectDate(unsigned short int day, unsigned short int month, unsigned short int year) {
    if (day > 9) {
        cout << day << ".";
    }
    else {
        cout << right << "0" << day << ".";
    }
    if (month > 9) {
        cout << month << ".";
    }
    else {
        cout << "0" << month << ".";
    }
    cout << year;
}
double maxKm(struct Record* Table) {
    double maxkm;
    maxkm = Table[0].km;
        if ((Table[0].km > Table[1].km) && (Table[0].km > Table[2].km)) {
            maxkm = Table[0].km;
        }
        if ((Table[1].km > Table[0].km) && (Table[1].km > Table[2].km)) {
            maxkm = Table[1].km;
            
        }
        if ((Table[2].km > Table[1].km) && (Table[2].km > Table[0].km)) {
            maxkm = Table[2].km;
        }
    return maxkm;
}
int maxMin(struct Record* Table) {
    int maxmin = Table[0].min;
    if ((Table[0].min > Table[1].min) && (Table[0].min > Table[2].min)) {
        maxmin = Table[0].min ;
    }
    if ((Table[1].min > Table[0].min) && (Table[1].min > Table[2].min)) {
        maxmin = Table[1].min;
    }
    if ((Table[2].min > Table[1].min) && (Table[2].min > Table[0].min)) {
        maxmin = Table[2].min;
    }
    return maxmin;
}
void DrawTable(struct Record* Table, int numTable) {
    line();
    cout.fill(' '); cout.width(100);  cout << left << "|Ведомость общественного транспорта" << "|" << endl;
    line();
    cout.fill(' '); cout.width(100 - 11); cout << "| Вид траспорта | маршрута | Протяжённость маршрута (в км) | Время в дороге(мин) |";
    cout.width(11); cout << left << "Дата" << "|" << endl;
    line();
    for (int i = 0; i < numTable; i++) {
        cout.fill(' ');

        cout << "|"; cout.width(15); cout << left << Table[i].type << "|";
        cout.width(10); cout << left << Table[i].route << "|";
        cout.width(31); cout.precision(3); cout << fixed << right << Table[i].km << "|";
        cout.width(21);  cout << left << Table[i].min << "|";
        cout.width(5); CorrectDate(Table[i].date.day, Table[i].date.month, Table[i].date.year); cout.width(5); cout << "|" << endl;
        line();
    }
    cout.fill(' '); cout.width(100);  cout << left << "|Примечание: Тр - трамвай, Тс - троллейбус, A - автобус" << "|" << endl;
    line();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Исходные данные:" << endl;
    struct Record Table[10];
    Table[0] = { "Тр.", "12 ", 27.550, 75 ,{03,04,2022} };
    Table[1] = { "Т-с", "17 ", 13.600, 57 ,{03,04,2020} };
    Table[2] = { "А", "12а",  57.300, 117 , {04,03,2022} };
    DrawTable(Table,3);

    //practice_1:
    cout << endl << "Вариант задания: Добавить новую запись (элемент массива структур),";
    cout << endl << "содержащие максимальные числовые значения в столбцах" << endl;
    cout << endl << "Максимальное числовое значение во 3-м столбце: " << maxKm(Table) << endl;
    cout << "Максимальное числовое значение в 4-м столбце: " << maxMin(Table) << endl;
    cout << endl<<"Данные по варианту задания:" << endl;
    Table[3] = { "А", "17", maxKm(Table) , maxMin(Table) , {04,03,2022} };
    DrawTable(Table,4);
}