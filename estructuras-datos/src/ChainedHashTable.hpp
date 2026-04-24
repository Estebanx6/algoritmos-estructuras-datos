/*
 Credits
 Based on: Prof. Arturo Camacho, Universidad de Costa Rica
 Modified by: Prof. Allan Berrocal, Universidad de Costa Rica
 */

#pragma once
#include <cstdint>
#include <vector>

#include "DoublyLinkedList.hpp"

template <typename DataType>
class ChainedHashTable {
 public:
  ChainedHashTable(size_t size);

  ~ChainedHashTable();

  void insert(const DataType& value);

  int64_t search(const DataType& value) const;

  void remove(const DataType& value);

  size_t getSize() const;

 private:
  size_t size;
  size_t hash(const DataType& k) const;

  std::vector<DLList<DataType>> table;
};

#include "ChainedHashTable.tpp"
