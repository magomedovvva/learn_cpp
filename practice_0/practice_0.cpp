//practice_0_var_7_Магомедова_Карина_БББО-05-22
#include <iostream>
#include<windows.h>
using namespace std;
struct Date {
    unsigned short int day;
    unsigned short int month;
    unsigned short int year;
};
struct Record{
    char type[5];
    char route[5];
    double km;
    int min;
    struct Date date;
};
void line() {
    cout.width(100+1); cout.fill('-'); cout << "-" << endl;
}
void CorrectDate(unsigned short int day, unsigned short int month, unsigned short int year) {
    if (day > 9) {
        cout << day << ".";
    }
    else {
        cout << right << "0" << day << ".";
    }
    if (month>9) {
        cout << month << ".";
    }
    else {
        cout << "0" << month << ".";
    }
    cout << year;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    struct Record Table[3];

    Table[0] = { "Тр.", "12 ", 27.550, 75,{03,04,2022} };
    Table[1] = { "Т-с", "17 ", 13.600, 57,{03,04,2020} };
    Table[2] = { "А", "12а",  57.300, 117, {04,03,2022} };
    line();
    cout.fill(' '); cout.width(100);  cout << left << "|Ведомость общественного транспорта" << "|" << endl;
    line();
    cout.fill(' '); cout.width(100-11); cout << "| Вид траспорта | маршрута | Протяжённость маршрута (в км) | Время в дороге(мин) |"; 
    cout.width(11); cout << left << "Дата" << "|" << endl;
    line();
    for (int i = 0; i < 3; i++) {
        cout.fill(' ');
       
        cout << "|"; cout.width(15); cout <<  left << Table[i].type << "|";
        cout.width(10); cout << left << Table[i].route << "|";
        cout.width(31); cout.precision(3); cout << fixed << right << Table[i].km << "|";
        cout.width(21);  cout << left << Table[i].min << "|";
        cout.width(5); CorrectDate(Table[i].date.day, Table[i].date.month, Table[i].date.year); cout.width(5); cout << "|" << endl;
        line();
    }
    cout.fill(' '); cout.width(100);  cout << left << "|Примечание: Тр - трамвай, Тс - троллейбус, A - автобус" << "|" << endl;
    line();
}
