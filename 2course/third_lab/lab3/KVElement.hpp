#pragma once

#include "Optional.hpp"
#include <stdexcept>

namespace dictionary {
    template<typename K, typename V>
    class KVElement{
    private:
        V value;
        bool hasValue;
        K key;
        bool hasKey;
    public:
        KVElement();

        KVElement(K key, V value);

        KVElement(const KVElement<K, V> &kvEl);

        void setValue(V value);

        void setKey(K key);

        void setKV(K key, V value);

        V &getValue();

        K getKey();

        bool checkValue();

        bool checkKey();

        KVElement<K, V> &operator=(const KVElement<K, V> &kvEl);

        KVElement<K, V> &operator=(V value);

        bool operator==(const KVElement<K, V> &kvEl);

        bool operator!=(const KVElement<K, V> &kvEl);

        bool operator<=(const KVElement<K, V> &kvEl);

        bool operator>(const KVElement<K, V> &kvEl);

        bool operator>=(const KVElement<K, V> &kvEl);

        bool operator<(const KVElement<K, V> &kvEl);

       template<typename K1, typename V1> friend std::ostream& operator<< (std::ostream &out, KVElement<K1, V1> &kvEl);
    };

    template<typename K, typename V>
    KVElement<K, V>::KVElement() {
        this->hasValue = false;
        this->hasKey = false;
    }

    template<typename K, typename V>
    KVElement<K, V>::KVElement(K key, V value){
        this->value = value;
        this->hasValue = true;
        this->key = key;
        this->hasKey = true;
    }

    template<typename K, typename V>
    KVElement<K, V>::KVElement(const KVElement<K, V> &kvEl) {
        this->key = kvEl.key;
        this->value = kvEl.value;
        this->hasValue = kvEl.hasValue;
        this->hasKey = kvEl.hasKey;
    }

    template<typename K, typename V>
    void KVElement<K, V>::setValue(V value) {
        this->value = value;
        this->hasValue = true;
    }

    template<typename K, typename V>
    void KVElement<K, V>::setKey(K key) {
        this->key = key;
        this->hasKey = true;
    }

    template<typename K, typename V>
    V &KVElement<K, V>::getValue() {
        if (this->hasValue) {
            return this->value;
        } else {
            throw std::out_of_range("..");
        }
    }

    template<typename K, typename V>
    K KVElement<K, V>::getKey() {
        if (this->hasKey) {
            return this->key;
        } else {
            throw std::out_of_range("..");
        }
    }

    template<typename K, typename V>
    bool KVElement<K, V>::checkValue() {
        return this->hasValue;
    }

    template<typename K, typename V>
    KVElement<K, V> &KVElement<K, V>::operator=(const KVElement<K, V> &kvEl) {
        if (this == &kvEl) {
            return *this;
        }
        this->hasValue = kvEl.hasValue;
        this->value = kvEl.value;
        this->key = kvEl.key;
        this->hasKey = kvEl.hasKey;
        return *this;
    }

    template<typename K, typename V>
    KVElement<K, V> &KVElement<K, V>::operator=(V value) {
        this->value = value;
        this->hasValue = true;
        return *this;
    }

    template<typename K, typename V>
    bool KVElement<K, V>::operator==(const KVElement<K, V> &kvEl) {
        if (kvEl.hasKey && this->hasKey) {
            return this->key == kvEl.key;
        } else {
            throw std::out_of_range("..");
        }
    }
    template<typename K, typename V>
    bool KVElement<K, V>::operator!=(const KVElement<K, V> &kvEl) {
        if (kvEl.hasKey && this->hasKey) {
            return !(this->key == kvEl.key);
        } else {
            throw std::out_of_range("..");
        }
    }

    template<typename K, typename V>
    bool KVElement<K, V>::operator<=(const KVElement<K, V> &kvEl) {
        if (kvEl.hasKey && this->hasKey) {
            return this->key <= kvEl.key;
        } else {
            throw std::out_of_range("..");
        }
    }

    template<typename K, typename V>
    bool KVElement<K, V>::operator<(const KVElement<K, V> &kvEl) {
        if (kvEl.hasKey && this->hasKey) {
            return this->key < kvEl.key;
        } else {
            throw std::out_of_range("..");
        }
    }

   template<typename K1, typename V1>
   std::ostream &operator<<(std::ostream &out, KVElement<K1, V1> &kvEl) {
       if (kvEl.hasValue && kvEl.hasKey) {
           out << kvEl.key << ": " << kvEl.value;
       } else {
           out << "null";
       }
       return out;
   }

    template<typename K, typename V>
    void KVElement<K, V>::setKV(K key, V value) {
        this->key = key;
        this->value = value;
        this->hasKey = true;
        this->hasValue = true;
    }

    template<typename K, typename V>
    bool KVElement<K, V>::checkKey() {
        return this->hasKey;
    }

    template<typename K, typename V>
    bool KVElement<K, V>::operator>(const KVElement<K, V> &kvEl) {
        if (kvEl.hasKey && this->hasKey) {
            return this->key > kvEl.key;
        } else {
            throw std::out_of_range("..");
        }
    }

    template<typename K, typename V>
    bool KVElement<K, V>::operator>=(const KVElement<K, V> &kvEl) {
        if (kvEl.hasKey && this->hasKey) {
            return this->key >= kvEl.key;
        } else {
            throw std::out_of_range("..");
        }
    }
}