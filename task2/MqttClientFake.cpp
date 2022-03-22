
#include "MqttClientFake.h"
#include "MqttBrokerFake.h"
MqttClientFake::MqttClientFake(void (*callback)(std::string))
{
    this->on_command = callback;
}

MqttClientFake::~MqttClientFake()
{
 
}

void MqttClientFake::getResult(string id, string task, void (*on_command)(std::string))
{
         //ger result from remote client
        auto broker = MqttBrokerFake::instance();
        while(!broker->acceptConnection(id)){};
        on_command(id + "a");
        broker->closeConnection(id);
}

void MqttClientFake::sendCommand(std::string id, std::string command)
{
   //send to remote mqtt client
   thread t1(getResult, id, command, on_command);
   t1.detach();
 }