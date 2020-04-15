#pragma once 

#include "Country.h"

class Planet 
{
private: 
    Country* countries;
    size_t size; 
    size_t capacity;
    void copy(const Planet& other)
    {
        this->size = other.size;
        this->capacity = other.capacity;
        this->countries = new Country[this->capacity];
        for(size_t i = 0; i < this->size; i++)
        {
            this->countries[i] = other.countries[i];
        }
    }
    void destroy()
    {
       delete [] this->countries; 
    }
    
    void resize() 
    {
        this->capacity *= 2;
        Country* temp = new Country[this->capacity];
        for(size_t i = 0; i < this->size; i++)
        {
            temp[i] = this->countries[i];
        }
        delete [] this->countries;
        this->countries = temp;
    }
public: 
    Planet()
    {
        this->size = 0;
        this->capacity = 16;
        this->countries = new Country[this->capacity];
    }
    Planet(const Planet& other)
    {
        this->copy(other);
    }
    Planet& operator=(const Planet& other)
    {
        if(this != &other)
        {
            this->destroy();
            this->copy(other);
        }
        
        return *this;
    }
    ~Planet()
    {
        this->destroy();
    }
    
    void addCountry(Country country) 
    {
        if(this->size >= this->capacity)
        {
            this->resize();
        }
        this->countries[this->size++] = country;
    }
};