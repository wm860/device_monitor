#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

#include <mutex>
#include <thread>
#include <chrono>

#include <jsoncpp/json/json.h>

class Reader
{
private:
    Json::Value dev_config_val;
    Json::Value dev_val;
    std::vector<Json::Value> dev_vector;

public:
    Reader();
    void read_config();
    void read_json(std::string filename);
    void print_one();
};

class DeviceMonitor
{
private:
    bool running;
    std::unique_ptr<std::thread> monitorThreadPtr;
    std::vector<Reader> readers;

public:
    DeviceMonitor();
    // void get_statuses();
    void get_statuses(std::string folder_name);
    void start();
    void stop();
    bool get_running();
};
