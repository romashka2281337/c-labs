#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Abonent {
    string phone_number;
    string name;
    string passport_number;
};

bool compare_abonents(const Abonent& a, const Abonent& b) {
    return a.name < b.name;
}

int main() {
    // Создаем картотеку абонентов
    vector<Abonent> abonents = {
        {"1234567890", "Иванов Иван Иванович", "1234567890"},
        {"0987654321", "Петров Петр Петрович", "0987654321"},
        {"9876543210", "Сидоров Сидор Сидорович", "9876543210"}
    };

    // Сортируем картотеку по алфавиту
    sort(abonents.begin(), abonents.end(), compare_abonents);

    // Выводим всю картотеку
    cout << "Картотека абонентов:" << endl;
    for (const Abonent& abonent : abonents) {
        cout << abonent.phone_number << " " << abonent.name << " " << abonent.passport_number << endl;
    }

    // Запрашиваем у пользователя номер телефона
    cout << "Введите номер телефона: ";
    string phone_number;
    cin >> phone_number;

    // Ищем абонента по номеру телефона
    auto it = find_if(abonents.begin(), abonents.end(), [&](const Abonent& abonent) {
        return abonent.phone_number == phone_number;
    });

    // Выводим имя владельца или сообщение об ошибке
    if (it != abonents.end()) {
        cout << "Имя владельца: " << it->name << endl;
    } 
    else {
        cout << "Абонент с таким номером телефона не найден" << endl;
    }

    return 0;
}