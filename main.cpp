#include <iostream>
#include <fstream>
#include <sys/stat.h>
using namespace std;

class User {
public:
    string _name;
    string _login;
    string _pass;};

class Message {
public:
    string _text;
    string _sender;
    string _receiver;};

int main() {
    chmod("message.dat", S_IRUSR | S_IWUSR);
    User user;
    ifstream userFile("user.dat", ios::binary);

    if (userFile) {userFile.read((char*)&user, sizeof(User));
        userFile.close();}
    else {cerr << "Error opening user file" << endl;
        return 1;}

    ofstream userFO("user.dat", ios::binary);
    if (userFO) {userFO.write((char*)&user, sizeof(User));
        userFO.close();}
    else {cerr << "Error opening user file" << endl;
        return 1;}
    chmod("message.dat", S_IRUSR | S_IWUSR);

    Message message;
    ifstream messageFile("message.dat", ios::binary);

    if (messageFile) {messageFile.read((char*)&message, sizeof(Message));
        messageFile.close();}
    else {cerr << "Error opening message file" << endl;
        return 1;}

    ofstream messageFileOut("message.dat", ios::binary);
    if (messageFileOut) {messageFileOut.write((char*)&message, sizeof(Message));
        messageFileOut.close();}
    else {cerr << "Error opening message file" << endl;
        return 1;}

    return 0;
}
