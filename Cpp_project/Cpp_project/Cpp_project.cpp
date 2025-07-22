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
    bool empty()
    {
        return front == rear;
    }
    bool full()
    {
        return (rear + 1) % SIZE = front;
    }
    void push(T data)
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else if (full())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {

        }
    }
    void pop()
    {

    }
};

int main()
{
    Queue<int>queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(40);
    return 0;
}