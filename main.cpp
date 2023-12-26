#include <iostream>
#include "prototype.h"

int main ()
{
	BinaryTree<int> bin;
	bin.insert(10);
	bin.insert(9);
	bin.insert(545);
	bin.insert(8);
	bin.insert(99);
	bin.insert(134);
	bin.insert(534);
	bin.insert(33);
	bin.insert(45);
	bin.print();
	std::cout << "search result is :  " <<  bin.search(33) << std::endl;
	bin.find_min();
	bin.find_max();
	bin.successor(33);
	bin.predecessor(99);
	bin.print();
	std::cout << "The height of Tree is :: " << bin.height() << std::endl;
	std::cout << " isValid() :: " << std::boolalpha << bin.isValid() << std::endl;
	std::cout << " The size of Tree is :: " << bin.size() << std::endl;
	bin.inOrder();
	bin.preOrder();
	bin.postOrder();

}
