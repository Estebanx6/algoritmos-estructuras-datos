#include "BinarySearchTree.hpp"
#include <iostream>

// BSTreeNode<DataType> 


/**
 * @brief Constructor de la clase nodo del arbol binario
 * @param value Valor del nodo
 * @param parent Nodo padre
 * @param left Nodo hijo izquierdo
 * @param right Nodo hijo derecho
 */
template <typename DataType>
BSTreeNode<DataType>::BSTreeNode(const DataType &value, BSTreeNode<DataType> *parent, BSTreeNode<DataType> *left,
  BSTreeNode<DataType> *right) 
  :key(value)
  , parent(parent)
  , left(left)
  , right(right) {}

/**
 * @brief Destructor por defecto de la clase nodo del arbol binario
 */
template <typename DataType>
BSTreeNode<DataType>::~BSTreeNode() = default;


/**
 * @brief Getter del key del nodo.
 * @return key del nodo
 */
template <typename DataType>
DataType BSTreeNode<DataType>::getKey() const{
  return this->key;
}


/**
 * @brief Getter del nodo padre.
 * @return puntero al nodo padre
 */
template <typename DataType>
BSTreeNode<DataType>* BSTreeNode<DataType>::getParent() const{
  return this->parent;
}

/**
 * @brief Getter del nodo hijo izquierdo.
 * @return puntero al nodo hijo izquierdo
 */
template <typename DataType>
BSTreeNode<DataType>* BSTreeNode<DataType>::getLeft() const{
  return this->left;
}

/**
 * @brief Getter del nodo hijo derecho.
 * @return puntero al nodo hijo derecho
 */
template <typename DataType>
BSTreeNode<DataType>* BSTreeNode<DataType>::getRight() const{
  return this->right;
}

/**
 * @brief Setter del nodo padre
 * @param parent puntero al nodo padre
 */
template <typename DataType>
void BSTreeNode<DataType>::setParent(BSTreeNode<DataType> *parent) {
  this->parent = parent;
}


/**
 * @brief Setter del nodo hijo izquierdo.
 * @param left puntero al nodo hijo izquierdo
 */
template <typename DataType>
void BSTreeNode<DataType>::setLeft(BSTreeNode<DataType> *left) {
  this->left = left;
}

/**
 * @brief Setter del nodo hijo derecho
 * @param right puntero al nodo hijo derecho
 */
template <typename DataType>
void BSTreeNode<DataType>::setRight(BSTreeNode<DataType> *right) {
  this->right = right;
}


// BSTree<DataType>


/**
 * @brief Inserta un valor en el arbol binario
 * @param value Valor a insertar
 */
template <typename DataType>
void BSTree<DataType>::insert(const DataType &value) {


  BSTreeNode<DataType>* x = this->root;
  BSTreeNode<DataType>* y = nullptr;
  BSTreeNode<DataType>* z = new BSTreeNode<DataType>(value, nullptr, nullptr, nullptr);


  while (x != nullptr) {
    y = x;

    if (y->key == z->key) {
      delete z;
      return; // evita repetidos
    }

    if (z->getKey() < x->getKey()) {
      x = x->getLeft();

    } else {
      x = x->getRight();
    }
  }

  z->setParent(y);

  if (y == nullptr) {
    this->root = z;
  } else if (z->getKey() < y->getKey()) {
    y->setLeft(z);
  } else {
    y->setRight(z);
  }
}



/**
 * @brief Reemplaza el subarbol en u por el subarbol en v
 * @param u nodo a reemplazar
 * @param v nodo que reemplaza
 */
template <typename DataType>
void BSTree<DataType>::transplant(BSTreeNode<DataType>* u, BSTreeNode<DataType>* v) {
  if (u == nullptr){
    return;
  }

  if (u->getParent() == nullptr) {
    this->root = v;
  } else if ((u->getParent())->getLeft() == u) {
    (u->getParent())->setLeft(v);
  } else {
    (u->getParent())->setRight(v);
  }

  if (v != nullptr){
    v->setParent(u->getParent());
  }
  
}

/**
 * @brief Elimina un valor del arbol binario
 * @param value Valor a eliminar
 */
template <typename DataType>
void BSTree<DataType>::remove(const DataType &value) {
  BSTreeNode<DataType>* z = this->search(this->root, value);

  BSTreeNode<DataType>* y;


  if (z == nullptr){
    return;
  }

  if (z->getLeft() == nullptr) {
    this->transplant(z, z->getRight());
  } else if (z->getRight() == nullptr) {

    this->transplant(z, z->getLeft());

  } else {
    y = this->getMinimum(z->getRight());

    if (y != z->getRight()) {
      this->transplant(y, y->getRight());
      y->setRight(z->getRight());

      y->getRight()->setParent(y);
    }

    this->transplant(z, y);

    y->setLeft(z->getLeft());

    y->getLeft()->setParent(y);
  }

  z->left = nullptr;
  z->right = nullptr;

  delete z;

}

/**
 * @brief Recorre el arbol en inorden e imprime los valores
 * @param rootOfSubtree raíz del subarbol
 */
template <typename DataType>
void BSTree<DataType>::inorderWalk(BSTreeNode<DataType> *rootOfSubtree) const {
  BSTreeNode<DataType>* actual = rootOfSubtree;

  while (actual != nullptr)
  {
    if (actual->getLeft() == nullptr) {
      std::cout << actual->getKey() << " ";
      actual = actual->getRight();

    } else {
      BSTreeNode<DataType>* predecesor = actual->getLeft();

      while (predecesor->getRight() != nullptr && predecesor ->getRight() != actual )
      {
        predecesor = predecesor->getRight();
      }

      if (predecesor->getRight() == NULL) {
        predecesor->setRight(actual);
        actual = actual->getLeft();
      } else {
        predecesor->setRight(nullptr);
        std::cout << actual->getKey() << " ";
        actual = actual->getRight();
      }
    }
  }
}




/**
 * @brief Busca un valor en un subarbol
 * @param rootOfSubtree raíz del subárbol
 * @param value valor a buscar
 * @return puntero al nodo que contiene value o nullptr si no existe
 */
template <typename DataType>
BSTreeNode<DataType>* BSTree<DataType>::search(const BSTreeNode<DataType> *rootOfSubtree,
  const DataType &value) const {

    const BSTreeNode<DataType>* x = rootOfSubtree;
    const DataType& k = value;

    while (x != nullptr)
    {
      if (x->key == k) {
        return const_cast<BSTreeNode<DataType>*>(x);
      } else if (k < x->key) {
        x = x->left;
      } else if (k > x->key) {
        x = x->right;
      }
    }

    return nullptr;
  }


/**
 * @brief Devuelve el nodo con el valor mínimo de un subárbol
 * @param rootOfSubtree raíz del subárbol
 * @return puntero al nodo con valor mínimo
 */
template <typename DataType>
BSTreeNode<DataType>* BSTree<DataType>::getMinimum(const BSTreeNode<DataType> *rootOfSubtree) const {
  const BSTreeNode<DataType>* x = rootOfSubtree;
  if (x == nullptr) {
    return const_cast<BSTreeNode<DataType>*>(x);
  }

  while (x->getLeft() != nullptr) {
    x = x->getLeft();
  }

  return const_cast<BSTreeNode<DataType>*>(x);

}


/**
 * @brief Devuelve el nodo con el valor máximo de un subárbol
 * @param rootOfSubtree raíz del subárbol
 * @return puntero al nodo con valor máximo
 */
template <typename DataType>
BSTreeNode<DataType>* BSTree<DataType>::getMaximum(const BSTreeNode<DataType> *rootOfSubtree) const {

  const BSTreeNode<DataType>* x = rootOfSubtree;
  if (x == nullptr) {
    return x;
  }

  while (x->getRight() != nullptr) {
    x = x->getRight();
  }

  return x;

}

/**
 * @brief Devuelve el sucesor de un nodo en inorden
 * @param node nodo del que se busca el sucesor
 * @return puntero al nodo sucesor o nullptr si no existe
 */

template <typename DataType>
BSTreeNode<DataType>* BSTree<DataType>::getSuccessor(const BSTreeNode<DataType> *node) const {
  const BSTreeNode<DataType>* x = node;

  if (x == nullptr) {
    return x;
  }

  if(x->getRight() != nullptr){
    return this->getMinimum(x->getRight());
  } else {
    const BSTreeNode<DataType>* y = x->getParent();

    while (y != nullptr && x == y->getRight())
    {
      x = y;
      y = y->getParent();
    }

    return y;
    
  }
}

/**
 * @brief Devuelve la raíz del árbol
 * @return puntero a la raíz
 */
template <typename DataType>
BSTreeNode<DataType>* BSTree<DataType>::getRoot() const {

  return this->root;

}

/**
 * @brief Inserta rápidamente valores consecutivos creando un árbol degenerado (lista)
 * @param n cantidad de valores a insertar
 */
template <typename DataType>
void BSTree<DataType>::fastInsert(size_t n) {
  

  this->insert(0);

  BSTreeNode<DataType>*it = this->root;
  
  for(size_t i = 1; i < n; i++) {
    it->right = new BSTreeNode<DataType>(i, it, nullptr, nullptr);
    it = it->right;
  }

}


/**
 * @brief Destructor iterativo del arbol binario
 */
template <typename DataType>
BSTree<DataType>::~BSTree() {
  BSTreeNode<DataType>* actual = this->root;

  BSTreeNode<DataType>* to_delete = nullptr;

  while (actual != nullptr)
  {
    if (actual->getLeft() == nullptr) {
      to_delete = actual;
      actual = actual->getRight();

      delete to_delete;

    } else {
      BSTreeNode<DataType>* predecesor = actual->getLeft();

      while (predecesor->getRight() != nullptr && predecesor ->getRight() != actual )
      {
        predecesor = predecesor->getRight();
      }

      if (predecesor->getRight() == NULL) {
        predecesor->setRight(actual);
        actual = actual->getLeft();
      } else {
        predecesor->setRight(nullptr);
        to_delete = actual;
        actual = actual->getRight();

        delete to_delete;
      }
    }
  }
}