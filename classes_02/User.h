#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class User 
{
private:
    char username[64];
    char password[32];
    char email[64];
public:
    User(); 
    User(const char* username,const char* password,const char* email); 
    User(const char* username,const char* password); 
    void createUser(const char* username,const char* password,const char* email);
    void setUserData(const char* username,const char* password,const char* email);
    const char* logIn(const char* username,const char* password) const;
    const char* getUsername() const;
    void setUsername(const char* username);
    const char* getPassword() const;
    void setPassword(const char* password);
    const char* getEmail() const;
    void setEmail(const char* email);
};
