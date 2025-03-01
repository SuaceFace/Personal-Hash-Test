//
//  Hasher.h
//  Hash-Map-Test
//
//  Created by David Dang on 2/27/25.
//
#include "StateLinkedList.h"
#include <iostream>
#include <vector>

using namespace std;

//google how to default templatized variables

template<typename T>
class Hasher{
public:
    Hasher() {
        _hashedList = new LinkedList<T>[_hashTableSize];
    }
    ~Hasher(){
        delete [] _hashedList;
    }
    
    void SetValue(string key, T value){
        int index = hashedIndex(key);
        _hashedList[index].pushBack(key, value);
        if(_hashedList[index].length() > _linkedListLimit) {
            reHash();
        }
        _hashTableElements++;
    }
    
    T getValue(string key){
        T result;
        int index = hashedIndex(key);
        ListNode<T> *curNode = _hashedList[index].head();
        while(curNode != nullptr){
            if(curNode->key() == key){
                result = curNode->value();
                break;
            }
            curNode = curNode->nextNode();
        }
        return result;
    }
    
    void checkSpread(){
        for(int index = 0; index < _hashTableSize; index++){
            cout << "Index: " << index << ", LinkedList Length: " << _hashedList[index].length() << endl;
        }
    }
    
    string* allMyKeys(){
        string* allKeys = new string[_hashTableElements];
        int allKeysIndex = 0;
        for(int i = 0; i < _hashTableSize; i++){
            ListNode<T> *curNode = _hashedList[i].head();
            while(curNode != nullptr){
                allKeys[allKeysIndex] = curNode->key();
                curNode = curNode->nextNode();
                allKeysIndex++;
            }
        }
        return allKeys;
    }
    
private:
    int _hashTableSize = 4;
    int _hashTableElements = 0;
    const int _linkedListLimit = 5;
    LinkedList<T> * _hashedList;
    
    int hashedIndex(const string key){
        int hashIndex = 0;
        for(int index = 0; index < key.size(); index++){
            hashIndex += (key[index]);
        }
        hashIndex %=  _hashTableSize;
        
        /*while(_hashedList[hashIndex].head() != nullptr){
         hashIndex++;
         if(hashIndex == _hashTableSize-1) break;
         }*/
        
        return hashIndex;
    }
    
    void reHash(){
        _hashTableSize *= 2;
        LinkedList<T>* temp = new LinkedList<T>[_hashTableSize];
        //Go through all the cells of the old array
        for(int i = 0; i < _hashTableSize/2; i++){
            ListNode<T> *curNode = _hashedList[i].head();
            while(curNode != nullptr){
                string key = curNode->key();
                int index = hashedIndex(key);
                temp[index].pushBack(key, curNode->value());
                curNode = curNode->nextNode();
            }
        }
        delete [] _hashedList;
        _hashedList = temp;
    }
};

