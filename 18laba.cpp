#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyObject {
public:
    MyObject(int value) : value(value) {}

    int value;
};

int main() {
    // Запрашиваем размерности векторов
    int num_objects;
    cout << "Введите размерность векторов: ";
    cin >> num_objects;

    // Создаем исходный вектор из объектов класса
    vector<MyObject> initial_vector;
    for (int i = 0; i < num_objects; i++) {
        initial_vector.push_back(MyObject(rand() % 100));
    }

    // Выводим исходный вектор
    cout << "Исходный вектор:" << endl;
    for (const MyObject& obj : initial_vector) {
        cout << obj.value << " ";
    }
    cout << endl;

    // критерий для перезаписи объектов (перезаписываем объекты, значение которых больше 50)
    vector<MyObject> new_vector;
    for (const MyObject& obj : initial_vector) {
        if (obj.value > 50) {
            new_vector.push_back(obj);
        }
    }

    // Отображаем новый вектор
    cout << "Новый вектор:" << endl;
    for (const MyObject& obj : new_vector) {
        cout << obj.value << " ";
    }
    cout << endl;

    // Проверяем, не пуст ли новый вектор
    if (new_vector.empty()) {
        cout << "Новый вектор пуст" << endl;
    } else {
        // Сортируем объекты в новом векторе
        sort(new_vector.begin(), new_vector.end(), [](const MyObject& a, const MyObject& b) {
            return a.value < b.value;
        });
        cout << "Сортированный новый вектор:" << endl;
        for (const MyObject& obj : new_vector) {
            cout << obj.value << " ";
        }
        cout << endl;
    }

    return 0;
}