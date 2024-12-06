#include <iostream>

template <typename T>
class Coda {
private:
    // Definizione della struttura del nodo
    struct Nodo {
        T valore;      // Valore del nodo
        Nodo* next;    // Puntatore al nodo successivo
    };

    Nodo* head;       // Puntatore alla testa della coda
    Nodo* tail;       // Puntatore alla fine della coda
    int lunghezza;    // Numero di elementi nella coda

public:

    // Distruttore per liberare la memoria
    Coda() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Aggiunge un elemento alla fine della coda
    void enqueue(T elem) {
        Nodo* nuovo = new Nodo{elem, NULL};
        if (isEmpty()) {
            head = tail = nuovo; // Se la coda è vuota, nuovo nodo è sia head che tail
        } else {
            tail->next = nuovo;
            tail = nuovo;
        }
        lunghezza++;
    }

    // Rimuove l'elemento in testa alla coda e lo restituisce
    T dequeue() {
        if (isEmpty()) {
            std::cout << "Coda vuota." << std::endl;
            return T(); // Restituisce un valore di default
        }
        Nodo* temp = head;
        T valore = temp->valore;
        head = head->next;
        delete temp;
    }

    // Restituisce l'elemento in testa alla coda senza rimuoverlo
    T front() const {
        if (isEmpty()) {
            std::cout << "Nessun elemento in testa." << std::endl;
            return T(); // Restituisce un valore di default
        }
        return head->valore;
    }

    bool isEmpty() const {
        return lunghezza == 0;
    }

    int size() const {
        return lunghezza;
    }
};

// Esempio di utilizzo della classe Coda
int main() {
    Coda<int> codaInteri;

    codaInteri.enqueue(10);
    codaInteri.enqueue(20);
    codaInteri.enqueue(30);

    std::cout << "Elemento in testa: " << codaInteri.front() << std::endl; 
    std::cout << "Dimensione della coda: " << codaInteri.size() << std::endl; 

    std::cout << "Dequeue: " << codaInteri.dequeue() << std::endl; 
    std::cout << "Elemento in testa: " << codaInteri.front() << std::endl; 
    std::cout << "Dimensione della coda: " << codaInteri.size() << std::endl; 

    return 0;
}
