#include "DeviceMonitor.h"

int main()
{
    Reader reader1;
    reader1.read_config();
    reader1.read_json("radar_1.json");
    reader1.print();
    return 0;
}