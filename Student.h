#pragma once
#include"Data.h"


const int lengt = 20;
struct marks
{
    int mark1;// ������ � ����������  
    int mark2;// ������ � ���������� ���� 
    int mark3;// ������ � ��쳿 
    int mark4;// ������ � ����㳿 
    int mark5;// ������ � �����������  
};

struct Student
{
    
     char   surname[ lengt ];  //������� ��������
    int group;         //����� �����
    Data  Birthday;    //���� ����������
    marks marksStudent;//������


};
void average_mark(Student* temp, const int &n, double * average);//�������� ������� ������� ������ 
void input(Student* temp, const int& n);                        //��������  ������� ��� ����� �� �����
void Show(fstream&file ,Student* temp, const int& n, const double* av)  ;//�������� ������� ��� ������ �� �����

