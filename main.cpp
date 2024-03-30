#include "DeviceMonitor.h"
#include <thread> // Do obsługi wątków
#include <chrono> // Do obsługi czasu

int main()
{
    DeviceMonitor monit;
    for (int i = 0; i < 300; i++)
    {
        monit.get_statuses();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::system("clear");
    }
    return 0;
}