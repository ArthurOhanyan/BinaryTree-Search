#include <iostream>
#include "prototype.h"

int main ()
{
	BinaryTree<int> bin;
	bin.insert(10);
	bin.insert(9);
	bin.insert(5);
	bin.insert(8);
	bin.insert(2);
	bin.insert(4);
	bin.insert(5);
	bin.insert(33);
	bin.insert(45);
	bin.print();
	bin.remove(8);
	bin.print();
}
