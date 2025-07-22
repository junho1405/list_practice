#include<iostream>
#define SIZE 5
using namespace std;
template <typename T>

class Stack
{
private:
    int count;
    int highset;// -1부터 시작
    T container[SIZE];

public:
    Stack()
    {
        count = 0;
        highset = -1;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }
    void push(T data)
    {
        if (highset >= SIZE - 1)
        {
            cout << "Stack overflow" << endl;


        }
        else
        {
            container[++highset];
        }

    }
    bool empty()
    {
        return(highset <= -1);
    }
    void pop(T data)
    {
        if (empty())
        {
            cout << "stack is full" << endl;
        }
        else
        {
            highset--;
        }
    }
    const int& size()
    {
        count = highset + 1;
        return count;
    }
    const T& top()
    {
        return container[highset];
    }
};

int main()
{
    Stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);//여기서부턴 stack이 가득참
    while (s.empty() == false)
    {
        cout << s.top() << endl;
        s.pop(10);
    }
    cout << s.empty() << endl;
}