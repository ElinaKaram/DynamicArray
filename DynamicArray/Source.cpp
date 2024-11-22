#include <iostream>
using namespace std;

class DynamicArray
{
private:

    int* data;
    int size;

public:

    DynamicArray() : data(nullptr), size(0) {}

    DynamicArray(int s) : size(s) 
    {
        data = new int[size];

        for (int i = 0; i < size; i++) 
        {
            data[i] = 0;
        }
    }

    DynamicArray(const DynamicArray& other) : size(other.size)
    {
        data = new int[size];

        for (int i = 0; i < size; i++) 
        {
            data[i] = other.data[i];
        }
    }

    ~DynamicArray() 
    {
        delete[] data;
    }

    DynamicArray& operator=(const DynamicArray& other) 
    {
        if (this == &other) return *this;
        delete[] data;
        size = other.size;
        data = new int[size];

        for (int i = 0; i < size; i++) 
        {
            data[i] = other.data[i];
        }
        return *this;
    }

    DynamicArray operator+(int value) const 
    {
        DynamicArray result(size + value);

        for (int i = 0; i < size; i++)
        {
            result.data[i] = data[i];
        }
        return result;
    }

    DynamicArray operator-(int value) const 
    {
        if (size <= value) 
        {
            return DynamicArray();
        }

        DynamicArray result(size - value);

        for (int i = 0; i < result.size; i++) 
        {
            result.data[i] = data[i];
        }
        return result;
    }

    DynamicArray operator*(int value) const 
    {
        DynamicArray result(size);

        for (int i = 0; i < size; i++) 
        {
            result.data[i] = data[i] * value;
        }
        return result;
    }

    DynamicArray operator-(const DynamicArray& other) const
    {
        int newSize = size > other.size ? size - other.size : 0;
        DynamicArray result(newSize);

        for (int i = 0; i < newSize; i++)
        {
            result.data[i] = data[i];
        }
        return result;
    }

    DynamicArray operator+(const DynamicArray& other) const 
    {
        DynamicArray result(size + other.size);

        for (int i = 0; i < size; i++) 
        {
            result.data[i] = data[i];
        }

        for (int i = 0; i < other.size; i++)
        {
            result.data[size + i] = other.data[i];
        }
        return result;
    }

    DynamicArray& operator+() 
    {
        *this = *this + 1;
        return *this;
    }

    DynamicArray& operator--() 
    {
        *this = *this - 1;
        return *this;
    }

    void display() const {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void set(int index, int value)
    {
        if (index >= 0 && index < size) 
        {
            data[index] = value;
        }
    }
};

int main()
{
    DynamicArray a(5);
    for (int i = 0; i < 5; i++) 
    {
        a.set(i, i + 1);
    }

    cout << "Source array a: ";
    a.display();

    DynamicArray rez = a + 10;
    cout << "a + 10: ";
    rez.display();

    DynamicArray rez1 = a - 2;
    cout << "a - 2: ";
    rez1.display();

    DynamicArray rez2 = a * 2;
    cout << "a * 2: ";
    rez2.display();

    DynamicArray rez3 = a + rez2;
    cout << "a + rez2: ";
    rez3.display();

    DynamicArray rez4 = rez3 - rez2;
    cout << "rez3 - rez2: ";
    rez4.display();

    +a;
    cout << "+a: ";
    a.display();

    --a;
    cout << "--a: ";
    a.display();

    return 0;
}