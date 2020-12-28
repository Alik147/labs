#pragma once

#include "test_runner.h"
#include "BTreeDictionary.hpp"
#include "AVLTreeDictionary.hpp"
#include "SparseVector.hpp"

    void testBTreeDictionaryInsert() {
        dictionary::BTreeDictionary<int, int> tree(2, "ArraySequence", -1, -1);
        int key = std::rand() % 1000;
        int value = std::rand() % 1000;
        tree.insert(key, value);
        ASSERT_EQUAL(tree.get(key).getValue(), value)
    }

    void testBTreeDictionaryRemove() {
        dictionary::BTreeDictionary<int, int> tree(2, "ArraySequence", -1, -1);
        int key = std::rand() % 1000;
        int value = std::rand() % 1000;
        tree.insert(key, value);
        tree.remove(key);
        ASSERT(!tree.contains(key));
    }

    void testAVLTreeDictionaryInsert() {
        dictionary::AVLTreeDictionary<int, int> tree("ArraySequence", -1, -1);
        int key = std::rand() % 1000;
        int value = std::rand() % 1000;
        tree.insert(key, value);
        ASSERT_EQUAL(tree.get(key).getValue(), value)
    }

    void testAVLTreeDictionaryRemove() {
        dictionary::AVLTreeDictionary<int, int> tree("ArraySequence", -1, -1);
        int key = std::rand() % 1000;
        int value = std::rand() % 1000;
        tree.insert(key, value);
        tree.remove(key);
        ASSERT(!tree.contains(key));
    }
    void testSparseVectorAppend() {
        int mas[] = {0, 0, 0, 0, 2, 3, -13};
        myvector::SparseVector<int> vec("BTreeDictionary", "ArraySequence", 0);
        for (unsigned int i = 0; i < 7; ++i) {
            vec.append(mas[i]);
        }
        int check[7];
        for (size_t i = 0; i < 7; i++)
        {
            if (vec[i] != mas[i])
            {
                throw "ex";
            }
            
        }
    }

    void testSparseVectorSwap() {
        int mas1[] = {0, 0, 0, 0, 2, 3, -13};
        int mas2[] = {0, 0, 0, 2, 0, 3, -13};
        myvector::SparseVector<int> vec("BTreeDictionary", "ArraySequence", 0);
        for (unsigned int i = 0; i < 7; ++i) {
            vec.append(mas1[i]);
        }
        vec.swap(3, 4);
        for (unsigned int i = 0; i < 7; ++i) {
            if (vec[i] != mas2[i]) {
                throw "ex";
            }
        }
    }

    void testSparseVectorInsert() {
        int mas1[] = {0, 0, 0, 0, 2, 3, -13};
        int mas2[] = {0, 0, 0, 0, 1, 2, 3, -13};
        myvector::SparseVector<int> vec("BTreeDictionary", "ArraySequence", 0);
        for (unsigned int i = 0; i < 7; ++i) {
            vec.append(mas1[i]);
        }
        vec.insert(4, 1);
        for (unsigned int i = 0; i < 8; ++i) {
            if (vec[i] != mas2[i]) {
                throw "ex";
            }
        }
    }

    void startTests() {
        TestRunner tr;
        RUN_TEST(tr, testBTreeDictionaryInsert);
        RUN_TEST(tr, testBTreeDictionaryRemove);
        RUN_TEST(tr, testAVLTreeDictionaryInsert);
        RUN_TEST(tr, testAVLTreeDictionaryRemove);
        RUN_TEST(tr, testSparseVectorAppend);
        RUN_TEST(tr, testSparseVectorSwap);
        RUN_TEST(tr, testSparseVectorInsert);
    }