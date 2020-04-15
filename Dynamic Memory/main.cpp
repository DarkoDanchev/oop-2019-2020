#include "User.h"
#include "Pair.h"
#include "String.h"
#include "Planet.h"

void func1()
{
    Planet p1;
}

template<typename T>
void print(T element)
{
    //...this prints element
}

void print(int element)
{
    
}
int main()
{
    User test;
    User user = User("darko","darko","darko@mail.com");
    User user2("danchev","darko","custmail@mail.com");
    const char* result = test.logIn("default","default");
    
    test.setUserData("test1","test","test@gmail.com");
    
    test.setUserData("test","TeSt123","test@gmail.com");
       
    cout<<result<<endl;
    
    Pair<int,int> firstPair = Pair<int,int>(5,5);
    
    cout<<firstPair.getKey()<<endl;
    
    String str1("abcd");
    cout<<str1.getValue()<<endl;
    str1.setValue("1234");
    cout<<str1.getValue()<<endl;
    
    String str2("5678");
    
    String str3 = String("abcdfg");
                  //String temp("abcdfg")
                  //String str3(temp);
                  //temp
    String temp("abcd");
    int a = 5;
    print(a);
    //String str3(temp);
    //temp dies
    
    //func1();
    //funct
    //....
    //....
    
        
	return 0;
}

