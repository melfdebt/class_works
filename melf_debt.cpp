// melf_debt.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define random(min,max) min+rand()%(max-min+1);
using namespace std;

template<typename T>
class DinamicMassive {
public:
    DinamicMassive() {
        array = new T[size];
    }
    ~DinamicMassive() {
        size = 0;
        delete[] array;
    }
    void show() {
        if (size == 0) return;
        for (int i = 0; i < size; i++) {
            cout << array[i] << ' ';
        }
        cout << endl;
    }
    void showSize() {
        cout << "size: " << size << endl;
    }
    T* addElem(T e) {
        T* buf = new T[size + 1];
        for (int i = 0; i < size; i++) {
            buf[i] = array[i];
        }
        buf[size] = e;
        delete[] array;
        array = buf;
        size++;
        return array;
    }
    T* deleteLastElem() {
        T* buf = new T[size - 1];
        for (int i = 0; i < size - 1; i++) {
            buf[i] = array[i];
        }
        delete[] array;
        array = buf;
        size--;
        return array;
    }

private:
    T* array;
    int size = 0;
};

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    DinamicMassive<int> array;
    array.show();
    array.showSize();
    for (int i = 0; i < 10; i++) {
        int a = random(0, 10);
        array.addElem(a);
    }
    array.showSize();
    array.show();
    array.deleteLastElem();
    array.showSize();
    array.show();
}
