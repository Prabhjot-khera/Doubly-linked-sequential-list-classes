#include "doubly-linked-list.h"
using namespace std;

DoublyLinkedList::Node::Node(DataType data) {
    this->next = nullptr;
    this->prev = nullptr;
    this->value=data;
}


DoublyLinkedList::DoublyLinkedList() {
    size_=0;
    head_= nullptr;
    tail_= nullptr;
}


DoublyLinkedList::~DoublyLinkedList() {

    Node *current = head_;

    while (current)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }

}


unsigned int DoublyLinkedList::size() const {
    return size_;
}


unsigned int DoublyLinkedList::capacity() const {
    return CAPACITY;
}


bool DoublyLinkedList::empty() const {
    if(size_==0)
    {
        return true;
    }

    return false;
}


bool DoublyLinkedList::full() const {
    if(size_==CAPACITY)
    {
        return true;
    }

    return false;
}


DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    int count = 0;
    Node* current = getNode(index);

    if (current== nullptr)
        current = getNode(size_-1);

    return current->value;




}


unsigned int DoublyLinkedList::search(DataType value) const {

    int position = -1;
    Node *temp = head_;

    for (int count = 0; count<=size_-1; count ++)
    {
        if (temp->value==value)
            position = count;

        temp = temp->next;
    }

    if (position ==-1)
        return size_;
    else
        return position;

}


void DoublyLinkedList::print() const {

    if (head_ == nullptr) {
        return;
    }

    Node *temp = head_;
    while (temp != nullptr) {
        cout<< temp->value << "->";
        temp = temp->next;
    }
    cout<< endl;
}



DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {

    if (head_ == nullptr) {
        return nullptr; // Return nullptr if the list is empty
    }

    Node* current = head_;
    int count = 0;

    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        return nullptr;
    }

    return current;
}


bool DoublyLinkedList::insert(DataType value, unsigned int index) {
    if (index<0 || index >size_ || size_>=CAPACITY)
        return false;

    Node *newNode = new Node(value);

    if(index == 0){
        if(head_ == nullptr){
            head_ = newNode;
            tail_=newNode;
            size_++;
            return true;
        }
        else{ //2.2 when size > 0
            newNode->next = head_;
            newNode->prev = nullptr;
            head_->prev = newNode;
            head_ = newNode;
            size_++;
            return true;
        }
    }

    if (index==size_)
    {
        newNode->prev = tail_;
        newNode->next = nullptr;
        tail_->next = newNode;
        tail_ = newNode;
        size_++;
        return true;
    }


    Node *previous = head_;
    Node *current = head_->next;
    int i = 1;
    while (i < index) {
        previous = current;
        current = current->next;
        if (current == nullptr) {
            break;
        }
        i++;
    }

    //step 4. insert the node between previous and current
    current->prev = newNode;
    newNode->next = current;
    newNode->prev = previous;

    previous->next = newNode;
    size_++;
    return true;
}


bool DoublyLinkedList::insert_front(DataType value) {
    if ( size_ < CAPACITY) {
        Node *newNode = new Node(value);
        if (head_ == nullptr) {
            head_ = newNode;
            tail_=newNode;
            size_++;
            return true;
        } else { //2.2 when size > 0
            newNode->next = head_;
            newNode->prev = nullptr;
            head_->prev = newNode;
            head_ = newNode;
            size_++;
            return true;
        }
    }

    return false;
}


bool DoublyLinkedList::insert_back(DataType value) {
    Node *newNode = new Node(value);

    if (size_ < CAPACITY)
    {

        if (head_ == nullptr) {
            head_ = newNode;
            tail_=newNode;
            size_++;
            return true;
        } else {
            newNode->next = nullptr;
            newNode->prev = tail_;
            tail_->next = newNode;
            tail_ = newNode;
            size_++;
            return true;
        }
    }
    return false;
}


bool DoublyLinkedList::remove(unsigned int index) {
    if (size_>0 && index<=size_-1)
    {
        if(size_==1)
        {
            Node *temp = head_;
            delete temp;
            temp = nullptr;
            size_--;
            return true;
        }

        if(index == 0){
            Node *temp = head_;
            head_ = head_->next;
            head_->prev= nullptr;
            delete temp;
            temp = nullptr;
            size_--;
            return true;
        }

        if (index==size_-1)
        {
            Node *temp = tail_;
            tail_=temp->prev;
            tail_->next= nullptr;
            delete temp;
            temp= nullptr;
            size_--;
            return true;
        }


        Node *previous = head_;
        Node *current = head_->next;
        int i = 1;
        while (i < index) {
            if (current->next == nullptr) {
                break;
            }
            previous = current;
            current = current->next;
            i++;
        }

        previous->next = current->next;
        current->next->prev=previous;
        delete current;
        current = nullptr;
        size_--;
    }
    return false;
}


bool DoublyLinkedList::remove_front() {
    if(size_>0)
    {
        if(size_==1)
        {
            Node *temp = head_;
            delete temp;
            temp = nullptr;
            size_--;
            return true;
        }
        Node *temp = head_;
        head_ = head_->next;
        head_->prev= nullptr;
        delete temp;
        temp = nullptr;
        size_--;
        return true;
    }
    return false;
}


bool DoublyLinkedList::remove_back() {
    if(size_>0)
    {
        if(size_==1)
        {
            Node *temp = head_;
            delete temp;
            temp = nullptr;
            size_--;
            return true;
        }
        Node *temp = tail_;
        tail_=tail_->prev;
        tail_->next= nullptr;
        delete temp;
        temp= nullptr;
        size_--;
        return true;
    }
    return false;
}


bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    int position = 0;
    Node *temp = getNode(index);

    if (temp== nullptr)
        return false;

    temp->value =value;
    return true;

}
