#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <filesystem>

#include <jsoncpp/json/json.h>

// #include "rapidjson/document.h"
// #include "rapidjson/filereadstream.h"
// #include "rapidjson/filewritestream.h"
// #include "rapidjson/writer.h"

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
    // void print();
};

class DeviceMonitor
{
private:
    std::vector<Reader> readers;

public:
    DeviceMonitor();
    void get_statuses();
    void start();
    void print_all();
};
