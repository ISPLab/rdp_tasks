#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "MqttClientFake.h"
using namespace std;
/*class Owner
{

public:
    string name;
    Owner(string name)
    {
        this->name = name;
    }
};*/

class Robo
{
    private :

public:
    string id;

    std::vector<string> ownners {}; //std::unique_ptr<Interface>
    MqttClientFake* client;
    void addOwner(string owner);
 
    void deleteOwner(string name);
    Robo(string owner);
    /*virtual std::string toString()
    {
        return "I am an robo";
    }*/
    virtual void longCalculate(string task,  void (*callback)(std::string) ) {
        if(!client)
           client = new MqttClientFake(callback);
        client->sendCommand(id, task);
    }
    virtual ~Robo() {
        delete client;
    }
 
};

//void Robo::calculate() { std::cout << "calculating...;"
//    << "\n"; };
/*Robo::Robo(string owner)
{
    ownners.push_back(owner);
}*/

/*void Robo::deleteOwner(string name)
{
    ownners.erase(ownners.begin());
    if (ownners.size() == 0)
        this->~Robo();
};*/

class RoboSinger : public Robo
{
public:
    void Sing();
    bool canFly;

    RoboSinger(std::string owner) : Robo(owner) // call the super class constructor with its parameter
    {
    }
};

class RoboNarrator : public Robo
{
public:
    void Tell();
    RoboNarrator(std::string owner) : Robo(owner) // call the super class constructor with its parameter
    {
    }
};
