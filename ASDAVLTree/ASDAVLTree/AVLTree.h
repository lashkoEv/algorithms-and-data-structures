#pragma once
#include <iostream>
using namespace std;

template <class T>
class AVLTree
{
private:
    class Node
    {
    public:
        T data;
        Node* left;
        Node* right;
        int height;

        Node(T data = T(), Node* left = nullptr, Node* right = nullptr, int ht = 0)
        {
            this->data = data;
            this->left = left;
            this->right = right;
            this->height = ht;
        }
    };

    Node* root;

public:
    AVLTree();
    ~AVLTree();
    void add(T data);
	void clear();
	void print();
    void remove(T data);




private:

    Node* add(T data, Node*& node)
    {
        if (node == nullptr)
        {
            node = new Node(data);
        }
        else {
            if (data < node->data) {
                node->left = add(data, node->left);
                if (height(node->left) - height(node->right) == 2)
                {
                    if (data < node->left->data) {
                        node = simple_right_rotate(node);
                    }
                    else {
                        node = big_right_rotate(node);
                    }
                }
            } else {
                if (data > node->data) {
                    node->right = add(data, node->right);
                    if (height(node->right) - height(node->left) == 2)
                    {
                        if (data > node->right->data)
                            node = simple_left_rotate(node);
                        else
                            node = big_left_rotate(node);
                    }
                }
            }
        }

        node->height = max(height(node->left), height(node->right)) + 1;
        return node;
    }


    Node* remove(T data, Node* node)
    {
        //Node* tmp;

        //if (node == nullptr) 
        //    return nullptr;

        // if (data < node->data)
        //    node->left = remove(data, node->left);

        //else  if (data > node->data)
        //    node->right = remove(data, node->right);

        //else
        //    // Если оба поддерева
        //    if (node->left && node->right) {
        //        tmp = find_min(node->right);
        //        node->data = tmp->data;
        //        node->right = remove(node->data, node->right);
        //    }
        //    else {
        //        // С одним поддеревом или без поддеревьев
        //        tmp = node;
        //        if (node->left == nullptr)
        //            node = node->right;
        //        else if (node->right == nullptr)
        //            node = node->left;


        //        delete tmp;
        //    }

        //if (node == nullptr) {
        //    return node;
        //}

        //node->height = max(height(node->left), height(node->right)) + 1;

        ///*// Если разбалансировано
        //// Если левый узел удален, балансировка правого
        //if (height(node->left) - height(node->right) == -2)
        //{
        //    if (height(node->right->right) - height(node->right->left) == 1) {// rr
        //        return simple_left_rotate(node);
        //    }
        //    else { // rl
        //        return big_left_rotate(node);
        //    }
        //}
        //// Если правый узел удален, балансировка левого
        //else if (height(node->right) - height(node->left) == 2)
        //{
        //    if (height(node->left->left) - height(node->left->right) == 1) {// ll
        //        return simple_right_rotate(node);
        //    }
        //    else { // lr
        //        return big_right_rotate(node);
        //    }
        //}
        //return node;
        //*/

        //int balance = getBalance(node);

        ////rotate the tree if unbalanced

        //// Left Left Case  
        //if (balance > 1 &&
        //    getBalance(node->left) >= 0)
        //    return simple_right_rotate(node);

        //// Left Right Case  
        //if (balance > 1 && getBalance(node->left) < 0) {
        //   // node->left = simple_left_rotate(node->left);
        //    return big_right_rotate(node);
        //}
        //// Right Right Case  
        //if (balance < -1 && getBalance(node->right) <= 0)
        //    return simple_left_rotate(node);

        //// Right Left Case  
        //if (balance < -1 && getBalance(node->right) > 0) {
        //  //  node->right = simple_right_rotate(node->right);
        //    return big_left_rotate(node);
        //}
        //return node;
     
        if (node->left == nullptr && node->right == nullptr) {
            if (node == this->root)
                this->root = nullptr;
            delete node;
            return nullptr;
        }

        Node* t;
        Node* q;
        if (node->data < data) {
            node->right = remove(data, node->right);
        }
        else if (node->data > data) {
            node->left = remove( data, node->left);
        }
        else {
            if (node->left != nullptr) {
                q = q = inpre(node->left);
                node->data = q->data;
                node->left = remove(q->data,node->left );
            }
            else {
                q = insuc(node->right);
                node->data = q->data;
                node->right = remove( q->data, node->right);
            }
        }
        
        if (bf(node) == 2 && bf(node->left) == 1) { node = llrotation(node); }
        else if (bf(node) == 2 && bf(node->left) == -1) { node = lrrotation(node); }
        else if (bf(node) == 2 && bf(node->left) == 0) { node = llrotation(node); }
        else if (bf(node) == -2 && bf(node->right) == -1) { node = rrrotation(node); }
        else if (bf(node) == -2 && bf(node->right) == 1) { node = rlrotation(node); }
        else if (bf(node) == -2 && bf(node->right) == 0) { node = llrotation(node); }


        return node;
    }

    Node* inpre(Node* p) {
        while (p->right != NULL)
            p = p->right;
        return p;
    }

    Node* insuc(Node* p) {
        while (p->left != NULL)
            p = p->left;

        return p;
    }

    int bf(Node* n) {
        if (n->left && n->right) {
            return n->left->height - n->right->height;
        }
        else if (n->left && n->right == nullptr) {
            return n->left->height;
        }
        else if (n->left == nullptr && n->right) {
            return -n->right->height;
        }
    }

    Node* llrotation(Node* n) {
        Node* p;
        Node* tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp;
    }


    Node* rrrotation(Node* n) {
        Node* p;
        Node* tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp;
    }


    Node* rlrotation(Node* n) {
        Node* p;
        Node* tp;
        Node* tp2;
        p = n;
        tp = p->right;
        tp2 = p->right->left;

        p->right = tp2->left;
        tp->left = tp2->right;
        tp2->left = p;
        tp2->right = tp;

        return tp2;
    }

    Node* lrrotation(Node* n) {
        Node* p;
        Node* tp;
        Node* tp2;
        p = n;
        tp = p->left;
        tp2 = p->left->right;

        p->left = tp2->right;
        tp->right = tp2->left;
        tp2->right = p;
        tp2->left = tp;

        return tp2;
    }


    Node* simple_right_rotate(Node*& t)
    {
        cout << "simple_right_rotate"<<endl;
      //  if (t->left != NULL) {
            Node* u = t->left;
            t->left = u->right;
            u->right = t;
            t->height = max(height(t->left), height(t->right)) + 1;
            u->height = max(height(u->left), t->height) + 1;
            return u;
//}
   //     return t;
    }

    Node* simple_left_rotate(Node*& t)
    {
        cout << "simple_left_rotate" << endl;
     //   if (t->right != NULL) {
            Node* u = t->right;
            t->right = u->left;
            u->left = t;
            t->height = max(height(t->left), height(t->right)) + 1;
            u->height = max(height(t->right), t->height) + 1;
            return u;
   //     }
    //    return t;
    }


    Node* big_left_rotate(Node*& node) 
    {
        cout << endl << "Big left rotate" << endl;
        node->right = simple_right_rotate(node->right);
        return simple_left_rotate(node);
    }


    Node* big_right_rotate(Node*& node) 
    {
        cout << endl << "Big right rotate" << endl;
        node->left = simple_left_rotate(node->left);
        return simple_right_rotate(node);
    }


    Node* find_max(Node* node)
    {
        if (node == nullptr) {
            return nullptr;
        }
        else {
            if (node->right == nullptr) {
                return node;
            }
            else {
                return find_max(node->right);
            }
        }
    }


    Node* find_min(Node* node)
    {
        if (node == nullptr) {
            return nullptr;
        }
        else {
            if (node->left == nullptr) {
                return node;
            }
            else {
                return find_min(node->left);
            }
        }
    }


    int max(int left, int right)
    {
        return (left >= right) ? left : right;
    }


    void clear(Node* node)
    {
        if (node == nullptr) {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    }


    void print(Node*& node, int tabs)
    {
        if (node == nullptr) return;
        tabs += 5;
        print(node->left, tabs);
        for (int i = 0; i < tabs; i++) cout << " ";
        cout << node->data << endl;
        print(node->right, tabs);
        tabs -= 5;
        return;
    }

   
    int height(Node* node)
    {
        return (node == nullptr ? -1 : node->height);
    }

    
    int getBalance(Node* node)
    {
        if (node == nullptr) {
            return 0;
        }
        else {
            return height(node->left) - height(node->right);
        }
    }

};


template<class T>
inline AVLTree<T>::AVLTree()
{
    root = nullptr;
}

template<class T>
inline AVLTree<T>::~AVLTree()
{
    clear(root);
}


template<class T>
inline void AVLTree<T>::clear()
{
    clear(root);
    root = nullptr;
}

template<class T>
inline void AVLTree<T>::print()
{
    int tabs = 0;
    print(root, tabs);
}

template<class T>
inline void AVLTree<T>::add(T data)
{
    add(data, root);
}


template<class T>
inline void AVLTree<T>::remove(T data)
{
    remove(data, root);
}