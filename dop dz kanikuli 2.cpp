#include <iostream>
#include <string>
using namespace std;

struct person
{
    string name;
    float time;
    person* next;
    person* last;
    person( string name, float time )
    {
      this->name = name;
      this->time = time;
      next = NULL;
      last = NULL;
    };
};

class queve
{
private:
    person* head;
    person* find_( string n , person* p )
    {
       if (p == NULL)
         return NULL;
       if (p->name == n)
         return p;
       return (find_(n, p->next));
    };

    void del( person* n )
    {
        if (n->last == NULL)
        {
            n->next->last=NULL;
            head = n->next;
            delete n;
        }
        if (n->next == NULL)
        {
            n->last->next = 0;
            delete n;
        }
       n->last->next = n->next;
       n->next->last = n->last;
       delete n;
    };

    person* last( person* p )
    {
       if (p == NULL)
         return NULL;
       if (p->next)
         return (p->next);
       return p;
    };

public:

    void push( string name, float time )
    {
      person* n = last (head);
      if (n)
          n->next = new person (name, time);
      n->next->last = n;
    };

    void exit( string name )
    {
      del(find_(name , head ));
    };

    person* get()
    {
       person* n = head;
       head->next->last = NULL;
       head = head->next;
       return n;
    };

    ~queve()
    {
      while (head)
        del(head);
    };
};

int main()
{
    queve Q;
    Q.push("I.Ivanov", 11.10);
    Q.push("A.Popova", 12.45);
    Q.push("P.Ribakov", 17.15);
    Q.push("D.Larin", 19.00);
    Q.exit("P.Ribakov");
    for (;;)
    {
      person* p = Q.get();
      if (p) break;
      cout<<p->name<<' '<<p->time<<endl;
    };
    return 0;
}
