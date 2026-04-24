#include "BinarySearchTree.hpp"
#include "ChainedHashTable.hpp"
#include "DoublyLinkedList.hpp"
#include "OpenAddressHashTable.hpp"
#include "RedBlackTree.hpp"
#include "SinglyLinkedList.hpp"


#include <random>
#include <iostream>
#include <chrono>
#include <omp.h>
#include <sstream>

#define SEED 465674

void datosLSE_random();
void datosLSE_orden();
void datosABB_orden();
void datosABB_random();

void datosARN_orden();
void datosARN_random();

void datosTDDA_orden();
void datosTDDA_random();

void datosTDE_orden();
void datosTDE_random();


void funciona();

int main () {

  datosLSE_random();
  datosLSE_orden();
  
  datosABB_orden();
  datosABB_random();

  datosARN_orden();
  datosARN_random();


  datosTDE_orden();
  datosTDE_random();

  datosTDDA_orden();
  datosTDDA_random();


  return 0;
}


void funciona() {
  
  std::cout << "funciona :D" << std::endl;
}

// LSE


void datosLSE_random() {


  std::cout << "LSE Random:" << std::endl;

  size_t n = 1000000;
  size_t n10 = n * 10; 
  size_t e = 10000;

  for(int i = 1; i <=3; i++) {

    SLList<size_t>* LSE = new SLList<size_t>();
    ChainedHashTable<size_t>* tabla_hash = new ChainedHashTable<size_t>(n);

    std::cout << "\tEjecucion#" << i << ":\n";

    // INSERTAR  

    for(size_t i = 0; i < n; i++) {

      // Generar número a insertar

      size_t k = random() % n10;

      while (tabla_hash->search(k) >= 0) { // Evitamos repetidos
        k = random() % n10;
      }
      tabla_hash->insert(k);
      LSE->insert(k);
    }

    // FIN INSERTAR

    // BUSCAR

    auto start = std::chrono::high_resolution_clock::now();

    for(size_t i = 0; i < e; i++) {

      // Generar número a buscar
      size_t k = random() % n10;;

      LSE->search(k);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tBuscar:" << duration.count() << "ms" << std::endl;

    // FIN Buscar

    // ELIMINAR

    start = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i < e; i++) {

      // Generar número a eliminar
      size_t k = random() % n10;;

      LSE->remove(k);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tELiminar:" << duration.count() << "ms" << std::endl << std::endl;
    delete LSE;
  }

  

  // FIN ELIMINAR
}


void datosLSE_orden() {


  std::cout << "LSE orden:" <<std::endl;

  size_t n = 1000000;
  size_t n10 = n * 10; 
  size_t e = 10000;


  for(int i = 1; i <=3; i++) {

    SLList<size_t>* LSE = new SLList<size_t>();

    std::cout << "\tEjecucion#" << i << ":\n";

    // INSERTAR  

    for(size_t i = 0; i < n; i++) {

      LSE->insert(i);
    }

    // FIN INSERTAR

    // BUSCAR

    auto start = std::chrono::high_resolution_clock::now();

    for(size_t i = 0; i < e; i++) {

      // Generar número a buscar
      size_t k = random() % n10;;

      LSE->search(k);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tBuscar:" << duration.count() << "ms" << std::endl;


    // FIN Buscar

    // ELIMINAR

    start = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i < e; i++) {

      // Generar número a eliminar
      size_t k = random() % n10;;

      LSE->remove(k);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tELiminar:" << duration.count() << "ms" << std::endl << std::endl;

    // FIN ELIMINAR

    delete LSE;

  }

  

}

// ABB

void datosABB_random() {


  std::cout << "ABB Random:" << std::endl;

  size_t n = 1000000;
  size_t n10 = n * 10; 
  size_t e = 10000;

  for(int i = 1; i <=3; i++) {

    BSTree<size_t>* ABB = new BSTree<size_t>();

    std::cout << "\tEjecucion#" << i << ":\n";

    // INSERTAR  

    for(size_t i = 0; i < n; i++) {

      // Generar número a insertar
      size_t k = random() % n10;;

      ABB->insert(k);
    }

    // FIN INSERTAR

    // BUSCAR

    auto start = std::chrono::high_resolution_clock::now();

    for(size_t i = 0; i < e; i++) {

      // Generar número a buscar
      size_t k = random() % n10;;

      ABB->search(ABB->getRoot(), k);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tBuscar:" << duration.count() << "ms" << std::endl;

    // FIN Buscar

    // ELIMINAR

    start = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i < e; i++) {

      // Generar número a eliminar
      size_t k = random() % n10;;

      ABB->remove(k);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tELiminar:" << duration.count() << "ms" << std::endl << std::endl;
    delete ABB;
  }

  

  // FIN ELIMINAR
}


void datosABB_orden() {





  std::cout << "ABB orden:" <<std::endl;

  size_t n = 1000000;
  size_t n10 = n * 10; 
  size_t e = 10000;


  for(int i = 1; i <=3; i++) {

    BSTree<size_t>* ABB = new BSTree<size_t>();

    std::cout << "\tEjecucion#" << i << ":\n";

    // INSERTAR  

   ABB->fastInsert(n);

    // FIN INSERTAR

    // BUSCAR

    auto start = std::chrono::high_resolution_clock::now();

    for(size_t i = 0; i < e; i++) {

      // Generar número a buscar
      size_t k = random() % n10;;

      ABB->search(ABB->getRoot(),k);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tBuscar:" << duration.count() << "ms" << std::endl;


    // FIN Buscar

    // ELIMINAR

    start = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i < e; i++) {

      // Generar número a eliminar
      size_t k = random() % n10;;

      ABB->remove(k);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tELiminar:" << duration.count() << "ms" << std::endl << std::endl;

    // FIN ELIMINAR

    delete ABB;

  }

  

}

// ARN


void datosARN_random() {


  std::cout << "ARN Random:" << std::endl;

  size_t n = 1000000;
  size_t n10 = n * 10; 
  size_t e = 10000;

  for(int i = 1; i <=3; i++) {

    RBTree<size_t>* ARN = new RBTree<size_t>();

    std::cout << "\tEjecucion#" << i << ":\n";

    // INSERTAR  

    for(size_t i = 0; i < n; i++) {

      // Generar número a insertar
      size_t k = random() % n10;;

      ARN->insert(k);
    }

    // FIN INSERTAR

    // BUSCAR

    auto start = std::chrono::high_resolution_clock::now();

    for(size_t i = 0; i < e; i++) {

      // Generar número a buscar
      size_t k = random() % n10;;

      ARN->search(ARN->getRoot(), k);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tBuscar:" << duration.count() << "ms" << std::endl;

    // FIN Buscar

    // ELIMINAR

    start = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i < e; i++) {

      // Generar número a eliminar
      size_t k = random() % n10;;

      ARN->remove(k);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tELiminar:" << duration.count() << "ms" << std::endl << std::endl;
    delete ARN;
  }

  

  // FIN ELIMINAR
}


void datosARN_orden() {





  std::cout << "ARN orden:" <<std::endl;

  size_t n = 1000000;
  size_t n10 = n * 10; 
  size_t e = 10000;


  for(int i = 1; i <=3; i++) {

    RBTree<size_t>* ARN = new RBTree<size_t>();

    std::cout << "\tEjecucion#" << i << ":\n";

    // INSERTAR  

    for(size_t i = 0; i < n; i++) {

      // Generar número a insertar
      size_t k = random() % n10;;

      ARN->insert(k);
    }

    // FIN INSERTAR

    // BUSCAR

    auto start = std::chrono::high_resolution_clock::now();

    for(size_t i = 0; i < e; i++) {

      // Generar número a buscar
      size_t k = random() % n10;;

      ARN->search(ARN->getRoot(),k);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tBuscar:" << duration.count() << "ms" << std::endl;


    // FIN Buscar

    // ELIMINAR

    start = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i < e; i++) {

      // Generar número a eliminar
      size_t k = random() % n10;;

      ARN->remove(k);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tELiminar:" << duration.count() << "ms" << std::endl << std::endl;

    // FIN ELIMINAR

    delete ARN;

  }

  

}



// TDE

void datosTDE_random() {


  std::cout << "TDE Random:" << std::endl;

  size_t m = 1048575;
  size_t n = 1000000;
  size_t n10 = n * 10; 
  size_t e = 10000;

  for(int i = 1; i <=3; i++) {

    
    ChainedHashTable<size_t>* TDE = new ChainedHashTable<size_t>(m);

    std::cout << "\tEjecucion#" << i << ":\n";

    // INSERTAR  

    for(size_t i = 0; i < n; i++) {

      // Generar número a insertar

      size_t k = random() % n10;

      while (TDE->search(k) >= 0) { // Evitamos repetidos
        k = random() % n10;
      }

      TDE->insert(k);
    }

    // FIN INSERTAR

    // BUSCAR

    auto start = std::chrono::high_resolution_clock::now();

    for(size_t i = 0; i < e; i++) {

      // Generar número a buscar
      size_t k = random() % n10;;

      TDE->search(k);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tBuscar:" << duration.count() << "ms" << std::endl;

    // FIN Buscar

    // ELIMINAR

    start = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i < e; i++) {

      // Generar número a eliminar
      size_t k = random() % n10;;

      TDE->remove(k);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tELiminar:" << duration.count() << "ms" << std::endl << std::endl;
    delete TDE;
  }

  

  // FIN ELIMINAR
}


void datosTDE_orden() {

  std::cout << "TDE orden:" <<std::endl;
  size_t m = 1048575;
  size_t n = 1000000;
  size_t n10 = n * 10; 
  size_t e = 10000;


  for(int i = 1; i <=3; i++) {

    ChainedHashTable<size_t>* TDE = new ChainedHashTable<size_t>(m);

    std::cout << "\tEjecucion#" << i << ":\n";

    // INSERTAR  

    for(size_t i = 0; i < n; i++) {

      TDE->insert(i);
    }

    // FIN INSERTAR

    // BUSCAR

    auto start = std::chrono::high_resolution_clock::now();

    for(size_t i = 0; i < e; i++) {

      // Generar número a buscar
      size_t k = random() % n10;;

      TDE->search(k);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tBuscar:" << duration.count() << "ms" << std::endl;


    // FIN Buscar

    // ELIMINAR

    start = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i < e; i++) {

      // Generar número a eliminar
      size_t k = random() % n10;;

      TDE->remove(k);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tELiminar:" << duration.count() << "ms" << std::endl << std::endl;

    // FIN ELIMINAR

    delete TDE;

  }


}



// TDE

void datosTDDA_random() {


  std::cout << "TDDA Random:" << std::endl;

  size_t m = 1048575;
  size_t n = 1000000;
  size_t n10 = n * 10; 
  size_t e = 10000;

  for(int i = 1; i <=3; i++) {

    
    OpenAddressHashTable<size_t>* TDDA = new OpenAddressHashTable<size_t>(m);

    std::cout << "\tEjecucion#" << i << ":\n";

    // INSERTAR  

    for(size_t i = 0; i < n; i++) {

      // Generar número a insertar

      size_t k = random() % n10;

      while (TDDA->search(k) >= 0) { // Evitamos repetidos
        k = random() % n10;
      }

      TDDA->insert(k);
    }

    // FIN INSERTAR

    // BUSCAR

    auto start = std::chrono::high_resolution_clock::now();

    for(size_t i = 0; i < e; i++) {

      // Generar número a buscar
      size_t k = random() % n10;;

      TDDA->search(k);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tBuscar:" << duration.count() << "ms" << std::endl;

    // FIN Buscar

    // ELIMINAR

    start = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i < e; i++) {

      // Generar número a eliminar
      size_t k = random() % n10;;

      TDDA->remove(k);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tELiminar:" << duration.count() << "ms" << std::endl << std::endl;
    delete TDDA;
  }

  

  // FIN ELIMINAR
}


void datosTDDA_orden() {

  std::cout << "TDDA orden:" <<std::endl;
  size_t m = 1048575;
  size_t n = 1000000;
  size_t n10 = n * 10; 
  size_t e = 10000;


  for(int i = 1; i <=3; i++) {

    OpenAddressHashTable<size_t>* TDDA = new OpenAddressHashTable<size_t>(m);

    std::cout << "\tEjecucion#" << i << ":\n";

    // INSERTAR  

    for(size_t i = 0; i < n; i++) {

      TDDA->insert(i);
    }

    // FIN INSERTAR

    // BUSCAR

    auto start = std::chrono::high_resolution_clock::now();

    for(size_t i = 0; i < e; i++) {

      // Generar número a buscar
      size_t k = random() % n10;;

      TDDA->search(k);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tBuscar:" << duration.count() << "ms" << std::endl;


    // FIN Buscar

    // ELIMINAR

    start = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i < e; i++) {

      // Generar número a eliminar
      size_t k = random() % n10;;

      TDDA->remove(k);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - start);

    std::cout << "\t\tELiminar:" << duration.count() << "ms" << std::endl << std::endl;

    // FIN ELIMINAR

    delete TDDA;

  }


}