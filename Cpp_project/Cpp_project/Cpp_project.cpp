﻿#include<iostream>
#define SIZE 10
using namespace std;

template<typename T>
class AdjacencyList
{
private:
    struct Node
    {
        T data;
        Node* next;

        Node(T data, Node* link = nullptr)
        {
            this->data = data;
            next = link;
        }
    };
    int size; // 정점의 개수
    T vertex[SIZE]; //  정점의 집합
    Node* list[SIZE];   //  인접리스트
public:

    AdjacencyList()
    {
        size = 0;
        for (int i = 0; i < SIZE; i++)
        {
            list[i] = NULL;
            vertex[i] = NULL;
        }
    }
    void push(T data)
    {
        if (size >= SIZE)
        {
            cout << "꽉참" << endl;
        }
        else
        {
            vertex[size++] = data;
        }
    }
    void edge(int i, int j)
    {   
        //if (i >= size || j >= size)
        //{
        //    cout << "안돼" << endl;
        //}
        //
        //list[i] = new Node(j, list[i]);
        //list[j] = new Node(i, list[j]);
        if (size <= 0)
        {
            cout << "adjacency list is empty" << endl;
        }
        else if (i >= size || j >= size)
        {
            cout << "index out of range" << endl;
        }
        else
        {
            list[i] = new Node(vertex[j], list[i]);
            list[j] = new Node(vertex[i], list[j]);
        }
    }
    ~AdjacencyList()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (list[i] != nullptr)
            {
                delete[] list[i];
            }

        }
    }
};

int main()
{
    AdjacencyList<char> adjacencyList;

    adjacencyList.push('A');
    adjacencyList.push('B');
    adjacencyList.push('C');

    adjacencyList.edge(0,1);
    adjacencyList.edge(0,2);

    return 0;

}