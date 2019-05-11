#include<iostream> // input and output streams
#include <string>
template <typename dtype>
class node {
public:
	// data container, contains data of type dtype which is to be specified
	dtype data; // read write access, can be directly set and get
	
	// the adjacent node
	node<dtype> *next; // read write access, can be directly set and get
	
	// construct and set next node, default is null
	node(node<dtype> *n=0) {
		this->next = n;
	}
	
	// construct with data 
	node(dtype d) {
		this->data = d;
	}
			
	// construct and set both data and next node
	node(dtype d, node<dtype> *n) {
		this->data = d;
		this->next = n;
	}
	
	// traverse the list n steps
	node* traverse(unsigned int n=1) {
		node<dtype>* nth_node = this;
		for (unsigned int i=0; i<n; i++) {
			nth_node = nth_node->next;
		}
		return nth_node;
	}
	
	// operator overload for cout << node
	friend std::ostream& operator << (std::ostream &os, const node<dtype> *n) {
		using namespace std;
		os << "[ " ;
		while (n != 0) {
			os << *n << " ";
			n = n->next;
		}
		os << "]";
		return os;
	}
	
	friend std::ostream& operator << (std::ostream &os, const node<dtype> &n) {
		os << n.data;
		return os;
	}
};

namespace options {
	int traversal_length;
};

int main(int argc, char *argv[]) {
	using namespace std;
	cout << "running program: " << argv[0] << endl;
	options::traversal_length = (argc > 0) ? stoi(argv[1]) : 0;
	
	node<char> *m = new node<char>('c', 0);
	node<char> *o = new node<char>('e', m);
	node<char> *p = new node<char>('s', o);
	//cout << n->data << " " << n->next << endl;
	cout << "m = " << m << endl;
	cout << "o = " << o << endl;
	cout << "p = " << p << endl;
	
	node<char> *next = p->traverse(options::traversal_length);
	cout << "next = " << *next << endl;
    return 0;
}
