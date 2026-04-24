#include "Ordenador.hpp"
#include <iostream>
#include <random>
#include <chrono>
#define n1k 1000
#define n10k 10000
#define n100k 100000
#define n1m 1000000

/**
 * @brief Macros para realizar pruebas.
 */
#define calls(arr, n, ns)   \
  std::cout << "Mezcla: n = " << ns << std::endl; \
    call(od, &Ordenador::ordenamientoPorMezcla, arr, n); \
  std::cout << "Monticulos: n = " << ns << std::endl; \
    call(od, &Ordenador::ordenamientoPorMonticulos, arr, n); \
  std::cout << "Rapido: n = " << ns << std::endl; \
    call(od, &Ordenador::ordenamientoRapido, arr, n); \
  std::cout << "Residuos: n = " << ns << std::endl; \
    call(od, &Ordenador::ordenamientoPorResiduos, arr, n); \
  std::cout << "Seleccion: n = " << ns << std::endl; \
    call(od, &Ordenador::ordenamientoPorSeleccion, arr, n); \
  std::cout << "Inserccion: n = " << ns << std::endl; \
    call(od, &Ordenador::ordenamientoPorInserccion, arr, n); \

#define calls2(nombre, puntero)   \
  std::cout << nombre << ": n = 1k" << std::endl; \
  call(od, puntero, arr1k, n1k); \
  std::cout << nombre << ": n = 10k" << std::endl; \
  call(od, puntero, arr10k, n10k); \
  std::cout << nombre << ": n = 100k" << std::endl; \
  call(od, puntero, arr100k, n100k); \
  std::cout << nombre << ": n = 1m" << std::endl; \
  call(od, puntero, arr1m, n1m); \

std::uint32_t* dupeArray(std::uint32_t* A, std::uint32_t n);
std::uint32_t* makeArray(std::uint32_t n);

/**
 * @brief Imprime el arreglo. 
 */
void printArray(std::uint32_t* A, std::uint32_t n);


/**
 * @brief Metodo que realiza las pruebas.
 */
void call(Ordenador& od, void (Ordenador::*metodo)(uint32_t*, uint32_t) const, uint32_t* A, uint32_t n);


int main () {


  Ordenador od;

  /**
   * Creamos arreglos aleatorios de 1k, 10k, 100k y 1m.
   */

  uint32_t* arr1k = makeArray(n1k);
  uint32_t* arr10k = makeArray(n10k);
  uint32_t* arr100k = makeArray(n100k);
  uint32_t* arr1m = makeArray(n1m);



  calls2("Mezcla", &Ordenador::ordenamientoPorMezcla)
  calls2("Monticulos", &Ordenador::ordenamientoPorMonticulos)
  calls2("Residuos", &Ordenador::ordenamientoPorResiduos)
  calls2("Rapido", &Ordenador::ordenamientoRapido)
  calls2("Inserccion", &Ordenador::ordenamientoPorInserccion)
  calls2("Seleccion", &Ordenador::ordenamientoPorSeleccion)


  delete[] arr1k;
  delete[] arr10k;
  delete[] arr100k;
  delete[] arr1m;

  return 0;
}

/**
 * @brief Duplica un arreglo.
 */
std::uint32_t* dupeArray(std::uint32_t* A, std::uint32_t n) {
  std::uint32_t* B = new uint32_t[n];
  for(std::uint32_t i = 0; i < n; i++) {
    B[i] = A[i];
  }
  return B;
}

/**
 * @brief Crea un arreglo.
 */
std::uint32_t* makeArray(std::uint32_t n) {
  std::uint32_t* A = new uint32_t[n];
  for(std::uint32_t i = 0; i < n; i++) {
    A[i] = random() % 1000;
  }
  return A;
}

void printArray(std::uint32_t* A, std::uint32_t n) {
  std::cout << "[";
  for(std::uint32_t i = 0; i < n-1; i++){
    std::cout << A[i] << ", ";
  }

  std::cout << A[n-1];
  std::cout << "]" << std::endl;
}



void call(Ordenador& od, void (Ordenador::*metodo)(uint32_t*, uint32_t) const, uint32_t* A, uint32_t n) {
  size_t total = 0;
  for(int i = 1; i < 4; i++){
    uint32_t* b = dupeArray(A, n);
    auto start = std::chrono::high_resolution_clock::now();
    (od.*metodo)(b, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start);
    total += duration.count();
    std::cout << "\t" << i << ": " << duration.count() << "µs" << std::endl;
    delete[] b;
  }

  std::cout << "\tpromedio: " << total / 3 << std::endl;
}



