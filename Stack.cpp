#include "Stack.hpp"

template <class T>
Stack<T>::Stack() : item_count_{0}, top_{nullptr} {}

template <class T>
Stack<T>::~Stack() {
    Node<T>* node_to_delete_ptr = top_;
    while(top_ != nullptr) {
        top_ = top_->getNext();
        
        // Return node to the system
        node_to_delete_ptr->setNext(nullptr);
        delete node_to_delete_ptr;

        node_to_delete_ptr = top_;
    }

    item_count_ = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T>& a_stack) { // called when object is initialized with a copy of another object.
                                           // e.g Stack<string> stack1 = stack2;
    item_count_ = a_stack.item_count_;
    Node<T>* orig_chain_ptr = a_stack.top_; // points to nodes in original chain.
    if (orig_chain_ptr == nullptr) {
        top_ = nullptr; // original bag is empty
    } else {
        //copy first node
        top_ = new Node<T>();
        top_->setItem(orig_chain_ptr->getItem());

        //copy remaining nodes
        Node<T>* new_chain_ptr = top_; // points to the last node in the new chain
        orig_chain_ptr = orig_chain_ptr->getNext(); // advance original-chain-pointer
        while (orig_chain_ptr != nullptr) {
            //Get next item from original chain
            T next_item = orig_chain_ptr->getItem(); // copy item from current node.
            //Create a ne node containing the next item
            Node<T>* new_node_ptr = new Node<T>(next_item); // create new node with item.
            //Link new node to the end of the chain
            new_chain_ptr->setNext(new_node_ptr); //connect new node to new chain

            //Advance pointer to new last node
            new_chain_ptr = new_chain_ptr->getNext(); // advance pointer traversing new chain
            // Advance original-chain pointer
            orig_chain_ptr = orig_chain_ptr->getNext(); // advance pointer traversing original chain
        }
        new_chain_ptr->setNext(nullptr); //flag end of chain // signals last node.
    }
}

template <class T>
void Stack<T>::push(const T& new_entry) {
    Node<T>* new_node_ptr = new Node<T>;
    new_node_ptr->setItem(new_entry);
    new_node_ptr->setNext(top_);
    
    top_ = new_node_ptr;
    item_count_++;
}

template <class T>
void Stack<T>::pop() {
    Node<T>* node_to_delete_ptr = top_;
    top_ = top_->getNext();
    delete node_to_delete_ptr;
    node_to_delete_ptr = nullptr;
    item_count_--;
}

template <class T>
T Stack<T>::top() const {
    return top_->getItem();
}

template <class T>
int Stack<T>::size() const {
    return item_count_;
}

template <class T>
bool Stack<T>::isEmpty() const {
    return item_count_ == 0;
}
