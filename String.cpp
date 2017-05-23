#include <iostream>
using namespace std;

 class string {
  int size;
  char* mas[100];
public:
  string();
  ~string();
  void concat(string s);
  int find(string s);
  void get(int i);
  void set(int i);
};


string::string( int a )
{
  size = a;
  mas = new char[size];
  for (int i = 0; i < size; i++)
    cin >> a;
}
string::~string()
{
  for (int i = 0; i < size; i++)
    delete mas[i];
  delete mas;
}

void string::concat( string s )//приписывает к данной строке строку s
{
  for (int i = size; i < size + s.size; i++)
    mas[i] = s.mas[i - size];
  size += s.size;
}

int string::find( string s )//ищет вхождение подстроки s в нашей строке
{

}

void string::set( int i )
{
  cin >> mas[i];
}
void string::get( int i )
{
  cout << mas[i] << endl;
}

void string::print()
{
  for (int i = 0; i < size; i++)
    cout << mas[i];
}


int main()
{

    return 0;
}
