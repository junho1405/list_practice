#include<iostream>
using namespace std;
template<typename T>
#define SIZE 5
class Queue
{
private:
    int rear;
    int front;

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
    void push(T data)
    {
        if (rear >= SIZE)
        {
            cout << "lirear Queue is overflow" << endl;
            return;
        }
        else
        {
            container[rear++] = data;
        }
    }
    bool empty()
    {
        return front == rear;
    }
    void pop()
    {
        if (empty())
        {
            cout << "lirear queue is empty" << endl;
            return;
        }
        else
        {
            container[front++] == NULL;
        }
    }
    const T& Front()
    {
        if (empty())
        {
            exit(1);
        }
        else
        {
            return container[front];
        }
    }
    const int& size()
    {
        return rear - front;
    }
};

int main()
{
    Queue<int>queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);
    queue.push(60);

    cout << "linear queue is size" << queue.size() << endl;
    while (queue.empty() == false)
    {
        cout << queue.Front() << endl;
        queue.pop();
    }
    queue.push(100);

    return 0;
}