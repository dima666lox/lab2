#include "aeroflot.h"

Aeroflot::Aeroflot() : destination(""), number(0), type("") {cout << "Вызван конструктор без параметров для класса Aeroflot\n";}

Aeroflot::Aeroflot(const string& d, const int& n, const string& t) : destination(d), number(n), type(t) {
    cout << "Вызван конструктор с параметрами для класса Aeroflot\n";
}

Aeroflot::Aeroflot(const Aeroflot& other) : destination(other.destination), number(other.number), type(other.type) {
    cout << "Вызван конструктор копирования для класса Aeroflot\n";
}

Aeroflot::~Aeroflot() {cout << "Вызван деструктор для класса Aeroflot\n";}

string Aeroflot::get_destination() {
    return this->destination;
}

void Aeroflot::set_destination(const string& d) {
    this->destination = d;
}

int Aeroflot::get_number() {
    return this->number;
}

void Aeroflot::set_number(const int& n) {
    this->number = n;
}

string Aeroflot::get_type() {
    return this->type;
}

void Aeroflot::set_type(const string& t) {
    this->type = t;
}

void Aeroflot::display_Aeroflot() {
    cout << "Пункт назначения: " << this->get_destination() << endl;
    cout << "Номер рейса: " << this->get_number() << endl;
    cout << "Тип самолета: " << this->get_type() << endl; 
    cout << endl;
}

void Aeroflot::edit_Aeroflot() {
    int choice;
    cout << "Выберите, что хотите изменить:\n";
    cout << "1. Пункт назначения\n";
    cout << "2. Номер рейса\n";
    cout << "3. Тип самолета\n";
    cout << "Введите ваш выбор: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string new_destination;
            cout << "Введите новый пункт назначения: ";
            cin.ignore();
            getline(cin, new_destination);
            set_destination(new_destination);
            break;
        }
        case 2: {
            int new_number;
            cout << "Введите новый номер рейса: ";
            cin >> new_number;
            set_number(new_number);
            break;
        }
        case 3: {
            string new_type;
            cout << "Введите новый тип самолета: ";
            cin.ignore();
            getline(cin, new_type);
            set_type(new_type);
            break;
        }
        default:
            cout << "Неверный выбор!" << endl;
    }
}
