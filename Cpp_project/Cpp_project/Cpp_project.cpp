#include<iostream>
using namespace std;

template <typename T>
class list
{
private:
	int size;
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
public:
	list()
	{
		size = 0;
		head = nullptr;
		cout << "출력\n";
	}
	
	void push_front(T data)
	{
		Node* newnode = new Node;
		newnode->data = data;
		if (head == nullptr)
		{
			head = newnode;
			newnode->next = nullptr;
		}
		else
		{
			newnode->next = head;
			head = newnode;

		}
		size++;
	}
	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = nullptr;
		}
		else
		{
			Node* currentNode = head;
			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;
		}
		size++;
	}

	void pop_front()//헤더변경하고 삭제//empty면 empty라고 출력
	{
		if (head == nullptr)
		{
			cout << "rinked is empty" << endl;
		}
		else
		{
			Node* deleteNode = head;
			head = deleteNode->next;
			delete deleteNode;
			size--;
		}
	}
	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "rinked is empty" << endl;
			return;
		}
		else
		{
			Node* deleteNode = head;
			Node* previousNode = nullptr;
			if (size == 1)
			{
				head = deleteNode->next;

				delete deleteNode;

			}
			else
			{
				while (deleteNode->next != nullptr)
				{
					previousNode = deleteNode;
					deleteNode = deleteNode->next;
				}

				delete deleteNode->next;
				deleteNode->next = nullptr;
				size--;
			}
			
		}
		//if (head->next == nullptr)
		//{
		//	delete head;
		//	head = nullptr;
		//	size--;
		//	return;
		//}
		//Node* currentNode = head;
		//while (currentNode->next->next != nullptr)
		//{
		//	currentNode = currentNode->next;
		//}
		//
		//delete currentNode->next;
		//currentNode->next = nullptr;
		//size--;
	}
	
	bool empty()
	{
		return (head == nullptr);
	}

	~list()
	{
		while (head != nullptr)
		{
			pop_front();
		}
		cout << "~list작동" << endl;
	}
};


//이것은 깃허브용 테스트 주석입니다.
int  main()
{
#pragma region list
	list<int>list;
	list.push_back(20);
	list.pop_front();
	list.pop_back();
	return 0;
#pragma endregion
}