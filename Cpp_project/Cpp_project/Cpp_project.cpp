#include<iostream>

using namespace std;
template<typename T>

class AdjacencyMatrix
{
    // int ** ptr = new int *[5] <<예시
    //필요한거
    // 정점의 개수
    // 인접행렬의 개수
    // 인접행렬의 메모리
    // 정점의 집합
    // 인접 행렬
    // 
private:
    int size;//정점의 개수
    int capacity;//최대용량
    T* vertex;//정점의 집합

    int** matrix;//인접행렬
    int matrixCount;//인접행렬의 크기


public:
    AdjacencyMatrix()
    {
        size = 0;
        capacity = 0;
        vertex = nullptr;
        
        matrix = nullptr;
        
    }
    void resize(int newSize)
    {
        // 1. capacity에 새로운 size값을 저장 v
        capacity = newSize;

        // 2. 새로운 포인터 변수를 생성, 새롭게 만들어진 메모리 공간을 가리키도록 합니다.
        T* newVertex = new T[capacity];
        // 3. 새로운 메모리 공간의 값을 초기화합니다.
        for (int i = 0; i < size; i++)
        {
            newVertex[i] = NULL;
        }
        // 4. 기존 배열에 있는값을 복사해서 새로운 배열에 넣어준다.
        for (int i = 0; i < size; i++)
        {
            newVertex[i] = vertex[i];
        }
        // 5. 기존배열의 메모리 해제
        if (vertex != nullptr)
        {
            delete[] vertex;
        }
        // 6. 기존 배열을 가르키던 포인터 변수의 값을 새로운 배열의 시작주소로 가르킨다.
        vertex = newVertex;
    }


    void resize()
    {
        int** newmatrix = new int* [size];
        for (int i = 0; i < size; i++)
        {
            newmatrix[i] = new int[size] {0};

        }
        for (int i = 0; i < matrixCount; i++)
        {
            for (int j = 0; j < matrixCount; j++)
            {
                newmatrix[i][j] = matrix[i][j];
            }
        }
        if (matrix != nullptr)
        {
            for (int i = 0; i < matrixCount; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
        matrix = newmatrix;
        matrixCount = size;
    }

    void push(T data)//인접행렬
    {
        if (size <= 0)
        {
            resize(1);
        }
        if (size >= capacity)
        {
            resize(capacity*2);
        }
        vertex[size] = data;
        size++;

        if (matrix != nullptr)
        {
            resize(); // matrix 리사이즈
        }
    }

    void edge(int i, int j)//연결
    {
        // 1. 인접행렬(vertex)가 없는 상태에서 연결하면 인접행렬이 없다고 출력되야 함
        // 2. vertex의 크기 범위를 벗어나게 되면 연결이 되지 않도록 설정
        // 3. 인접행렬이 없을 때 정점의 크기만큼 인접행렬을 생성합니다.
        //resize가 2개들어간다. 이번에 하는건 매개변수 없이 
        // 인접행렬을 리사이즈한다면 size*size가 값이되면되나?
        //
        
        if (size <=0)
        {
            cout << "adjancence matrix is empty" << endl;
        }
        else if (i >= size||j>=size)
        {
            cout << "index out of range" << endl;
        }
        else
        {
            if (matrix == nullptr)
            {
                matrixCount = size;
                matrix = new int* [size];
                for (int i = 0; i < size; i++)
                {
                    matrix[i] = new int[size];
                }
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        matrix[i][j] = 0;
                    }
                }
                if (matrix != nullptr)
                {
                    resize();
                }
                matrix[i][j] = 1;//하나만 됨
                
            }
        }
    }
    
};

int main()
{
    AdjacencyMatrix<int>adjacencyMatrix;
    adjacencyMatrix.push(5);
    adjacencyMatrix.push(7);
    adjacencyMatrix.push(10);
    adjacencyMatrix.edge(1,2);

}