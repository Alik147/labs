#ifndef TRI_MATRIX
#define TRI_MATRIX
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "complex.hpp"
#include <cmath>
template<class T>
class TriangularMatrix
{
private:
	Sequence<Sequence<T>*> *data;
	int size;
	bool listORarray;
public:
	TriangularMatrix(Sequence<T> **mat,int size, bool listORarray){
		this->listORarray = listORarray;
		this->size = size;
		if (listORarray)
		{
			this->data = new ArraySequence<Sequence<T>*>(mat,size);
		}
		if (!listORarray)
		{
			this->data = new LinkedListSequence<Sequence<T>*>(mat,size);
		}
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				this->data->get(i)->set(j, mat[i]->get(j));
			}
		}
	}
	void print(){
		for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; ++j)
				{
					std::cout<<(data->get(i)->get(j));
					std::cout<<" ";
				}
				std::cout<<'\n';
			}
	}
	template<class TT>
	void scalarMultiplication(TT scalar){
		for (int i = 0; i < this->size; i++)
			{
				for (int j = i; j < this->size; ++j)
				{
					this->data->get(i)->set(j,this->data->get(i)->get(j)*scalar);
				}
			}
	}
	void sum_with(TriangularMatrix<T> matrix){
		if (this->size != matrix.getSize())
		{
			std::cout<<"Size dif\n";
		} else{
			for (int i = 0; i < size; i++)
			{
				for (int j = i; j < size; ++j)
				{
					this->data->get(i)->set(j,this->data->get(i)->get(j) + matrix.data->get(i)->get(j));
				}
			}
		}
	}
	double norm() {
    	double Sum = 0;
	    for (int i = 0; i < this->size; i++) {
	        for (int j = 0; j < this->size; j++) {
	            Sum += this->data->get(i)->get(j) * this->data->get(i)->get(j);
	        }
	    }
	    return sqrt(Sum);
	}
	T det() {
		T detA = 0;
		if (this->size>1){
			detA = data->get(0)->get(0);
			for (int i = 1; i < this->size; ++i)
			{
				detA= detA*data->get(i)->get(i);
			}
		}
		if (this->size == 1){
			detA = data->get(0)->get(0);
		}
		return detA;
	}
	int getSize(){
		return this->size;
	}
	~TriangularMatrix() = default;
};
#endif