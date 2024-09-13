#ifndef SORTERS_H
#define SORTERS_H

#include "DoublyLinkedList.h"

template <typename T>
class Sorters {
public:
    static void QuickSort(DoublyLinkedList<T>& list);
    static void BubbleSort(DoublyLinkedList<T>& list);
    static void InsertionSort(DoublyLinkedList<T>& list);
    static void PrintList(const DoublyLinkedList<T>& list);

private:
    static void PrintListImpl(const DoublyLinkedList<T>& list);
    static void QuickSortRecursive(DoublyLinkedList<T>& list, typename DoublyLinkedList<T>::Node* low, typename DoublyLinkedList<T>::Node* high);
    static typename DoublyLinkedList<T>::Node* Partition(DoublyLinkedList<T>& list, typename DoublyLinkedList<T>::Node* low, typename DoublyLinkedList<T>::Node* high);
    //static void SwapNodes(typename DoublyLinkedList<T>::Node* a, typename DoublyLinkedList<T>::Node* b);
};

template <typename T>
typename DoublyLinkedList<T>::Node* Sorters<T>::Partition(DoublyLinkedList<T>& list, typename DoublyLinkedList<T>::Node* low, typename DoublyLinkedList<T>::Node* high) {
    T pivot = *high->data;  // Valor del pivote
    typename DoublyLinkedList<T>::Node* i = low->prev;

    for (typename DoublyLinkedList<T>::Node* j = low; j != high; j = j->next) {
        std::cout << "Comparing " << *j->data << " with pivot " << pivot << std::endl;
        if (*j->data < pivot) {  // Comparar valores
            i = (i == nullptr) ? low : i->next;
            // Intercambiar los valores
            T temp = *i->data;
            *i->data = *j->data;
            *j->data = temp;
            std::cout << "Swapped: " << *i->data << " with " << *j->data << std::endl;
        }
    }

    i = (i == nullptr) ? low : i->next;
    // Intercambiar el pivote con el valor en i
    T temp = *i->data;
    *i->data = *high->data;
    *high->data = temp;

    std::cout << "End of partition:" << std::endl;
    Sorters<T>::PrintList(list); // Imprimir lista para verificar estado actual después de la partición
    return i;
}

template <typename T>
void Sorters<T>::QuickSortRecursive(DoublyLinkedList<T>& list, typename DoublyLinkedList<T>::Node* low, typename DoublyLinkedList<T>::Node* high) {
    if (low && high && low != high && low != high->next) {
        std::cout << "QuickSortRecursive: Low = " << *low->data << ", High = " << *high->data << std::endl;
        typename DoublyLinkedList<T>::Node* p = Partition(list, low, high);
        std::cout << "Pivot after partition: " << *p->data << std::endl;
        QuickSortRecursive(list, low, p->prev);
        QuickSortRecursive(list, p->next, high);
    }
}

template <typename T>
void Sorters<T>::QuickSort(DoublyLinkedList<T>& list) {
    std::cout << "Lista antes de QuickSort:" << std::endl;
    PrintList(list);

    typename DoublyLinkedList<T>::Node* head = list.getHead();
    typename DoublyLinkedList<T>::Node* tail = list.getTail();
    QuickSortRecursive(list, head, tail);

    std::cout << "Lista después de QuickSort:" << std::endl;
    PrintList(list);
}

template <typename T>
void Sorters<T>::BubbleSort(DoublyLinkedList<T>& list) {
    std::cout << "Lista antes de BubbleSort:" << std::endl;
    PrintList(list);
    bool swapped;
    do {
        swapped = false;
        typename DoublyLinkedList<T>::Node* current = list.getHead();
        while (current && current->next) {
            if (*current->data > *current->next->data) {
                typename DoublyLinkedList<T>::Node* next = current->next;
                current->next = next->next;
                if (next->next) {
                    next->next->prev = current;
                }
                next->prev = current->prev;
                next->next = current;
                if (current->prev) {
                    current->prev->next = next;
                } else {
                    list.head = next;
                }
                current->prev = next;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
    std::cout << "Lista después de BubbleSort:" << std::endl;
    PrintList(list);
}

template <typename T>
void Sorters<T>::InsertionSort(DoublyLinkedList<T>& list) {
    std::cout << "Lista antes de InsertionSort:" << std::endl;
    PrintList(list);
    if (!list.getHead() || !list.getHead()->next) return;
    typename DoublyLinkedList<T>::Node* sorted = nullptr;
    typename DoublyLinkedList<T>::Node* current = list.getHead();
    while (current) {
        typename DoublyLinkedList<T>::Node* next = current->next;

        if (!sorted || *current->data < *sorted->data) {
            current->next = sorted;
            if (sorted) {
                sorted->prev = current;
            }
            current->prev = nullptr;
            sorted = current;
        } else {
            typename DoublyLinkedList<T>::Node* temp = sorted;
            while (temp->next && *temp->next->data < *current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next) {
                temp->next->prev = current;
            }
            temp->next = current;
            current->prev = temp;
        }
        current = next;
    }
    list.head = sorted;
    std::cout << "Lista después de InsertionSort:" << std::endl;
    PrintList(list);
}

template<typename T>
void Sorters<T>::PrintList(const DoublyLinkedList<T>& list) {
    PrintListImpl(list);
}

template <typename T>
void Sorters<T>::PrintListImpl(const DoublyLinkedList<T>& list) {
    typename DoublyLinkedList<T>::Node* current = list.getHead();
    while (current != nullptr) {
        std::cout << "Value: " << *current->data << std::endl;
        current = current->next;
    }
}

#endif //SORTERS_H
