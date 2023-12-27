#include <iostream>
#include <queue>
#include <vector>

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
void BinaryTree<T>::level_order_print()
{
	if (!size()){
		
		std::cout << " The Tree is empty " << std::endl;
		return;
	}

	if (!root){
		
		return;
	}
	
	std::queue<Node*> qu;
	qu.push(root);
	//std::cout << " " << root -> m_val << std::endl;
	
	while(!qu.empty()){
		
		Node* tmp = qu.front();
		std::cout << " " << tmp -> m_val ;	
		if (tmp -> m_left){
			
			qu.push(tmp -> m_left);
			
		}

		if (tmp -> m_right){
			
			qu.push(tmp -> m_right);
			
		}

		qu.pop();
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
	int tmp_num = 1;
	height_helper(root,1,tmp_num);
	return tmp_num;
}

template <typename T>
void BinaryTree<T>::height_helper(Node* root, int i, int& num){
	
	if (root == nullptr){
		
		return;
	}

	if (i > num){
		
		num = i;
	}

	height_helper(root -> m_left, i + 1, num);
	height_helper(root -> m_right, i + 1, num);
}

template <typename T>
bool BinaryTree<T>::isValid()
{
	return isValid_helper(root);
}

template <typename T>
bool BinaryTree<T>::isValid_helper(Node* root)
{
	if (!root){
		
		return true;
	}

	if (root -> m_left && root -> m_left -> m_val > root -> m_val){
		
		return false;
	}

	if (root -> m_right && root -> m_right -> m_val < root -> m_val){
	
		return false;
	}

	bool left = isValid_helper(root -> m_left);
	bool rigth = isValid_helper(root -> m_right);

	if (left && rigth){
		
		return true;
	}

	return false;
}

template <typename T>
int BinaryTree<T>::size()
{
	int tmp_size = 0;
	size_helper(root,tmp_size);
	return tmp_size;

}

template <typename T>
void BinaryTree<T>::size_helper(Node* root, int& size)
{
	if (!root){
		
		return;
	}
	++size;
	size_helper(root -> m_left,size);
	size_helper(root -> m_right,size);
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::find_node(Node* root)
{
	if (root -> m_left == nullptr){
		
		return root;
	}

	return find_node(root -> m_left);
}

template <typename T>
void BinaryTree<T>::inOrder()
{
	inOrder_helper(root);
	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::inOrder_helper(Node* root)
{
	if (!root){
		
		return;
	}

	inOrder_helper(root -> m_left);
	std::cout << " " << root -> m_val;
	inOrder_helper(root -> m_right);
}

template <typename T>
void BinaryTree<T>::preOrder()
{
	preOrder_helper(root);
	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::preOrder_helper(Node* root)
{
	if (!root){
		
		return;
	}

	std::cout << " " << root -> m_val;
	preOrder_helper(root -> m_left);
	preOrder_helper(root -> m_right);
}

template <typename T>
void BinaryTree<T>::postOrder()
{
	postOrder_helper(root);
	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::postOrder_helper(Node* root)
{
	if (!root){
		
		return;
	}

	postOrder_helper(root -> m_left);
	postOrder_helper(root -> m_right);
	std::cout << " " << root -> m_val;
}

template <typename T>
bool BinaryTree<T>::contains(const T& val)
{
	return search(val);
}

template <typename T>
void BinaryTree<T>::clear()
{
	clear_helper(root);	
}

template <typename T>
void BinaryTree<T>::clear_helper(Node*& root)
{
	if (!root){
		
		return;
	}

	clear_helper(root -> m_left);
	clear_helper(root -> m_right);
	//std::cout << " " << root -> m_val ;	
	delete root;
	root = nullptr;
}

template <typename T>
std::vector<T> BinaryTree<T>::seriallized()
{
	std::vector<T> vec;
	seriallized_helper(root,vec);
	return vec;

}

template <typename T>
void BinaryTree<T>::seriallized_helper(Node* root, std::vector<T>& vec)
{

	if (!root){
		
		return;
	}
	
	vec.push_back(root -> m_val);
	seriallized_helper(root -> m_left,vec);
	seriallized_helper(root -> m_right,vec);

}

template <typename T>
void BinaryTree<T>::range_query(const T& start, const T& end)
{

	range_query_helper(root,start,end);
	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::range_query_helper(Node* root,const T& start,const T& end)
{
	if (!root){
		
		return;
	}

	if (root -> m_val >= start && root -> m_val <= end){
		
		std::cout << " " << root -> m_val ;
	}

	range_query_helper(root -> m_left,start,end);
	range_query_helper(root -> m_right,start,end);


}

template <typename T>
void BinaryTree<T>::copy()
{
	Node* tmp = copy_helper(root,root -> m_val);
	inOrder_helper(tmp);
	std::cout << std::endl;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::copy_helper(Node* root, const T& val)
{
	if (!root){
		
		return nullptr;
	}

	Node* tmp = new Node(root -> m_val);
	tmp -> m_left = copy_helper(root -> m_left, root -> m_left -> m_val);
	tmp -> m_right = copy_helper(root -> m_right, root -> m_right -> m_val);
	return tmp;
}

template <typename T>
void BinaryTree<T>::k_smallest(T val)
{
	Node* tmp = k_smallest_helper(root,val);
	if (!tmp){
		
		std::cout << " INVALID INPUT " << std::endl;
		return;
	}
	std::cout << " k smallest =  " << tmp -> m_val << std::endl;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::k_smallest_helper(Node* root, T& val)
{
	if (!root){
		
		return root;
	}

	Node* tmp = k_smallest_helper(root -> m_left,val);

	if (tmp){
		
		return tmp;
	}

	--val;
	if (val == 0){
		
		return root;
	}

	return k_smallest_helper(root -> m_right, val);
}

template <typename T>
void BinaryTree<T>::k_bigest(T val)
{
	Node* tmp = k_bigest_helper(root,val);
	if (tmp){
		
		std::cout << " k bigest = " << tmp -> m_val << std::endl;
		return;
	}

	std::cout << " INVALID VALUE " << std::endl;

}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::k_bigest_helper(Node* root, T& val)
{
	if (!root){
		
		return root;
	}

	Node* tmp = k_bigest_helper(root -> m_right,val);
	if (tmp){
		
		return tmp;
	}

	--val;
	
	if (val == 0){
		
		return root;
	}

	return k_bigest_helper(root -> m_left,val);
}

template <typename T>
void BinaryTree<T>::update(const T& current, const T& new_val)
{
	Node* tmp = update_helper(root,current,new_val);
	if (!tmp){
		
		std::cout << " Invalid value " << std::endl;
		return;
	}	
	std::cout << " the value changed :: " << tmp -> m_val << std::endl;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::update_helper(Node* root , const T& current, const T& new_val)
{
	if (!root){
		
		return root;
	}

	if (root -> m_val == current){
		
		 root -> m_val = new_val;
		return root;
	
	} else if (current > root -> m_val){
		
		return update_helper(root -> m_right, current, new_val);
	
	} else {
		
		return update_helper(root -> m_left, current, new_val);
	} 
	
	
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
