
# rdp_tasks

task1 cодержит задание:
Реализовать свою версию утилиты ls (без использования system()) на C

основной код:
в фале support.cpp

![image](https://user-images.githubusercontent.com/8803512/159418192-d57aa63a-78e1-4504-9336-4711aac83b14.png)

* компиляция 
   make

task2 содержит задание:
C++: завод выпускает роботов двух типов: RoboSinger, который умеет петь (Sing()), и
RoboNarrator, который умеет рассказывать истории (Tell()). Все роботы умеют считать
(Calculate()). У каждого робота есть один или несколько хозяев, при этом когда у робота
хозяев не остается, он отправляется в дезинтегратор и уничтожается. Завод, выпускающий
роботов, планирует захватить мир. Для этого, когда кол-во существующих (не считая
уничтоженных) роботов достигнет 1'000'000, нужно провести расчет злобного плана: каждый
робот удаленно подключается к заводу и проводит свою часть вычислений (LongCalculate()).
При этом одновременно к серверам завода может подключиться не более 1000 роботов.
Необходимо реализовать подходящую иерархию классов и обеспечить эффективное
выполнение злобного плана завода.



серверная часть:
основной код находится в Manager.cpp,
содержит орбработку команд по заданию:
  create singer[narrator] name_owner
  add_owner id_device owner_name
  delete_owner id_device owner_name

создание 1'000'000 клиента,
       test1000000 находится в main.cpp:
          if (strcmp(cmd_argv[0], "test1000000") == 0)
            {
                string res;
                for(int i=0; i<1000000; i++)
                    {
                        cmd_argv[0] = (char*)"create";
                        cmd_argv[1] = (char*)"singer";
                        cmd_argv[2] = (char*)"aa";
                        res = sup->run_command(3, cmd_argv);
                        cout << i <<" : "<<res << endl;
                    }
                cout << res << std::endl;
            }
  
при каждом добвалении устройства проверяется колличество зарегистрированных устройств. checkPlan
в случае 1'000'000 устройствам отправлятся команда longCalculate на каждое устройсво с асинхронным callback.
 virtual void longCalculate(string task, void (*callback)(std::string))
клиент устройства создает канал подключения к удаленному устройству (предполагается использование  mqtt (https://mosquitto.org/) или чистого websocet)
и отправлят команду - 
  if (!client)
            client = new MqttClientFake(callback);
        client->sendCommand(id, task);
        
реальное устройство получив команду проводит вычисление (код клиентской части (MqttClientFake.cpp) точно такойже как на серверной - потому что предпологается подключаеться к одному и тому же брокеру):

клиетская часть:
 void MqttClientFake::getResult(string id, string task, void (*on_command)(std::string))
{
         //ger result from remote client
        auto broker = MqttBrokerFake::instance();
        while(!broker->acceptConnection(id)){};
        on_command(id + "a");
        broker->closeConnection(id);
}
проверив доступность подключения на брокере (MqttBrokerFake.cpp):
bool acceptConnection(string id)
    {
        
        if(countClient<1000){
             countClient++;
         return true;
        }
        return false;
    }
 отправлят результат в Manager (на сервер)
 
 * компиляция 
            сmake проект сделан на Visual studio
            
 * для выполненения теста :
            
            
 Задание протестрована Rasperry PI 4, Ubuntu 20.04.3 LTS (GNU/Linux 5.4.0-1042-raspi aarch64)
      


    




