#include "DeviceMonitor.h"

Reader::Reader()
{
    std::cout << "Reading started" << std::endl;
    std::ifstream f("config_data.json");
    if (!f.is_open())
    {
        std::cerr << "Failed to open file." << std::endl;
        // exit;
    }
    else
    {
        std::cout << "Configuration file opened" << std::endl;
    }
    f.close();
}
void Reader::read(std::string filename)
{
    std::string folder = "./devices_data";
    std::string path = folder + "/" + filename;
    std::ifstream f(path);

    if (f.is_open())
    {
        std::string line;
        if (std::getline(f, line))
        {
            dev_type = line;
        }
        std::getline(f, line);
        // na podstawie wczytanej linii pierwszej ustawienie jakie
        // dane sa w pliku i jak je pobierac z wykorzystaniem jsona
        while (std::getline(f, line))
        {
            parameters.push_back(std::make_tuple(line, "0"));
            // std::cout << line << std::endl;
        }
        f.close();
    }
    else
    {
        std::cout << "Failed to open the file." << std::endl;
    }
}
// void Reader::read_config()

void Reader::read_json(std::string filename)
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
    float voltage = val["power supplier"]["voltage"].asFloat();
    std::cout << "voltage:\t" << voltage << std::endl;
}
void Reader::print()
{
    std::cout << "Device type: " << dev_type << std::endl;
    for (auto &param : parameters)
    {
        std::cout << std::get<0>(param) << " " << std::get<1>(param) << std::endl;
    }
}