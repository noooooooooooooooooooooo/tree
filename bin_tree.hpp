#ifndef __BIN_TREE_HPP__
#define __BIN_TREE_HPP__

#include "node.hpp"
#include "container.hpp"

template <class T>
class BinTree: public Container<T> {
public:
	BinTree();
    
	void insert(T value);
    bool exists(T value);
    void remove(T value);
    void print();

	~BinTree();

private:
	Node<T>* insert(Node<T>* node, T value);
	Node<T>* exists(Node<T>* node, T value);
	void print(Node<T>* node, int depth);	 
	void clear(Node<T>* node);
	Node<T>* remove(Node<T>* node, T value);

	Node<T>* balance(Node<T>* node);
	unsigned char height(Node<T>* node);
	Node<T>* slr(Node<T>* node);
	Node<T>* srr(Node<T>* node);
	void fix_height(Node<T>* node);
	signed char check_balance(Node<T>* node);
	unsigned char max(unsigned char, unsigned char);

	Node<T>* root;
};

#endif //__BIN_TREE_HPP__
