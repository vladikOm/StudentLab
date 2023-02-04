//////////////////////////////////
//Файл-опис структури студент ////
//////////////////////////////////

#pragma once
#include"Data.h"


const int lengt = 20; //Кількість символів яке може містити ім'я включаючи '\0'
struct marks
{
    int mark1;// Оцінка з математики  
    int mark2;// Оцінка з українсьокої мови 
    int mark3;// Оцінка з хімії 
    int mark4;// Оцінка з біології 
    int mark5;// Оцінка з фізкультури  
};

struct Student
{
    
     char   surname[ lengt ];  //Прізвище студента
    int group;                 //номер групи
    Data  Birthday;            //Дата народження
    marks marksStudent;        //Оцінки


};

void average_mark(Student* temp, const int &n, double * average);        //Прототип функції середня оцінка 
void input(Student* temp, const int& n);                                 //Прототип  функції для вводу на екран
void Show(fstream&file ,Student* temp, const int& n, const double* av)  ;//Прототип функції для виводу на екран








