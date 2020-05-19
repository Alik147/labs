#ifndef TRI_MATRIX
#define TRI_MATRIX
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "complex.hpp"
template<class T>
class TriangularMatrix
{
private:
	T** data;
	int size;
public:
	TriangularMatrix(){
		data = nullptr;
	}
	TriangularMatrix(T** data_ , int size_){
		this->size = size_;
		this->data = data_;
	}
	void print(){
		for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; ++j)
				{
					std::cout<<(data[i][j]);
					std::cout<<" ";
				}
				std::cout<<'\n';
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
					this->data[i][j] = this->data[i][j] + matrix.data[i][j];
				}
			}
		}
	}
	int getSize(){
		return this->size;
	}
	template<typename TT>
	void scalarMultiplication(TT scalar){
		for (int i = 0; i < this->size; i++)
			{
				for (int j = i; j < this->size; ++j)
				{
					this->data[i][j] = this->data[i][j]*scalar;
				}
			}
	}
	void fill() {
        for (int i = 0; i < this->size; i++)
			{
				for (int j = i; j < this->size; ++j)
				{
					std::cin>>this->data[i][j];
				}
			}
    }

	T norm_x() {
		T norm = 0,box = 0;
		for (int i = 0; i < this->size; i++)
			{
				box = 0;
				for (int j = i; j < this->size; ++j)
				{
					box = box + data[i][j];
				}
				if (box>norm)
				{
					norm = box;
				}
			}
		return norm;
	}
	T norm_y(){
		T norm = 0,box = 0;
		for (int i = 0; i < this->size; i++)
			{
				box = 0;
				for (int j = 0; j < this->size; ++j)
				{
					box = box + data[j][i];
				}
				if (box>norm)
				{
					norm = box;
				}
			}
		return norm;
	}
	T det() {
		T detA = 0;
		if (this->size>1){
			detA = data[0][0];
			for (int i = 1; i < this->size; ++i)
			{
				detA= detA*data[i][i];
			}
		}
		if (this->size == 1){
			detA = data[0][0];
		}
		return detA;
	}
};
#endif