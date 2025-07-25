#include <iostream>
#define SIZE 6
using namespace std;
template<typename KEY, typename VALUE>

class HashTable
{
private:
    struct Node
    {
        KEY key;
        VALUE value;
        Node* next;//자식(Node)의주소
    };
    struct Bucket//필요한거 갯수count/시작head/ 버켓이 만들어졌으니 생성자 초기화
    {
        int count;
        Node* head;//헤드(Bucket)의 주소
    };
    Bucket bucket[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            bucket[i].count = 0;
            bucket[i].head = nullptr;
        }
    }
    template<typename T>
    const int& hash_function(T key)
    {
        unsigned int hash_index = (unsigned int)key % SIZE;
        //양수만 나오게하기 : if(key <= 0)을 사용한다?
        //SIZE이상의 갯수를 저장못하게 : if(count >= 6)을 사용한다?
        return hash_index;
    }
    Node* create_node(KEY key, VALUE value)
    {
        //노드를 생성합니다.(동적으로 생성)
        //newnode를 만들었으면 접근해서 key와 value값을 넣어준다.
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;
        return newNode;
    }
    void insert(KEY key, VALUE value)
    {
        //1. 해쉬함수를 통해 값을 받는 임시변수
        int hashindex = hash_function(key);
        //2 새로운 노드를 생성합니다.
        Node* newNode = create_node(key, value);
        //과정 : 값을 받고 원래 헤드를 next로 만든다.
        //본인이 헤드가 된다. front개념과 유사
        if (bucket[hashindex].count == 0)
        {
            bucket[hashindex].head = newNode;
        }
        else
        {
            newNode->next = bucket[hashindex].head;
            bucket[hashindex].head = newNode;
        }
        //bucket[hashindex]의 count가 증가합니다.
        bucket[hashindex].count++;
    }
    ~HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node* deleteNode = bucket[i].head;// i번째 버컷의 헤드를 말함
            Node* nextNode = bucket[i].head;// i번째 버컷의 헤드를 말함
            if (bucket != nullptr)
            {
                nextNode = deleteNode;
                delete deleteNode;
                deleteNode = nextNode;
            }
            //Node* current = bucket[i].head;// i번째 버컷의 헤드를 말함
            //while (current != nullptr)//버켓이 비어있지 않다면 작동
            //{
            //    // i번째 버킷의 헤드를 current란 값에 임시저장
            //    Node* deleteNode = current;
            //    cout << deleteNode->key << endl;
            //    //current값에 저장한 주소를 타고 자식을 current(헤드)로 만듬
            //    current = current->next;
            //
            //    // i번째 bucket의 헤더"였던"애를 삭제
            //    delete deleteNode;
            //}
            //없어질 애는 굳이 초기화 안시켜도 됨
        }

    }
    void erase(KEY key)
    {
        //함수로 인덱스를 찾기

        //1.해쉬 함수를 통해서 값을 받는 임시 변수
        int hashIndex = hash_function(key);  //hashfunction()의 값
        //2.Node를 탐색할 수 있는 포인터 변수 선언
        Node* currentNode = bucket[hashIndex].head;
        //3. 이전 Node를 지정할 수 있는 포인터 변수 선언
        Node* previousNode = nullptr;
        //4. currentNode가 nullptr과 같다면 함수를 종료
        if (currentNode == nullptr)
        {
            cout << "not key found" << endl;
            return;
        }
        else
        {
            //5. currentNode를 이용해서 내가 찾고자 하는 key값 찾기
            while (currentNode != nullptr)
            {
                if (currentNode->key == key)
                {
                    if (currentNode == bucket[hashIndex].head)
                    {
                        bucket[hashIndex].head = currentNode->next;
                    }
                    else
                    {
                        previousNode->next = currentNode->next;
                    }
                    delete currentNode;
                    return;
                }
                else
                {
                    previousNode = currentNode;
                    currentNode = currentNode->next;
                }
            }
            cout << "not key found" << endl;
        }

        //10-20-30이 있다. 20을지운다면 10을 30이랑 연결시코기 20을 지워야한다.
        // 헤드를 지울때는 bucket[0]을 다음 장소로
        //버킷의 연결리스트를 순회
        //int hashIndex = hash_function(key);  //hashfunction()의 값
        //Node* current = bucket[hashIndex].head;
        //Node* previous = nullptr;
        //for (int i = 0; i < SIZE; i++)
        //{
        //    if (previous == nullptr)//젤 앞에거 지우기 (노드찾기)
        //    {
        //        //1번을 0번으로
        //        bucket[hashIndex].head = current->next;
        //        //내가 삭제하려는 곳의 주소를 current(삭제할곳)의 다음주소 로 만든다
        //    }
        //    else//굳이 if쓴다면 prev != nullstr
        //    {
        //        previous->next = current->next;
        //        // 이전노드의 다음= 내가 삭제할것의 다음
        //        // A-B-C가 있다면 A다음이 C가 되며 연결리스트는 A-C가 된다.
        //        // 햇갈렸던것! prvious는 nullptr이라고 했는데 nullptr->next가 존재할 수 있는가?
        //        // 빡통아 if문에서 nullptr아니랬잖아
        //        // 그러니 else에서의 previous->next는 current가 된다.
        //    }
        //    delete current;
        //    return;
        //}
    }

};
int main()
{
    HashTable<const char*, int> hashTable;
    hashTable.insert("1번", 1);
    hashTable.insert("2번", 2);
    hashTable.insert("3번", 3);
    hashTable.erase("3번");
    hashTable.erase("3번");

}
