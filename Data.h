#pragma once
#include"Library.h"
using namespace std; 


struct  constants
{              
    enum Month { January,February, March, April, May, June, July, 
                 August, September, October, November, December };                     //������������ ��� ������ ���� 
   
    enum Week { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };      //������������ ���  ��� ����� 


    int getDayMonth(Month month, bool isleapYear = false); // ����� �������� ����� ������ ������ ��� �������� �����


    string getNameWeek(Week week);  // ����� �������� ��'� ����� ��� �����


    string getNameMonth(Month month);  // ����� �������� ��'� ����� �����

    Week getWeek(int day, int month, int year);  // ����� ��������


    bool isleapYear(int year);    //������� ��� �������� �� ���������� �� � ���� � ���� ��������� �������



};

void checkInputChar(char * str, const int size);
void checkInputInt(int& t, int N, int Z);
struct Data
{
    constants  calendar;//��'��� ���������    constants

    int year, month, day;//����� ��������� ���� 

    //���������� ����� ����� �������
    friend ostream& operator << (ostream& os, Data& calendar);        //���������� ������
    friend istream& operator >> (istream& in, Data& t);               //���������� �����
};

