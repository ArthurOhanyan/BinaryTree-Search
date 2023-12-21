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
		//std::cout << std::endl;

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
bool BinaryTree<T>::search(const T& val)
{
	return search_helper(root, val);
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::search_helper(Node* root, const T& val)
{
	if (root == nullptr){
		
		return root;
	}

	if (val > root -> m_val){
		
		return search_helper(root -> m_right, val);
	
	} else if (val < root -> m_val){
		
		return search_helper(root -> m_left, val);
	
	} else {
	
		return root;	
	}

}

template <typename T>
void BinaryTree<T>::find_min()
{
	Node* tmp = find_min_helper(root);
	if (tmp){

	 	std::cout << " The minimum is : " << tmp -> m_val << std::endl;
	}
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::find_min_helper(Node* root)
{
	if (root == nullptr || root -> m_left == nullptr){
		
		return root;

	} 

	return find_min_helper(root -> m_left);


}

template <typename T>
void BinaryTree<T>::find_max()
{
	Node* tmp = find_max_helper(root);
	if (tmp){
		
		std::cout << " The max val is :  " << tmp -> m_val << std::endl;

	 }
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::find_max_helper(Node* root)
{
	if (root == nullptr || root -> m_right == nullptr){
		
		return root;
	}

	return find_max_helper(root -> m_right);
}

template <typename T>
void BinaryTree<T>::successor(const T& val)
{
	Node* succ = nullptr;
	Node* tmp = successor_helper(root,succ,val);
	if (tmp){
		
		std::cout << " The successor of  " << val << " is :: " << tmp -> m_val << std::endl;
	}
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::successor_helper(Node* root,Node* succ, const T& val)
{
	if (root == nullptr){
		
		return nullptr;
	}

	if (val == root -> m_val){
	
		if (root -> m_right != nullptr){
			
			Node* tmp = root -> m_right;
			while (tmp -> m_left){
				
				tmp = root -> m_left;
			}

			succ = tmp;
		}

	} else if (val < root -> m_val){
		
		succ = root;
		return successor_helper (root -> m_left,succ,val);
	
	} else {
	
		return successor_helper (root -> m_right,succ,val);
	} 
	
	return succ;
}

template <typename T>
void BinaryTree<T>::predecessor(const T& val){
	
	Node* pred = nullptr;
	Node* tmp = predecessor_helper(root,pred,val);
	if (tmp){
		
		std::cout << " The predecessor for " << val << " is : " << tmp -> m_val << std::endl;
	}

}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::predecessor_helper(Node* root, Node* pred, const T& val)
{
	if (root == nullptr){
		
		return root;
	}

	if (val == root -> m_val){
		
		if (root -> m_left != nullptr){
			
			Node* tmp = root -> m_left;
			while (tmp -> m_right){
				
				tmp = tmp -> m_right;
			}

			pred = tmp;
		} 

	} else if (val > root -> m_val){
		
		pred = root;
		return predecessor_helper (root -> m_right, pred, val);
	
	} else {
		
		return predecessor_helper (root -> m_left, pred, val);
	}

	return pred;

}

template <typename T>
int BinaryTree<T>::height()
{
	int tmp_num = 0;
	return height_helper(root,0,tmp_num);
}

template <typename T>
int BinaryTree<T>::height_helper(Node* root, int i, int& num){
	
	if (root == nullptr){
		
		return num;
	}

	if (i > num){
		
		num = i;
	}

	return height_helper(root -> m_left, i + 1, num);
	return height_helper(root -> m_right, i + 1, num);
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
