#include "SinglyLinkedList.hpp"

// Implementaciones de la clase SLListNode

/**
 * @brief Constructor por defecto del nodo de la  lista.
 */
template <typename DataType>
SLListNode<DataType>::SLListNode() = default;

/**
 * @brief Constructor parametrizado del nodo de la lista.
 * @param value valor del nodo
 * @param next puntero al siguiente nodo
 */
template <typename DataType>
SLListNode<DataType>::SLListNode(const DataType& value, SLListNode<DataType>* next) 
: key(value)
, next(next) 
{}

/**
 * @brief Destructor por defecto del nodo de la lista
 */
template <typename DataType>
SLListNode<DataType>:: ~SLListNode() = default;

/**
 * @brief Getter del atributo next del nodo
 * @param puntero al nodo next
 */
template <typename DataType>
SLListNode<DataType>* SLListNode<DataType>::getNext() const {
  return this->next;
}

/**
 * @brief Getter del key del nodo
 * @return key del nodo
 */
template <typename DataType>
DataType SLListNode<DataType>::getKey() const {
  return this->key;
}

/**
 * @brief Setter del key del nodo
 * @param key key a settear del nodo 
 */
template <typename DataType>
void SLListNode<DataType>::setKey(DataType key) {
  this->key = key;
}

/**
 * @brief Setter del next del nodo
 * @param newNode puntero al nuevo nodo next a settear del nodo.
 */
template <typename DataType>
void SLListNode<DataType>::setNext(SLListNode<DataType>* newNode) {
  this->next = newNode;
}

// Implementaciones de la clase SLList

/**
 * @brief Busca un nodo dentro de la tabla
 * @param value valor del nodo a buscar
 */
template <typename DataType>
SLListNode<DataType>* SLList<DataType>::search(const DataType& value) const {

  SLListNode<DataType>* it = this->nil->next;

  while (it != this->nil && it->getKey() != value)
  {
   it = it->getNext();
  }

  return it;
}

/**
 * @brief Inserta un nodo en la lista
 * @param value valor del nodo a insertar
 */
template <typename DataType>
void SLList<DataType>::insert(const DataType& value) {
  SLListNode<DataType>* x = new SLListNode<DataType>(value, this->nil->next);
  nil->next = x;
}

/**
 * @brief ELimina un nodo en la lista
 * @param value valor del nodo a eliminar
 */
template <typename DataType>
void SLList<DataType>::remove(const DataType& value) {

  SLListNode<DataType>* it = this->nil;

  if (it == it->next) {
    return; // Retorna si esta vacia
  }

  while (it->next != this->nil && it->next->key != value) {
    it = it->next;
  }

  if (it->next->key != value) {
    return; // No esta el elemento
  }

  SLListNode<DataType>* tmp = it->next;

  it->next = tmp->next;

  tmp->next = nullptr;

  delete tmp;

}


/**
 * @brief Constructor por defecto de la lista
 */
template <typename DataType>
SLList<DataType>::SLList() {

  this->nil = new SLListNode<DataType>();
  this->nil->next = this->nil;

}