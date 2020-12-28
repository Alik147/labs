#pragma once

#include "Sequence.hpp"
#include "DynamicArray.hpp"

namespace sequence {
    template<typename T>
    class SequenceIterator {
    private:
        Sequence<T> *sequence;
        myarray::Array<T> arr;
    public:
        SequenceIterator(Sequence<T> *seq);

        typename myarray::Array<T>::ArrayIterator begin();

        typename myarray::Array<T>::ArrayIterator end();

        ~SequenceIterator();
    };

    template<typename T>
    SequenceIterator<T>::SequenceIterator(Sequence<T> *seq) {
        this->sequence = seq;
        for (unsigned int i = 0; i < this->sequence->length(); ++i) {
            this->arr.append((*this->sequence)[i]->getValue());
        }
    }

    template<typename T>
    typename myarray::Array<T>::ArrayIterator SequenceIterator<T>::begin() {
        return this->arr.begin();
    }

    template<typename T>
    typename myarray::Array<T>::ArrayIterator SequenceIterator<T>::end() {
        return this->arr.end();
    }


    template<typename T>
    SequenceIterator<T>::~SequenceIterator() = default;
}