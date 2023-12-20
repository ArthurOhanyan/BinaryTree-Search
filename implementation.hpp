#include <iostream>
#include <queue>

template <typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	delete root;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::insert_helper(Node* root,const T& val)
{
	if (root == nullptr){
		
		root = new Node (val);
		return root;
	}

	if (val > root -> m_val){
		
		root -> m_right = insert_helper (root -> m_right,val);

	} else if (val < root -> m_val){
		
		root -> m_left = insert_helper (root -> m_left,val);
	}

	return root;
}

template <typename T>
void BinaryTree<T>::insert(const T& val)
{	
	root = insert_helper(root,val);
	return;
}
	

template <typename T>
void BinaryTree<T>::print()
{
	if (!root){
		
		return;
	}
	
	std::queue<Node*> qu;
	qu.push(root);
	std::cout << " " << root -> m_val << std::endl;
	
	while(!qu.empty()){
		
		Node* tmp = qu.front();
		
		if (tmp -> m_left){
			
			qu.push(tmp -> m_left);
			std::cout << " " << tmp -> m_left -> m_val;
		}

		if (tmp -> m_right){
			
			qu.push(tmp -> m_right);
			std::cout << " " << tmp -> m_right -> m_val;
		}

		//std::cout << " " << qu.front() -> m_val << std::endl;
		qu.pop();
		std::cout << std::endl;

	}

	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::remove(const T& val)
{
 	root = del_node(root, val);
	return;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::del_node(Node* root, const T& val)
{
	if (root == nullptr){
		
		return root;
	}

	if (val < root -> m_val){
		
		root -> m_left = del_node(root -> m_left,val);
	
	} else if (val > root -> m_val){
		
		root -> m_right = del_node(root -> m_right, val);
	
	} else {
		
		if (root -> m_left == nullptr){
			
			Node* tmp = root -> m_right;
			delete root;
			return tmp;
		
		} else if (root -> m_right == nullptr){
		
			Node* tmp = root -> m_left;
			delete root;
			return tmp;	
		}

		Node* tmp = find_node(root -> m_right);
		root -> m_val = tmp -> m_val;
		root -> m_right = del_node(root -> m_right, root -> m_val);
	}

	return root;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::find_node(Node* root)
{
	if (root == nullptr){
		
		return root;
	}

	return find_node(root -> m_left);
}

template <typename T>
BinaryTree<T>::Node::Node()
{
	m_val = 0;
	m_left = nullptr;
	m_right = nullptr;
}

template <typename T>
BinaryTree<T>::Node::Node(const T& val)
{
	m_val = val;
	m_left = nullptr;
	m_right = nullptr;

}
