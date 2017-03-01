#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int data;
    node* left = NULL;
    node* right = NULL;
    int bal;
};

class bin_tree
{
    node* root;

public:
    bin_tree(int a)
    {
     root = new node;
     root -> data = a;
     root -> left = NULL;
     root -> right = NULL;
     root -> bal = 0;
    }

    node* get()
    {
        return root;
    }

    int get_bal(node* n)
    {
        return n -> bal;
    }

    void push(int a, node* n)
    {
        if(n == NULL)
        {
            node* tmp = new node;
            tmp -> data = a;
            tmp -> left = NULL;
            tmp -> right = NULL;
            tmp -> bal = 0;
            n = tmp;
            return;
        }

        if(n -> left == NULL)
        {
            node* tmp = new node;
            tmp -> data = a;
            tmp -> left = NULL;
            tmp -> right = NULL;
            tmp -> bal = 0;
            n -> left = tmp;
            n -> bal++;
            return;
        }

        if(n -> right == NULL)
        {
            node* tmp = new node;
            tmp -> data = a;
            tmp -> left = NULL;
            tmp -> right = NULL;
            tmp -> bal = 0;
            n -> right = tmp;
            n -> bal--;
            return;
        }

        if(n -> right -> right != NULL)
        {
            push(a, n -> left);
            n -> bal++;
        }
        else
        {
            push(a, n -> right);
            n -> bal--;
        }
        return;
    }

   bool DFS(int data, node* n)
   {
       if (n == NULL)
        return false;

       if (n -> data == data)
        return true;

       if (DFS(data, n -> left) == true)
        return true;

       if (DFS(data, n -> right) == true)
        return true;

    return false;
   }

   bool BFS(int data)
   {
       queue <node*> A;
       A.push(root);
       while(!A.isempty())
       {
           node* tmp = A.pop();

           if (tmp -> data == data)
            return tmp;

           if (tmp -> left != NULL)
            A.push(tmp -> left);

           if (tmp -> right != NULL)
            A.push(tmp -> right);
       }
       return false;
   }

   void delTree(node* n);
    if(n == NULL)
    return;

   delTree(n -> left);
   delTree(n -> right);
   delete n;
};

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >>d;
    bin_tree obj1(a);
    obj1.push(b, obj1.get());
    obj1.push(c, obj1.get());
    obj1.push(d, obj1.get());
    cout << obj1.DFS(d, obj1.get()) << endl;
    cout << obj1.BFS(c) << endl;
    return 0;
}
