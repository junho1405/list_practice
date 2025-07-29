#pragma region MyRegion
///#include<iostream>
//
//using namespace std;
//template<typename T>
//
//class AdjacencyMatrix
//{
//    // int ** ptr = new int *[5] <<예시
//    //필요한거
//    // 정점의 개수
//    // 인접행렬의 개수
//    // 인접행렬의 메모리
//    // 정점의 집합
//    // 인접 행렬
//    // 
//private:
//    int size;//정점의 개수
//    int capacity;//최대용량
//    T* vertex;//정점의 집합
//
//    int** matrix;//인접행렬
//    int matrixCount;//인접행렬의 크기
//
//
//public:
//    AdjacencyMatrix()
//    {
//        size = 0;
//        capacity = 0;
//        vertex = nullptr;
//        
//        matrix = nullptr;
//        
//    }
//    void resize(int newSize)
//    {
//        // 1. capacity에 새로운 size값을 저장 v
//        capacity = newSize;
//
//        // 2. 새로운 포인터 변수를 생성, 새롭게 만들어진 메모리 공간을 가리키도록 합니다.
//        T* newVertex = new T[capacity];
//        // 3. 새로운 메모리 공간의 값을 초기화합니다.
//        for (int i = 0; i < size; i++)
//        {
//            newVertex[i] = NULL;
//        }
//        // 4. 기존 배열에 있는값을 복사해서 새로운 배열에 넣어준다.
//        for (int i = 0; i < size; i++)
//        {
//            newVertex[i] = vertex[i];
//        }
//        // 5. 기존배열의 메모리 해제
//        if (vertex != nullptr)
//        {
//            delete[] vertex;
//        }
//        // 6. 기존 배열을 가르키던 포인터 변수의 값을 새로운 배열의 시작주소로 가르킨다.
//        vertex = newVertex;
//    }
//
//
//    void resize()
//    {
//        int** newmatrix = new int* [size];
//        for (int i = 0; i < size; i++)
//        {
//            newmatrix[i] = new int[size] {0};
//
//        }
//        for (int i = 0; i < matrixCount; i++)
//        {
//            for (int j = 0; j < matrixCount; j++)
//            {
//                newmatrix[i][j] = matrix[i][j];
//            }
//        }
//        if (matrix != nullptr)
//        {
//            for (int i = 0; i < matrixCount; i++)
//            {
//                delete[] matrix[i];
//            }
//            delete[] matrix;
//        }
//        matrix = newmatrix;
//        matrixCount = size;
//    }
//
//    void push(T data)//인접행렬
//    {
//        if (size <= 0)
//        {
//            resize(1);
//        }
//        if (size >= capacity)
//        {
//            resize(capacity*2);
//        }
//        vertex[size] = data;
//        size++;
//
//        if (matrix != nullptr)
//        {
//            resize(); // matrix 리사이즈
//        }
//    }
//
//    void edge(int i, int j)//연결
//    {
//        // 1. 인접행렬(vertex)가 없는 상태에서 연결하면 인접행렬이 없다고 출력되야 함
//        // 2. vertex의 크기 범위를 벗어나게 되면 연결이 되지 않도록 설정
//        // 3. 인접행렬이 없을 때 정점의 크기만큼 인접행렬을 생성합니다.
//        //resize가 2개들어간다. 이번에 하는건 매개변수 없이 
//        // 인접행렬을 리사이즈한다면 size*size가 값이되면되나?
//        //
//        
//        if (size <=0)
//        {
//            cout << "adjancence matrix is empty" << endl;
//        }
//        else if (i >= size||j>=size)
//        {
//            cout << "index out of range" << endl;
//        }
//        else
//        {
//            if (matrix == nullptr)
//            {
//                matrixCount = size;
//                matrix = new int* [size];
//                for (int i = 0; i < size; i++)
//                {
//                    matrix[i] = new int[size];
//                }
//                for (int i = 0; i < size; i++)
//                {
//                    for (int j = 0; j < size; j++)
//                    {
//                        matrix[i][j] = 0;
//                    }
//                }
//                     
//            }
//            if (i == j)
//            {
//                matrix[i][j] = 1;
//            }
//            else if (matrixCount < size)
//            {
//                resize();
//            }
//            matrix[i][j] = 1;//하나만 됨
//            matrix[j][i] = 1;//하나만 됨
//        }
//    }
//
//    template <typename T>
//    friend ostream& operator << (ostream& ostream, const AdjacencyMatrix<T>& adjacencyMatrix);
//};
//
//int main()
//{
//    AdjacencyMatrix<int>adjacencyMatrix;
//    adjacencyMatrix.push(5);
//    adjacencyMatrix.push(7);
//    adjacencyMatrix.push(10);
//    adjacencyMatrix.push(15);
//    adjacencyMatrix.push(17);
//    adjacencyMatrix.push(20);
//    adjacencyMatrix.edge(5,5);
//    adjacencyMatrix.edge(0,5);
//    adjacencyMatrix.edge(3,5);
//    adjacencyMatrix.edge(5,0);
//    adjacencyMatrix.edge(0,0);
//
//    cout << adjacencyMatrix << endl;
//
//    return 0;
//}
//
//template <typename T>
//ostream& operator<<(ostream& ostream, const AdjacencyMatrix<T>& adjacencyMatrix)
//{
//    for (int i = 0; i < adjacencyMatrix.matrixCount; i++)
//    {
//        for (int j = 0; j < adjacencyMatrix.matrixCount; j++)
//        {
//            cout << adjacencyMatrix.matrix[i][j] << " ";
//
//        }
//        cout << endl;
//    }
//    return ostream;
//    // TODO: 여기에 return 문을 삽입합니다.
//}

#pragma endregion 내가한거

#pragma region 강사님거


#include <iostream>

using namespace std;

template <typename T>
class AdjacencyMatrix
{
private:
    int size; // 정점의 개수
    int capacity; // 최대 용량

    int** matrix; // 인접 행렬
    int matrixCount; // 인접 행렬의 크기

    T* vertex; // 정점의 집합

public:
    AdjacencyMatrix()
    {
        size = 0;
        capacity = 0;
        vertex = nullptr;
    }

    void push(T data)
    {
        if (capacity <= 0)
        {
            resize(1);
        }
        else if (size >= capacity)
        {
            resize(capacity * 2);
        }

        vertex[size++] = data;
    }


    void resize(int newSize)
    {
        // 1. capacity에 새로운 size 값을 저정합니다.
        capacity = newSize;

        // 2. 새로운 포인터 변수를 생성해서 새롭게 만들어진
        //    메모리 공간을 가리키도록 합니다.
        T* pointer = new T[capacity];

        // 3. 새로운 메모리 공간의 값을 초기화합니다.
        for (int i = 0; i < capacity; i++)
        {
            pointer[i] = NULL;
        }

        // 4. 기존 배열에 있는 값을 복사해서 새로운
        //    배열에 넣어줍니다.
        for (int i = 0; i < size; i++)
        {
            pointer[i] = vertex[i];
        }

        // 5. 기존 배열의 메모리를 해제합니다.
        if (vertex != nullptr)
        {
            delete[] vertex;
        }

        // 6. 기존에 배열을 가리키던 포인터 변수의 값을
        //    새로운 배열의 시작 주소로 가리킵니다.
        vertex = pointer;
    }

    void resize()
    {
        int** newMatrix = new int* [size];

        for (int i = 0; i < size; i++)
        {
            newMatrix[i] = new int[size] {0};
        }

        for (int i = 0; i < matrixCount; i++)
        {
            for (int j = 0; j < matrixCount; j++)
            {
                newMatrix[i][j] = matrix[i][j];
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

        matrix = newMatrix;

        matrixCount = size;
    }

    void edge(int i, int j)
    {
        if (size <= 0)
        {
            cout << "adjancency matrix is empty" << endl;
        }
        else if (i >= size || j >= size)
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
            }
            else if (matrixCount < size)
            {
                resize();
            }

            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }
    }

    template <typename T>
    friend ostream& operator<<(ostream& ostream, const AdjacencyMatrix<T>& adjacencyMatrix)
    {
        for (int i = 0; i < adjacencyMatrix.matrixCount; i++)
        {
            for (int j = 0; j < adjacencyMatrix.matrixCount; j++)
            {
                ostream << adjacencyMatrix.matrix[i][j] << " ";
            }

            ostream << endl;
        }

        return ostream;
    }

    ~AdjacencyMatrix()
    {
        if (matrix != nullptr)
        {
            for (int i = 0; i < matrixCount; i++)
            {
                delete[] matrix[i];

            }
            delete[] vertex;
        }
    }
};

int main()
{
    AdjacencyMatrix<int> adjacencyMatrix;

    adjacencyMatrix.push(5);
    adjacencyMatrix.push(7);
    adjacencyMatrix.push(12);

    adjacencyMatrix.edge(0, 1);

    cout << adjacencyMatrix << endl;

    return 0;
}
#pragma endregion