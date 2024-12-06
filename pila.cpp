#include <iostream>
template <typename T>


class Pila {
private:
    struct Nodo {
        T valore;       
        Nodo* next;     // Puntatore al nodo successivo
    };

    Nodo* topNodo;       // Puntatore al nodo in cima alla pila
    int lunghezzaPila;   // Numero di elementi nella pila

public:
    // Aggiunge un elemento alla pila
    void push(T elem) {
        Nodo* nuovo = new Nodo{elem, topNodo};
        topNodo = nuovo;
        lunghezzaPila++;
    }

    // Rimuove l'elemento in cima alla pila e lo restituisce
    T pop() {
        if (isEmpty()) {
            std::cout << "Errore: pila vuota. Impossibile eseguire pop." << std::endl;
            return T(); // Restituisce un valore di default
        }
        Nodo* temp = topNodo;
        T valore = temp->valore;
        topNodo = topNodo->next;
        delete temp;
        lunghezzaPila--;
        return valore;
    }

    // Restituisce l'elemento in cima alla pila senza rimuoverlo
    T top() const {
        if (isEmpty()) {
            std::cout << "Nessun elemento in cima." << std::endl;
            return T(); // Restituisce un valore di default
        }
        return topNodo->valore;
    }

    bool isEmpty() const {
        return lunghezzaPila == 0;
    }

    int size() const {
        return lunghezzaPila;
    }
};

// Esempio di utilizzo della classe Pila
int main() {
    Pila<int> pilaInteri;

    pilaInteri.push(10);
    pilaInteri.push(20);
    pilaInteri.push(30);

    std::cout << "Elemento in cima: " << pilaInteri.top() << std::endl; 
    std::cout << "Dimensione della pila: " << pilaInteri.size() << std::endl; 

    std::cout << "Pop: " << pilaInteri.pop() << std::endl; 
    std::cout << "Elemento in cima: " << pilaInteri.top() << std::endl; 
    std::cout << "Dimensione della pila: " << pilaInteri.size() << std::endl; 

    return 0;
}
