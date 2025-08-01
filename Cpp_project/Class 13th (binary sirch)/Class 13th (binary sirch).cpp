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
        Node* newNode = new Node(data);

        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;

        size++;

        return newNode;

    }
    void insert(T data)
    {
        if (root == nullptr)
        {
            root = create_node(data);
            return;
        }
        Node* currentNode = root;
        while (true)
        {
            if (data == currentNode->data)
                return; // 중복 삽입 방지
            if (data < currentNode->data)
            {
                if (currentNode->left == nullptr)
                {
                    currentNode->left = create_node(data);
                    return;
                }
                else
                {
                    currentNode = currentNode->left;
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
        //if (root == nullptr)
        //{
        //    root = create_node(data);
        //    return;
        //}
        //else
        //{
        //    Node* currentNode = root;
        //    //while (currentNode != nullptr)
        //    //{
        //    //    return;
        //    //}
        //    if (currentNode->data > data)
        //    {
        //        if (currentNode->left == nullptr)
        //        {
        //            currentNode->left = create_node(data);
        //        }
        //        else
        //        {
        //            currentNode = currentNode -> left;
        //        }
        //
        //    }
        //    else
        //    {
        //        if (currentNode->right == nullptr)
        //        {
        //            currentNode->right = create_node(data);
        //
        //            return;
        //        }
        //        else
        //        {
        //            currentNode = currentNode->right;
        //        }
        //    }
        //
        //}
    }
    void release(Node* root)
    {
        //재귀함수, 3줄정도면 끝남
        // nullptr이면 이전으로 돌아가게한다.
        // 그러고 반대편 탐색
        // 둘다 nullptr이나오면 보닝ㄴ을 삭제
        //if (root == nullptr) return;
        //release(root->left);
        //release(root->right);
        //delete root;    

        if (root != nullptr)
        {
            release(root->left);
            release(root->right);
            delete root;
        }
        //본인을 호출해서 하는것

    }

    void erase(T data)
    {
        //root는 currentNode로접근
        //currentNode가 없으면 없다고도 출력
        // parentNode를 만들어 currntNode의 값을 준다.
        // currentNode는 경우에 맞는 자식값을 준다.(left/right)
        // 반복
        // 지울값을 찾으면 parentNode의 자식을 nullptr로 만들고 currentNode삭제
        // 
        // 
        //
        if (root == nullptr) cout << "set is empty" << endl;
        else
        {

            Node* parentNode = nullptr;
            Node* currentNode = root;
            parentNode = currentNode;


            while (currentNode != nullptr && currentNode->data != data)
            {
                if (currentNode->data > data)
                {
                    currentNode = currentNode->left;
                }
                else
                {
                    currentNode = currentNode->right;
                }
            }
            if (currentNode == nullptr)
            {
                cout << "the data does not exist" << endl;
            }
            else if (currentNode->left == nullptr && currentNode->right == nullptr)
            {
                if (parentNode != nullptr)
                {
                    if (parentNode->left == currentNode)
                    {
                        parentNode->left = nullptr;
                    }
                    else
                    {
                        parentNode->right = nullptr;
                    }
                }
                else if (currentNode->left == nullptr || currentNode->right == nullptr)
                {
                    if (currentNode == root)
                    {
                        if (currentNode->left != nullptr)
                        {
                            root = currentNode->left;
                        }
                        else
                        {
                            root = currentNode->right;
                        }
                    }
                    else
                    {
                        if (currentNode->left != nullptr)
                        {
                            parentNode->left = currentNode->left;
                        }
                        else
                        {
                            parentNode->right = currentNode->right;
                        }
                    }
                }
                else
                {
                    Node* childNode = currentNode->right;
                    Node* traceNode = currentNode;

                    while (childNode->left != nullptr)
                    {
                        traceNode = childNode;
                        childNode = childNode->left;
                    }
                    currentNode->data = childNode->data;
                    traceNode->left = childNode->left;
                    delete childNode;
                    return;
                    //if (traceNode->left == childNode)
                    //{
                    //    traceNode->left = childNode->right;
                    //}
                    //else
                    //{
                    //    traceNode->right = childNode->right;
                    //}
                    //delete childNode;
                }
                cout << currentNode->data << "를삭제" << endl;
                delete currentNode;
            }
        }
    }

    void inorder()
    {
        inorder(root);
    }
    void inorder(Node* root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            cout << root->data << " " << endl;
            inorder(root->right);
        }
    }

    ~Set()
    {
        release(root);
    }

};

int main()
{
    Set<int> set;
    set.insert(3);
    set.insert(5);
    set.insert(8);
    set.insert(12);
    set.insert(13);
    set.insert(15);
    set.insert(17);
    set.insert(19);
    set.erase(13);
    set.erase(20);
    set.inorder();

}