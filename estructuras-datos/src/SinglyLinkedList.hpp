/*
Credits
Original template provided by:
- Prof. Arturo Camacho, ECCI - Universidad de Costa Rica
- Prof. Allan Berrocal, ECCI - Universidad de Costa Rica

Completed and adapted by:
- Esteban Cruz
*/


#pragma once
template <typename DataType>
class SLList;

template <typename DataType>
class SLListNode {
 public:
  friend class SLList<DataType>;

  SLListNode();

  SLListNode(const DataType& value, SLListNode<DataType>* next = nullptr);

  ~SLListNode();

  DataType getKey() const;

  SLListNode<DataType>* getNext() const;

  void setKey(DataType key);

  void setNext(SLListNode<DataType>* newNode);

 private:
  DataType key;

  SLListNode<DataType>* next;
};

template <typename DataType>
class SLList {
 public:
  SLList();

  ~SLList() {
    
    while (this->nil->next != this->nil) {
      SLListNode<DataType>* tmp = this->nil->next->next;
      delete this->nil->next;
      this->nil->next = tmp;
    }

    delete this->nil;
  };

  void insert(const DataType& value);

  SLListNode<DataType>* search(const DataType& value) const;

  void remove(const DataType& value);

  SLListNode<DataType>* getNil() const;
  
 private:
  SLListNode<DataType>* nil;

};

#include "SinglyLinkedList.tpp"
