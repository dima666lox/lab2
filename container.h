#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "aeroflot.h"

using namespace std;

struct Node
{
    Node* next;
    Aeroflot* data;
};

class Container
{
private:
    Node* head;
    Node* tail;
    int count;

public:
    Container();
    Container(Node* h, Node* t, const int c);
    Container(const Container& other);
    ~Container();

    Node* get_head();
    Node* get_tail();

    void add_Aeroflot(Aeroflot* Tr, int index);
    Container& delete_Aeroflot(int index);
    Container& edit_Aeroflot(int index);
    void display_Aeroflots();
    void sort_Aeroflots_by_dest();
    void search_Aeroflot(const string type);

    Container& operator[](int index);
};

