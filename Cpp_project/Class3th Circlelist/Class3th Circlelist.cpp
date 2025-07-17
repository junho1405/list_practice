#include<iostream>
using namespace std;
template <typename T>

class List
{
private:
    struct Node
    {
        T data;
        Node* next;
    };
    Node* head;
    int size;
public:
    List()
    {
        size = 0;
        head = nullptr;
    }
    void push_back(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            cout << data << endl;
        }
        else
        {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
            cout << data << endl;
        }
        size++;
        cout << head << endl;
    }
    void push_front(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            cout << data << endl;
        }
        else//newNode->head
        {
            newNode->next = head->next;
            head->next = newNode;
            cout << data << endl;
        }
        size++;
        cout << head << endl;
    }
    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
        }
        else
        {
            Node* deleteNode = head->next;
            if (head == head->next)
            {
                head = nullptr;
            }
            else
            {
                head->next = deleteNode->next;
            }
            cout << "삭제된 값:" << deleteNode->data << endl;
            delete deleteNode;
        }

    }
    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }



        if (head == head->next)//하나일때
        {
            cout << "삭제된 값:" << head->data << endl;
            delete head;
            head = nullptr;
        }
        else//둘 이상일 때
        {
            Node* current = head;
            Node* deleteNode = head;
            Node* previous = head;

            //for (int i = 0; i < size; i++)
            //{
            //    current = current->next;
            //}
            //current->next = head->next;
            //cout << "삭제된 값: " << current->data << endl;
            //delete deleteNode;

            while(current->next != head)
            {
            	previous = current;
            	current = current->next;
            }
            previous->next = head;
            delete previous;
        }
        size--;
    }
    bool empty()
    {
        return(head == nullptr);
    }

    ~List()
    {
        while (head != nullptr)
        {
            pop_front();
            size--;
        }
    }
};


int main()
{
    List<int> list;
    list.push_front(10);
    list.push_front(20);
    list.push_back(50);
    list.push_back(40);
    list.pop_front();
    list.pop_back();
}