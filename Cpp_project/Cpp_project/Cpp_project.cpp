#include <iostream>

using namespace std;

template<typename T>
class Set
{
private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;

        Node(T data) : data(data), left(nullptr), right(nullptr) {}
    };
        Node* root;
        int size;
public:
    Set()
    {   
        size = 0;
        root = nullptr;
    } 
    Node* create_node(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;

    }
    void insert(T data)
    {
        if (root == nullptr)
        {
            root = create_node(data);
        }
        else
        {
            Node* currentNode = root;
            //while (currentNode != nullptr)
            //{
            //    return;
            //}
            if (currentNode->data > data)
            {
                if (currentNode->left == nullptr)
                {
                    currentNode->left = create_node(data);
                }
                else
                {
                    currentNode = currentNode -> left;
                }

            }
            else
            {
                if (currentNode->right == nullptr)
                {
                    currentNode->right = create_node(data);

                    return;
                }
                else
                {
                    currentNode = currentNode->right;
                }
            }

        }
    }
    void release(Node* node)
    {
        //재귀함수, 3줄정도면 끝남
        // nullptr이면 이전으로 돌아가게한다.
        // 그러고 반대편 탐색
        // 둘다 nullptr이나오면 보닝ㄴ을 삭제
        if (root == nullptr) return;
        release(node->left);
        release(node->right);
        delete node;    
        //본인을 호출해서 하는것

    }
    ~Set()
    {
        release(root);
    }
};

int main()
{

  
}