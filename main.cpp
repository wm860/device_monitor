#include "DeviceMonitor.h"
#include <thread> // Do obsługi wątków
#include <chrono> // Do obsługi czasu

int main()
{
    DeviceMonitor monit;
    for (int i = 0; i < 5; i++)
    {
        monit.start();
        monit.stop();
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::system("clear");
    }
    std::cout << "get_statuses() called in another thread:\n\n";
    monit.get_statuses();
    return 0;
}