#include "Student.h"
#include"Data.h"
void  input(Student* temp, const int& n) //
{
    cout << "����i�� ���i ��� �������i�:  " << endl;
    for (int i = 0; i < n; i++)
    {
         
        checkInputChar(temp[i].surname,lengt );

        cout << "\n����i�� ���� ����������  ��������   : " << temp[i].surname << " \n " << endl;
        cin >> temp[i].Birthday;
        cout << "\n����i�� ����� �����  �������� : " ;
        //����� ����� �� �������� 3 ������� ����� 
        checkInputInt( temp[i].group , 0,999) ;


        cout << "\n����i�� 5 ��i���  �� [ 0 - 12 ] �������� :" << temp[i].surname << endl;
        //�������� �� ���� ����� ���� �� 0 �� 12
        cout << "��i��� � ����������     :    "; checkInputInt (temp[i].marksStudent.mark1, 0 ,12);
        cout << "\n��i��� � ���  ����    :    "; checkInputInt (temp[i].marksStudent.mark2, 0, 12);
        cout << "\n��i��� � �i�i�        :    "; checkInputInt (temp[i].marksStudent.mark3, 0, 12);
        cout << "\n��i��� � �i����i�     :    "; checkInputInt (temp[i].marksStudent.mark4, 0, 12);
        cout << "\n��i��� � �i���������  :    "; checkInputInt (temp[i].marksStudent.mark5, 0, 12);
        cin.get();
     }

}


void  average_mark(Student* t, const int& n, double* average)  //�������� ������� ������� ������ 
{ //����� ��� ��������� ���� ������ ������� ��������

    for (int i = 0; i < n; i++)
    {
        //������� ������� ��� ������� ��������
        average[i] = (double)(t[i].marksStudent.mark1 + 
                              t[i].marksStudent.mark2 +
                              t[i].marksStudent.mark3 +
                              t[i].marksStudent.mark4 + 
                              t[i].marksStudent.mark5) / 5;

    }

}


void Show(fstream& file, Student* temp, const int &n, const double* av)
{
    file<< "�������� ���i ��� �������i� ������� ��� ���� ����� �� 4.5 " << endl;
    file << "_ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ __ _ _ _ _ __ _ _ _ _ __ _ _ _ _ __ _ _ _ _ _\n";
    for (int i = 0; i < n; i++)
    {
        if (av[i] > 4.5)
        {
            
           file << "I�'� �������� : \t" << temp[i].surname << endl;
           file << "������� ����� � :\t" << temp[i].group << endl;
           file << "��i��� ��������: ["
                << temp[i].marksStudent.mark1 << " | "
                << temp[i].marksStudent.mark2 << " | "
                << temp[i].marksStudent.mark3 << " | "
                << temp[i].marksStudent.mark4 << " | "
                << temp[i].marksStudent.mark5 << " | " << endl; 

           file << "���� ���������� � �������� : ";   file << temp[i].Birthday;
           file << "������� ��i��� :" << av[i] << endl;
        }
        file<< "_ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ __ _ _ _ _ __ _ _ _ _ __ _ _ _ _ __ _ _ _ _ _\n";
    }
}
