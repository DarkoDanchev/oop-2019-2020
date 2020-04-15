#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
    T* data;
    size_t size;
    size_t capacity;
    void copy(const Vector& other)
    {
        this->size = other.size;
        this->capacity = other.capacity;
        this->data = new T[this->capacity];
        for(size_t i = 0; i < this->size; i++)
        {
            this->data[i] = other.data[i];
        }
    }
    void erase()
    {
        delete [] this->data;
    }
    void resize()
    {
        this->capacity *= 2;
        T* temp = new T[this->capacity];
        for(size_t i = 0; i < this->size; i++)
        {
            temp[i] = this->data[i];
        }
        this->erase();
        this->data = temp;
    }
public:
    Vector()
    {
        this->size = 0;
        this->capacity = 8;
        this->data = new T[this->capacity];
    }
    Vector(const Vector& other)
    {
        this->copy(other);
    }
    Vector& operator=(const Vector& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }
        
        return *this;
    }
    void add(T element)
    {
        if(this->size >= this->capacity)
        {
            this->resize();
        }
        this->data[this->size++] = element;
    }
    ~Vector()
    {
        this->erase();
    }
};