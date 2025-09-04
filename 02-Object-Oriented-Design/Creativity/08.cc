/*
# C-2.8
Write a set of C++ classes that can simulate an Internet application, where
one party, Alice, is periodically creating a set of packets that she wants to
send to Bob. The Internet process is continually checking if Alice has any
packets to send, and if so, it delivers them to Bob’s computer, and Bob is
periodically checking if his computer has a packet from Alice, and, if so,
he reads and deletes it.
*/
#include <iostream>
#include <string>
#include <unistd.h>

class Connection
{
private: 
    std::string packet;
public:
    void send(std::string pkt)
    {
        packet = pkt;
    }

    std::string recieve() const
    {
        std::string temp = packet;
        return temp;
    }
};

class User
{
private:
    std::string name;
    Connection &conn;
public:
    User(const std::string &n, Connection &con) : name(n), conn(con) {}
    void send(std::string str) {
        conn.send(str);
    }

    void recieve()
    {
        std::string str = conn.recieve();
        if (str != "")
            std::cout << "Recieved : " << str << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Connection conn;
    User alice("Alice", conn), bob("Bob", conn);

    while (true)
    {
        if (rand() % 100 < 50)
            alice.send("Random Message From Alice");

        bob.recieve();
        sleep(1);
    }

    return 0;
}

