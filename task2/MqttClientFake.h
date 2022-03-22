#include <string>
#include <chrono>
#include <thread>
#include<unistd.h>
using namespace std;
//same client (code) on server and device(robot)
class MqttClientFake
{
private:
    /* data */
    static void getResult(string id, string task, void (*on_command)(std::string));
public:
    void (*on_command)(string);
    void sendCommand(string id, string command);
    MqttClientFake(void (*callback)(std::string));
    ~MqttClientFake();
};

