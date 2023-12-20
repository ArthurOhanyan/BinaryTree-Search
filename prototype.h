#include <iostream>

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
	void print();

private:
	Node* root;
			
};

#include "implementation.hpp"
