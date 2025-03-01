//
//  ListNode.hpp
//  Hash-Map-Test
//
//  Created by David Dang on 2/25/25.
//
#include <iostream>
#include <vector>
using namespace std;


template<typename T>
class ListNode {
public:
    ListNode(string key, T value, ListNode *nextNode) : _key(key), _value(value), _nextNode(nextNode) {};
    
    string key() const {return _key;};
    T value() const {return _value;};
   
    ListNode *nextNode() const { return _nextNode; };
    
    void setNextNode(ListNode *nextNode) { _nextNode = nextNode; };
    
private:
    string _key;
    T _value;
    ListNode *_nextNode;
};

//Make _length a private data member, change it when pushing and popping
template<typename T>
class LinkedList {
public:
    ~LinkedList();
    
    void pushFront(string key, T value);
    void popFront();
    
    void pushBack(string key, T value);
    void popBack();
    
    int length() const {return _length;};
    
    ListNode<T> *head() const { return _head; };
    ListNode<T> *tail() const;
    
    
private:
    ListNode<T> *_head = nullptr;
    int _length = 0;
};

template<typename T>
LinkedList<T>::~LinkedList() {
    ListNode<T> *curNode = _head;
    while (curNode != nullptr) {
        ListNode<T> *nextNode = curNode->nextNode();
        delete curNode;
        curNode = nextNode;
    }
}

template<typename T>
ListNode<T> *LinkedList<T>::tail() const {
    ListNode<T> *prevNode = nullptr;
    ListNode<T> *curNode = _head;
    while (curNode != nullptr) {
        prevNode = curNode;
        curNode = curNode->nextNode();
    }
    
    return prevNode;
}

template<typename T>
void LinkedList<T>::pushFront(string key, T value) {
    _head = new ListNode<T>(key, value, _head);
    _length++;
}

template<typename T>
void LinkedList<T>::popFront() {
    if (ListNode<T> *oldHead = _head) {
        _head = _head->nextNode();
        delete oldHead;
        _length--;
    }
}

template<typename T>
void LinkedList<T>::pushBack(string key, T value) {
    ListNode<T> *tailNode = tail();
    ListNode<T> *newTailNode = new ListNode<T>(key, value, nullptr);
    if (tailNode == nullptr) {
        _head = newTailNode;
    } else {
        tailNode->setNextNode(newTailNode);
    }
    _length++;
}

template<typename T>
void LinkedList<T>::popBack() {
    if (_head == nullptr) {
        return;
    } else {
        if(_head->nextNode() == nullptr) {
            delete _head;
            _head = nullptr;
        }
        else {ListNode<T> *tailNode = tail();
            int len = length();
            ListNode<T> *currNode = _head;
            for(int i = 0; i < len-2; i++){
                currNode = currNode->nextNode();
            }
            delete tailNode;
            currNode->setNextNode(nullptr);
        }
        _length--;
    }
}
