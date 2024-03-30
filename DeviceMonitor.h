#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

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
    std::string dev_type;
    std::vector<std::tuple<std::string, std::string>> parameters;

public:
    Reader();
    void read(std::string filename);
    void read_config();
    void read_json(std::string filename);
    void print();
};
