#include "Data.h"
#include"Library.h"

//����� ������� ������� ��� � �����

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

//����� ������� ����� ��� �����

string  constants::getNameWeek(Week week)
{
    switch (week)
    {
    case Monday:   return "�����i���";
    case Tuesday:  return "�i������";
    case Wednesday:return "������";
    case Thursday: return "������";
    case Friday:   return "�'������";
    case Saturday: return "������";
    case Sunday:   return "���i��";
    }
}

//����� ������� ����� �����

string  constants::getNameMonth(Month month)
{
    switch (month)
    {
    case January:  return "�i����";
    case February: return "�����";
    case March:    return "��������";
    case April:    return "��i����";
    case May:      return "�������";
    case June:     return "�������";
    case July:     return "������";
    case August:   return "�������";
    case September:return "��������";
    case October:  return "�������";
    case November: return "��������";
    case December: return "�������";
    }
}

//����� ������� ���� �����

constants::Week  constants::getWeek(int day, int month, int year)
{ //������� ��� ��������� ��� �����
    int a, y, m, R;
    a = (14 - month) / 12;
    y = year - a;
    m = month + 12 * a - 2;
    R = 7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
    return static_cast<Week>(R % 7);
}



// ������� ����� true ���� �� ����������, ���� � false
bool  constants::isleapYear(int year)
{
    if (year % 400 == 0)
        return true;
    //���� �������  �� 400, ����� �������  �� 100
    if (year % 100 == 0)
        return false;
    // ���� ������� ��� ������ ��4 (��� �� ������� �� 100 � 400)
    if (year % 4 == 0)
        return true;
    //� ������ ������� �� �������  �� 4 
    return false;
}





//���������������� ��������� �����

ostream& operator << (ostream& os, Data& other)
{   //�������� ���������� ��� ���� ����������
    os << "["; 
    if (other.day < 10) { os << "0"; os << other.day;}
    else   os << other.day;  os << "/";
     
    if (other.month < 10) { os << "0"; os << other.month; }
    else   os << other.month;  os << "/";
   
    os << other.year  << "]" << endl;
 
    os << "����� �i���� � ���� ��������� c������: = " 
       << other.calendar.getNameMonth(static_cast<constants::Month>(other.month - 1)) << endl;

    //��������� ���� ���� ����� 
    int day_in_Week = other.calendar.getWeek(other.day, other.month, other.year) - 1;

    //�������� ���� ����� 
    os << "����� ��� ����� � ���� ��������� c������ : " 
       << other.calendar.getNameWeek(constants::Week(day_in_Week)) << endl;

    os << "�i� � ���� ��������� ������� ���������� ���/�I :";
    //���������� �� ���������� � �������� ��� ��� �  
  
        if ( other.calendar.isleapYear(other.year) != true)    os<<  "�I\n";
        else   os << "���\n";
 
    return os;
}



//���������������� ��������� ������

istream& operator >> (istream& in, Data& t)
{
    cout << "������� ���� � ���� ��������� ������� :\n";
    checkInputInt (t.day, 1, 31);//�������� �� ���� ��� ����� �������  ������ �� 1 �� 31 � ����'������ ���� �����

    cout << "������� ����� � ���� ��������� ������� :\n";
    checkInputInt (t.month, 1, 12);    //�������� �� ���� ���� ������� ���� �� 1 �� 12 ���� �����

    cout << "������� �� � ���� ��������� ������� :\n";
    checkInputInt (t.year, 1900, 2100);//�������� �� ���� ���� ������� ���� �� 1900 �� 2100,  ���� �����

    return in;
}



 //�������� �� ���� ������ ����� � �������  [beginNumber - endNumber]

void checkInputInt(int &number, int beginNumber ,int endNumber)
{ 
    bool valid = false;
    while (!valid)
    {  
        std::cout << "����i�� ����� :["<< beginNumber <<"-" << endNumber <<"]:   ";
        cin >> number;
        if (!cin >> number   || cin.peek() != '\n')
        {
            valid = false;
            cout << "�� �� ����� ���� �����\n" << endl;   //����������� ��� ������� �����
            cin.clear();                                  // ������� �� ������ ����� ����� � ������������ goodbit
            cin.ignore(32767, '\n');                      // ������� ���� �� �����
        }
        else
        {
            if (number >= beginNumber && number  <= endNumber)
            {
              valid = true;
              cout << "�� ����� �����  ��������� ["  << beginNumber <<"-" << endNumber <<"]\n" << endl  ;
            } 
            else
            {
                valid = false;
                cout << "�� ����� ����� �� ��������� [" << beginNumber << "-" << endNumber << "]\n"
                     <<  " ���������  ������ ������\n" << endl;
            }
        }
    }
}




//�������� �� ���� ����� ���� 

void checkInputChar( char *str, const int  size)
{ 
    //���� ������������ �� ��� �� ���� ���� ���� ��������� 
    while (true)
    { 
        std::cout << "\n����i�� ��'�  ��������:\t";
        cin.getline( str , size,'\n');

       bool   valid_char = false;

        //���������� ���� ���������� �� ��� ��'� �� ��������� ��� ��
        if (strlen(str) == 0)
        {
            cout << "��'�  �� �������!  \n";
            continue;
        }

       //���� ������������ �� ��� �� ���� ��� �� ���� ������ �� ��'� ��������� ��������� ��� ���� ���������� ������

        for (int i = 0; i < strlen(str) && !valid_char; i++)
        {
            //���������� �� �� ������� �  �������  
            //���� ����� ���� ������ �� ����� �� ����������� ��������

            if ( str[i]  >(char)64  && str[i]  < (char)91  //�������� ����� ����� 
              || str[i]  >(char)96  && str[i] < (char)123  //�������� ������� ����� 
              || str[i]  >(char)190 && str[i] < (char)256  )//��������        
            {
                //���� ������ � ������, �� �� ��� ���������� ���������  
                //���������� ��� � ���� ����� ��� �� ��������� �� ����� 
                continue;
            }
            else
            { 
            //�������� ����������� ����������� ��� ����������� ��� ��'� � ������� ���� �� �����
             cout << " ��'� ������� �� ���� !  \n" << endl;
            } 
           
            valid_char = true;   
         
        }

      //���� ���� ���������� �������� �����������
        if (!valid_char)
        {
         cout << " ��'� ������� ���� !  \n" << endl;
         break;
        }

    }
 }
