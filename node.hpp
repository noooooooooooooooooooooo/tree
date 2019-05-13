#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <cstdlib>

template <class T>
class Node {
public:
	Node(T val): left(NULL), right(NULL), value(val) {}

	Node* left;
	Node* right;
	T value;	
	unsigned char height; 
};

#endif //__NODE_HPP__