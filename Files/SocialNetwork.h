#pragma once
#include "User.h"

class SocialNetwork
{
private: 
    User* users;
    size_t size;
    size_t capacity;
    void copy(const SocialNetwork& other)
    {
        this->size = other.size;
        this->capacity = other.capacity;
        this->users = new User[this->capacity];
        for(size_t i = 0; i < this->size; i++)
        {
            this->users[i] = other.users[i];
        }
    }
    void erase() 
    {
        delete [] this->users;
    }
    void resize()
    {
        this->capacity *= 2;
        User* temp = new User[this->capacity];
        for(size_t i = 0; i < this->size; i++)
        {
            temp[i] = this->users[i];
        }
        this->erase();
        this->users = temp;
    }
public: 
    SocialNetwork()
    {
        this->size = 0;
        this->capacity = 8;
        this->users = new User[this->capacity];
    }
    
    SocialNetwork(const SocialNetwork& other)
    {
        this->copy(other);
    }
    
    SocialNetwork& operator=(const SocialNetwork& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }
        
        return *this;
    }
    
    void add(User user)
    {
        if(this->size >= this->capacity)
        {
            this->resize();
        }
        this->users[this->size++] = user;
    }
    
    void saveUsers(ofstream& out)
    {
        if(out.is_open()) 
        {
            out<<this->size<<endl;
            for(size_t i = 0; i < this->size; i++)
            {
                this->users[i].saveUser(out);
            }  
        }

    }
    
    void readUsers(ifstream& in)
    {
        int size = 0;
        in>>size;
        for(int i = 0; i < size; i++)
        {
            User user;
            user.readUser(in);
            this->add(user);
        }
    }
    
    /*
    void deleteUser(ofstream& os) 
    {
        //...
        saveUsers(os);
    }
    */
    ~SocialNetwork()
    {
        this->erase();
    }
    
    void print() const 
    {
        for(int i = 0; i < this->size; i++)
        {
            this->users[i].print();
        }
    }
    
};