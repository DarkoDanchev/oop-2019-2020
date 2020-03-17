#include "User.h"

User::User() 
{
    strcpy(this->username,"default");
    strcpy(this->password,"default");
    strcpy(this->email,"default@default.com");
}

User::User(const char* username,const char* password,const char* email) 
{
    strcpy(this->username,username);
    strcpy(this->password,password);
    strcpy(this->email,email);
}

User::User(const char* username,const char* password) 
{
    strcpy(this->username,username);
    strcpy(this->password,password);
    strcpy(this->email,strcat(this->username,"@mail.com"));
}

void User::createUser(const char* username,const char* password,const char* email)
{
    strcpy(this->username,username);
    strcpy(this->password,password);
    strcpy(this->email,email);
}

const char* User::logIn(const char* username,const char* password) const
{
    if(strcmp(this->username,username) == 0 && strcmp(this->password,password) == 0)  
    {
        return this->email;
    }
    else 
    {
        return "Wrong username or password";
    }
}

void User::setUserData(const char* username,const char* password,const char* email) 
{
    strcpy(this->username,username);
    strcpy(this->password,password);
    strcpy(this->email,email);  
}

const char* User::getUsername() const
{
    return this->username;
}
    
void User::setUsername(const char* username)
{
    strcpy(this->username,username);
}

const char* User::getPassword() const
{
    return this->password;
}
    
void User::setPassword(const char* password)
{
    strcpy(this->password,password);
}
    
const char* User::getEmail() const
{
    return this->email;
}

void User::setEmail(const char* email)
{
    strcpy(this->email,email);  
}