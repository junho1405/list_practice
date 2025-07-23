#include<iostream>

using namespace std;
template<typename T>

class PriorityQueue
{
private:
    int index;      //사용중인 용량
    int capacity;   //최대용량
    T* container;   //사용하려는 주소
public:
    PriorityQueue()
    {
        index = 0;
        capacity = 0;
        container = nullptr;
    }

    void resize(int newSize)
    {
        // 1. capacity에 새로운 size값을 저장 v
        capacity = newSize;

        // 2. 새로운 포인터 변수를 생성, 새롭게 만들어진 메모리 공간을 가리키도록 합니다.
        T* newContainer = new T[capacity];
        // 3. 새로운 메모리 공간의 값을 초기화합니다.
        for (int i = 0; i < index; i++)
        {
            newContainer[i] = 0;
        }
        // 4. 기존 배열에 있는값을 복사해서 새로운 배열에 넣어준다.
        for (int i = 0; i < index; i++)
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
    void push(T data)
    {
        if (index <= 0) resize(1);
        if (index >= capacity)  resize(capacity * 2);

        container[index++] = data;
        int child = index - 1;
        int parent = (child - 1) / 2;

        //int child = index;
        //int parent = (child-1)/2;
        //container[child] = data;

        while (child > 0)
        {
            if (container[parent] < container[child])
            {
                std::swap(container[parent], container[child]);
            }
            child = parent;
            parent = (child - 1) / 2;
        }
    }
    const  T& top()
    {
        return container[0];
    }
    const bool& empty()
    {
        return index <= 0;
    }
    void pop()
    {
        if (empty())
        {
            cout << "비었음" << endl;
            return;
        }
        container[0] = container[index-1];
        index--;
        int parent = 0;

        while (true)
        {
            int left = parent * 2;
            int right = left + 1;
            int largest = parent;

            if (left < index && container[left] > container[largest])
            {
                largest = left;
            }

            // 오른쪽 자식이 존재하고 더 크면
            if (right < index && container[right] > container[largest])
            {
                largest = right;
            }

            // 부모가 제일 크면 종료
            if (largest == parent) break;
            swap(container[parent], container[largest]);
            parent = largest;

            //if (container[parent] < container[left] && container[right])
            //{
            //    std::swap(container[parent], container[left]);
            //}
        }



    }
    ~PriorityQueue()
    {
        if (container != nullptr)
        {
            delete[]container;
        }
    }

};
int main()
{
    PriorityQueue<int>P;
    P.push(10);
    P.push(20);
    P.push(30);
    P.push(40);
    P.push(50);
    P.push(60);
    P.push(70);
    P.push(80);
    P.pop();
    cout << P.pop << endl;
    cout << P.top() << endl;
    cout << P.empty() << endl;
    
}