#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

template<class T>
class Sequence {
public:
    virtual int getLength()  = 0;

    virtual T getFirst()  = 0;

    virtual T getLast()  = 0;

    virtual T get(const int i)  = 0;

    virtual Sequence<T> *getSubsequence(const int startIndex, const int endIndex)  = 0;

    virtual void append(T value) = 0;

    virtual void prepend(T value) = 0;

    virtual void set(int index, T value) = 0;

    virtual void insertAt(const int index, T value) = 0;

    virtual Sequence<T> *concat(Sequence<T> *list) = 0;

    virtual void print() = 0;
};

#endif