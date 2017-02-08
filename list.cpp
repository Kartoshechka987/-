#include <iostream>

using namespace std;

typedef struct node
{
    int date;
    node* next;
};

typedef class list
{
    node* head;
public:
    list (int a)
    {
      head = new node;
      head->next = NULL;
    }
    ~list()
    {
        while (head != NULL)
        {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push_head (int a)
    {
        node* temp = new node;
        temp->next = head;
        temp->date = a;
        head = temp;
    }
    int size()
    {
        int a = 1;
        node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
            a++;
        }
        return a;
    }
    void push_back (int a)
    {
        node* temp = new node;
        if (head == NULL)
        {
            temp->next = head;
            temp->date = a;
            head = temp;
        }

        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        node* temp1 = new node;
        temp->next = temp1;
        temp1->date = a;
        temp1->next = NULL;
    }
};

int main()
{
int a,b,c,d;
cin >> a >> b >> c >> d;
list L(a);
L.push_back(b);
L.push_head(b);
cout << L.size() << endl;
    return 0;
}
