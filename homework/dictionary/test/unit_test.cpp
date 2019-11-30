#include "ArrayDictionary.h"
#include "gtest/gtest.h"

#define PRINT

TEST(dict, array_dict_basic) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(1, 2));
    ASSERT_EQ(hashTable.size(), 1);
    ASSERT_FALSE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(8, 4));
    ASSERT_EQ(hashTable.size(), 2);

    ASSERT_TRUE(hashTable.add(11, 4));
    ASSERT_EQ(hashTable.size(), 2);
#ifdef PRINT
    hashTable.print();
#endif
}

TEST(dict, array_dict_add_overwrite) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 2));
    ASSERT_TRUE(hashTable.add(2, 4));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.size(), 1);
}

TEST(dict, array_dict_value_set_size) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.valueSetSize(5), 0);
    ASSERT_EQ(hashTable.valueSetSize(2), 2);
    ASSERT_EQ(hashTable.valueSetSize(3), 1);
}

TEST(dict, array_dict_add_get) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    int val = 0;
    ASSERT_TRUE(hashTable.get(2, val));
    ASSERT_EQ(val, 9);
    ASSERT_TRUE(hashTable.get(12, val));
    ASSERT_EQ(val, 8);
    ASSERT_TRUE(hashTable.get(3, val));
    ASSERT_EQ(val, 4);
    ASSERT_FALSE(hashTable.get(7, val));
    ASSERT_EQ(val, 4);
}

TEST(dict, set1) {
    ArrayDictionary<int, int> table;
    ASSERT_FALSE(table.contain(-1));
    ASSERT_FALSE(table.contain(0));
    ASSERT_FALSE(table.contain(1));
}

TEST(dict, set2) {
    ArrayDictionary<int, int> table(1);
    table.add(0, 103);
    ASSERT_FALSE(table.contain(2));
    ASSERT_TRUE(table.contain(0));
}

TEST(dict, set3) {
    ArrayDictionary<int, int> table(2);
    table.add(0, 105);
    table.add(1, 105);
    ASSERT_TRUE(table.contain(0));
    ASSERT_TRUE(table.contain(1));
    ASSERT_FALSE(table.contain(2));
    ASSERT_FALSE(table.contain(3));
}

TEST(dict, set4) {
    ArrayDictionary<int, int> table(3);
    table.add(0, 105);
    table.add(1, 105);
    ASSERT_FALSE(table.contain(3));
    table.add(2, 206);
    ASSERT_TRUE(table.contain(1));
}

TEST(dict, set5) {
    ArrayDictionary<int, int> table(3);
    table.add(0, 103);
    table.add(1, 105);
    table.add(2, 206);
    table.add(4, 407);
    ASSERT_TRUE(table.contain(1));
    ASSERT_TRUE(table.contain(4));
    ASSERT_FALSE(table.contain(7));
    ASSERT_FALSE(table.contain(8));
}

TEST(dict, removeEmpty) {
    ArrayDictionary<int, int> table;
    ASSERT_FALSE(table.remove(0)); // placeholder
}

TEST(dict, removeKeyNoCollision) {
    ArrayDictionary<int, int> table(3);
    table.add(0, 100);
    table.add(1, 200);
    table.add(2, 500);
    ASSERT_TRUE(table.remove(0)); // placeholder
}

TEST(dict, removeKeyNotInDictionaryNoCollision) {
    ArrayDictionary<int, int> table(3);
    table.add(0, 100);
    table.add(1, 200);
    table.add(2, 500);
    ASSERT_FALSE(table.remove(4)); // placeholder
}

TEST(dict, removeKeyWithCollionKeyInCollision) {
    ArrayDictionary<int, int> table(3);
    table.add(0, 103);
    table.add(1, 105);
    table.add(2, 206);
    table.add(4, 407);
    ASSERT_TRUE(table.remove(0));
}

TEST(dict, removeNoKeyWithCollion) {
    ArrayDictionary<int, int> table(3);
    table.add(0, 103);
    table.add(1, 105);
    table.add(4, 407);
    ASSERT_FALSE(table.remove(2));
}
