#include "container.h"
#include "aeroflot.h"
#include "check.h"
#include "sentense_filter.h"

void display_menu() {
    cout << "\n===== Меню управления самолетами =====" << endl;
    cout << "1. Добавить самолет" << endl;
    cout << "2. Удалить самолет" << endl;
    cout << "3. Редактировать самолет" << endl;
    cout << "4. Показать все самолеты" << endl;
    cout << "5. Сортировать самолеты по пункту назначения" << endl;
    cout << "6. Найти самолет по типу" << endl;
    cout << "0. Выйти" << endl;
    cout << "Введите ваш выбор: ";
}

int Aeroflots_program() {
    Container Aeroflots;
    int choice;

    while (true) {
        display_menu();
        choice = check_input();

        switch (choice) {
            case 1: {
                string destination, type;
                int number, index;
                cout << "Введите пункт назначения: ";
                getline(cin, destination);
                cout << "Введите номер самолета: ";
                number = check_input();
                cout << "Введите тип самолета: ";
                getline(cin, type);
                cout << "Введите индекс, куда вставить самолет: ";
                index = check_input();

                Aeroflot* new_Aeroflot = new Aeroflot(destination, number, type);
                try {
                    Aeroflots.add_Aeroflot(new_Aeroflot, index - 1);
                    cout << "Самолет добавлен." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                    delete new_Aeroflot;
                }
                break;
            }
            case 2: {
                int index;
                cout << "Введите индекс удаляемого самолета: ";
                index = check_input();
                try {
                    Aeroflots.delete_Aeroflot(index - 1);
                    cout << "Самолет удален." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: {
                int index;
                cout << "Введите индекс редактируемого самолета: ";
                index = check_input();
                try {
                    Aeroflots.edit_Aeroflot(index - 1);
                    cout << "Самолет отредактирован." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                Aeroflots.display_Aeroflots();
                break;
            }
            case 5: {
                Aeroflots.sort_Aeroflots_by_dest();
                cout << "Самолеты отсортированы по названия пункта назначения." << endl;
                Aeroflots.display_Aeroflots();
                break;
            }
            case 6: {
                cout << "Введите тип самолета для поиска: ";
                string type;
                getline(cin, type);
                Aeroflots.search_Aeroflot(type);
                break;
            }
            case 0: {
                cout << "Выход из программы." << endl;
                return 0;
            }
            default: {
                cout << "Неверный выбор! Попробуйте снова." << endl;
                break;
            }
        }
    }

    return 0;
}

int words_program() {
    try {
        SentenceFilter filter;

        int choice;
        cout << "Выберите источник текста:\n1 - Ввод с клавиатуры\n2 - Чтение из файла\nВаш выбор: ";
        if (!(cin >> choice)) {
            throw invalid_argument("Ошибка: некорректный ввод выбора источника.");
        }
        cin.ignore(); 

        if (choice == 1) {
            filter.processFromInput(); 
        } else if (choice == 2) {
            char filename[256];
            cout << "Введите имя файла: ";
            cin.getline(filename, sizeof(filename));
            if (strlen(filename) == 0) {
                throw invalid_argument("Ошибка: имя файла не может быть пустым.");
            }

            filter.processFromFile(filename); 
        } else {
            throw out_of_range("Ошибка: выбран некорректный вариант.");
        }

        filter.printReversed();
    }
    catch (const ifstream::failure& e) {
        cerr << "Ошибка ввода/вывода: " << e.what() << endl;
        return 1;
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка ввода: " << e.what() << endl;
        return 2;
    }
    catch (const out_of_range& e) {
        cerr << "Ошибка диапазона: " << e.what() << endl;
        return 3;
    }
    catch (const exception& e) {
        cerr << "Произошла ошибка: " << e.what() << endl;
        return 4;
    }
    catch (...) {
        cerr << "Произошла неизвестная ошибка." << endl;
        return 5;
    }

    return 0;
}



int main() {
    setlocale(LC_ALL, "ru"); 
    int choice;
    while (true) {
        cout << "Выберите тип задания:" << endl;
        cout << "1 - Стандартные потоки" << endl;
        cout << "2 - Файловые и строковые потоки" << endl;
        cout << "3 - Выход" << endl;
        choice = check_input();

        switch (choice) {
            case 1:
                Aeroflots_program();
                break;
            case 2:
                words_program();
                break;
            case 3:
                cout << "Завершение работы." << endl;
                return 0;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
                break;
        }
    }
}
