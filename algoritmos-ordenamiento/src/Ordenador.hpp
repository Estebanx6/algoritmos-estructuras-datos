#include <cstdint>
#pragma once

/*
Credits
Original template provided by:
- Prof. Arturo Camacho, ECCI - Universidad de Costa Rica
- Prof. Allan Berrocal, ECCI - Universidad de Costa Rica

Completed and adapted by:
- Esteban Cruz
*/

class Ordenador {
    private:
      /**
       * @brief Metodo auxiliar encargado de realizar el merge en el ordenamiento por mezcla
       * @param A Arreglo a ordenar.
       * @param p Inicio del arreglo.
       * @param q Pivote.
       * @param r Findal del arreglo.
       */
      void merge(std::uint32_t* A, std::uint32_t p, std::uint32_t q, std::uint32_t r) const;

      /**
       * @brief Metodo auxiliar recursivo del ordenamiento por mezcla
       * @param A Arreglo a ordenar.
       * @param p Inicio del arreglo.
       * @param r Findal del arreglo.
       */
      void mergeSort(std::uint32_t* A, std::uint32_t p, std::uint32_t r) const;

      /**
       * @brief Metodo auxiliar recursivo encargado de crear los sub monticulos maximos del arreglo
       * @param A Arreglo a ordenar.
       * @param n Tamaño del arreglo.
       * @param i Indice donde se iniciara el metodo.
       */
      void maxHeapify(std::uint32_t* A, std::uint32_t n, std::uint32_t i) const;

      /**
       * @brief Metodo auxiliar encargado de convertir el arreglo A en un monticulo maximo.
       * @param A Arreglo a ordenar.
       * @param n Tamaño del arreglo.
       */
      void buildMaxHeap(std::uint32_t* A, std::uint32_t n) const;

      /**
       * @brief Metodo auxiliar recursivo del ordenamiento rapido.
       * @param A Arreglo a ordenar.
       * @param p Inicio del arreglo.
       * @param r Final del arreglo.
       */
      void quickSort(std::uint32_t* A, std::int32_t p, std::int32_t r ) const;

      /**
       * @brief Metodo auxiliar del ordenamiento rapido, crea el pivote q.
       * @param A Arreglo a ordenar.
       * @param p Inicio del arreglo.
       * @param r Final del arreglo.
       * @return pivote de particion.
       */
      std::int32_t partition (std::uint32_t* A, std::int32_t p, std::int32_t r ) const;

      void radixSort(std::uint32_t* A, std::uint32_t n, std::uint32_t d) const;

      void countingSort(std::uint32_t* A, std::uint32_t n, std::uint32_t k, std::uint32_t d) const;
      



    public:
    Ordenador() = default;
    ~Ordenador() = default;
    /* Nota:
     - Si no planea implementar algunos de los métodos de ordenamiento, no los borre.
     - Simplemente déjelos con el cuerpo vacío para evitar errores de compilación, ya
       que se ejecutará el mismo main para todas las tareas.
     - Recuerde hacer uso de programación defensiva y documentar los métodos con formato Doxygen, por ejemplo.
     - No cambié la firma de los métodos de la clase Ordenador.
     - No lance excepciones para el manejo de errores.
       Ante un error, basta con que el método no modifique el arreglo original y que no cause la caída del programa.
    */ 
  
    void ordenamientoPorSeleccion(std::uint32_t *A, std::uint32_t n) const;
    void ordenamientoPorInserccion(std::uint32_t *A, std::uint32_t n) const;
    void ordenamientoPorMezcla(std::uint32_t *A, std::uint32_t n) const;
    void ordenamientoPorMonticulos(std::uint32_t *A, std::uint32_t n) const;
    void ordenamientoRapido(std::uint32_t *A, std::uint32_t n) const;
    void ordenamientoPorResiduos(std::uint32_t *A, std::uint32_t n) const;

    /**
     * @brief Retorna un std::string con los datos de la tarea.
     * 
     * Este método devuelve una cadena de texto que contiene el carné, nombre y tarea.
     * 
     * @return std::string Una cadena de texto con los datos de la tarea.
     */
    constexpr const char* imprimirDatosDeTarea() const {
      return "Carné: C0A123, Nombre: Esteban Cruz Castro, Tarea 1";
    } 
};
