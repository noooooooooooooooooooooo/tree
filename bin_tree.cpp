
#include "bin_tree.hpp"
#include <iostream>


template <class T>
BinTree<T>::BinTree(): root(NULL) {}

template <class T>
void BinTree<T>::insert(T value) {
	root = insert(root, value);
}

template <class T>
Node<T>* BinTree<T>::insert(Node<T>* node, T value) {
	if(node == NULL)
		return new Node<T>(value);
	if(value > node->value) {
		node->right = insert(node->right, value);
	} else if(value < node->value) {
		node->left  = insert(node->left,  value); 
	}

	return balance(node);
}

template <class T>
bool BinTree<T>::exists(T value) {
	return exists(root, value) != NULL;
}

template <class T>
Node<T>* BinTree<T>::exists(Node<T>* node, T value) {
	if(node == NULL) {
		return NULL;
	}

	if(value == node->value) {
		return node;
	}
	if(value > node->value) {
		return exists(node->right, value);
	}
	if(value < node->value) {
		return exists(node->left, value);
	}
}

template <class T>
void BinTree<T>::print() {
	print(root, 0);
}

template <class T>
void BinTree<T>::print(Node<T>* node, int depth) {
	if(node == NULL) {
		return;
	}
	print(node->right, depth + 1);
	for(int i = 0; i < depth; ++i) {
		std::cout << "--";
	}
	std::cout << "|" << node->value << "\n";
	print(node->left, depth + 1);
}

template <class T> 
void BinTree<T>::remove(T value) {
	root = remove(root, value);
}

template <class T>
Node<T>* BinTree<T>::remove(Node<T>* node, T value) {
	if(node == NULL) {
		return NULL;
	}
	if(value == node->value) {
		if(node->right == NULL) {
			Node<T>* left = node->left;
			delete node;
			return left;
		}
	
		Node<T>* p = node;
		Node<T>* c = p->right;
		while(c->left != NULL) {
			p = c;
			c = c->left;
		}
		p->left = c->right;
		c->left = node->left;
		c->right = node->right;

		delete node;
		return c;
	}
	if(value > node->value) {
		node->right = remove(node->right, value);
	} else if(value < node->value) {
		node->left  = remove(node->left,  value);
	}
	return balance(node);
}

template <class T>
void BinTree<T>::clear(Node<T>* node) {
	if(node == NULL)
		return ;
	clear(node->left);
	clear(node->right);
	delete node;
}

template <class T>
BinTree<T>::~BinTree() {
	clear(root);
}

template <class T>
Node<T>* BinTree<T>::balance(Node<T>* node) {
	fix_height(node);
	if(check_balance(node) == 2) {
		if (check_balance(node->left) < 0)
			node->left = slr(node->left);
		node = srr(node);
	} else if (check_balance(node) == -2) {
		if(check_balance(node->right) > 0)
			node->right = srr(node->right);
		node = slr(node);		
	}
	return node;
}

template <class T>
unsigned char BinTree<T>::height(Node<T>* node) {
	return node ? node->height : 0;
}

template <class T>
Node<T>* BinTree<T>::slr(Node<T>* node) {
	Node<T>* tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;
	fix_height(node);
	fix_height(tmp);
	return tmp;
}

template <class T>
Node<T>* BinTree<T>::srr(Node<T>* node) {
	Node<T>* tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	fix_height(node);
	fix_height(tmp);
	return tmp;
}

template <class T>
void BinTree<T>::fix_height(Node<T>* node) {
	node->height = max(height(node->left), height(node->right)) + 1;
}

template <class T>
signed char BinTree<T>::check_balance(Node<T>* node) {
	if(node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}

template <class T>
unsigned char BinTree<T>::max(unsigned char x, unsigned char y) {
	return (x > y) ? x : y;
}


template class BinTree<int>;
