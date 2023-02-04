//Опис програми 
/////////////////////////////////////////
//1) Зробити шаблон структури 
// структура складається:
// а)Прізвище 
// б)Номер групи
// в)Об'єкт з оцінками 
//    - Оцінка з математики ;
//    -Оцінка з українсьокої мови;
//    -Оцінка з хімії;
//    -Оцінка з біології;
//    -Оцінка з фізкультури ;
// г)Дата народження
/////////////////////////////////////////////////////////
//2)Створити функцію яка обраховує середній бал з 5 предметів передаючи туди оцінки і повертаючи число
////////////////////////////////////////////////////////////////
//3)Функція виводить дані студента я  середній бал якого  вище за 4.76 
//4)Зробити вивід всієї інформації в файл а також щоб цей файл можна було видалити  




#include"Library.h"
#include"Student.h"
#include "Data.h"

const int  Size = 1;  // Константа яка зберігає кількість студентів  
const  char* nameFile = "C:\\Users\\wladu\\OneDrive\\Робочий стіл\\Student.txt"; //Константа для збереження файлу


//Прототипи функцій
void deleteFile(const char*& name);   // Функція для видалення файлу
void OpenFile(fstream& objectFile);   //Функція для відкриття файлу
void CloseFile(fstream& objectFile);  //Функція для закриття файлу

int  main()
{
    //Для кирилиці
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
     
   fstream File(nameFile, ios::app | ios::ate | ios::out);
   OpenFile(File);
   
    Student stud[Size];                     //Виділяємо пам'ять для зберігання масиву структур  тобто даних про кожного студента
    double* avarageStud = new double[Size]; //Виділяємо пам'ять для зберігання середніх балів студентів
 
    input(stud, Size);                      // Функція для вводу данихпро студентів 
    average_mark(stud, Size, avarageStud);  //Функція для отримання середнього балу кожного з студентів 
    Show(File, stud, Size, avarageStud);    // Функція  для виводу інформації в файл 

    delete[] avarageStud;        
    CloseFile(File);                        //Функція для закриття файлу
   // deleteFile(nameFile);                 //Функція для видалення файлу
    return 0;
}


//Функція для видалення файлу
void deleteFile(const char*& name)
{  
    int deleteResult =remove(name);
    if (deleteResult != 0)
        cout << "Файл не видалений\n";
    else        cout << "Файл успішно видалений\n"; 
}

//Функція для відкриття файлу
void OpenFile(fstream& objectFile)
{ 
    if (!objectFile.is_open())
    {
        cout << "Файл не вдалось відкрити\n";
    }
    else cout << " Файл   відкритий\n ";

}

//Функція для закриття файлу
void CloseFile(fstream& objectFile)
{
    objectFile.close();
    cout << "Файл закритий";
}


