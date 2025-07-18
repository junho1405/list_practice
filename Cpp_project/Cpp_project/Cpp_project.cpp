#include <iostream>
#include<string>
using namespace std;
class String
{
private:
    char* pointer;
    int size;
public:
    String()
    {
        size = 0;
        pointer = nullptr;
    }
    void operator = (const char* word)
    {
        size = strlen(word)+1;
        if (pointer == nullptr)
        {
            pointer = new char[size];
            for (int i = 0; i < size; i++)
            {
                pointer[i] = word[i];
            }
        }
        else
        {
            char* container = new char[size];

            for (int i =0;i<size;i++)
            { 
                container[i] = word[i];
            }
            delete[] pointer;
            pointer = container;
        }
    }
    int getSize() const {
        return size - 1;  // null 문자 제외
    }
    

    char operator[]( int index) const//이게 있어야지 카운트를 배열화시키는 게 가능하다.
    {
        return pointer[index];
    }

    ~String()
    {
        delete[] pointer;
    }
};
int main()
{
    String message;
    message = "League of Legend";
    //String adidas;
    //cout <<message.size()<<endl;adidas = "adidas";
    for (int i = 0; i < message.getSize(); i++)
    {
        cout << message[i] ;
    }
    return 0;
}