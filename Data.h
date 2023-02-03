#pragma once
#include"Library.h"
using namespace std; 


struct  constants
{              
    enum Month { January,February, March, April, May, June, July, 
                 August, September, October, November, December };                     //Перечислення для місяців року 
   
    enum Week { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };      //Перечислення для  днів тижня 


    int getDayMonth(Month month, bool isleapYear = false); // метод отримати число скільки містить днів введений місяць


    string getNameWeek(Week week);  // метод отримати ім'я назву дня тижня


    string getNameMonth(Month month);  // метод отримати ім'я назву місяця

    Week getWeek(int day, int month, int year);  // метод отримати


    bool isleapYear(int year);    //Функція для перевірки чи високосний чи ні день в який народився студент



};

void checkInputChar(char * str, const int size);
void checkInputInt(int& t, int N, int Z);
struct Data
{
    constants  calendar;//Об'єкт структури    constants

    int year, month, day;//Члени структури Дата 

    //Перегрузка через дружні функції
    friend ostream& operator << (ostream& os, Data& calendar);        //Перегрузка виводу
    friend istream& operator >> (istream& in, Data& t);               //Перегрузка вводу
};

