#include <string>
using namespace std;

//remote broker (on server)
class MqttBrokerFake
{
private:
    // active client in real broker;
    int countClient;
    MqttBrokerFake(/* args */);
public:

    MqttBrokerFake(MqttBrokerFake const&) = delete;
    MqttBrokerFake& operator=(MqttBrokerFake const&) = delete;

    static std::shared_ptr<MqttBrokerFake> instance()
    {
        static std::shared_ptr<MqttBrokerFake> s{new MqttBrokerFake};
        return s;
    }

    ~MqttBrokerFake();
    
    bool acceptConnection(string id)
    {
        
        if(countClient<1000){
             countClient++;
         return true;
        }
        return false;
    }
    void closeConnection(string id)
    {
         countClient--;
    }
};

MqttBrokerFake::MqttBrokerFake(/* args */)
{
}

MqttBrokerFake::~MqttBrokerFake()
{
}
