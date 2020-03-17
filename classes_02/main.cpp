#include "User.h"
#include "Pair.h"

int main()
{
    User test;
    User user = User("darko","darko","darko@mail.com");
    User user2("danchev","darko","custmail@mail.com");
    //user.createUser("darko","darko","darko@mail.com");
    const char* result = test.logIn("default","default");
    
    test.setUserData("test1","test","test@gmail.com");
    
    test.setUserData("test","TeSt123","test@gmail.com");
       
    cout<<result<<endl;
    
    Pair<int,int> firstPair = Pair<int,int>(5,5);
    
    cout<<firstPair.getKey()<<endl;
        
	return 0;
}

