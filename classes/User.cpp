#include "User.h"

User::User() 
{
    this->username = "default";
    this->password = "default";
    this->email = "default@default.com";
}
User::User(string username,string password,string email) 
{
    this->username = username;
    this->password = password;
    this->email = email;
}
User::User(string username, string password) 
{
    this->username = username;
    this->password = password;
    this->email = username + "@mail.com";
}
void User::createUser(string username,string password,string email)
{
    this->username = username;
    this->password = password;
    this->email = email;
}
string User::logIn(string username,string password) const
{
    if(this->username == username && this->password == password)  
    {
        return this->email;
    }
    else 
    {
        return "Wrong username or password";
    }
}