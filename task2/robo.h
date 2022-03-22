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
private:
public:
    string id;

    std::vector<string> ownners{}; //std::unique_ptr<Interface>
    MqttClientFake *client;
    void addOwner(string owner);

    void deleteOwner(string name);
    Robo(string owner);
    virtual void longCalculate(string task, void (*callback)(std::string))
    {
        if (!client)
            client = new MqttClientFake(callback);
        client->sendCommand(id, task);
    }
    virtual ~Robo()
    {
        delete client;
    }
};

class RoboSinger : public Robo
{
public:
    void Sing();
    bool canFly;

    RoboSinger(std::string owner) : Robo(owner)
    {
    }
};

class RoboNarrator : public Robo
{
public:
    void Tell();
    RoboNarrator(std::string owner) : Robo(owner)
    {
    }
};
