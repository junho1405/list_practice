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
			cout<<data<<endl;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
			head = newNode;
			cout<<data<<endl;
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
		Node* deleteNode = head;
		if (head == deleteNode)
		{
			cout << "삭제된 값:" << deleteNode->data << endl;
			delete deleteNode;
			size--;
		}
		else
		{

		}
	}
};

int main()
{
	List<int> list;
	list.push_front(10);
	list.push_front(20);
	list.push_back(30);
	list.pop_front();
}