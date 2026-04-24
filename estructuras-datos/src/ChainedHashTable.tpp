#include "ChainedHashTable.hpp"

/**
 * @brief Constructor por defecto de la tabla
 * @param size Tamaño de la tabla
 */
template <typename DataType>
ChainedHashTable<DataType>::ChainedHashTable(size_t size) 
: size(size)
, table(size) {}


/**
 * @brief Destructor por defecto de la tabla
 */
template <typename DataType>
ChainedHashTable<DataType>::~ChainedHashTable() = default;


/**
 * @brief Crea la funcion hash con el valor k para dispersar la tabla
 * @param k valor para crear el hash
 * @return hash creado
 */
template <typename DataType>
size_t ChainedHashTable<DataType>::hash(const DataType& k) const{
  return (k % this->size);
}

/**
 * @brief Inserta value en la tabla
 * @param value valor a insertar
 */
template <typename DataType>
void ChainedHashTable<DataType>::insert(const DataType& value) {
  size_t h = this->hash(value);

  this->table[h].insert(value);

}

/**
 * @brief remueve value de la tabla
 * @param value valor a remover
 */
template <typename DataType>
void ChainedHashTable<DataType>::remove(const DataType& value) {
  size_t h = this->hash(value);

  this->table[h].remove(value);

}

/**
 * @brief busca value en la tabla
 * @param value valor a buscar
 * @return Puntero al nodo que contiene el valor
 */
template <typename DataType>
int64_t ChainedHashTable<DataType>::search(const DataType& value) const {
  size_t h = this->hash(value);

  if (this->table[h].search(value) == this->table[h].getNil()) {
    return -1;

  } else {
    return h;
  }

}




