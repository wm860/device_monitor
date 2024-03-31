#include "catch_amalgamated.hpp"
#include "../DeviceMonitor.h"

TEST_CASE("simple tests", "[DeviceMonitor]")
{

    SECTION("initialize monitor")
    {
        DeviceMonitor monitor;
        bool a = monitor.get_running();
        CHECK(a == false);
    }
    SECTION("start monitor")
    {
        DeviceMonitor monitor;
        monitor.start();
        bool a = monitor.get_running();
        CHECK(a == true);
        monitor.stop();
    }
}
