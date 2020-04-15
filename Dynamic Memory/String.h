#pragma once

#include <iostream>

class String 
{
private:
    char* value;
    
    void copy(const String& other)
    {
        this->value = new char[strlen(other.value) + 1];
        strcpy(this->value,other.value);
    }
    void erase()
    {
        delete [] this->value;
    }
    //resize()
public:
    String()
    {
        this->value = new char[1];
        strcpy(this->value,"");
    }
    String(const char* value)
    {
        this->value = new char[strlen(value) + 1];
        strcpy(this->value,value);
    }
    String(const String& other)
    {
        this->copy(other);
    }
    void setValue(const char* value)
    {
        delete [] this->value;
        this->value = new char[strlen(value) + 1];
        strcpy(this->value,value);
    }
    
    String& operator=(const String& other)
    {
        if(this != &other) 
        {
            this->erase();
            this->copy(other);
        }
        return *this;
    }
    const char* getValue() const
    {
        return this->value;
    }
    ~String()
    {
       this->erase();
    }
};