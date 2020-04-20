#include <iostream>
#include <fstream>
#include "SocialNetwork.h"

using namespace std;

int main()
{
    /*fstream inputOutputStream("example.txt");
    ofstream outputStream("example.txt");
    if(outputStream.is_open()) {
        outputStream << "Hello world" << endl;
        outputStream << "Hello world1" << endl;
        outputStream << "Hello world2" << endl;

    } else {
        cout << "Cannot open file" << endl;
    }
    
    ifstream inputStream("example.txt");

    char line[256];
    inputStream.getline(line,256);
    cout<<line<<endl;*/
    
    ofstream outputStream("user.txt");
    ifstream inputStream("user.txt");
    
    //User darko("darko","darko");
    //darko.saveUser(outputStream);
    
    
    //darko.print();
    //userRead.print();
    SocialNetwork network;
    User darko("darko","darko");
    User darko1("darko1","darko");
    User darko2("darko2","darko");

    network.add(darko);
    network.add(darko1);
    network.add(darko2);
    network.saveUsers(outputStream);
    network.print();
    cout<<endl;
    SocialNetwork second;
    second.readUsers(inputStream);
    second.print();
    

    


	return 0;
}