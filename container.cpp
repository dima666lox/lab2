#include "container.h"

Container::Container() : head(nullptr), tail(nullptr), count(0) {cout << "Вызван конструктор без параметров для класса Container\n";}

Container::Container(Node* h, Node* t, const int c) : head(h), tail(t), count(c) {
    cout << "Вызван конструктор с параметрами для класса Container\n";
}

Container::Container(const Container& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "Вызван конструктор копирования для класса Container\n";
}

Container::~Container() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    tail = nullptr;
    count = 0;
    cout << "Вызван деструктор для класса Container" << endl;
}


Node* Container::get_head() {
    return this->head;
}

Node* Container::get_tail() {
    return this->tail;
}

void Container::add_Aeroflot(Aeroflot* Tr, int index) {
    if (index < 0 || index > count) {
        throw out_of_range("Index out of range");
    }
    
    Node* node_to_add = new Node;
    node_to_add->data = Tr;
    node_to_add->next = nullptr;

    if (index == 0) {
        node_to_add->next = head;
        head = node_to_add;
        if (count == 0) {
            tail = node_to_add;
        }
    } else {
        Node* prev = head;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }
        node_to_add->next = prev->next;
        prev->next = node_to_add;
        
        if (node_to_add->next == nullptr) {
            tail = node_to_add;
        }
    }
    
    ++count;
}

Container& Container::delete_Aeroflot(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;

    if (index == 0) {
        head = head->next;
        delete temp->data;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    } else {
        Node* prev = nullptr;
        for (int i = 0; i < index; ++i) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        if (temp == tail) {
            tail = prev;
        }
        delete temp->data;
        delete temp;
    }

    --count;
    return *this;
}

void Container::display_Aeroflots() {
    Node* temp = head;
    if (count == 0) {
        cout << "Самолетов нет" << endl;
        return;
    }
    int index = 1;
    while (temp != 0) {
        cout << index << " - Информация о самолете:\n";
        temp->data->display_Aeroflot();
        temp = temp->next;
        index++;
    }
}

void Container::sort_Aeroflots_by_dest() {
    if (count < 2) return;

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = head; j->next != nullptr; j = j->next) {
            if (j->data->get_destination() > j->next->data->get_destination()) {
                Aeroflot* temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

void Container::search_Aeroflot(const string type) {

    Node* temp = head;
    int flag = 0;
    while (temp != nullptr) {
        if (temp->data->get_type() == type) {
            temp->data->display_Aeroflot();
            flag = 1;
        }
        temp = temp->next;
    }
    if (flag == 0) {
        cout << "Самолеты с типами " << type << " не найден." << endl;
    }
}

Container& Container::edit_Aeroflot(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    temp->data->edit_Aeroflot();
    return *this;
}

Container& Container::operator[](int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    return *this;
}