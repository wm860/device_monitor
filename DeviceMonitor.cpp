#include "DeviceMonitor.h"

Reader::Reader()
{
    // std::cout << "\n\nReading started" << std::endl;
}
void Reader::read_config()
{
    std::ifstream f("config_data.json");
    if (!f.is_open())
    {
        std::cerr << "Failed to open file." << std::endl;
        // exit;
    }
    else
    {
        // std::cout << "Configuration file opened" << std::endl;
    }
    Json::Reader reader;
    Json::Value val;
    bool parsingSuccessful = reader.parse(f, val);
    f.close();
    if (!parsingSuccessful)
    {
        std::cerr << "Failed to parse JSON" << std::endl;
        return;
    }
    dev_config_val = val;
}
void Reader::read_json(const std::string filename)
{
    std::string folder = "./devices_data";
    std::string path = folder + "/" + filename;
    std::ifstream f(path);

    if (!f.is_open())
    {
        std::cerr << "Failed to open file." << std::endl;
        // exit;
    }
    // Read JSON file
    Json::Reader reader;
    Json::Value val;
    bool is_ok = reader.parse(f, val);
    f.close();
    if (!is_ok)
    {
        std::cerr << "Failed to parse JSON" << std::endl;
        // exit;
    }
    dev_val = val;
    // float voltage = val["power supplier"]["voltage"].asFloat();
    // std::cout << "voltage:\t" << voltage << std::endl;
}
void Reader::print_one()
{
    if (dev_config_val.empty())
    {
        std::cerr << "No configuration data" << std::endl;
        return;
    }
    if (dev_val.empty())
    {
        std::cerr << "No device data" << std::endl;
        return;
    }
    std::string type = dev_val["type"].asString();
    if (dev_config_val.isMember(type.c_str()))
    {
        // std::cout << "Given file exists in configuration file :)\n";
        // std::cout << type << " data: {";
        std::cout << " { ";
        Json::Value device_params = dev_config_val[type];
        for (auto it = device_params.begin(); it != device_params.end(); ++it)
        {
            std::string key = it.key().asString();
            Json::Value value = *it;
            // Json::Value dev_val
            if (value.isString())
            {
                std::string val = dev_val[key].asString();
                std::cout << key << " : " << val << ", ";
            }
            else if (value.isNumeric())
            {
                float val = dev_val[key].asFloat();
                std::cout << key << " : " << val << ", ";
            }
            else if (value.isBool())
            {
                bool val = dev_val[key].asBool();
                std::cout << key << " : " << (val ? "true" : "false") << ", ";
            }
        }
        std::cout << "}\n";
    }
    else
    {
        std::cerr << "No power supplier data" << std::endl;
    }
}
DeviceMonitor::DeviceMonitor()
{
    std::cout << "Device Monitor started" << std::endl;
    running = false;
}
// void DeviceMonitor::get_statuses()
// {
//     std::string folder = "./devices_data";
//     for (const auto &entry : std::filesystem::directory_iterator(folder))
//     {
//         std::string filename = entry.path().filename().string();
//         std::cout << filename << "\t:\t";
//         Reader reader;

//         reader.read_config();
//         reader.read_json(filename);

//         reader.print_one();
//         readers.push_back(reader);
//         std::this_thread::sleep_for(std::chrono::milliseconds(100));
//     }
// }
void DeviceMonitor::get_statuses(std::string filename)
{
    std::string folder = filename;
    for (const auto &entry : std::filesystem::directory_iterator(folder))
    {
        std::string filename = entry.path().filename().string();
        std::cout << filename << "\t:\t";
        Reader reader;

        reader.read_config();
        reader.read_json(filename);

        reader.print_one();
        readers.push_back(reader);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
void DeviceMonitor::start()
{
    if (!running)
    {
        running = true;
        monitorThreadPtr = std::make_unique<std::thread>(&DeviceMonitor::get_statuses, this, "devices_data");
    }
}
void DeviceMonitor::stop()
{
    running = false;
    if (monitorThreadPtr && monitorThreadPtr->joinable())
    {
        monitorThreadPtr->join();
    }
}
bool DeviceMonitor::get_running()
{
    return running;
}