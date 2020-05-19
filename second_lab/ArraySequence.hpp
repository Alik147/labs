#ifndef ARR_SEQUENCE
#define ARR_SEQUENCE

#include "Sequence.hpp"
#include "DynamicArray.hpp"
#include "complex.hpp"

template<class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> *arr;
public:
    ArraySequence(T *items, int count){
        this->arr = new DynamicArray<T>(items, count);
    }

    ArraySequence(){
        this->arr = new DynamicArray<T>();
    }

    ArraySequence(const ArraySequence<T> &list){
        T* data = new T[list.getLength()];
        for (int i = 0; i < list.getLength(); i++) {
            data[i] = list.get(i);
        }
        this->arr = new DynamicArray<T>(data, list.getLength());
    }

    void print() override{
        this->arr->print();
    }

    int getLength()  override{
        return this->arr->getSize();
    }

    T getFirst()  override{
        return this->arr->get(0);
    }

    T getLast()  override{
        return this->arr->get(this->getLength() - 1);
    }

    T get(const int i)  override{
        return this->arr->get(i);
    }

    Sequence<T> *getSubsequence(const int startIndex, const int endIndex) override{
         const int arraySize = endIndex - startIndex + 1;
         T* box = new T[arraySize];

         for (int i = startIndex; i <= endIndex; ++i)
         {
             box[i-startIndex] = this->arr->get(i);
         }
         return new ArraySequence(box, arraySize);
    }

    void append(T value) override{
        this->arr->Resize(this->getLength() + 1);
        this->arr->set(this->getLength() - 1, value);
    }

    void prepend(T value) override{
        this->arr->Resize(this->getLength() + 1);
        for (int i = this->getLength() - 1; i > 0; i--) {
            this->arr->set(i, this->arr->get(i - 1));
        }
        this->arr->set(0, value);
    }

    void insertAt(const int index, T value) override{
        this->arr->Resize(this->getLength() + 1);
        for (int i = this->getLength() - 2; i >= index; i--) {
            this->arr->set(i + 1, this->arr->get(i));
        }
        this->arr->set(index, value);
    }

    Sequence<T> *concat(Sequence<T> *list) override{
        const int arraySize = this->getLength() + list->getLength();
        T *box = new T[arraySize];
        int j = 0;

        for (int i = 0; i < this->getLength(); i++) {
            box[j] = this->arr->get(i);
            j++;
        }
        for (int i = 0; i < list->getLength(); i++) {
            box[j] = list->get(i);
            j++;
        }

        return new ArraySequence(box, arraySize);
    }

    void set(int index, T value) override{
        this->arr->set(index, value);
    }

    ~ArraySequence() = default;
};
#endif