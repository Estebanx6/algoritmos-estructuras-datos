#include "RedBlackTree.hpp"


 // RBTreeNode<DataType>


 /**
  * @brief constructor por defecto del nodo del arbol rojinegro
  * @param value Valor del nodo
  * @param parent Nodo padre
  * @param left Nodo hijo izquierdo
  * @param right Nodo hijo derecho
  * @param colors color del nuevo nodo
  */
template <typename DataType>
RBTreeNode<DataType>::RBTreeNode(const DataType &value, RBTreeNode<DataType> *parent,
  RBTreeNode<DataType> *left , RBTreeNode<DataType> *right, enum colors c) 

: key(value)
, parent(parent)
, left(left)
, right(right)
, color(c) 
{}

/**
 * Destructor por defecto del nodo del arbol rojinegro
 */
template <typename DataType>
RBTreeNode<DataType>::~RBTreeNode() = default;


/**
 * @brief Getter del nodo padre.
 * @return puntero al nodo padre
 */
template <typename DataType>
RBTreeNode<DataType>* RBTreeNode<DataType>::getParent() const {
  return this->parent;

}

/**
 * @brief Getter del nodo hijo izquierdo.
 * @return puntero al nodo hijo izquierdo
 */
template <typename DataType>
RBTreeNode<DataType>* RBTreeNode<DataType>::getLeft() const {
  return this->left;

}


/**
 * @brief Getter del nodo hijo derecho.
 * @return puntero al nodo hijo derecho
 */
template <typename DataType>
  RBTreeNode<DataType>* RBTreeNode<DataType>::getRight() const {
    return this->right;
  }


/**
 * @brief Getter del key del nodo.
 * @return key del nodo
 */
template <typename DataType>
DataType RBTreeNode<DataType>::getKey() const {
  return this->key;
}



// RBTree

/**
 * @brief Inserta un valor en el arbol rojinegro
 * @param value Valor a insertar
 */
template <typename DataType>
void RBTree<DataType>::insert(const DataType &value) {



  RBTreeNode<DataType>* x = this->root;
  RBTreeNode<DataType>* y = this->nil;

  RBTreeNode<DataType>* z = new RBTreeNode<DataType>(value, this->nil, this->nil, this->nil, RED);

  while (x != this->nil) {
    y = x;

    if (y->key == z->key) { // evita repetidos
      delete z;
      return;
    }

    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  z->parent = y;

  if (y == this->nil) {
    this->root = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }

  z->left = this->nil;
  z->right = this->nil;
  z->color = RED;

  this->insertFixUp(z);

}

/**
 * @brief Vuelve a balancear el arbol despues de insertar un valor
 * @param z nodo desde el cual se inicia el fix
 */
template <typename DataType>
void RBTree<DataType>::insertFixUp(RBTreeNode<DataType>* z) {
  
  while (z->parent->color == RED) {
    if (z->parent == z->parent->parent->left) {
      RBTreeNode<DataType>* y = z->parent->parent->right;

      if (y->color == RED) {
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->right) {
          z = z->parent;
          this->leftRotate(z);
        }

        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        this->rightRotate(z->parent->parent);
      }
    } else {
      RBTreeNode<DataType>* y = z->parent->parent->left;

      if (y->color == RED) {
        z->parent->color = BLACK;
        y->parent->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->left) {
          z = z->parent;
          this->rightRotate(z);
        }

        z->parent->color = BLACK;
        z->parent->parent->color = RED;
      }
    }

  }

  this->root->color = BLACK;
}


/**
 * @brief Rota hacia la izquierda un nodo
 * @param x nodo desde el cual se hará la rotacion
 */
template <typename DataType>
void RBTree<DataType>::leftRotate(RBTreeNode<DataType>* x) {
  RBTreeNode<DataType>* y = x->right;
  x->right = y->left;

  if (y->left != this->nil) {
    y->left->parent = x;
  }

  y->parent = x->parent;

  if (x->parent == this->nil) {
    this->root = y;
  } else if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }

  y->left = x;
  x->parent = y;

}


/**
 * @brief Rota hacia la derecha un nodo
 * @param x nodo desde el cual se hará la rotacion
 */
template <typename DataType>
void  RBTree<DataType>::rightRotate(RBTreeNode<DataType>* x) {
  RBTreeNode<DataType>* y = x->left;

  x->left = y->right;


  if (y->right != this->nil) {
    y->right->parent = x;
  }

  y->parent = x->parent;

  if (x->parent == this->nil) {
    this->root = y;
  } else if (x == x->parent->right) {
    x->parent->right = y;
  } else {
    x->parent->left = y;
  }

  y->right = x;

  x->parent = y;

}


/**
 * @brief Reemplaza el subarbol en u por el subarbol en v
 * @param u nodo a reemplazar
 * @param v nodo que reemplaza
 */
template <typename DataType>
void RBTree<DataType>::transplant(RBTreeNode<DataType>* u, RBTreeNode<DataType>* v) {
  if (u == this->nil){
    return;
  }

  if (u->parent == this->nil) {
    this->root = v;
  } else if (u->parent->left == u) {
    u->parent->left = v;
  } else {
    u->parent->right = v;
  }

  if (v != this->nil){
    v->parent = u->parent;
  }
  
}

/**
 * @brief Elimina un valor del arbol binario
 * @param value Valor a eliminar
 */
template <typename DataType>
void  RBTree<DataType>::remove(const DataType &value) {
  RBTreeNode<DataType>* z = this->search(this->root, value);

  if (z == this->nil) {
    return;
  }
  RBTreeNode<DataType>* y = z;
  RBTreeNode<DataType>* x;


  enum colors y_original_color = y->color;

  if (z->left == this->nil) {
    x = z->right;

    this->transplant(z, z->right);
  } else if (z->right == this->nil) {
    x = z->left;
    this->transplant(z, z->left);
  } else {
    y = this->getMinimum(z->right);
    y_original_color = y->color;
    x = y->right;

    if (y != z->right) {
      this->transplant(y, y->right);
      y->right = z->right;
      y->right->parent = y;
    } else {
      x->parent = y;
    }

    this->transplant(z, y);
    y->left = z->left;
    y->left->parent = y;

    y->color = z->color;
  }

  if (y_original_color == BLACK) {
    this->deleteFixUp(x);
  }


  if (z != this->nil) {
      z->left = nullptr;
    z->right = nullptr;
    delete z;

  }  
}


/**
 * @brief Vuelve a balancear el arbol despues de remover un valor
 * @param z nodo desde el cual se inicia el fix
 */
template <typename DataType>
void RBTree<DataType>::deleteFixUp(RBTreeNode<DataType>* x) {

  
  RBTreeNode<DataType>* w;
  while (x != this->root && x->color == BLACK) {
    if (x == x->parent->left) {
      w = x->parent->right;
      if (w->color == RED) {
        w->color = BLACK;
        x->parent->color = RED;
        this->leftRotate(x->parent);
        w = x->parent->right;
      }

      if (w->left->color == BLACK && w->right->color == BLACK) {
        w->color = RED;
        x = x->parent;
      } else {
        if (w->right->color == BLACK) {
          w->left->color = BLACK;
          w->color = RED;
          this->rightRotate(w);
        }

        w->color = x->parent->color;
        x->parent->color = BLACK;

        w->right->color = BLACK;

        this->leftRotate(x->parent);
        x = this->root;
      }
    } else {
      w = x->parent->left;
      if (w->color == RED) {
        w->color = BLACK;
        x->parent->color = RED;
        this->rightRotate(x->parent);
        w = x->parent->left;
      }

      if (w->right->color == BLACK && w->left->color == BLACK) {
        w->color = RED;
        x = x->parent;
      } else {
        if (w->left->color == BLACK) {
          w->right->color = BLACK;
          w->color = RED;
          this->leftRotate(w);
          w = x->parent->left;
        }

        w->color = x->parent->color;
        x->parent->color = BLACK;
        w->left->color = BLACK;
        this->rightRotate(x->parent);
        x = this->root;
      }
    }
  }

  x->color = BLACK;
}


/**
 * @brief Busca un nodo a partir de un subarbol
 * @param rootOfSubtree puntero al nodo desde el cual se va a empezar a buscar
 * @return puntero al nodo. Nil si no está en el subarbol
 */
template <typename DataType>
RBTreeNode<DataType>* RBTree<DataType>::search(const RBTreeNode<DataType> *rootOfSubtree,
const DataType &value) const {

  const RBTreeNode<DataType>* x = rootOfSubtree;
  const DataType& k = value;

  while (x != this->nil)
  {
    if (x->key == k) {
      return const_cast<RBTreeNode<DataType>*>(x);
    } else if (k < x->key) {
      x = x->left;
    } else if (k > x->key) {
      x = x->right;
    }
  }

  return this->nil;

}

/**
 * @brief Busca el minimo de un subarbol
 * @param rootOfSubtree puntero al subarbol desde donde se empezará a buscar
 * @return puntero al nodo. Nil si no está en el subarbol
 */
template <typename DataType>
RBTreeNode<DataType>* RBTree<DataType>::getMinimum(const RBTreeNode<DataType> *rootOfSubtree) const {

  const RBTreeNode<DataType>* x = rootOfSubtree;

  if (x == this->nil) {
    return const_cast<RBTreeNode<DataType>*>(x);
  }

  while (x->getLeft() != this->nil) {
    x = x->getLeft();
  }

  return const_cast<RBTreeNode<DataType>*>(x);
  
}


/**
 * @brief Busca el maximo de un subarbol
 * @param rootOfSubtree puntero al subarbol desde donde se empezará a buscar
 * @return puntero al nodo. Nil si no está en el subarbol
 */
template <typename DataType>
RBTreeNode<DataType>* RBTree<DataType>::getMaximum(const RBTreeNode<DataType> *rootOfSubtree) const {

  const RBTreeNode<DataType>* x = rootOfSubtree;
  if (x == this->nil) {
    return const_cast<RBTreeNode<DataType>*>(x);
  }

  while (x->getRight() != this->nil) {
    x = x->getRight();
  }

  return const_cast<RBTreeNode<DataType>*>(x);
}

/**
 * @brief Busca  al sucesor de un nodo
 * @param rootOfSubtree puntero al nodo del cual se quiere el sucesor
 * @return puntero al nodo.
 */
template <typename DataType>
RBTreeNode<DataType>* RBTree<DataType>::getSuccessor(const RBTreeNode<DataType> *node) const {

  const RBTreeNode<DataType>* x = node;

  if (x == this->nil) {
    return x;
  }

  if(x->getRight() != this->nil){
    return this->getMinimum(x->getRight());
  } else {
    const RBTreeNode<DataType>* y = x->getParent();

    while (y != this->nil && x == y->getRight())
    {
      x = y;
      y = y->getParent();
    }

    return y;
    
  }

}

/**
 * @brief Metodo auxiliar para destruir un subarbol rojinegro.
 * @brief r raiz del subarbol a destruir
 */
template <typename DataType>
void RBTree<DataType>::deleteSubtree(RBTreeNode<DataType>* r) {

  if (r == nil) {
    return;
  }

  this->deleteSubtree(r->left);
  this->deleteSubtree(r->right);
  delete r;

}
/**
 * @brief retorna la raiz del arbol rojinegro
 * @return puntero a la raiz
 */
template <typename DataType>
RBTreeNode<DataType>* RBTree<DataType>::getRoot() const {
  return this->root;
}

/**
 * @brief Constructor por defecto del arbol rojinegro
 */
template <typename DataType>
RBTree<DataType>::RBTree() {

  this->nil = new RBTreeNode<DataType>();
  this->nil->parent = this->nil;
  this->nil->left = this->nil;
  this->nil->right = this->nil;
  this->nil->color = BLACK;
  this->root = this->nil;

}