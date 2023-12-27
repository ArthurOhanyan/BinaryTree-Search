#include <iostream>
#include <vector>

template <typename T>
class BinaryTree 
{
public:
	class Node 
	{
		public:
			T m_val;
			Node* m_left;
			Node* m_right;
			Node();
			Node(const T&);
			
	};

	BinaryTree();
	~BinaryTree();
	Node* insert_helper(Node*,const T&);
	void insert(const T&);
	void remove (const T&);
	Node* del_node(Node*,const T&);
	Node* find_node(Node*);
	Node* search_helper(Node*, const T&);
	bool search (const T&);
	void find_min();
	Node* find_min_helper(Node*);
	void find_max();
	Node* find_max_helper(Node*);
	void successor(const T&);
	Node* successor_helper(Node*,Node*,const T&);
	void predecessor(const T&);
	Node* predecessor_helper(Node*,Node*,const T&);
	int height ();
	void height_helper(Node*,int,int&);
	bool isValid();
	bool isValid_helper(Node*);
	int size();
	void size_helper(Node*,int&);	
	void inOrder();
	void inOrder_helper(Node*);
	void preOrder();
	void preOrder_helper(Node*);
	void postOrder();
	void postOrder_helper(Node*);
	void level_order_print();
	bool contains(const T&);
	void clear();
	void clear_helper(Node*&);
	std::vector<T> seriallized();
	void seriallized_helper(Node*,std::vector<T>&);
	void range_query(const T&,const T&);
	void range_query_helper(Node*,const T&,const T&);
	void copy();
	Node* copy_helper(Node*, const T&);
	void k_smallest(T);
	Node* k_smallest_helper(Node*, T&);
	void k_bigest(T);
	Node* k_bigest_helper(Node*,T&);
	void update(const T&, const T&);
	Node* update_helper(Node*, const T&, const T&);
private:
	Node* root;
			
};

#include "implementation.hpp"
