#include<iostream>
using namespace std;
#define SIZE 4
template<typename T>

class Queue
{
private:
    int front;
    int rear;
    T container[SIZE];
public:
    Queue()
    {

        front = 0;
        rear = 0;
        for (int i = 0; i < SIZE; i++)
        {
            container[i] = 0;
        }
    }

    bool full()
    {
        return (rear + 1) % SIZE == front;
    }
    void push(T data)
    {

        if (front == (rear + 1) % SIZE)
        {
            cout << "circle queue overload" << endl;
        }
        else
        {
            rear = (rear + 1) % SIZE;
            container[rear] = data;
            return;
        }
    }
    void pop()
    {
        if (empty())
        {
            cout << "circle queue is empty" << endl;
        }
        else
        {
            //프론트는 지우고 뒤에걸 앞으로

            front = (front + 1) % SIZE;
            container[front] = NULL;

        }
    }
    bool empty()
    {
        return front == rear;
    }
    const T& Front()
    {
        if (empty())
        {
            exit(1);
        }
        else
        {
            return container[(front + 1) % SIZE];
        }
    }
};

int main()
{
    Queue<int>queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    while (queue.empty() == false)
    {
        cout << queue.Front() << endl;
        queue.pop();
    }
    //queue.push(40);
    return 0;
}