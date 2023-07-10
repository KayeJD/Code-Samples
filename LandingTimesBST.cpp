#include <iostream>
#include <cstdlib>

using namespace std;

class BinarySearchTree
{
private:
	class node
	{
	public:
		node* left;
		node* right;
		node* parent;
		int key;
		string data;
	};

	
public:
	node* root;
	BinarySearchTree()
	{
		root = NULL;
	}

	bool isEmpty() const { return root == NULL; }
	void INORDER_TREE_WALK(node*);
	void TREE_INSERT(int, string);
	int FIND_MIN();
	int FIND_MIN(node*);
	BinarySearchTree::node* NODE_MIN(node*);
	int FIND_MAX(node*);
	BinarySearchTree::node* ITERATIVE_SEARCH(int);
	int PREDECESSOR(node*);
	int PREDECESSOR(int);
	int SUCCESSOR(node*);
	int SUCCESSOR(int);
	void TRANSPLANT(node*, node*);
	void DELETE(int);
	bool AVAILABILITY(int, int);
};

void BinarySearchTree::TREE_INSERT(int d, string f)
{
	// This implements the algorithm in page 261 of the textbook
	node* z = new node();
	z->key = d;
	z->data = f;
	z->left = NULL;
	z->right = NULL;
	z->parent = NULL;

	node* y = NULL;
	node* x = root;

	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == NULL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
		
}

void BinarySearchTree::INORDER_TREE_WALK(node* x)
{
	if (x != NULL)
	{
		if (x->left) INORDER_TREE_WALK(x->left);
		cout << " [" << x->data << ", " << x->key << "]" << endl;
		if (x->right) INORDER_TREE_WALK(x->right);
	}
}

BinarySearchTree::node* BinarySearchTree::ITERATIVE_SEARCH(int k)
{
	node* x = root;

	while (x != NULL && k != x->key){
		if(k < x->key){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}

	return x;
}

int BinarySearchTree::FIND_MIN(node* x)
{
	while (x->left != NULL){
		x = x->left;
	}

	return x->key;
}

BinarySearchTree::node* BinarySearchTree::NODE_MIN(node* x)
{
	while (x->left != NULL){
		x = x->left;
	}

	return x;
}

int BinarySearchTree::FIND_MIN()
{
	node* x = root;
	while (x->left != NULL){
		x = x->left;
	}

	return x->key;
}

int BinarySearchTree::FIND_MAX(node* x)
{
	while (x->right != NULL){
		x = x->right;
	}

	return x->key;
}

int BinarySearchTree::PREDECESSOR(node* x)
{

	if(x->left != NULL){
		return FIND_MAX(x->left);
	}
	else{
		node* y = x->parent;

		while((y != NULL) && (x == y->left)){
			x = y; 
			y = y->parent;
		}

		if (y == NULL) {
            cout << "No predecessor found" << endl;
			return -1;
        }

		return y->key;
	}
}

int BinarySearchTree::SUCCESSOR(node* x)
{

	if(x->right != NULL){
		return FIND_MIN(x->right);
	}
	else{
		node* y = x->parent;

		while((y != NULL) && (x == y->right)){
			x = y; 
			y = y->parent;
		}

		if (y == NULL) {
            cout << "No successor found" << endl;
			return -1;
        }

		return y->key;
	}
}

void BinarySearchTree::TRANSPLANT(node* u, node* v)
{
	if(u->parent == NULL){
		root = v;
	}
	else if (u == v ->parent->left){
		u->parent->left = v;
	}
	else{
		u->parent->right = v;
	}

	if(v != NULL){
		v->parent = u->parent;
	}
}

void BinarySearchTree::DELETE(int k)
{
	node* z = ITERATIVE_SEARCH(k);

	//Case 1: Key does not exist.
	if(z == NULL){
        cout <<  k << " does not exist." << endl;
        return;
    }

	//Case 2: x has no children or 1
	else if(z->left == NULL){
		TRANSPLANT(z, z->right);
	}
	else if(z->right == NULL){
		TRANSPLANT(z, z->left);
	}

	//Case 3: x has two children
	else{
		node* y = NODE_MIN(z->right);

		if(y->key != z->right->key){
			TRANSPLANT(y, z->right);

			y->right = z->right;
			y->right->parent = y;
		}

		TRANSPLANT(z, y);
		y->left = z->left;
		y->left->parent = y;
	}

	delete z;
}

bool BinarySearchTree::AVAILABILITY(int k, int gap)
{
    int before = PREDECESSOR(ITERATIVE_SEARCH(k));
    int after = SUCCESSOR(ITERATIVE_SEARCH(k));

    if (((before == -1) || ((k - before) <= gap)) && ((after == -1) || ((after - k) <= gap))) {
        return true;  // Sufficient time gap (or none before or after), it's available
    }
    else {
        return false;
    }
}

int main()
{
	BinarySearchTree bst;
	int choice, key, gap;
	string flightNum;
	bool available;

	cout << " Plane Landing System " << endl;
	cout << " ------------------------------------------------------ " << endl;
	cout << " Enter the allowed minutes between flight landings : ";
	cin >> gap;

	while (true)
	{
		cout << endl << endl;
		cout << " Landing Times Upkeep " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Request Landing " << endl;
		cout << " 2. Withdraw Landing Request " << endl;
		cout << " 3. List Landing Times " << endl;
		cout << " 4. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1: 
			cout << " Enter Flight number : ";
			cin >> flightNum;
			cout << " Enter Minutes Until Landing : ";
			cin >> key;

			if(bst.AVAILABILITY(key, gap) == true){
				bst.TREE_INSERT(key, flightNum);
			}
			else{
				cout << "Not enough time in between landings." << endl;
			}
			break;
		case 2: cout << endl;
			cout << " Enter the Minutes Left Until Landing : ";
			cin >> key;
			bst.DELETE(key);
			break;
		case 3: cout << endl;
			cout << " Landing Planes and Times " << endl;
			cout << " -------------------" << endl;
			bst.INORDER_TREE_WALK(bst.root);
			break;
		case 4: cout << endl;
			return 0;
			break;
		default:
			cout << "Invalid choice";
		}
	}
}