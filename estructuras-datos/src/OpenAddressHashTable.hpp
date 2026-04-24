/*
Credits
Original template provided by:
- Prof. Arturo Camacho, ECCI - Universidad de Costa Rica
- Prof. Allan Berrocal, ECCI - Universidad de Costa Rica

Completed and adapted by:
- Esteban Cruz
*/


#pragma once
#include <cstdint>
#include <vector>

template <typename DataType>

class OpenAddressHashTable {
 public:
  OpenAddressHashTable(size_t size);

  ~OpenAddressHashTable();

  void insert(const DataType& value);

  int64_t search(const DataType& value) const;

  void remove(const DataType& value);

  size_t getSize() const;

 private:
  size_t size;
  size_t hast(const DataType& k) const;

  size_t len;

  std::vector<DataType> table;
};

#include "OpenAddressHashTable.tpp"
