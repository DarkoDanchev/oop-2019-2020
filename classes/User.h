#include <iostream>
#include <string>

using namespace std;

class User 
{
private:
    string username;
    string password;
    string email;
public:
    User(); 
    User(string username,string password,string email); 
    User(string username, string password); 
    void createUser(string username,string password,string email); 
    string logIn(string username,string password) const;
};
