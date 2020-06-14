#include "tree.h"

template <typename T>
Tree<T>::Tree() : root(new node<T>()) {}

template <typename T>
Tree<T>::Tree(const node<T>& root_) : root(root_) {}

template<typename T>
node<T>* Tree<T>::getRoot() const{
	return root;
}

template<typename T>
void Tree<T>::InsertNewNode(const T& val) {
	node<T>* ptr = root;
	node<T>* ptr_box = nullptr;
	while(ptr != nullptr) {
		ptr_box = ptr;
		if (ptr->getValue() > val)
		{
			ptr = ptr->left;
		} else {
			ptr = ptr->right;
		}
	}
	node<T>* new_node = new node<T>(val);
	if (val < ptr_box->getValue())
	{
		ptr_box->left = new_node;
	} else
	{
		ptr_box->right = new_node;
	}
}

template<typename T>
void Tree<T>::map_(function<T(T)> func , node<T>* node) {
	node->setValue(func(root->getValue()));
	if (node->left == nullptr && node->right == nullptr) {
            return;
    }
    if (node->left != nullptr) {
        map_(func, node->left);
    }
    if (node->right != nullptr) {
        map_(func, node->right);
    }
}

template<typename T>
int Tree<T>::findWidth(){
	int n = 0;
	node<T>* ptr = root;
	while(ptr != nullptr) {
	    n++;
	    ptr = ptr->left;
	}
	return n;
}
template<typename T>
int Tree<T>::height(node<T>* node) {
        int L;
        int R;
        if (node->left == nullptr && node->right == nullptr) {
            return 0;
        } else {
            if (node->left != nullptr) {
                L = height(node->left) + 1;
            } else {
                L = 0;
            }
            if (node->right != nullptr) {
                R = height(node->right) + 1;
            } else {
                R = 0;
            }
        }
        if (L > R)
        {
        	return L;
        }
        else {
        	return R;
        }
}
template<typename T>
 void Tree<T>::deleteNode(T val, node<T>* curNode) {
        if (curNode == nullptr) {
           	throw invalid_argument("no node");
        }
        bool where;
        node<T>* ptr1 = nullptr;
        node<T>* ptr = curNode;
        if (ptr->left == nullptr && ptr->right == nullptr) {
            if (ptr->getValue() == val) {
                delete ptr;
                return;
            } else {
                throw invalid_argument("no node");
            }
        }

        while (ptr != nullptr && ptr->getValue() != val) {
            if (val < ptr->getValue()) {
                where = false;
                ptr1 = ptr;
                ptr = ptr->left;
            } else if (val > ptr->getValue()) {
                where = true;
                ptr1 = ptr;
                ptr = ptr->right;
            }
        }
        if (ptr == nullptr) {
            throw invalid_argument("..");
        } else {
            if (ptr->right == nullptr && ptr->left == nullptr) {
                if (!where) {
                    ptr1->left = nullptr;
                } else {
                    ptr1->right = nullptr;
                }
                delete ptr;
                return ;
            } else if (ptr->right != nullptr && ptr->left == nullptr) {
                if (ptr1->left == ptr) {
                    ptr1->left = ptr->right;
                } else {
                    ptr1->right = ptr->right;
                }
                delete ptr;
                return ;
            } else if (ptr->left != nullptr && ptr->right == nullptr) {
                if (ptr1->left == ptr) {
                    ptr1->left = ptr->left;
                } else {
                    ptr1->right = ptr->left;
                }
                delete ptr;
                return;
            } else if (ptr->left != nullptr && ptr->right != nullptr) {
                node<T> *ptr2 = nullptr;
                ptr1 = ptr;
                ptr2 = ptr;
                where = true;
                ptr = ptr->right;
                while (ptr->left != nullptr) {
                    ptr2 = ptr;
                    where = false;
                    ptr = ptr->left;
                }
                ptr1->value = ptr->value;

                if (ptr->right != nullptr) {
                    if (where) {
                        ptr2->right = ptr->right;
                    } else {
                        ptr2->left = ptr->right;
                    }
                    delete ptr;
                    return;
                } else {
                    if (where) {
                        ptr2->right = nullptr;
                    } else {
                        ptr2->left = nullptr;
                    }
                    delete ptr;
                    return ;
                }
            }
        }
    }
template<typename T>
node<T>* Tree<T>::find_node(node<T> *curNode, T val) {
        if (curNode->get->Value() == val) {
            return curNode;
        } else if (val < curNode->get->Value()) {
            if (curNode->left != nullptr) {
                return find_node(curNode->left, val);
            } else {
                return nullptr;
            }
        } else {
            if (curNode->right != nullptr) {
                return find_node(curNode->right, val);
            } else {
                return nullptr;
            }
        }
}