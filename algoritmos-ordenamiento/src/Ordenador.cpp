#include "Ordenador.hpp"
#include <iostream>




void Ordenador::ordenamientoPorSeleccion(std::uint32_t *A, std::uint32_t n) const {
  for (uint32_t i = 0; i < n-1; i++ ) {
    uint32_t m = i;
    for (uint32_t j = i+1; j < n; j++){
      if (A[j] < A[m]){
        m = j;
      }
    }

    // swap (A[i], A[m])
    uint32_t tmp = A[i];
    A[i] = A[m];
    A[m] = tmp;
  }
}


void Ordenador::ordenamientoPorInserccion(std::uint32_t *A, std::uint32_t n) const{
  for (uint32_t i = 1; i < n; i++) {
    uint32_t key = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > key)
    {
      A[j+1] = A[j];
      j = j-1;
    }
    A[j+1] = key;
  }
}

void Ordenador::mergeSort(std::uint32_t* A, std::uint32_t p, std::uint32_t r) const{
  if (p >= r) {
    return;
  }
  uint32_t q;
  if ((p + r) % 2) {
    q =  (p + r - 1) / 2;
  } else {
    q =  (p + r) / 2;
  }
  this->mergeSort(A, p, q);
  this->mergeSort(A, q+1, r);
  this->merge(A, p, q, r);
  return;
}

void Ordenador::merge(std::uint32_t* A, std::uint32_t p, std::uint32_t q, std::uint32_t r) const{
  uint32_t nl = q - p + 1;
  uint32_t nr = r-q;
  uint32_t L[nl];
  uint32_t R[nr];

  for (uint32_t i = 0; i < nl; i++) {
    L[i] = A[p+i];
  }

  for (uint32_t j = 0; j < nr; j++) {
    R[j] = A[q+j+1];
  }

  uint32_t i = 0;
  uint32_t j = 0;
  uint32_t k = p;

  while (i < nl && j < nr)
  {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < nl)
  {
    A[k] = L[i];
    i++;
    k++;
  }

  while (j < nr)
  {
    A[k] = R[j];
    j++;
    k++;
  }

  return;
}

void Ordenador::ordenamientoPorMezcla(std::uint32_t *A, std::uint32_t n) const {
  this->mergeSort(A, 0, n-1);
  return;

}

void Ordenador::ordenamientoPorMonticulos(std::uint32_t *A, std::uint32_t n) const {
  std::uint32_t heap_size = n - 1;
  this->buildMaxHeap(A, n);

  for (int i = n-1; i >= 1; i--){
    std::uint32_t tmp = A[0];
    A[0] = A[i];
    A[i] = tmp;

    heap_size--;
    this->maxHeapify(A, heap_size, 0);
  }

  return;
}



void Ordenador::buildMaxHeap(std::uint32_t* A, std::uint32_t n) const{

  for (int i = (n-1)/2; i >= 0; i--) {
    this->maxHeapify(A, n-1, i);
  }

  return;
}


void Ordenador::maxHeapify(std::uint32_t* A, std::uint32_t n, std::uint32_t i) const{

  std::uint32_t left = 2*i;
  std::uint32_t right = (2*i) +1;
  std::uint32_t largest = 0;

  if (left <= n && A[left] > A[i]) {
    largest = left;
    
  } else { 
    largest = i;
  }

  if (right <= n && A[right] > A[largest]) {
    largest = right;
  }

  if (largest != i) {
    std::uint32_t tmp = A[i];
    A[i] = A[largest];
    A[largest] = tmp;
    this->maxHeapify(A, n, largest);
  }

  return;
}



std::int32_t Ordenador::partition (std::uint32_t* A, std::int32_t p, std::int32_t r ) const {
  std::uint32_t x = A[r];
  std::int32_t i = p - 1;

  for (int32_t j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      std::uint32_t tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }

  std::uint32_t tmp = A[i + 1];
  A[i+1] = A[r];
  A[r] = tmp;
  return (i + 1);
}


void Ordenador::quickSort(std::uint32_t* A, std::int32_t p, std::int32_t r ) const {
  if (p < r) {
    std::int32_t q = this->partition(A, p, r);
    this->quickSort(A, p, q - 1);
    this->quickSort(A, q + 1, r);
  }
  return;
}


void Ordenador::ordenamientoRapido(std::uint32_t *A, std::uint32_t n) const {
  this->quickSort(A, 0, n-1);
  return;
}

void Ordenador::countingSort(std::uint32_t* A, std::uint32_t n, std::uint32_t k, std::uint32_t d) const {

  std::uint32_t B[n];
  std::uint32_t C[k+1];

  for(std::uint32_t i = 0; i <= k; i++) {
    C[i] = 0;
  }

  for (std::uint32_t j = 0; j < n; j++) {
    C[(A[j] >> d) & k] = (C[(A[j] >> d) & k] + 1);
  }

  for (std::uint32_t i = 1; i <= k; i++) {
    C[i] = C[i] + C[i-1];
  }

  for (std::int32_t j = n-1; j >= 0; j--) {
    B[C[(A[j] >> d) & k] - 1] = A[j];
    C[(A[j] >> d) & k] = C[(A[j] >> d) & k] - 1;
  }

  for(std::uint32_t i = 0; i < n; i++){
    A[i] = B[i];
  }

  ;
  return; 
}


void Ordenador::radixSort(std::uint32_t* A, std::uint32_t n, std::uint32_t d) const {
  std::uint32_t bits_for_d = 32 / d;
  std::uint32_t k = 1;
  for(std::uint32_t j = 1; j <= bits_for_d; j++){
    k = k * 2;
  }
  k--;

  for(std::uint32_t i = 0; i < d; i++) {
    this->countingSort(A, n, k, i * bits_for_d);
  }
}


void Ordenador::ordenamientoPorResiduos(std::uint32_t *A, std::uint32_t n) const {
  this->radixSort(A, n, 8);
}