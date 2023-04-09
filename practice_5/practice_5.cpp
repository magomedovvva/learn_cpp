//practice_5_Магомедова_Карина_БББО-05-22
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <fstream>
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
class clDate {
private:
    unsigned short int day;
    unsigned short month;
    unsigned short int year;
public:
    // Конструктор по умолчанию
    clDate()
    {
        day = 0; month = 0; year = 0;
    }

    // Конструкторы с параметрами
    clDate(unsigned short _day, unsigned short _month, unsigned short _year)
    {
        setDate(_day, _month, _year);
    }
    clDate(struct Date mD)
    {
        setDate(mD);
    }
    clDate(struct Date* pD)
    {
        day = pD->day; month = pD->month; year = pD->year;
    }
    
    //Конструктор копирования
    clDate(const clDate& p) 
    {
        day = p.day;
        month = p.month;
        year = p.year;
    }
    // Деструктор  
    ~clDate() { } 

    Date getDate()
    {
        struct Date MD;
        MD.year = year;
        MD.month = month;
        MD.day = day;
        return MD;
    }
    void setDate(unsigned short _day, unsigned short _month, unsigned short _year) {
        this->day = _day;
        this->month = _month;
        this->year = _year;
    }
    void setDate(Date _mD)
    {
        setDate(_mD.day, _mD.month, _mD.year);
    }
    void printDate() {
        if (this->day > 0 and this->day < 10)
            cout << "0";
        cout << day << '.';
        if (this->month > 0 and this->month < 10)
            cout << "0";
        cout << month << '.' << year << endl;
    }
    // проверка корректности даты
    bool cheakDate(int d, int m, int y) 
    {
        if (m > 0 && m < 13)
        {
            int maxDay;
            switch (m)
            {
            case 2: maxDay = (y % 4 == 0) ? 29 : 28; // високосный год (раз в 4 года)
            case 1: case 3: case 5: case 7:case 8: case 10: case 12: maxDay = 31;
            default: maxDay = 30;
            }
            if (d > 0 && d <= maxDay)
            {
                day = d; month = m; year = y;
                return true;
            }
            else return false;
        }
        return false;
    }
    void addDay(int num)
    {
        if (!cheakDate(day + num, month, year)) // проверяем увеличенную дату
            cout << "\n Дата: " << day + num << "." << month << "." << year << " не корректна\n";
    }
};
class clRecord {
    string type;
private:
    double km;
protected:
    int min;
    struct Date date;
public:
    string route;
    // Конструктор по умолчанию
    clRecord()
    {
        type = '0'; route = '0'; km = 0; min = 0; date = { 11, 11, 1111 };
    }
    
    clRecord(Record* pR) {
        type = pR->type; route = pR->route; km = pR->km; min = pR->min; date = pR->date;
    }
   // clRecord(char* FileName){} //конструктор (имя файла)
    
    clRecord(string type, string route, double km, int min, Date d) {
        this->type = type;
        this->route = route;
        this->km = km;
        this->min = min;
        this->date = d;
       
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
    void printRecord()
    {
        cout << this->type << "  " << this->route << "  " << this->km << "  " << this->min << "  ";
        CorrectDate(date.day,date.month,date.year);

    }
    
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
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    
    //practice_0
    struct Record Table[10];
    Table[0] = { "Тр.", "12 ", 27.550, 75 ,{03,04,2022} };
    Table[1] = { "Т-с", "17 ", 13.600, 57 ,{03,04,2020} };
    Table[2] = { "А", "12а",  57.300, 117 , {04,03,2022} };
    cout << endl << "Таблица из практической 0: " << endl;
    DrawTable(Table, 3);


    //practice_5:
    // Создание статических объектов:
    clDate D1; cout << "\n  D1 = "; D1.printDate(); // по умолчанию
    clDate D2(4, 8, 2022); cout << "\n  D2 = "; D2.printDate();

    struct Date MD = { 3, 3, 2023 };
    clDate D3(MD); cout << "\n  D3 = "; D3.printDate();
    clDate D4(&MD); cout << "\n  D4 = "; D4.printDate();
   
    // Создание динамического объекта:
    clDate* D5;
    D5 = new clDate(5, 5, 2000); cout << "\n  D5 = "; D5->printDate();

    // Создаём объект с именем DC класса clDate на основе конструктора копирования
    clDate D6(4, 8, 2022);cout << "\n  D6 = "; D6.printDate();
    clDate DC{ D6 }; cout << "\n  DC = "; DC.printDate();
    
    DC.addDay(5); cout << "\n  DC + 5 дней = "; DC.printDate();
    
    
    // Создание статического объекта:
    clRecord A1; cout << "\n  A1 = "; A1.printRecord(); // по умолчанию
    struct Record A= { "Тр.", "12 ", 27.550, 75, { 03,04,2022 } };
    clRecord A2(&A); cout << "\n  A2 = "; A2.printRecord();
   
    // Создание динамического объекта:
    struct Record B = { "А", "12а",  57.300, 117 , {04,03,2022} };
    
    clRecord* A3 = new clRecord(&B); cout << "\n  A3 = "; A3->printRecord();
    
    //Создаем массив объектов класса clRecord (2 способа записи)
    
    // передача в конструктор clRecord(Record* pR)
    /*Record r1 = {"Тр.", "12 ", 27.550, 75 ,{03,04,2022}};
    Record r2 = { "Т-с", "17 ", 13.600, 57 ,{03,04,2020} };
    Record r3 = { "А", "12а",  57.300, 117 , {04,03,2022} };
    clRecord recArr[3] = { clRecord(&r1), clRecord(&r2), clRecord(&r3) };*/
   
    // передача в конструктор clRecord(string type, string route, double km, int min, Date d)
    clRecord recArr[3] = { { "Тр.", "12 ", 27.550, 75 ,{03,04,2022}}, \
        { "Т-с", "17 ", 13.600, 57 ,{03,04,2020} }, \
        { "А", "12а",  57.300, 117 , {04,03,2022} } }; 
    
    cout << endl << "\n Значения строк таблицы из практической 0: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\n  " << i +1 << " строка = ";
        recArr[i].printRecord();
        cout << endl;
    }
    delete D5; delete A3;
    return 0;
}