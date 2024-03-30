#include "DeviceMonitor.h"
#include <thread> // Do obsługi wątków
#include <chrono> // Do obsługi czasu

int main()
{
    // Reader reader1;
    // Reader reader2;
    // Reader reader3;
    // reader1.read_config();
    // reader1.read_json("pow_sup_1.json");
    // reader1.print_one();
    // reader2.read_config();
    // reader2.read_json("radar_1.json");
    // reader2.print_one();
    // reader3.read_config();
    // reader3.read_json("barometer_1.json");
    // reader3.print_one();
    DeviceMonitor monit;
    for (int i = 0; i < 100; i++)
    {
        monit.get_statuses();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::system("clear");
    }

    return 0;
}