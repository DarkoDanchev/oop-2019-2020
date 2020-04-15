#pragma once

#include <cstring>

using namespace std;


class Citizen 
{
private: 
    char name[256];
    char* uuid;
    size_t age;
    bool gender;
    void copy(const Citizen& other)
    {
        strcpy(this->name,other.name);
        this->uuid = new char[strlen(other.uuid) + 1];
        strcpy(this->uuid,other.uuid);
        this->age = other.age;
        this->gender = other.gender;
    }
    void erase()
    {
        delete [] this->uuid;
    }
public: 
    Citizen()
    {
        strcpy(this->name,"");
        this->uuid = new char[1];
        strcpy(this->uuid, "");
        this->age = 0;
        this->gender = false;
    }
    Citizen(const char* name,const char* uuid, size_t age,
            bool gender)
    {
        strcpy(this->name,name);
        this->uuid = new char[strlen(uuid) + 1];
        strcpy(this->uuid,uuid);
        this->age = age;
        this->gender = gender;
    }
    Citizen(const Citizen& other)
    {
        this->copy(other);
    }
    Citizen& operator=(const Citizen& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }
        
        return *this;
    }
    bool operator==(const Citizen& other) const
    {
        /*if(strcmp(this->uuid,other.id) == 0)
        {
            return true;
        }
        else 
        {
            return false;
            
        }*/
        return strcmp(this->uuid,other.uuid) == 0;
    }
    bool operator!=(const Citizen& other) const
    {
        //return strcmp(this->uuid,other.uuid) != 0;
        return !((*this) == other);
    }
    void print() const
    {
        cout<<"Name: "<<this->name<<endl;
        cout<<"UUID: "<<this->uuid<<endl;
        cout<<"Age: "<<this->age<<endl;
        cout<<"Gender: "<<this->gender<<endl;
    }
    ~Citizen()
    {
        this->erase();
    }
};