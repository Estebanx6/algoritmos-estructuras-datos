/*
Credits
Original template provided by:
- Prof. Arturo Camacho, ECCI - Universidad de Costa Rica
- Prof. Allan Berrocal, ECCI - Universidad de Costa Rica

Completed and adapted by:
- Esteban Cruz
*/

#pragma once

enum colors { RED, BLACK };

template <typename DataType>
class RBTree;

template <typename DataType>
class RBTreeNode {
 public:
  friend class RBTree<DataType>;

  RBTreeNode() = default;

  RBTreeNode(const DataType &value, RBTreeNode<DataType> *parent = nullptr,
             RBTreeNode<DataType> *left = nullptr,
             RBTreeNode<DataType> *right = nullptr, enum colors c = RED);

  ~RBTreeNode();

  DataType getKey() const;

  RBTreeNode<DataType> *getParent() const;

  RBTreeNode<DataType> *getLeft() const;

  RBTreeNode<DataType> *getRight() const;

  void setKey(DataType key);

  void setParent(RBTreeNode<DataType> *parent);

  void setLeft(RBTreeNode<DataType> *left);

  void setRight(RBTreeNode<DataType> *right);

  void setColor(enum colors newColor);

 private:
  DataType key;

  RBTreeNode<DataType> *parent;

  RBTreeNode<DataType> *left;

  RBTreeNode<DataType> *right;

  enum colors color;
};


template <typename DataType>
class RBTree {
 public:
  RBTree();

  ~RBTree() {
    deleteSubtree(this->root);
    delete this->nil;
    this->root = nullptr;
    this->nil = nullptr;
  }

  void insert(const DataType &value);

  void remove(const DataType &value);

  RBTreeNode<DataType> *search(const RBTreeNode<DataType> *rootOfSubtree,
                               const DataType &value) const;

  RBTreeNode<DataType> *getMinimum(
      const RBTreeNode<DataType> *rootOfSubtree) const;

  RBTreeNode<DataType> *getMaximum(
      const RBTreeNode<DataType> *rootOfSubtree) const;

  RBTreeNode<DataType> *getSuccessor(const RBTreeNode<DataType> *node) const;

  RBTreeNode<DataType> *getRoot() const;

  RBTreeNode<DataType> *getNil() const;



  private:
    void insertFixUp(RBTreeNode<DataType>* z);
    void leftRotate(RBTreeNode<DataType>* x);
    void rightRotate(RBTreeNode<DataType>* x);
    void transplant(RBTreeNode<DataType>* u, RBTreeNode<DataType>* v);
    void deleteFixUp(RBTreeNode<DataType>* x);
    void deleteSubtree(RBTreeNode<DataType>* r);



 private:
  RBTreeNode<DataType> *root;

  RBTreeNode<DataType> *nil;



};


#include "RedBlackTree.tpp"