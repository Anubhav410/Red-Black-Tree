#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE
#include <iostream>
using namespace std;
#define BLACK 1
#define RED 2


template<typename K>
class Tree
{
	private:
	class Node
	{
	public:
	
			Node(K k = K()) : key(k) , left(0) , right(NULL) {}  //default and Parametrised ctor
			Node *left;
			Node *right;
			Node *parent;
			int color;// = "red"; 
			K key;
	};


	Node* grandparent(Node *n)
	{
		 if ((n != NULL) && (n->parent != NULL))
		  return n->parent->parent;
		 else
		 {
		  cout<< "Null Encountered in grandparent";
		  return NULL;
		 }
	}
	 
	Node* uncle(Node *n)
	{
		 Node* g = grandparent(n);
		 if (g == NULL){
			cout<< "Null Encountered in uncle";
		  return NULL; // No grandparent means no uncle
		 }
		 if (n->parent == g->left)
		  return g->right;
		 else
		  return g->left;
	}


		void addNode1(Node**,Node*,K);
		void display1(Node* head);
		void insert_case1( Node ** n);
		void insert_case2(Node ** n);
		void insert_case3(Node ** n);
		void insert_case4(Node ** n);
		void insert_case5(Node ** n);
		void rotate_right(Node ** n);
		void rotate_left (Node ** n);

		Tree<K>(Tree<K>& rhs){}					//made private copy ctor
//		operator=(Tree<K>& lhs){}	//made private equality operator
		bool search1(K key, Node*);
	Node *head;
			Node *prev; 
	public:
		~Tree()
		{
			emptyTree(head);
			cout<<"Removed Everything";
		}
		void emptyTree(Node* head)
		{
			if(head != NULL)
			{
			emptyTree(head->left);
			emptyTree(head->right);
			delete head;
			}
		}

	
	class Iterator
	{
		public:
		bool visited(Node* node)
		{
			int i = 0;
			while(i < visitNo)
			{
				if(node == visitedArray[i])
				{
//								cout<<"lol\n";
					return true;
				}
				i++;
//			cout<<"lolq\n";
			}
//						cout<<"p\n";
			return false;
		}	
		void visit(Node* node)
		{
			if(!visited(node))
			{
//							cout<<"here89\n";
				visitedArray[visitNo++] = node;
			}
		}
		explicit Iterator(Node* p_it = 0 , Node* prev = 0) : p_it_(p_it), previous(prev),visitNo(0)  { visit(p_it_); }
		int operator*() const
		{
			return p_it_->key;
		}
		bool operator==(const Iterator& rhs) const
		{
			return p_it_->key == rhs.p_it_->key;
//			return p_it_ == rhs.p_it_;
		}
		bool operator!=(const Iterator& rhs) const
		{
		//	return p_it_ != rhs.p_it_;
			return !(*this == rhs);
		}
		
		Iterator& operator++() // pre
		{
//			cout<<"start.."<<p_it_->key<<"\n"<<"Visited...."<<visited(p_it_)<<"\n"<<"visted..."<<visited(p_it_->right)<<"\n";
			return lol();
		}

		
		Iterator& lol()
		{
//			Node* lp_it_ = *hlp
			if(!visited(p_it_))
			{
				if(p_it_->left != NULL)
				{
						if(!visited(p_it_->left))
						{
							p_it_ = p_it_->left;
							lol();
						}
						else
						{
							visit(p_it_);
							return *this;
						}
				}
				else
				{
					visit(p_it_);
					return *this;
				}
			}
			else
			{
//				cout<<"inelse\n";
				if(p_it_->right != NULL)
				{
					p_it_ = p_it_->right;
					return 	lol();
				}
				else
				{
					while(p_it_->parent != NULL && visited(p_it_->parent))
					{
						p_it_ = p_it_->parent;
					}
						if(p_it_->parent == NULL)
						{
//							cout<<"shit\n";
							visit(p_it_);
							return *this;
						}
						else
						{
//							cout<<"shit1\n";
							p_it_ = p_it_->parent;
							visit(p_it_);
							return *this;
						}
				}
			}
		}

		Iterator operator++(int) // post
		{
			Iterator temp(*this);
			++*this;
			return temp;

		}
Iterator& operator--() // pre
		{
//			cout<<"start.."<<p_it_->key<<"\n"<<"Visited...."<<visited(p_it_)<<"\n"<<"visted..."<<visited(p_it_->right)<<"\n";
			return lol1();
		}

		
		Iterator& lol1()
		{
//			Node* lp_it_ = *hlp
			if(!visited(p_it_))
			{
				if(p_it_->right != NULL)
				{
						if(!visited(p_it_->right))
						{
							p_it_ = p_it_->right;
							lol1();
						}
						else
						{
							visit(p_it_);
							return *this;
						}
				}
				else
				{
					visit(p_it_);
					return *this;
				}
			}
			else
			{
//				cout<<"inelse\n";
				if(p_it_->left != NULL)
				{
					p_it_ = p_it_->left;
					return 	lol1();
				}
				else
				{
					while(p_it_->parent != NULL && visited(p_it_->parent))
					{
						p_it_ = p_it_->parent;
					}
						if(p_it_->parent == NULL)
						{
//							cout<<"shit\n";
							visit(p_it_);
							return *this;
						}
						else
						{
//							cout<<"shit1\n";
							p_it_ = p_it_->parent;
							visit(p_it_);
							return *this;
						}
				}
			}
		}
		Iterator operator--(int) // post
		{
			Iterator temp(*this);
			--*this;
			return temp;

		}

		private:
		Node *p_it_;
		Node *previous;		
		Node* visitedArray[500];		//an array of visited nodes
		int visitNo;				//just indexing into the above array

	};
	Iterator begin()
	{
		Node* temp = head;
		Node* prev = NULL;
		while(temp->left != NULL)
		{
			prev = temp;
			temp = temp->left;
		}
		return Iterator(temp,prev);
	}
	Iterator end()
	{
		Node* temp = head;
		Node* prev;
		while(temp->right != NULL)
		{
			prev = temp;
			temp = temp->right;
		}

		//temp = temp->right;

		return Iterator(temp,prev);
	}

		 
			bool search(K key)
			{
				return search1(key, head);
			}
			void addNode(K key) //acts as a wrapper
			{
			//	cout<<"Here\n";
				addNode1(&head,NULL,key);
			}
	
			void removeNode(Tree);
			void display()	//acts as a wrapper
			{
				display1(head);
			}
			Tree<K>() //default constructor
			{
				head = NULL; 
			//	cout<<"Ctor";
			}
};


template<typename K>
bool Tree<K>::search1(K key, Node* head)
{
	
	if(head != NULL)
	{
		if( head->key == key)
		{
			return true;
		}
		else if (head->key > key)
		{
			search1(key, head->left);
		}
		else
		{
			search1(key, head->right);
		}
	}
	else
		return false;
}
template<typename K>
void Tree<K>::display1(Node* head)
{
	//	cout<<"displaying.......\n";
	if(head != NULL)
	{
	//	cout<<"hello\n";
	
		display1(head->left);
		cout<<head->key<<"\t"<<head->color<<"\tHead Parent\t"<<head->parent<<"\n";
		display1(head->right);
	}
	//cout<<"\n";
}



template<typename K>
void Tree<K>::addNode1(Node** head_ptr,Node* prev,K key)
{
	Node* head = *head_ptr; 
	if(head ==  NULL)
	{
		//cout<<"Hello\n";
		head = new Node(key);
		head->left = NULL;
		head->right = NULL;
		head->parent = prev;
		head->color = RED;
	
		*head_ptr = head;
		insert_case1(&head);
	//	insert_case1(&head);
		//cout<<"haha..."<<head->key<<"\n";
	}
	else

	{
		//cout<<"Helloelse\n";
		if(head->key > key)
		{
			addNode1(&head->left,head,key);
		}
		else if(head->key < key)
		{
			addNode1(&head->right,head,key);
		}
		else
		{
				cout<<"Trying to insert Duplicate Node\n";
		}
	}
	
	
}

template<typename K>
void Tree<K>::insert_case1( Node ** n)
{
	cout<<"i1\nThe node that came here is: "<<*n<<endl;
	 if ((*n)->parent == NULL)
	 {	
			cout<<"current color: " <<(*n)->color;
		  (*n)->color = BLACK;
		  cout<<"color now: " <<(*n)->color<<endl;
	 }
	 else 
		  Tree<K>::insert_case2(n);
}

template<typename K>
void Tree<K>::insert_case2(Node ** n)
{
	cout<<"i2\nThe node that came here is: "<<*n<<endl;
 if ((*n)->parent->color == BLACK)
 {

  return; /* Tree is still valid */
 
 }
 else 
  Tree<K>::insert_case3(n);
}

template<typename K>
void Tree<K>::insert_case3(Node ** n)
{
	cout<<"i3\nThe node that came here is: "<<*n<<endl;
 Node *u = uncle(*n), *g;
 
 if ((u != NULL) && (u->color == RED)) {
  (*n)->parent->color = BLACK;
  u->color = BLACK;
  g = grandparent(*n);
  g->color = RED;
  Tree<K>::insert_case1(&g);
 } else {
Tree<K>::insert_case4(n);
 }
}

template<typename K>
void Tree<K>:: insert_case4(Node **n)
{
	cout<<"i4\nThe node that came here is: "<<*n<<endl;
 Node *g = grandparent(*n);
 
 if (((*n) == (*n)->parent->right) && ((*n)->parent == g->left)) {
	rotate_left(&((*n)->parent));	//arpan uncomment this, remove the semicolon and implet this part
	
	
	
	*n = (*n)->left;
 } 
 else if (((*n) == (*n)->parent->left) && ((*n)->parent == g->right)) 
 {
	rotate_right(&((*n)->parent));	//arpan uncomment this, remove the semicolon and implet this part

	(*n) = (*n)->right;
 }
 Tree<K>::insert_case5(n);
}

template<typename K>
void Tree<K>::insert_case5(Node ** n)
{
	cout<<"i5\nThe node that came here is: "<<*n<<endl;
 Node *g = grandparent(*n);
 
 (*n)->parent->color = BLACK;
 g->color = RED;
 if ((*n) == (*n)->parent->left)
	rotate_right(&g);		//arpan uncomment this, remove the semicolon and implet this part
 else
	rotate_left(&g);		//arpan uncomment this, remove the semicolon and implet this part
}

template<typename K>
void Tree<K>::rotate_right(Node ** g)
{
	
	Node* myn = (*g)->left;
	Node* myp = (*g);
	Node* myg = (*g)->parent;
	Node* myn_r = myn->right;
	cout<<"rotate-rigt\nThe node that came here is: "<<(*g)->key<<endl;
	Node* p = (*g)->left;// we will need to change the parent of g->right, g-> left, g->left->right 
	(*g)->left = p-> right;
	p->right = (*g);
	*g = p;
	cout<<"the value of myn_r........"<<myn_r<<"\n";	
	myn->parent = myg;
	myp->parent = myn;
	if(myn_r!=NULL)
	{
		myn_r->parent = myp;
	}
	myg->left = myn;
}

template<typename K>
void Tree<K>::rotate_left(Node** p)
{
	Node* myn = (*p)->right;
	Node* myp = *p;
	Node* myg = (*p)->parent;
	Node* myn_l = myn->left;
		cout<<"rotate-left\nThe node that came here is: "<<*p<<endl;
	//will need to change the parent of p->right, p->
	Node * n = (*p)->right; //node n  // right points to n
	(*p)->right = n->left; //....... p's right is not lost as it's already n; n's left becomes p's right;
	n->left = *p; // n's left is not lost now as it has already been assigned 
	*p = n;

	cout<<"the value of myl_l........"<<myn_l<<"\n";
	myp->parent = myn;
	myn->parent = myg;
	if(myn_l != NULL)
	{
		myn_l->parent = myp;
	}
	myg->right = myn;


}
#endif