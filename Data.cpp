#include "Data.h"
#include"Library.h"

//Метод повертає кількість днів в місяці

int constants::getDayMonth(Month month, bool isleapYear)
{
    switch (month)
    {
    case January:  return 31;
    case February: return isleapYear ? 28 : 29;
    case March:    return 31;
    case April:    return 30;
    case May:      return 31;
    case June:     return 30;
    case July:     return 31;
    case August:   return 31;
    case September:return 30;
    case October:  return 31;
    case November: return 30;
    case December: return 31;
    }
}

//Метод повертає назву дня тижня

string  constants::getNameWeek(Week week)
{
    switch (week)
    {
    case Monday:   return "Понедiлок";
    case Tuesday:  return "Вiвторок";
    case Wednesday:return "Середа";
    case Thursday: return "Четвер";
    case Friday:   return "П'ятниця";
    case Saturday: return "Субота";
    case Sunday:   return "Недiля";
    }
}

//Метод повертає назву місяця

string  constants::getNameMonth(Month month)
{
    switch (month)
    {
    case January:  return "Сiчень";
    case February: return "Лютий";
    case March:    return "Березень";
    case April:    return "Квiтень";
    case May:      return "Травень";
    case June:     return "Червень";
    case July:     return "Липень";
    case August:   return "Серпень";
    case September:return "Вересень";
    case October:  return "Жовтень";
    case November: return "Листопад";
    case December: return "Грудень";
    }
}

//Метод повератє день тижня

constants::Week  constants::getWeek(int day, int month, int year)
{ //Формула для отримання дня тижня
    int a, y, m, R;
    a = (14 - month) / 12;
    y = year - a;
    m = month + 12 * a - 2;
    R = 7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
    return static_cast<Week>(R % 7);
}



// Повертає метод true якщо рік високосний, якщо ні false
bool  constants::isleapYear(int year)
{
    if (year % 400 == 0)
        return true;
    //Якщо ділиться  на 400, алене ділиться  на 100
    if (year % 100 == 0)
        return false;
    // якщо ділиться без остачі на4 (але не ділиться на 100 і 400)
    if (year % 4 == 0)
        return true;
    //в іншому випадку не ділиться  на 4 
    return false;
}





//Перезавантаження оператора вводу

ostream& operator << (ostream& os, Data& other)
{   //Виводимо інформацію про дату народження
    os << "["; 
    if (other.day < 10) { os << "0"; os << other.day;}
    else   os << other.day;  os << "/";
     
    if (other.month < 10) { os << "0"; os << other.month; }
    else   os << other.month;  os << "/";
   
    os << other.year  << "]" << endl;
 
    os << "Назва мiсяця в який народився cтудент: = " 
       << other.calendar.getNameMonth(static_cast<constants::Month>(other.month - 1)) << endl;

    //Визначаємо який день тижня 
    int day_in_Week = other.calendar.getWeek(other.day, other.month, other.year) - 1;

    //Виводимо день тижня 
    os << "Назва дня тижня в який народився cтудент : " 
       << other.calendar.getNameWeek(constants::Week(day_in_Week)) << endl;

    os << "Рiк в який народився студент високосний ТАК/НI :";
    //Перевіряємо рік високосний і виводимо так або ні  
  
        if ( other.calendar.isleapYear(other.year) != true)    os<<  "НI\n";
        else   os << "ТАК\n";
 
    return os;
}



//Перезавантаження оператора виводу

istream& operator >> (istream& in, Data& t)
{
    cout << "Вводимо день в який народився студент :\n";
    checkInputInt (t.day, 1, 31);//Перевірка на ввод дня число потрібно  ввести від 1 до 31 і обов'язково ціле число

    cout << "Вводимо місяць в який народився студент :\n";
    checkInputInt (t.month, 1, 12);    //Перевірка на ввод день повинен бути від 1 до 12 ціле число

    cout << "Вводимо рік в який народився студент :\n";
    checkInputInt (t.year, 1900, 2100);//Перевірка на ввод день повинен бути від 1900 до 2100,  ціле число

    return in;
}



 //Перевірка на ввод цілого числа в діапазоні  [beginNumber - endNumber]

void checkInputInt(int &number, int beginNumber ,int endNumber)
{ 
    bool valid = false;
    while (!valid)
    {  
        std::cout << "Введiть число :["<< beginNumber <<"-" << endNumber <<"]:   ";
        cin >> number;
        if (!cin >> number   || cin.peek() != '\n')
        {
            valid = false;
            cout << "Ви не ввели ціле число\n" << endl;   //Повідомлення про помилку вводу
            cin.clear();                                  // скидаємо всі поточні флаги стану і встановлюємо goodbit
            cin.ignore(32767, '\n');                      // очищаємо потік від сміття
        }
        else
        {
            if (number >= beginNumber && number  <= endNumber)
            {
              valid = true;
              cout << "Ви ввели число  правильно ["  << beginNumber <<"-" << endNumber <<"]\n" << endl  ;
            } 
            else
            {
                valid = false;
                cout << "Ви ввели число не правильно [" << beginNumber << "-" << endNumber << "]\n"
                     <<  " Спробуйте  ввести заново\n" << endl;
            }
        }
    }
}




//Перевірка на ввод тільки букв 

void checkInputChar( char *str, const int  size)
{ 
    //Цикл продовжується до тих пір коли ввод буде коректним 
    while (true)
    { 
        std::cout << "\nВведiть ім'я  студента:\t";
        cin.getline( str , size,'\n');

       bool   valid_char = false;

        //Перевіряємо якщо користувач не ввів ім'я то повідомити про це
        if (strlen(str) == 0)
        {
            cout << "Ім'я  не введено!  \n";
            continue;
        }

       //Цикл продовжується до тих пір поки або не буде істина що ім'я прочитали правильно або коли закінчиться строка

        for (int i = 0; i < strlen(str) && !valid_char; i++)
        {
            //Перевіряємо чи всі символи є  буквами  
            //Якщо хочаб один символ не літера ми зупиняємось перевірку

            if ( str[i]  >(char)64  && str[i]  < (char)91  //Англійські великі літери 
              || str[i]  >(char)96  && str[i] < (char)123  //Англійські маленькі літери 
              || str[i]  >(char)190 && str[i] < (char)256  )//Кирилиця        
            {
                //Якщо символ є літерою, то ми тоді продовжуємо перевіряти  
                //Зупинемось або в кінці рядка або як зустрінемо не літеру 
                continue;
            }
            else
            { 
            //Показуємо користувачу повідомлення про некоректний ввід ім'я і очишуємо потік від сміття
             cout << " Ім'я введено не вірно !  \n" << endl;
            } 
           
            valid_char = true;   
         
        }

      //Якщо ввод правильний показуємо повідомлення
        if (!valid_char)
        {
         cout << " Ім'я введено вірно !  \n" << endl;
         break;
        }

    }
 }

