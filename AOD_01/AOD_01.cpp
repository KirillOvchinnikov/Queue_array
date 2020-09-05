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
        last = -1;
        count = 0;
    }

    void Add(string num)
    {
        if (last == max - 1)
        {
            cout << "Очередь заполнена, начало заполнения новой очереди";
            last = -1;
            count = 0;
        }
        data[++last] = num;
        count++;
      //  cout << "COUNT: " << count;
    }

    void Delete()
    {
        if (count == 0)
        {
            cout << "Очередь пуста";
            return;
        }
        else
        {
            string temp = data[first++];
            if (first == max)
                first = 0;
            count--;
           // cout << "COUNT: " << count;
            cout << "Удален элемент: " << temp;
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
        //    return true;
        }
        else
        {
            cout << "Очередь не пуста\n";
         //  return false;
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
    int N, dig;
    string name;
    cout << "Введите размер очереди: ";
    cin >> N;
    Queue q(N);

    cout << "\nВыберите действие:\n1) Добавить элемент в очередь\n2) Удалить элемент из очереди\n3) Посмотреть первый элемент очереди\n4) Проверить, пуста ли очередь\n5) Проверить, полна ли очередь\n";

    do
    {
        cin >> dig;
        if (dig)
        {
            switch (dig)
            {
            case 1:
                cin >> name;
                q.Add(name);
                break;
            case 2:
                q.Delete();
                break;
            case 3:
              cout <<"Первый элемент: " << q.GetFirst();
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
    while (dig);
    return 0;
}