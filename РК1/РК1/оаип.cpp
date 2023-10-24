#include <iostream>
#include <string>
#include <algorithm> // ��� ����������

using namespace std;

// ��������� ��� �������� ���������� � ������
struct Order {
    string name;
    int quantity;
    float price;
};

// ������� ��� ������ �� ����� ����� ��������� ������
void printOrderTotal(const Order& order) {
    float total = order.quantity * order.price;
    cout << "����� ��������� ������: " << total << " ���." << endl;
}

// ������� ��� ��������� �������� ������� � ���������� �������
bool compareByName(const Order& order1, const Order& order2) {
    return order1.name < order2.name;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int numOrders; // ���������� �������
    cout << "������� ���������� �������: ";
    cin >> numOrders;

    // ��������� ������ ��� ������������ ������ �������� �������
    string* names = new string[numOrders];

    // ��������� ������ ��� ������������ ������ �������
    Order* orders = new Order[numOrders];

    // ���� ���������� � ������ ������
    for (int i = 0; i < numOrders; ++i) {
        cout << "������� ���������� � ������ #" << (i + 1) << endl;
        cout << "�������� ������: ";
        cin.ignore(); // ������� ������ ����� ������� ������
        getline(cin, orders[i].name);
        cout << "���������� ������: ";
        cin >> orders[i].quantity;
        cout << "���� �� �������: ";
        cin >> orders[i].price;

        printOrderTotal(orders[i]); // ����� ����� ��������� ������
    }

    // ���������� ����� ��������� ���� �������
    float totalCost = 0.0;
    for (int i = 0; i < numOrders; ++i) {
        totalCost += orders[i].quantity * orders[i].price;
    }

    // ���������� ���������� ������� �� ���������
    sort(orders, orders + numOrders, compareByName);

    // ����� ���������������� ������ ���������� �������
    cout << "\n��������������� ������ ���������� �������:\n";
    for (int i = 0; i < numOrders; ++i) {
        cout << orders[i].name << " (����������: " << orders[i].quantity << ", ����: " << orders[i].price << " ���.)\n";
    }

    // ����� ����� ��������� ���� �������
    cout << "\n����� ����� ���� �������: " << totalCost << " ���." << endl;

    // ������������ ������������ ������
    delete[] names;
    delete[] orders;

    return 0;
}
