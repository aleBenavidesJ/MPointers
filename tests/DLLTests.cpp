#include <gtest/gtest.h>
#include "DoublyLinkedList.h"

// Prueba de creación de una lista vacía
TEST(DoublyLinkedListTests, CreateEmptyList) {
    DoublyLinkedList<int> list;
    EXPECT_EQ(list.getHead(), nullptr);
    EXPECT_EQ(list.getTail(), nullptr);
}

// Prueba de la función append
TEST(DoublyLinkedListTests, AppendSingleNode) {
    DoublyLinkedList<int> list;
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 10;
    list.append(ptr);
    EXPECT_NE(list.getHead(), nullptr);
    EXPECT_NE(list.getTail(), nullptr);
    EXPECT_EQ(*list.getHead()->data, 10);
    EXPECT_EQ(*list.getTail()->data, 10);
}

// Prueba de añadir varios elementos
TEST(DoublyLinkedListTests, AppendMultipleNodes) {
    DoublyLinkedList<int> list;
    MPointer<int> ptr1 = MPointer<int>::New();
    MPointer<int> ptr2 = MPointer<int>::New();
    *ptr1 = 10;
    *ptr2 = 20;
    list.append(ptr1);
    list.append(ptr2);
    EXPECT_EQ(*list.getHead()->data, 10);
    EXPECT_EQ(*list.getTail()->data, 20);
    EXPECT_EQ(list.getHead()->next, list.getTail());
    EXPECT_EQ(list.getTail()->prev, list.getHead());
}

// Prueba de recorrer la lista hacia adelante
TEST(DoublyLinkedListTests, PrintForward) {
    DoublyLinkedList<int> list;
    MPointer<int> ptr1 = MPointer<int>::New();
    MPointer<int> ptr2 = MPointer<int>::New();
    *ptr1 = 10;
    *ptr2 = 20;
    list.append(ptr1);
    list.append(ptr2);
    testing::internal::CaptureStdout();
    list.printForward();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Value: 10"), std::string::npos);
    EXPECT_NE(output.find("Value: 20"), std::string::npos);
}

// Prueba de recorrer la lista hacia atrás
TEST(DoublyLinkedListTests, PrintBackward) {
    DoublyLinkedList<int> list;
    MPointer<int> ptr1 = MPointer<int>::New();
    MPointer<int> ptr2 = MPointer<int>::New();
    *ptr1 = 10;
    *ptr2 = 20;
    list.append(ptr1);
    list.append(ptr2);
    testing::internal::CaptureStdout();
    list.printBackward();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Value: 20"), std::string::npos);
    EXPECT_NE(output.find("Value: 10"), std::string::npos);
}

// Prueba de destrucción de la lista y liberación de memoria
TEST(DoublyLinkedListTests, DestructorTest) {
    DoublyLinkedList<int>* list = new DoublyLinkedList<int>();
    MPointer<int> ptr1 = MPointer<int>::New();
    *ptr1 = 10;
    list->append(ptr1);
    delete list;
}
