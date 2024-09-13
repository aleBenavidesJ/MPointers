#include <gtest/gtest.h>
#include "Sorters.h"

// Prueba de QuickSort en una lista vacía
TEST(SortersTests, QuickSortEmptyList) {
    DoublyLinkedList<int> list;
    Sorters<int>::QuickSort(list);
    EXPECT_EQ(list.getHead(), nullptr);
    EXPECT_EQ(list.getTail(), nullptr);
}

// Prueba de QuickSort en una lista con un solo elemento
TEST(SortersTests, QuickSortSingleElement) {
    DoublyLinkedList<int> list;
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 10;
    list.append(ptr);
    Sorters<int>::QuickSort(list);
    EXPECT_EQ(*list.getHead()->data, 10);
    EXPECT_EQ(list.getTail(), list.getHead());
}

// Prueba de QuickSort con múltiples elementos
TEST(SortersTests, QuickSortMultipleElements) {
    DoublyLinkedList<int> list;
    MPointer<int> ptr1 = MPointer<int>::New();
    MPointer<int> ptr2 = MPointer<int>::New();
    MPointer<int> ptr3 = MPointer<int>::New();
    *ptr1 = 30;
    *ptr2 = 10;
    *ptr3 = 20;
    list.append(ptr1);
    list.append(ptr2);
    list.append(ptr3);
    Sorters<int>::QuickSort(list);
    EXPECT_EQ(*list.getHead()->data, 10);
    EXPECT_EQ(*list.getHead()->next->data, 20);
    EXPECT_EQ(*list.getTail()->data, 30);
}

// Prueba de BubbleSort con múltiples elementos
TEST(SortersTests, BubbleSortMultipleElements) {
    DoublyLinkedList<int> list;
    MPointer<int> ptr1 = MPointer<int>::New();
    MPointer<int> ptr2 = MPointer<int>::New();
    MPointer<int> ptr3 = MPointer<int>::New();
    *ptr1 = 20;
    *ptr2 = 30;
    *ptr3 = 10;
    list.append(ptr1);
    list.append(ptr2);
    list.append(ptr3);
    Sorters<int>::BubbleSort(list);
    EXPECT_EQ(*list.getHead()->data, 10);
    EXPECT_EQ(*list.getHead()->next->data, 20);
    EXPECT_EQ(*list.getTail()->data, 30);
}

// Prueba de InsertionSort con múltiples elementos
TEST(SortersTests, InsertionSortMultipleElements) {
    DoublyLinkedList<int> list;
    MPointer<int> ptr1 = MPointer<int>::New();
    MPointer<int> ptr2 = MPointer<int>::New();
    MPointer<int> ptr3 = MPointer<int>::New();
    *ptr1 = 30;
    *ptr2 = 20;
    *ptr3 = 10;
    list.append(ptr1);
    list.append(ptr2);
    list.append(ptr3);
    Sorters<int>::InsertionSort(list);
    EXPECT_EQ(*list.getHead()->data, 10);
    EXPECT_EQ(*list.getHead()->next->data, 20);
    EXPECT_EQ(*list.getTail()->data, 30);
}