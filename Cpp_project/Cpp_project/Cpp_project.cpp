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
		Node* previousNode;

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


};
int main()
{
#pragma region 양방향 연결리스트
	list<int>list;
#pragma endregion

}