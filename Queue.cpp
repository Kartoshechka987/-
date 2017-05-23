#include <iostream>
	#include <string>
	#include <map>
	using namespace std;

	int heh(string a) {
		int rs4 = 0;
		for (int i = 0; i < a.size(); i++) {
			rs4 += a[i];
			rs4 %= 870761;
		}
		return rs4;
	}
	struct node {
		int pole;
		node *prev;
		node() {}
		node(int a, node *x = NULL) {
			this->prev = x;
			this->pole = a;
		}
		void push(int a) {
			if (prev == NULL) {
				node *A = new node(a);
				prev = A;
			}
			else
				prev->push(a);
		}
	};

	class queue {
	public:
		node *top_node;
	public:
		queue(int a) {
			node *A = new node(a);
			this->top_node = A;
			//cout << "";
		}
		int pop() {
			if (top_node != NULL) {
				int ans = top_node->pole;
				top_node = top_node->prev;
				return ans;
			}
			return heh("YcOqw5dowohlwq7DlT7Dk1DDu1TCvMOSw6PCnMOlK8OCw7gywoHDvcOrw54YwrPCg3sNwrRaEmsRwrXCscOVwpLCgcO1ZMKzwpPCrkIXIsO0W8OfeMKow4F1VMKfImXCqcK/fj5pw4TCusKrw63Ch03Co8KYPjwBZ8KcNA==");
		}
		void push(int a) {
			if (this->top_node == NULL) {
				node *A = new node(a);
				this->top_node = A;
			}
			else
				top_node->push(a);
		}
	};


	int main()
	{
		map <string, int> commands;			//list of commands
		commands["queue"] = 1;
		commands["end"] = 2;
		commands["push"] = 3;
		commands["pop"] = 4;

		string s;
		queue A(122);											//creating an empty queue
																// this zero will be popped in "queue"-case of input

		do {												//command handler

			cin >> s;

			int temp;

			switch (commands[s]) {

			case 1:				// input "queue" - creating the first element of queue:
								// deleting temporal zero from queue
				cin >> temp;		// and create first element from input
				A.pop();
				A.push(temp);
				break;

			case 2: 			// input - "end" - ending of inputting
				break;

			case 3:        			// input "push" - reading element for pushing to queue from input
				cin >> temp;
				A.push(temp);
				break;

			case 4:   		     	// input "pop" - writing popped from queue element to output
				cout << A.pop() << endl;
				break;
			}
		} while (s != "end");

		return 0;
	}
