#include<iostream>

using namespace std;
template<typename T>

//벡터의 크기 
//벡터 저장가능 메모리공간
//동적 배열을 하기 위한 포인터 변수
//생성자까지 모두 적을것

class Vector
{
private:
    int size;
    int capacity;
    T* container;

public:
    Vector() 
    {
        size = 0;
        capacity = 0;
        container = nullptr;
    }
    ~Vector()
    {
        if (container != nullptr)
        {
            delete[]container;
        }
    }
    void resize(int newSize)
    {
        // 1. capacity에 새로운 size값을 저장 v
        capacity = newSize;

        // 2. 새로운 포인터 변수를 생성, 새롭게 만들어진 메모리 공간을 가리키도록 합니다.
        T* newContainer = new T[capacity];
        // 3. 새로운 메모리 공간의 값을 초기화합니다.
        for (int i = 0; i < size; i++)
        {
            newContainer[i] = NULL;
        }
        // 4. 기존 배열에 있는값을 복사해서 새로운 배열에 넣어준다.
        for (int i = 0; i < size; i++)
        {
            newContainer[i] = container[i];
        }
        // 5. 기존배열의 메모리 해제
        if (container != nullptr)
        {
            delete[] container;
        }
        // 6. 기존 배열을 가르키던 포인터 변수의 값을 새로운 배열의 시작주소로 가르킨다.
        container = newContainer;
        }
    void push_back(T data)
    {
        if (size >= capacity)
        {
            int newCapacity = capacity * 2;
            resize(newCapacity);
        }
        container[size++] = data;
        cout << "들어간 값 : " << data << endl;
        cout << "새로 갱신된 최대치 : " << capacity << endl;
        cout << "배열의 값 : {";
        for (int i = 0; i < size; i++)
        {
            cout << container[i];            
        }
        cout << "}\n";
        cout << "최종 size :"<<size<<endl;
        cout << "최종 capacity :"<<capacity<<endl;
    }
};

int main()
{
    Vector<int> vec;
    vec.resize(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3); 
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3); 
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
}