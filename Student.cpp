#include "Student.h"
#include"Data.h"
void  input(Student* temp, const int& n) //
{
    cout << "Введiть данi про студентiв:  " << endl;
    for (int i = 0; i < n; i++)
    {
         
        checkInputChar(temp[i].surname,lengt );

        cout << "\nВведiть день народження  студента   : " << temp[i].surname << " \n " << endl;
        cin >> temp[i].Birthday;
        cout << "\nВведiть номер групи  студента : " ;
        //Номер групи це максимум 3 цифрове цисло 
        checkInputInt( temp[i].group , 0,999) ;


        cout << "\nВведiть 5 оцiнок  від [ 0 - 12 ] студента :" << temp[i].surname << endl;
        //Перевірка на ввод тільки цифр від 0 до 12
        cout << "Оцiнка з математики     :    "; checkInputInt (temp[i].marksStudent.mark1, 0 ,12);
        cout << "\nОцiнка з укр  мови    :    "; checkInputInt (temp[i].marksStudent.mark2, 0, 12);
        cout << "\nОцiнка з хiмiї        :    "; checkInputInt (temp[i].marksStudent.mark3, 0, 12);
        cout << "\nОцiнка з бiологiї     :    "; checkInputInt (temp[i].marksStudent.mark4, 0, 12);
        cout << "\nОцiнка з фiзкультури  :    "; checkInputInt (temp[i].marksStudent.mark5, 0, 12);
        cin.get();
     }

}


void  average_mark(Student* t, const int& n, double* average)  //Прототип функції середня оцінка 
{ //Змінна для підрахунки суми оцінок кожного студента

    for (int i = 0; i < n; i++)
    {
        //находим средний бал каждого студента
        average[i] = (double)(t[i].marksStudent.mark1 + 
                              t[i].marksStudent.mark2 +
                              t[i].marksStudent.mark3 +
                              t[i].marksStudent.mark4 + 
                              t[i].marksStudent.mark5) / 5;

    }

}


void Show(fstream& file, Student* temp, const int &n, const double* av)
{
    file<< "Виведемо данi про студентiв середній бал яких більше за 4.5 " << endl;
    file << "_ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ __ _ _ _ _ __ _ _ _ _ __ _ _ _ _ __ _ _ _ _ _\n";
    for (int i = 0; i < n; i++)
    {
        if (av[i] > 4.5)
        {
            
           file << "Iм'я студента : \t" << temp[i].surname << endl;
           file << "Студент групи № :\t" << temp[i].group << endl;
           file << "Оцiнки студента: ["
                << temp[i].marksStudent.mark1 << " | "
                << temp[i].marksStudent.mark2 << " | "
                << temp[i].marksStudent.mark3 << " | "
                << temp[i].marksStudent.mark4 << " | "
                << temp[i].marksStudent.mark5 << " | " << endl; 

           file << "День народження в студента : ";   file << temp[i].Birthday;
           file << "Середня оцiнка :" << av[i] << endl;
        }
        file<< "_ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ __ _ _ _ _ __ _ _ _ _ __ _ _ _ _ __ _ _ _ _ _\n";
    }
}
