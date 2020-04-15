#pragma once

#include "Citizen.h"

class Country 
{
private: 
    Citizen* citizens;
    size_t size;
    size_t capacity;
    void copy(const Country& other)
    {
        this->size = other.size;
        this->capacity = other.capacity;
        this->citizens = new Citizen[this->capacity];
        for(size_t i = 0; i < this->size; i++)
        {
            this->citizens[i] = other.citizens[i];
        }
    }
    void erase()
    {
        delete [] this->citizens;
    }
    void resize()
    {
        this->capacity *= 2;
        Citizen* temp = new Citizen[this->capacity];
        for(size_t i = 0; i < this->size; i++)
        {
            temp[i] = this->citizens[i];
        }
        this->erase();
        this->citizens = temp;
    }
    
    void removeAtIndex(size_t index) 
    {
        if(index > 0 && index <= this->size)
        {
            for(size_t i = index; i < this->size - 1; i++)
            {
                this->citizens[i] = this->citizens[i + 1];
            }
            this->size--;
        }
    }
public:
    Country()
    {
        this->size = 0;
        this->capacity = 8;
        this->citizens = new Citizen[this->capacity];
    }
    Country(const Country& other)
    {
        this->copy(other);
    }
    Country& operator=(const Country& other)
    {
        if(this != &other) 
        {
            this->erase();
            this->copy(other);
        }
        
        return *this;
    }
    void addCitizen(const Citizen& citizen)
    {
        if(this->size >= this->capacity)
        {
            this->resize();
        }
        this->citizens[this->size++] = citizen;
    }
    void removeCitizen(const Citizen& other)
    {
        for(int i = 0; i < this->size; i++)
        {
            if(this->citizens[i] == other)
            {
                this->removeAtIndex(i);
            }
        }
    }
    Country& operator+=(const Country& other)
    {
        size_t newSize = this->size + other.size;
        this->capacity = this->capacity + other.capacity;
        Citizen* temp = new Citizen[this->capacity];
        for(size_t i = 0; i < this->size; i++)
        {
            temp[i] = this->citizens[i];
        }
        for(size_t i = this->size, k = 0; i < newSize; i++,k++)
        {
            temp[i] = other.citizens[k];
        }
        
        delete [] this->citizens;
        this->size = newSize;
        this->citizens = temp;
        
        return *this;
    }
    //a += b;
    Country operator+(const Country& other)
    {
        Country newCountry;
        newCountry += *this;
        newCountry += other;
        return newCountry;
    }
    //a + b (C)
    ~Country()
    {
        this->erase();
    }
};