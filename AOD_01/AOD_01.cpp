#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
    string* data;
    int max;
    int first;
    int last;
    int count;
public:
    Queue(int max)
    {
        this->max = max;
        data = new string[this->max];
        first = 0;
        last = 0;
        count = 0;
    }

    void Add(string num)
    {
        if (count == max)
        {
            cout << "Очередь заполнена, начало заполнения новой очереди\n";
            last = 0;
            count = 0;
        }
        data[last] = num;
        count++;
        cout << "Добавлен элемент: " << num << endl;
    }

    void Delete()
    {
        if (count == 0)
        {
            cout << "Очередь пуста\n";
            return;
        }
        else
        {
            string temp = data[first++];
            if (first == max)
                first = 0;
            count--;
            cout << "Удален элемент: " << temp << endl;
        }
    }

    string GetFirst()
    {
        return data[first];
    }

    void IsEmpty()
    {
        if (count == 0)
        {
            cout << "Очередь пуста\n";
        }
        else
        {
            cout << "Очередь не пуста\n";
        }
    }

    void IsFull()
    {
        if (count == max)
            cout << "Очередь полна\n";
        else
            cout << "Очередь не полна\n";
    }
};

int main()
{
    setlocale(0, "");
    int N, digit;
    string name;
    cout << "Введите размер очереди: ";
    cin >> N;
    Queue q(N);

    cout << "\nВыберите действие:\n1) Добавить элемент в очередь\n2) Удалить элемент из очереди\n3) Посмотреть первый элемент очереди\n4) Проверить, пуста ли очередь\n5) Проверить, полна ли очередь\n";

    do
    {
        cin >> digit;
        if (digit)
        {
            switch (digit)
            {
            case 1:
                cin >> name;
                q.Add(name);
                break;
            case 2:
                q.Delete();
                break;
            case 3:
              cout <<"Первый элемент: " << q.GetFirst() << endl;
              break;
            case 4:
                q.IsEmpty();
                break;
            case 5:
                q.IsFull();
                break;
            default:
                cout << "Нельзя!";
            }
        }
        cout << endl;
    }
    while (digit);
    return 0;
}