//���� �������� 
/////////////////////////////////////////
//1) ������� ������ ��������� 
// ��������� ����������:
// �)������� 
// �)����� �����
// �)��'��� � �������� 
//    - ������ � ���������� ;
//    -������ � ���������� ����;
//    -������ � ��쳿;
//    -������ � ����㳿;
//    -������ � ����������� ;
// �)���� ����������
// 
/////////////////////////////////////////////////////////
// 
//2)�������� ������� ��� �������� ������� ��� � 5 �������� ��������� ���� ������ � ���������� �����
// 
////////////////////////////////////////////////////////////////
//3)������� �������� ��� �������� �  ������� ��� �����  ���� �� 4.76 
#include"Library.h"
#include"Student.h"
#include "Data.h"

const int  Size = 1;  // ��������� ��� ������ ������� ��������  
const  char* nameFile = "C:\\Users\\wladu\\OneDrive\\������� ���\\Student.txt"; //��������� ��� ���������� �����


//��������� �������
void deleteFile(const char*& name);   // ������� ��� ��������� �����
void OpenFile(fstream& objectFile);   //������� ��� �������� �����
void CloseFile(fstream& objectFile);  //������� ��� �������� �����

int  main()
{
    //��� ��������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
     
   fstream File(nameFile, ios::app | ios::ate | ios::out);
   OpenFile(File);
   
    Student stud[Size];                     //�������� ���'��� ��� ��������� ������ ��������  ����� ����� ��� ������� ��������
    double* avarageStud = new double[Size]; //�������� ���'��� ��� ��������� ������� ���� ��������
 
    input(stud, Size);                      // ������� ��� ����� �������� �������� 
    average_mark(stud, Size, avarageStud);  //������� ��� ��������� ���������� ���� ������� � �������� 
    Show(File, stud, Size, avarageStud);    // �������  ��� ������ ���������� � ���� 

    delete[] avarageStud;        
    CloseFile(File);                        //������� ��� �������� �����
   // deleteFile(nameFile);                   //������� ��� ��������� �����
    return 0;
}


//������� ��� ��������� �����
void deleteFile(const char*& name)
{  
    int deleteResult =remove(name);
    if (deleteResult != 0)
        cout << "���� �� ���������\n";
    else        cout << "���� ������ ���������\n"; 
}

//������� ��� �������� �����
void OpenFile(fstream& objectFile)
{ 
    if (!objectFile.is_open())
    {
        cout << "���� �� ������� �������\n";
    }
    else cout << " ����   ��������\n ";

}

//������� ��� �������� �����
void CloseFile(fstream& objectFile)
{
    objectFile.close();
    cout << "���� ��������";
}

