//practice_4_var_2_Магомедова_Карина_БББО-05-22
#include <iostream>
#include<windows.h>
#include <stdio.h>
#include <string>
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
        maxmin = Table[0].min;
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
    
    //practice_0
    struct Record Table[10];
    Table[0] = { "Тр.", "12 ", 27.550, 75 ,{03,04,2022} };
    Table[1] = { "Т-с", "17 ", 13.600, 57 ,{03,04,2020} };
    Table[2] = { "А", "12а",  57.300, 117 , {04,03,2022} };
    DrawTable(Table, 3);

    //practice_1:
    /*cout << endl << "Вариант задания: Добавить новую запись (элемент массива структур),";
    cout << endl << "содержащие максимальные числовые значения в столбцах" << endl;
    cout << endl << "Максимальное числовое значение во 3-м столбце: " << maxKm(Table) << endl;
    cout << "Максимальное числовое значение в 4-м столбце: " << maxMin(Table) << endl;
    cout << endl << "Данные по варианту задания:" << endl;
    Table[3] = { "А", "17", maxKm(Table) , maxMin(Table) , {04,03,2022} };
    DrawTable(Table, 4);*/

    //practice_4
    // Этап 1
    //1. Записать 3 записи в файл в текстовом формате
    FILE* txtFile;
    fopen_s(&txtFile, "Магомедова.txt", "w+");
    for (int i = 0; i < 3; i++) {
        fprintf(txtFile, "%s %s %lf %d %d %d %d \n", \
            Table[i].type, \
            Table[i].route, \
            Table[i].km, \
            Table[i].min, \
            Table[i].date.day, Table[i].date.month, Table[i].date.year);
    }
    fclose(txtFile);
   // 2. Считать 3 записи из файла в текстовом формате
    fopen_s(&txtFile, "Магомедова.txt", "r");
    Record readTable[3];
    for (int i = 0; i < 3; i++) {
        fscanf_s(txtFile, "%s", readTable[i].type, _countof(readTable[i].type));
        fscanf_s(txtFile, "%s", readTable[i].route, _countof(readTable[i].route));
        fscanf_s(txtFile, "%lf", &readTable[i].km);
        fscanf_s(txtFile, "%d", &readTable[i].min);
        fscanf_s(txtFile, "%d", &readTable[i].date.day);
        fscanf_s(txtFile, "%d", &readTable[i].date.month);
        fscanf_s(txtFile, "%d", &readTable[i].date.year);
    }
    fclose(txtFile);
    DrawTable(readTable, 3);
    
    // 1. Записать 3 записи в файл в бинарном формате
    FILE* binFile;
    fopen_s(&binFile, "Магомедова.bin", "w");
    fwrite(Table, sizeof(Table), 1, binFile);
    fclose(binFile);
    // 2. Считать 3 записи из файла в бинарном формате.
    fopen_s(&binFile, "Магомедова.bin", "rb");
    fread_s(readTable, sizeof(readTable), sizeof(readTable), 1, binFile);
    fclose(binFile);
    DrawTable(readTable, 3);
    
    // Этап 2
    
    //Добавить новую запись (четвертую) в указанный существующий файл,
    //вводя данные с клавиатуры.  
    
    struct Record inTable;
    cout << "Введите вид транспорта:";
    cin >> inTable.type;
    cout << "Введите маршрут:";
    cin >> inTable.route;
    cout << "Введите протяженность маршрута (км):";
    cin >> inTable.km;
    cout << "Введите время в дороге (мин):";
    cin >> inTable.min;
    cout << "Введите дату (день):";
    cin >> inTable.date.day;
    cout << "Введите дату (месяц):";
    cin >> inTable.date.month;
    cout << "Введите дату (год):";
    cin >> inTable.date.year;


    // Записываем в файл
    fopen_s(&txtFile, "Магомедова.txt", "a");
    fprintf(txtFile, "%s %s %lf %d %d %d %d \n", \
        inTable.type, \
        inTable.route, \
        inTable.km, \
        inTable.min, \
        inTable.date.day, inTable.date.month, inTable.date.year);
    fclose(txtFile);

    //Считываем данные из файла
    Record fileRecords[4];
    fopen_s(&txtFile, "Магомедова.txt", "r");
    for (int i = 0; i < 4; i++) {
        fscanf_s(txtFile, "%s", fileRecords[i].type, _countof(fileRecords[i].type));
        fscanf_s(txtFile, "%s", fileRecords[i].route, _countof(fileRecords[i].route));
        fscanf_s(txtFile, "%lf", &fileRecords[i].km);
        fscanf_s(txtFile, "%d", &fileRecords[i].min);
        fscanf_s(txtFile, "%d", &fileRecords[i].date.day);
        fscanf_s(txtFile, "%d", &fileRecords[i].date.month);
        fscanf_s(txtFile, "%d", &fileRecords[i].date.year);
    }
    fclose(txtFile);
    DrawTable(fileRecords, 4);
    // 2
    //Поменять местами строковые значения в 3 и 4 записях файла. Данные считываются из файла.
    //Текстовый
    fopen_s(&txtFile, "Магомедова.txt", "r");
    for (int i = 0; i < 4; i++) {
        fscanf_s(txtFile, "%s", fileRecords[i].type, _countof(fileRecords[i].type));
        fscanf_s(txtFile, "%s", fileRecords[i].route, _countof(fileRecords[i].route));
        fscanf_s(txtFile, "%lf", &fileRecords[i].km);
        fscanf_s(txtFile, "%d", &fileRecords[i].min);
        fscanf_s(txtFile, "%d", &fileRecords[i].date.day);
        fscanf_s(txtFile, "%d", &fileRecords[i].date.month);
        fscanf_s(txtFile, "%d", &fileRecords[i].date.year);
    }
    swap(fileRecords[2].type, fileRecords[3].type);
    swap(fileRecords[2].route, fileRecords[3].route);
    fclose(txtFile);
   
    fopen_s(&txtFile, "Магомедова.txt", "w+");
    for (int i = 0; i < 4; i++) {
        fprintf(txtFile, "%s %s %lf %d %d %d %d \n", \
            fileRecords[i].type, \
            fileRecords[i].route, \
            fileRecords[i].km, \
            fileRecords[i].min, \
            fileRecords[i].date.day, fileRecords[i].date.month, fileRecords[i].date.year);
    }
    fclose(txtFile);
    DrawTable(fileRecords, 4);

}
  





