#include <iostream>
#include "function.h"
using namespace std;

Matrix::Matrix(int s)
{
    this->size = s;
    this->matrix = new int*[this->size];
    for(int i = 0; i < this->size; i++)
    {
        this->matrix[i] = new int[this->size];
    }
    this->buf = new int[this->size];
}

Matrix::Matrix(const Matrix &a)
{
    this->size = a.size;
    this->matrix = new int*[this->size];
    for(int i = 0; i < this->size; i++)
    {
        this->matrix[i] = new int[this->size];
        for(int j = 0; j < this->size; j++)
        {
            this->matrix[i][j] = a.matrix[i][j];
        }
    }
    this->buf = new int[this->size];
}

Matrix &Matrix::operator=(const Matrix &a)
{
    this->size = a.size;
    for(int i = 0; i < a.size; i++)
    {
        for(int j = 0; j < a.size; j++)
        {
            this->matrix[i][j] = a.matrix[i][j];
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &output, const Matrix &a)
{
    for(int i = 0; i < a.size; i++)
    {
        for(int j = 0; j < a.size; j++)
        {
            output << a.matrix[i][j];
            if(j == a.size - 1)
                output << '\n';
            else
                output << ' ';
        }
    }
    return output;
}

std::istream &operator>>(std::istream &input, Matrix &a)
{
    for(int i = 0; i < a.size; i++)
    {
        for(int j = 0; j < a.size; j++)
        {
            input >> a.matrix[i][j];
        }
    }
    return input;
}
