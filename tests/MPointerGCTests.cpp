#include <gtest/gtest.h>
#include "MPointerGC.h"
#include "MPointer.h"

// Test Fixture para MPointerGC
class MPointerGCTests : public ::testing::Test {
protected:
    void SetUp() override {
        gc = MPointerGC::getInstance();
        gc->initializeGC(1);
    }

    void TearDown() override {
        delete gc;
        gc = nullptr;
    }

    MPointerGC* gc;
};

// Test para la inicialización y obtención de instancia
TEST_F(MPointerGCTests, GetInstance) {
    EXPECT_NE(gc, nullptr);
}

// Test para la generación de IDs
TEST_F(MPointerGCTests, GenerateID) {
    int id1 = gc->generateID();
    int id2 = gc->generateID();
    EXPECT_EQ(id1, 0);
    EXPECT_EQ(id2, 1);
}

// Test para agregar y eliminar punteros
TEST_F(MPointerGCTests, AddAndDeletePointer) {
    MPointer<int> ptr1 = MPointer<int>::New();
    *ptr1 = 5;
    MPointer<int> ptr2 = MPointer<int>::New();
    *ptr2 = 10;
    gc->addPointer(&ptr1);
    gc->addPointer(&ptr2);
    gc->deletePointer(&ptr1);
    gc->deletePointer(&ptr2);
}

// Test para la funcionalidad del recolector de basura
TEST_F(MPointerGCTests, GarbageCollector) {
    MPointer<int> ptr1 = MPointer<int>::New();
    *ptr1 = 5;
    MPointer<int> ptr2 = MPointer<int>::New();
    *ptr2 = 10;
    gc->addPointer(&ptr1);
    gc->addPointer(&ptr2);
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

// Test para la impresión de direcciones de memoria
TEST_F(MPointerGCTests, AddressInMemory) {
    MPointer<int> ptr1 = MPointer<int>::New();
    *ptr1 = 5;
    MPointer<int> ptr2 = MPointer<int>::New();
    *ptr2 = 10;
    gc->addPointer(&ptr1);
    gc->addPointer(&ptr2);
    std::ostringstream output;
    std::streambuf* oldBuf = std::cout.rdbuf(output.rdbuf());
    gc->addressInMemory();
    std::cout.rdbuf(oldBuf);
    std::string result = output.str();
    EXPECT_NE(result.find("Pointer at memory address:"), std::string::npos);
}

// Prueba para el destructor de MPointerGC
TEST_F(MPointerGCTests, Destructor) {
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 5;
    gc->addPointer(&ptr);
    delete gc;
    gc = nullptr;
}
