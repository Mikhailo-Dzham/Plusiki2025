#include <iostream>
#include <vector>

using namespace std;

// Шаблонний клас Array для роботи з довільним типом даних T
template <typename T>
class Array {
private:
    T* data;    // Вказівник на масив
    int size;   // Розмір масиву

public:
    // Конструктор
    Array(int n) : size(n) {
        data = new T[size];
    }

    // Деструктор для звільнення пам'яті
    ~Array() {
        delete[] data;
    }

    // Метод для заповнення масиву значеннями (для зручності тестування)
    void set(int index, T value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }

    // Метод для отримання значення (для перевірки)
    T get(int index) const {
        if (index >= 0 && index < size) return data[index];
        return T(); // Повернення дефолтного значення при помилці
    }

    // Допоміжний метод виводу
    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // ---------------------------------------------------------
    // 1. Метод екземпляру: Сортування вставками (Insertion Sort)
    // ---------------------------------------------------------
    void insertionSort() {
        // Викликаємо статичний метод для власного масиву data
        // Це дозволяє уникнути дублювання коду
        staticInsertionSort(this->data, this->size);
    }

    // ---------------------------------------------------------
    // 2. Статичний метод: Сортування вставками (In-place)
    // Працює з будь-яким переданим масивом
    // ---------------------------------------------------------
    static void staticInsertionSort(T* arr, int n) {
        for (int i = 1; i < n; i++) {
            T key = arr[i];
            int j = i - 1;

            // Зсуваємо елементи, які більші за key, на одну позицію вправо
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
};

int t18_5g() {
    // === ТЕСТ 1: Робота з методом об'єкту (int) ===
    cout << "--- Test 1: Member Method (Integer) ---" << endl;
    Array<int> myArray(5);
    myArray.set(0, 12);
    myArray.set(1, 11);
    myArray.set(2, 13);
    myArray.set(3, 5);
    myArray.set(4, 6);

    cout << "Before sort: ";
    myArray.print();

    myArray.insertionSort(); // Виклик методу класу

    cout << "After sort:  ";
    myArray.print();
    cout << endl;

    // === ТЕСТ 2: Робота зі статичним методом (double) ===
    cout << "--- Test 2: Static Method (Double array) ---" << endl;
    double rawArray[] = {3.14, 1.59, 2.65, 5.35, 0.99};
    int n = 5;

    cout << "Raw array before: ";
    for(double x : rawArray) cout << x << " ";
    cout << endl;

    // Виклик статичного методу без створення об'єкту класу
    Array<double>::staticInsertionSort(rawArray, n);

    cout << "Raw array after:  ";
    for(double x : rawArray) cout << x << " ";
    cout << endl;

    return 0;
}