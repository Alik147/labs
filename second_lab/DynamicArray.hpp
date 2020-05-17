#ifndef DYN_ARRAY
#define DYN_ARRAY

template<class T>
class DynamicArray
{
private:
    T* data;
    int size;
public:
    DynamicArray(T* items, int count){
        this->data = new T[count];
        for (int i = 0; i < count; ++i)
        {
            this->data[i] = items[i];
        }
        this->size = count;
    }

    DynamicArray(int size){
        this->size = size;
        this->data = nullptr;
    }

    DynamicArray(const DynamicArray<T> &dynamicArray){
        this->size = dynamicArray.getSize();
        this->data = new T[size];
        for (int i = 0; i < size; ++i)
        {
            this->data[i] = dynamicArray.Get(i);
        }
    }


    T Get(int index){
        if (index<0 || index>=size)
        {
            std::cout<<"index out of range"<<std::endl;
            return 0;
        }
        return this->data[index];
    }

    int getSize(){
        return this->size;
    }

    void Set(int index,T value){
        if (index<0 || index>=size)
        {
           std::cout<<"index out of range"<<std::endl;
        }    else {
            data[index] = value;
        }        
    }
    void Resize(int newSize){
        T* box[newSize] = {};
        int i = newSize > size ? size : newSize;
        for (int j = 0; j < i; ++j)
        {
           box[j]=data[j];
        }
        delete[] data;
        this->data = box;
    }
    void print() {
        for (int i = 0; i < this->size; i++) {
        std::cout << this->data[i] << " ";
        }
    }
    ~DynamicArray(){
        delete[] this->data;
    }
};
#endif