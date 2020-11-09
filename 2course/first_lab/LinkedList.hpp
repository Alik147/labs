#pragma once

template<class T>
class LinkedList {
public:
    typedef struct Element {
        T value;
        Element *next;
    } Element;
    Element *head;
    Element *tail;
public:
    LinkedList(T *items, int count){
        // this->head = new Element;
        // Element* ptr = this->head;
        // for (int i = 0; i < count-1; ++i)
        // {
        //     ptr->value = items[i];
        //     ptr->next = new Element;
        //     ptr = ptr->next;
        // }
        // ptr->value = items[count - 1];
        // ptr->next = nullptr;
        // this->tail = ptr;
        this->head = nullptr;
        this->tail = nullptr;
        // std::cout<<"items size "<< count << std::endl;
        for (size_t i = 0; i < count; i++)
        {
            // std::cout<<items[i]<<std::endl;
            this->append(items[i]);
            // std::cout<<"321"<<std::endl;
        }
        // std::cout<<"done"<<std::endl;
    }

    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }

    LinkedList(const LinkedList<T> &list){
        if (list.head == nullptr) {
        this->tail = nullptr;
        this->head = nullptr;
        }
        else{
            this->head = list->head;
            this->tail = list->tail;
            Element* ptr = this->head;
            int i = 0;
            while(ptr != this->tail)
            {
                ptr->value = list->get[i];
                ptr->next = new Element;
                ptr = ptr->next;
                i++;
            }
            ptr->value = list->get[i];
            ptr->next = nullptr;
        }
    }

    T getFirst(){
        return this->head->value;
    }

    T getLast(){
        return this->tail->value;
    }

    T get(int index){
        Element *ptr = this->head;

        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        return ptr->value;
    }

    LinkedList<T> *getSubList(int startIndex, int endIndex){
        const int subArraySize = endIndex - startIndex + 1;
        T *subArray = new T[subArraySize];
        Element *ptr = this->head;
        for (int i = 0; i < endIndex + 1; i++) {
            if (i >= startIndex) {
                subArray[i-startIndex] = ptr->value;
            }
            ptr = ptr->next;
        }
        return new LinkedList(subArray, subArraySize);
    }

    int getLength(){
        if (head == nullptr)
        {
            return 0;
        }
        
        int length = 1;
        Element *ptr = this->head;
        while (ptr->next != nullptr) {
            length++;
            ptr = ptr->next;
        }
        return length;
    }
    
    void append(T item){
        Element* newElem = new Element;
        newElem->value = item;
        newElem->next = nullptr;
        if (this->getLength() == 0)
        {
            this->head = new Element;
            // std::cout<<newElem->value<<endl;
            this->head = newElem;
            this->tail = this->head;
            // std::cout<<"ASDASD"<<endl;
            return;
        }

        this->tail->next = new Element;
        this->tail->next = newElem;
        this->tail = this->tail->next;
        
        // this->tail->next = new Element;
        // this->tail = this->tail->next;
        // this->tail->next = nullptr;
        // this->tail->value = item;
        
    }

    void prepend(T item){
        Element *box;
        box->next = this->head;
        this->head = box;
        this->head->value = item;
    }

    void set(int index, T value){
        Element *ptr = this->head;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        ptr->value = value;
    }

    void insertAt(int index, T item){
        Element *newElem = new Element;
        newElem->value = item;
        if (this->head != nullptr) {
            if (this->head->next != nullptr) {
                Element *temp1 = this->head, *temp2 = this->head->next;
                for (int i = 0; i < index - 1; i++) {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
                temp1->next = newElem;
                newElem->next = temp2;
            } else {
                this->prepend(item);
            }
        } else {
            newElem->next = nullptr;
            this->head = newElem;
        }
    }

    LinkedList<T> *concat(LinkedList<T> *list){
        Element *temp = this->head;
        T *elemArray = new T[this->getLength() + list->getLength()];
        int i = 0;
        while (temp != nullptr) {
            elemArray[i] = temp->value;
            i++;
            temp = temp->next;
        }
        temp = list->head;
        while (temp != nullptr) {
            elemArray[i] = temp->value;
            i++;
            temp = temp->next;
        }

        return new LinkedList(elemArray, this->getLength() + list->getLength());
    }

    void deleteEllement (std::function<bool(T item)> func) {
        Element* ptr = this->head;
        Element* help = ptr;
        while (func(head->value))
        {
            this->head = this->head->next;
            ptr = this->head;
        }
        while (ptr != nullptr) {
            if (func(ptr->value))
            {
                help->next = ptr->next;
                help = ptr;
            }
            help = ptr;
            ptr = ptr->next;
            }
    }

    void print(){
        if (this->head != nullptr) {
            Element *temp = this->head;
            while (temp != nullptr) {
                std::cout << temp->value << " ";
                temp = temp->next;
            }
        } else {
            std::cout << "Empty list!\n";
        }
        std::cout<<"\n";
    }

    ~LinkedList() = default;
};