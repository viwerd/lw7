#include <iostream>
#include <string>

/*
* Вот гайдики, по которым я делал эту лабу :
* https://metanit.com/cpp/tutorial/5.1.php
* https://metanit.com/cpp/tutorial/5.2.php
* https://metanit.com/cpp/tutorial/5.4.php
* https://metanit.com/cpp/tutorial/5.3.php
* https://metanit.com/cpp/tutorial/5.17.php
* https://metanit.com/cpp/tutorial/5.18.php
*/

using namespace std;

class Patient
{
private:
    string name;
    char gender;
    int age;
    string birthdate;
    string phone_number;
public:
    // Конструктор по умолчанию
    Patient()
    {
        name = "";
        gender = ' ';
        age = 0;
        birthdate = "";
        phone_number = "";
    }
    // Пользовательский конструктор
    Patient(string n, char g, int a, string bd, string pn)
    {
        name = n;
        gender = g;
        age = a;
        birthdate = bd;
        phone_number = pn;
    }
    // Конструктор копирования
    Patient(const Patient& p)
    {
        name = p.name;
        gender = p.gender;
        age = p.age;
        birthdate = p.birthdate;
        phone_number = p.phone_number;
    }
    // Методы get и set для всех переменных
    string get_name() const
    {
        return name;
    }
    void set_name(string n)
    {
        name = n;
    }
    char get_gender() const
    {
        return gender;
    }
    void set_gender(char g)
    {
        gender = g;
    }
    int get_age() const
    {
        return age;
    }
    void set_age(int a)
    {
        age = a;
    }
    string get_birthdate() const
    {
        return birthdate;
    }
    void set_birthdate(string bd)
    {
        birthdate = bd;
    }
    string get_phone_number() const
    {
        return phone_number;
    }
    void set_phone_number(string pn)
    {
        phone_number = pn;
    }
};

class Client : public Patient
{
private:
    string client_id;
public:
    // Пользовательский конструктор
    Client(string n, char g, int a, string bd, string pn, string sid) : Patient(n, g, a, bd, pn)
    {
        client_id = sid;
    }
    // Метод для получения id пациента
    string get_client_id() const
    {
        return client_id;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    // Создание объектов класса Person и Student
    Patient patient1("Влад", 'М', 18, "27.09.2004", "8-913-634-17-47");
    Patient patient2("Алина", 'Ж', 40, "21.01.1983", "8-999-999-99-99");
    Patient patient3 = patient2;
    Client client1("Марина", 'Ж', 19, "12.03.2004", "8-888-888-88-88", "634451667");

    // Вывод информации о созданных объектах
    cout << "patient1: " << patient1.get_name() << " " << patient1.get_gender() << " " << patient1.get_age() << " " << patient1.get_birthdate() << " " << patient1.get_phone_number() << endl;
    cout << "patient2: " << patient2.get_name() << " " << patient2.get_gender() << " " << patient2.get_age() << " " << patient2.get_birthdate() << " " << patient2.get_phone_number() << endl;
    cout << "patient3: " << patient3.get_name() << " " << patient3.get_gender() << " " << patient3.get_age() << " " << patient3.get_birthdate() << " " << patient3.get_phone_number() << endl;
    cout << "client1: " << client1.get_name() << " " << client1.get_gender() << " " << client1.get_age() << " " << client1.get_birthdate() << " " << client1.get_phone_number() << " " << client1.get_client_id() << endl;

    return 0;
}
