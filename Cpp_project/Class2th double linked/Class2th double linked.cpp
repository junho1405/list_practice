#include<iostream>
using namespace std;
template <typename T>

class list
{
private:
	struct Node
	{
		T data;
		Node* nextNode;
		Node* previouse;

	};
	int size;
	Node* head;
	Node* tail;

public:
	list()
	{
		cout << "출력" << endl;
		size = 0;
		head = NULL;
		tail = NULL;

	}
	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->nextNode = nullptr;
		newNode->previouse = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			head->previouse = newNode;
			newNode->nextNode = head;
			head = newNode;
		}
		size++;
	}
	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "linked list is empty" << endl;
		}
		else
		{
			Node* deleteNode = head;
			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				deleteNode->nextNode->previouse = nullptr;
				head = head->nextNode;
			}
			delete deleteNode;
			size--;
		}
	}
	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->nextNode = nullptr;
		newNode->previouse = nullptr;
		if (tail == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->nextNode = newNode;
			newNode->previouse = tail;
			tail = newNode;
		}
		size++;
	}
	void pop_back()
	{
		if (tail == nullptr)
		{
			cout << "linked list is empty" << endl;
		}
		else
		{
			Node* deleteNode = tail;
			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				tail->previouse->nextNode = nullptr;
				tail = tail->previouse;
			}
			delete deleteNode;
			size--;
		}
	}
	bool empty()
	{
		return (head == nullptr);
	}
	void remove(T data)
	{
		Node* deleteNode = head;
		Node* nextNode = nullptr;
		while (deleteNode != nullptr)
		{
			if (deleteNode->data == data)
			{
				if (deleteNode == head)
				{
					pop_front();
				}
				else if (deleteNode == tail)
				{
					pop_back();
					deleteNode = nullptr;
				}
				else
				{
					deleteNode->previouse->nextNode = deleteNode->nextNode;
					deleteNode->nextNode->previous = deleteNode->previouse;
					nextNode = deleteNode->nextNode;
					delete deleteNode;
					deleteNode = nextNode;
					size--;
				}
			}
		}

	}
	~list()
	{
		while (head != nullptr)
		{
			pop_front();
			cout << "pop" << endl;
		}
		cout << "empty" << endl;
	}
};

int main()
{
#pragma region 양방향 연결리스트
	list<int> list;
	list.push_front(10);
	list.push_front(20);
	list.push_front(30);
	list.push_front(40);
	list.pop_back();
	list.pop_front();
	list.remove(30);

	cout << list.empty() << endl;
#pragma endregion

}