//practice_3_var_2_Магомедова_Карина_БББО-05-22
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
struct node
{
    Record data;//данные
    node* next;// указатель на следующий элемент
    node* prev;// указатель на предыдущий элемент
};

struct node* head = NULL;//Указатель показывает на начало списка
struct node* current; // Указатель на текущий элемент
//добавить элемент в начало списка(двусвязанного)
void addItem(Record data)
{
    //создаем элемент, выделяем под него память, заносим данные:
    struct node* newItem = new node();
    newItem->data = data;
    
    newItem->prev = NULL;
    newItem->next = head;
    if (head != NULL)
        head->prev = newItem;
    head = newItem;
    
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
void printMyList() {
        cout <<endl<< "Значение головы списка (адрес первого элемента): " << head << endl;
        for (current = head; current; current = current->next)
        {
            cout << current->data.type << ", " << current->data.route << ", " << current->data.km << ", " << current->data.min << ", ";
            CorrectDate(current->data.date.day, current->data.date.month, current->data.date.year); cout <<"   \t";
            cout<<"  Тек. адрес: " << current << " Next=" << current->next << " Prev=" << current->prev << endl;
        
        }
}
void deliteItem(int index) {
    struct node* ptr;//вспомогательный указатель
    struct node* current = head; // Указатель на текущий элемент
    
    for (int i = 1; i < index && current != NULL; i++) {
        current = current->next;
    }
    if (current != NULL) {  //проверка на корректность 
        if (current->prev == NULL) {  //если удаляем первый элемент 
            head = head->next;
            delete(current);
            head->prev = NULL;
            current = head;
        }
        else {
            if (current->next == NULL) {  //если удаляем последний элемент
                current->prev->next = NULL;
                delete(current);
                current = head;
            }
            else { //удаляем непервый и непоследний элемент
                ptr = current->next;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete(current);
                current = ptr;
            }
        }
    }


 }

void line() {
    cout.width(100 + 1); cout.fill('-'); cout << "-" << endl;
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
    cout << endl << "Практическая № 1:" << endl;
    cout << "Исходные данные:" << endl;
    struct Record Table[10];

    Table[0] = { "Тр.", "12 ", 27.550, 75 ,{03,04,2022} };
    Table[1] = { "Т-с", "17 ", 13.600, 57 ,{03,04,2020} };
    Table[2] = { "А", "12а",  57.300, 117 , {04,03,2022} };

    DrawTable(Table, 3);
    cout << endl << "Вариант задания: Добавить новую запись (элемент массива структур),";
    cout << endl << "содержащие максимальные числовые значения в столбцах" << endl;
    cout << endl << "Максимальное числовое значение во 3-м столбце: " << maxKm(Table) << endl;
    cout << "Максимальное числовое значение в 4-м столбце: " << maxMin(Table) << endl;
    cout << endl << "Данные по варианту задания:" << endl;
    Table[3] = { "А", "17", maxKm(Table) , maxMin(Table) , {04,03,2022} };
    DrawTable(Table, 4);
    
    //practice_3
    cout << endl << "Практическая № 3: Динамический список" << endl;
    addItem(Table[0]);
    addItem(Table[1]);
    addItem(Table[2]);
    addItem(Table[3]);
    printMyList(); 

    cout << endl << "Вариант задания : (Двунаправленный список) Найти элементы списка, по вещественному числу,";
    cout << endl << "введенному с клавиатуры, и удалить найденные элементы списка." << endl;
    
    double x;
    cout << endl<< "Введите вещественное число: "; cin >> x;
    
    int ks = 0; //кол-во сопадающих чисел в списке с введенным значением
    for (current = head; current; current = current->next)
    {

        if ((current->data.km) == x){
            ks += 1;

        }
        
    }
    if (ks == 0) { cout << "в списке нет такого числа" << endl; }
    if (ks == 1) {
        int k = 1;
        for (current = head; current; current = current->next)
        {

            if ((current->data.km) == x) {

                cout << "Такое же число найдено в элементе списка под номером " << k << endl;
                break;

            }
            else {
                k += 1;
            }
        }
        deliteItem(k);
        printMyList();
    }
    if (ks > 1) {
        int k = 1;
        
        cout << "Такое же число найдено в элементе списка под номерами ";
       
        for (current = head; current; current = current->next){
            if ((current->data.km) == x) {
                cout << k << " " ;
                k += 1;
                
            }
            else { k += 1;}
        }
        
        while (ks!=0) {
            int k2 = 1;
            for (current = head; current; current = current->next) {
                if ((current->data.km) == x) {
                    deliteItem(k2); 
                    ks = ks - 1;
                    break;
                }
                else { k2 += 1; }
            }
            
        }
        printMyList();
        
    }
   //освобождаем память 
  
    for (current = head; head;)
    {
        head = current->next;
        delete current;
        current = head; 
    }
    if (head == NULL) cout << "Список пустой, память освобождена";
    
}
