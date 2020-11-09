#pragma once

#include "sorter.h"

template<typename T>
class heapsorter : public sorter<T> {
public:
    Sequence<T>* sort(Sequence<T>* seq, bool (* cmp)(const T&, const T&)) override;

private:
    void heapify(Sequence<T>* seq, int n, int i, bool (* cmp)(const T&, const T&));

    void heapSort(Sequence<T>* seq, int n, bool (* cmp)(const T&, const T&));
};

template<typename T>
Sequence<T>* heapsorter<T>::sort(Sequence<T>* seq, bool (* cmp)(const T&, const T&)) {
    this->heapSort(seq, seq->getLength(), cmp);
    return seq;
}

template<typename T>
void heapsorter<T>::heapify(Sequence<T>* seq, int n, int i, bool (* cmp)(const T&, const T&)) {
    int extreme = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2;
    if (left < n && !cmp(seq->get(left), seq->get(extreme)))
        extreme = left;
    if (right < n && !cmp(seq->get(right), seq->get(extreme)))
        extreme = right;
    if (extreme != i) {
        this->swap(i, extreme, seq);
        this->heapify(seq, n, extreme, cmp);
    }
}

template<typename T>
void heapsorter<T>::heapSort(Sequence<T>* seq, int n, bool (* cmp)(const T&, const T&)) {
    for (int i = n / 2 - 1; i >= 0; i--)
        this->heapify(seq, n, i, cmp);

    for (int i = n - 1; i > 0; i--) {
        this->swap(0, i, seq);
        this->heapify(seq, i, 0, cmp);
    }
}