#include <iostream>
	using namespace std;
	struct Tree {

	    int k;

	    Tree* l;

	    Tree* r;

	    int hight;

	    Tree ( int k): k(k) {

	        this-> l = NULL;

	        this-> r = NULL;

	        this-> hight = NULL; };
	};

	class bstree {

	private:

	    Tree* root;

	public:

	    unsigned char height(Tree* k) {

	        return k?k->hight:0;  }

	    int bfactor ( Tree* k )  {

	        return height( k->r ) - height( k->l );   }

	    void fixheight(Tree* t) {

	        unsigned char hl = height(t->l);

	        unsigned char hr = height(t->r);

	        t->hight = (hl>hr?hl:hr)+1;  }

	    Tree* rotateright (Tree* k) {

	        Tree* z = k->l;

	        k->l = z->r;

	        z->r = k;

	        fixheight(k);

	        fixheight(z);

	        return z;    }

	    Tree* rotateleft (Tree* k)    {

	        Tree* z = k->l;

	        k->r = z->l;

	        z->l = k;

	        fixheight(k);

	        fixheight(z);

	        return z;    }

	    Tree* add(Tree* t, int m)     {

	        if( !t ) return new Tree (m);

	        if( m<t->k )

	            t->l = add(t->l,m);

	        else

	            t->r = add(t->r,m);

	        return balance(t) ;   }

	    Tree* find1 (int m, Tree* a)  {

	      if ( m > a->t )

	        a->r?find1 ( m, a->r ): a = NULL;

	      if ( m < a->k )

	        a->l?find1 ( m, a->l ): a = NULL;

	      return a;    }

	    Tree* balance(Tree* t)    {

	        fixheight(t);

	        if( bfactor(t)==2 )   {

	            if( bfactor(t->r) < 0 )

	                t->r = rotateright(t->r);

	            return rotateleft(t);     }

	        if( bfactor(t)==-2 )      {

	            if( bfactor(t->l) > 0  )

				t->l = rotateleft(t->l);

	            return rotateright(t);        }

	        return t;     }

	    void dell (Tree* a) {

	        if (a->l)

	            dell ( a->l );

	        if (a->r)

	            dell (a->r);

	        delete a;    }

	    ~bstree (){

	    dell ( root );    }

	};

	int main()

	{ }
