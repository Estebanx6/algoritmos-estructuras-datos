#include "OpenAddressHashTable.hpp"

// Macro para la funcion hash
#define SW 0xB5AD4ECEDA1CE2A9

// Macro que representa un espacio vacio en la tabla
#define VACIO 0

// Macro que representa un espacio borrado en la tabla
#define BORRADO 0xFFFFFFFFFFFFFFFF


/**
 * @brief Constructor por defecto de la tabla hash
 * @param size Tamaño de la tabla
 */
template <typename DataType>
OpenAddressHashTable<DataType>::OpenAddressHashTable(size_t size) 
: size(size)
, table(size)
, len(0) {

  for(size_t i = 0; i < this->size; i++) {
    this->table[i] = VACIO;
  }
}

/**
 * @brief Destructor por defecto de la tabla hash
 */
template <typename DataType>
OpenAddressHashTable<DataType>::~OpenAddressHashTable() = default;


/**
 * @brief Inserta un valor en la tabla hash
 * @param value valor a insertar
 */
template <typename DataType>
void OpenAddressHashTable<DataType>::insert(const DataType& value) {

  for (size_t i = 0; i < this->size - this->len; i++) {
    size_t h = this->hast(value);

    // Colisión

    if (i != 0) {
      h +=  i*i;
    }

    h = h % this->size;

    if (this->table[h] == BORRADO || this->table[h] == VACIO) { // guarda si esta vacio
      this->table[h] = value;
      this->len++;
      return;
    }
  }
}

/**
 * @brief busca un valor en la tabla
 * @param value valor a buscar
 * @return Retorna la posicion en la tabla de valor, empezando desde 1, retorna 0 si no lo encuentra
 * como es size_T no acepta valores negativos
 */
template <typename DataType>
int64_t OpenAddressHashTable<DataType>::search(const DataType& value) const {

  for (size_t i = 0; i < this->size; i++) {
    size_t h = this->hast(value);

    // Colisión

    if (i != 0) {
      h +=  i*i;
    }

    h = h % this->size;



    if (this->table[h] == value) { // Verifica si está
      return h; // retorna la posición, [1, M]
    }

     if (this->table[h] == VACIO) {
      return -1; // Se detiene ya que no esta mas adelante
    }
  }

  return -1; // Retorna -0 si no se encuentra 

}

/**
 * @brief remueve un valor de la tabla
 * @param value valor a eliminar
 */
template <typename DataType>
void OpenAddressHashTable<DataType>::remove(const DataType& value) {
  int64_t index = this->search(value);

  if (index != (-1)) {
    this->table[index] = BORRADO;
  }
}

/**
 * @brief calcula el hash del k respectivo
 * @param k key para crear el hash
 * @return hash de k. h(k)
 */
template <typename DataType>
size_t OpenAddressHashTable<DataType>::hast(const DataType& k) const{

  // Hast normal
  
  uint64_t h = (uint64_t)k * (uint64_t)k;

  h = h + SW;
  
  // Mascara
  size_t s = (h >> 22) & 0xFFFFF;

  return s;

}

