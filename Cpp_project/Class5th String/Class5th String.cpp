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
        size = strlen(word) + 1;
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

            for (int i = 0; i < size; i++)
            {
                container[i] = word[i];
            }
            delete[] pointer;
            pointer = container;
        }
    }
    int getSize() const
    {
        return size - 1;  // null 문자 제외
    }


    char operator[](int index) const//이게 있어야지 카운트를 배열화시키는 게 가능하다.
    {
        return pointer[index];
    }
    const char& operator [] (const int& index)
    {
        return pointer[index];
    }

    void append(const char* word)
    {
        int previouseSize = size;
        size = size + strlen(word) + 1;
        char* container = new char[size];
        for (int i = 0; i < previouseSize; i++)
        {
            container[i] = pointer[i];
        }
        for (int i = 0; i < strlen(word) + 1; i++)
        {
            container[previouseSize + i] = word[i];
        }

        delete[] pointer;
        pointer = container;
    }
    const int& length()
    {
        return size - 1;
    }

    unsigned long long find(const char* word)
    {
        int length = size - strlen(word);

        int i = 0;
        int j = 0;

        for (int i = 0; i < length; i++)
        {
            if (pointer[i] != word[i])
            {
                break;
            }
            if (j == strlen(word))
            {
                return 1;
            }
        }
        return  18446744073709551615;
    }

    ~String()
    {
        delete[] pointer;
    }

};
int main()
{
    String message;
    message = "Adidas";

    //String adidas;
    //cout <<message.size()<<endl;adidas = "adidas";
    //for (int i = 0; i < message.getSize(); i++)
    //{
    //    cout << message[i] ;
    //}
    //cout << endl;

    //for (int i = 0; i < message.length(); i++)
    //{
    //    cout << message[i];
    //}

    message.append(" Shose");
    for (int i = 0; i < message.length(); i++)
    {
        cout << message[i];
    }
    cout << endl;
    cout << message.find("Dark") << endl;

    return 0;
}

