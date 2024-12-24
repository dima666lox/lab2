#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Aeroflot {
    private:
        string destination;
        int number;
        string type;
    public:
        Aeroflot();
        Aeroflot(const string& d, const int& n, const string& t);
        Aeroflot(const Aeroflot& other);
        ~Aeroflot();

        string get_destination();
        void set_destination(const string& d);
        int get_number();
        void set_number(const int& n);
        string get_type();
        void set_type(const string& t);

        void display_Aeroflot();
        void edit_Aeroflot();
};