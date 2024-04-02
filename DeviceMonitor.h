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

public:
    Reader();
    void read_config();
    void read_json(std::string filename);
    void print_one();
    Json::Value get_dev_config_val();
    Json::Value get_dev_val();
};

class DeviceMonitor
{
private:
    bool running;
    std::unique_ptr<std::thread> monitorThreadPtr;
    std::vector<Reader> readers;
    int counter;

public:
    DeviceMonitor();
    ~DeviceMonitor();
    void get_statuses(int time_interval = 0);
    void start(int time_interval = 100);
    void stop();
    bool get_running();
    std::vector<Reader> get_readers();
    int get_counter();
};
