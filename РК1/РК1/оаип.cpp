#include <iostream>
#include <string>
#include <algorithm> // для сортировки

using namespace std;

// Структура для хранения информации о заказе
struct Order {
    string name;
    int quantity;
    float price;
};

// Функция для вывода на экран общей стоимости заказа
void printOrderTotal(const Order& order) {
    float total = order.quantity * order.price;
    cout << "Общая стоимость заказа: " << total << " руб." << endl;
}

// Функция для сравнения названий товаров в алфавитном порядке
bool compareByName(const Order& order1, const Order& order2) {
    return order1.name < order2.name;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int numOrders; // количество заказов
    cout << "Введите количество заказов: ";
    cin >> numOrders;

    // Выделение памяти под динамический массив названий товаров
    string* names = new string[numOrders];

    // Выделение памяти под динамический массив заказов
    Order* orders = new Order[numOrders];

    // Ввод информации о каждом заказе
    for (int i = 0; i < numOrders; ++i) {
        cout << "Введите информацию о заказе #" << (i + 1) << endl;
        cout << "Название товара: ";
        cin.ignore(); // очистка буфера перед чтением строки
        getline(cin, orders[i].name);
        cout << "Количество единиц: ";
        cin >> orders[i].quantity;
        cout << "Цена за единицу: ";
        cin >> orders[i].price;

        printOrderTotal(orders[i]); // вывод общей стоимости заказа
    }

    // Вычисление общей стоимости всех заказов
    float totalCost = 0.0;
    for (int i = 0; i < numOrders; ++i) {
        totalCost += orders[i].quantity * orders[i].price;
    }

    // Сортировка заказанных товаров по названиям
    sort(orders, orders + numOrders, compareByName);

    // Вывод отсортированного списка заказанных товаров
    cout << "\nОтсортированный список заказанных товаров:\n";
    for (int i = 0; i < numOrders; ++i) {
        cout << orders[i].name << " (количество: " << orders[i].quantity << ", цена: " << orders[i].price << " руб.)\n";
    }

    // Вывод общей стоимости всех заказов
    cout << "\nОбщая сумма всех заказов: " << totalCost << " руб." << endl;

    // Освобождение динамической памяти
    delete[] names;
    delete[] orders;

    return 0;
}
