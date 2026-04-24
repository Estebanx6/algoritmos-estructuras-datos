#include "DoublyLinkedList.hpp"

/**
 * @brief Constructor por defecto del nodo de la lista
 * @param value valor del nodo
 * @param next puntero al siguiente nodo
 * @param prev puntero al nodo anterior
 */
template <typename DataType>
DLListNode<DataType>::DLListNode(const DataType& value, DLListNode<DataType>* next, DLListNode<DataType>* prev) 
  : key(value)
  , next(next) 
  , prev(prev)
  {}


/**
 * @brief inserta un valor a la lista
 * @param value valor a insertar
 */
template <typename DataType>
void DLList<DataType>::insert(const DataType& value) {
  
  DLListNode<DataType>* x = new DLListNode<DataType>(value, this->nil->next, this->nil);
  this->nil->next->prev = x;
  nil->next = x;

}


/**
 * @brief remueve un valor de la lista
 * @param value valor a remover
 */
template <typename DataType>
void DLList<DataType>::remove(const DataType& value) {
  DLListNode<DataType>* x = this->search(value);

  if (x == this->nil) {
    return; // No está
  }
  DLListNode<DataType>* tmp = x;

  x->prev->next = x->next;
  x->next->prev = x->prev;

  delete tmp;
}

/**
 * @brief Busca un valor en la lista
 * @param value valor a buscar
 * @return puntero al nodo respectivo, retorna nullptr si no lo encuentra
 */
template <typename DataType>
DLListNode<DataType>* DLList<DataType>::search(const DataType& value) const {
  DLListNode<DataType>* it = this->nil->next;

  while (it != this->nil && it->key != value)
  {
   it = it->next;
  }

  return it;

}

/**
 * @brief Constructor por defecto de la lista
 */
template <typename DataType>
DLList<DataType>::DLList() {

  this->nil = new DLListNode<DataType>();
  this->nil->next = this->nil;
  this->nil->prev = this->nil;
    
  
}

template <typename DataType>
DLListNode<DataType>* DLList<DataType>::getNil() const {

  return this->nil;

}
