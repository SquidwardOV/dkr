#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>

using namespace std;


struct Product {
    char name[50];
    float price;
    int quantity;
};

//функция для добавления товара в файл
void addProduct(fstream& file) {
    Product product;

    cout << "Введите название товара: ";
    cin.getline(product.name, 50);

    cout << "Введите цену товара: ";
    cin >> product.price;

    cout << "Введите количество товара: ";
    cin >> product.quantity;

 
    file.seekp(0, ios::end);

 
    file.write((char*)&product, sizeof(Product));

    cout << "Товар добавлен успешно!\n";
}

//функция для удаления товара из файла
void deleteProduct(fstream& file) {
    char name[50];
    bool found = false;

    cout << "Введите название товара для удаления: ";
    cin.ignore();
    cin.getline(name, 50);

    Product product;

    //поиск товара в файле
    file.seekg(0, ios::beg);
    while (file.read((char*)&product, sizeof(Product))) {
        if (strcmp(product.name, name) == 0) {
            found = true;
            break;
        }
    }

    //удаление товара из файла
    if (found) {
        fstream tempfile("temp.bin", ios::out | ios::binary);
        file.seekg(0, ios::beg);
        while (file.read((char*)&product, sizeof(Product))) {
            if (strcmp(product.name, name) != 0) {
                tempfile.write((char*)&product, sizeof(Product));
            }
        }
        file.close();
        tempfile.close();
        remove("products.bin");
        rename("temp.bin", "products.bin");
        cout << "Товар удалён успешно!\n";
    }
    else {
        cout << "Товар не найден!\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    fstream file("products.bin", ios::in | ios::out | ios::binary);

    if (!file) {
        file.open("products.bin", ios::out | ios::binary);
        file.close();
        file.open("products.bin", ios::in | ios::out | ios::binary);
    }

    int choice;
    do {
        cout << "1. Добавить товар\n";
        cout << "2. Удалить товар\n";
        cout << "3. Выход\n";
        cout << "Введите цифру: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addProduct(file);
            break;
        case 2:
            deleteProduct(file);
            break;
        case 3:
            break;
        default:
            cout << "Некорректный ввод!\n";
        }
    } while (choice != 3);

    file.close();

    return 0;
}
