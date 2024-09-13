#include <gtest/gtest.h>
#include "MPointer.h"

// Clase base para pruebas
class MPointerTest : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};

// Prueba para el constructor por defecto y los constructores de copia
TEST_F(MPointerTest, DefaultConstructor) {
    MPointer<int> ptr;
    EXPECT_EQ(ptr.getID(), 1);
    EXPECT_EQ(ptr.getRefCount(), 1);
    EXPECT_EQ(ptr, nullptr);
}

TEST_F(MPointerTest, NullptrConstructor) {
    MPointer<int> ptr(nullptr);
    EXPECT_EQ(ptr.getID(), 2);
    EXPECT_EQ(ptr.getRefCount(), 1);
    EXPECT_EQ(ptr, nullptr);
}

TEST_F(MPointerTest, NewMethod) {
    MPointer<int> ptr = MPointer<int>::New();
    EXPECT_NE(ptr.getID(), 0);
    EXPECT_EQ(ptr.getRefCount(), 1);
    EXPECT_EQ(*ptr, 0);
}

TEST_F(MPointerTest, DereferenceAndAccess) {
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 99;
    EXPECT_EQ(*ptr, 99);
    EXPECT_EQ(ptr.getRefCount(), 1);
}

// Prueba para el operador de copia y asignación
TEST_F(MPointerTest, CopyConstructor) {
    MPointer<int> ptr1 = MPointer<int>::New();
    *ptr1 = 10;

    MPointer<int> ptr2 = ptr1;
    EXPECT_EQ(*ptr1, *ptr2);
    EXPECT_EQ(ptr1.getRefCount(), 2);
}

TEST_F(MPointerTest, CopyAssignment) {
    MPointer<int> ptr1 = MPointer<int>::New();
    *ptr1 = 10;

    MPointer<int> ptr2 = MPointer<int>::New();
    ptr2 = ptr1;
    EXPECT_EQ(*ptr1, *ptr2);
    EXPECT_EQ(ptr1.getRefCount(), 2);
    EXPECT_EQ(ptr2.getRefCount(), 2);
}

// Prueba para la asignación de valor
TEST_F(MPointerTest, AssignmentOperator) {
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 20;
    ptr = 99;
    EXPECT_EQ(*ptr, 99);
}

// Pruebas para operadores de comparación
TEST_F(MPointerTest, ComparisonOperators) {
    MPointer<int> ptr1 = MPointer<int>::New();
    MPointer<int> ptr2 = MPointer<int>::New();

    *ptr1 = 10;
    *ptr2 = 10;

    EXPECT_EQ(ptr1, ptr2);
    EXPECT_FALSE(ptr1 != ptr2);

    *ptr2 = 20;
    EXPECT_NE(ptr1, ptr2);
}

// Pruebas para operadores de puntero
TEST_F(MPointerTest, PointerOperators) {
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 42;

    EXPECT_EQ(*ptr, 42);
}

// Pruebas para la función printPtr
TEST_F(MPointerTest, PrintPtr) {
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 55;

    testing::internal::CaptureStdout();
    ptr.printPtr();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("ID:"), std::string::npos);
    EXPECT_NE(output.find("Value: 55"), std::string::npos);
}

// Pruebas para el destructor
TEST_F(MPointerTest, Destructor) {
    {
        MPointer<int> ptr = MPointer<int>::New();
        *ptr = 123;
        EXPECT_EQ(ptr.getRefCount(), 1);
    }
}


