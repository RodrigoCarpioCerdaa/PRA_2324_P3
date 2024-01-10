#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
    private:
        int nelem;
	BSNode<T> *root;
	BSNode<T>* search(BSNode<T>* n, T e) const{
		if (n == nullptr){
			throw std::runtime_error("el arbol está vacío 1");	
		}
		else{
			if (n->elem < e){
				return search (n->right, e);
			}
			if (n->elem > e){
				return search (n->left, e);
			}
			else{
				return n;
			}
		}
	}
	BSNode<T>*insert (BSNode<T>* n, T e){
		if (n == nullptr){
			return new BSNode(e);
		}
		else if(n->elem == e){
			throw std::runtime_error("ya existe dicho elemento en el arbol 1");
		}
		else if(n->elem < e){
			n->right = insert(n->right, e);
		}
		else{
			n->left = insert(n->left, e);
		}
		return n;
	}
	void print_inorder(std::ostream &out, BSNode<T>* n) const{
		if(n != nullptr){
			if(n->left != nullptr){
				print_inorder(out , n->left);
			}

			out <<"  " << n->elem;

			if(n->right != nullptr){
				print_inorder(out , n->right);
			}

		}
	}

	BSNode<T>* remove(BSNode<T>* n, T e){
		if (n = nullptr){
			throw std::runtime_error("el arbol esta vacio 2");
		}
		else if(n->elem < e){
			remove(n->right, e);
		}
		else if (n->elem > e){
			remove(n->left, e);
		}
		else{
			if (n->left != nullptr && n->right != nullptr){
				n->elem = max(n->left);
				n->left = remove_max(n->left);
			}
			else{
				BSNode<T>* temp = n;
				n= (n->left != nullptr) ? n->left : n->right;
				delete temp;
			}
		}
		return n;
	}
	T max (BSNode<T>* n) const{
		if( n == nullptr){
			throw std::runtime_error("no va");
		}
		else if(n->right != nullptr){
			return max(n->right);
		}
		else{
			return n->elem;
		}
	}
	BSNode<T>* remove_max(BSNode<T>* n){
		if(n->rifht == nullptr){
			return n->left;
		}
		else{
			n->right = remove_max(n->right);
			return n;
		}
	}
	void delete_cascade(BSNode<T>* n){
		if(n!=nullptr){
			if(n->left != nullptr){
				delete_cascade(n->left);
				n->left = nullptr;
			}
			if (n->right != nullptr){
				delete_cascade(n->right);
				n->right = nullptr;
			}
			if(n->left == nullptr && n->right == nullptr){
				delete n;
			}
		}
	}
    public:
        BSTree(){
		nelem = 0;
	}
	int size() const{
		return nelem;
	}
	T search(T e) const{
		return search(root, e).elem;
	}
	T operator[] (T e) const{
		search(root, e);
	}
	void insert(T e){
		insert(root, e);
	}
	friend std::ostream& operator <<(std::ostream &out, const BSTree<T> &bst){
		print_inorder( out, bst);
		return out;
	}
	void remove (T e){
		remove(root, e);
	}
	~BSTree(){
		delete_cascade();
	}

    
};

#endif
