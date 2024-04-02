#include "catch_amalgamated.hpp"
#include "../DeviceMonitor.h"

TEST_CASE("tests for READER", "[Reader]")
{
    SECTION("reading config file")
    {
        Reader reader;
        reader.read_config();
        Json::Value a = reader.get_dev_config_val();
        CHECK(a.isMember("power supplier") == true);
        CHECK(a["power supplier"].isMember("voltage") == true);
        CHECK(a["power supplier"]["voltage"].isString());
        CHECK(a["power supplier"]["voltage"].asString() == "float");
        CHECK(a.isMember("barometer") == true);
        CHECK(a["barometer"]["compensated"].isString());
        CHECK(a["barometer"]["compensated"].asString() == "bool");
        CHECK(a.isMember("radar") == true);
    }
    SECTION("reading from file")
    {
        Reader reader;
        reader.read_config();
        reader.read_json("radar_1.json");
        Json::Value conf = reader.get_dev_config_val();
        Json::Value val = reader.get_dev_val();
        CHECK(conf.isMember("radar") == true);
        CHECK(val.isMember("type") == true);
        CHECK(val["type"].asString() == "radar");
        CHECK(val.isMember("light") == true);
        CHECK(val["light"].asString() == "on");
        CHECK(val.isMember("humidity") == true);
        CHECK(val["humidity"].asFloat() > 50);
        CHECK(val["humidity"].asFloat() < 51);
        CHECK(val.isMember("temperature") == true);
        CHECK(val["temperature"].asFloat() > 25);
        CHECK(val["temperature"].asFloat() < 26);
    }
}

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
    SECTION("start monitor in another thread")
    {
        DeviceMonitor monitor;
        monitor.start(0);
        std::this_thread::sleep_for(std::chrono::seconds(2)); // becouse monitor is running in another thread!!!
        CHECK(monitor.get_counter() == 7);
        monitor.stop();
    }
    SECTION("start monitor in the same thread")
    {
        DeviceMonitor monitor;
        monitor.get_statuses();
        CHECK(monitor.get_counter() == 7);
    }
    SECTION("get readers")
    {
        DeviceMonitor monitor;
        monitor.get_statuses();
        std::vector<Reader> readers = monitor.get_readers();
        CHECK(readers.size() == 7);
        CHECK(readers[0].get_dev_val().isMember("type") == true);
        CHECK(readers[0].get_dev_val()["type"].asString() == "lidar");
        std::cout << readers[0].get_dev_val() << std::endl;
    }
}
