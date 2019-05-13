#include <iostream>
#include <cstdlib>
#include <ctime>
#include "bin_tree.hpp"

int main() {
	srand(time(NULL));
	BinTree<int> tree;
	
	int n;
	std::cin >> n;
	for(int i = 0; i < n; ++i) {
		tree.insert(i);
	} 

	std::cout << "\n---------------------------\n";

	tree.print();
	std::cout << "\n---------------------------\n";

	int x;
	std::cin >> x;
	tree.remove(x);
	tree.print();

return 0;
}
