#pragma once 

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class User
{
private:
    char* username;
    char* password;
    void copy(const User& other)
    {
        this->username = new char[strlen(other.username) + 1];
        this->password = new char[strlen(other.password) + 1];
        
        strcpy(this->username, other.username);
        strcpy(this->password, other.password);
    }
    void erase()
    {
        delete [] this->username;
        delete [] this->password;
    }
public:
    User() 
    {
        this->username = new char[1];
        this->password = new char[1];
        strcpy(this->username,"");
        strcpy(this->password,"");
    }
    User(const char* username, const char* password)
    {
        this->username = new char[strlen(username) + 1];
        this->password = new char[strlen(password) + 1];
        
        strcpy(this->username, username);
        strcpy(this->password, password);
    }
    User(const User& other)
    {
        this->copy(other);
    }
    User& operator=(const User& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }
        
        return *this;
    }
    
    void saveUser(ofstream& os)
    {
        if(os.is_open())
        {
            os<<strlen(this->username)<<" ";
            os<<this->username<<endl;
            os<<strlen(this->password)<<" ";
            os<<this->password<<endl;
        }
        else 
        {
            cout<<"Cannot open stream for saving user"<<endl;
        }
    }
    
    void readUser(ifstream& is)
    {
        if(is.is_open()) 
        {
            this->erase();
            int usernameLength = 0;
            int passwordLength = 0;
            is>>usernameLength;
            is.seekg(1,ios::cur);
            this->username = new char[usernameLength + 1];
            is.getline(this->username,usernameLength + 1);
            is>>passwordLength;
            is.seekg(1,ios::cur);
            this->password = new char[passwordLength + 1];
            is.getline(this->password, passwordLength + 1);
        }
    }
    
    ~User()
    {
        this->erase();
    }
    
    void print() const 
    {
        cout<<"Username: "<<this->username<<endl;
        cout<<"Password: "<<this->password<<endl;
    }
};