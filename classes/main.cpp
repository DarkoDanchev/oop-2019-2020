#include "User.h"

int main()
{
    User test;
    User user = User("darko","darko","darko@mail.com");
    User user2("danchev","darko","custmail@mail.com");
    //user.createUser("darko","darko","darko@mail.com");
    string result = test.logIn("default","default");
    
    cout<<result<<endl;
	return 0;
}

