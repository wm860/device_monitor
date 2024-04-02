#!/bin/bash

# Zmienna przechowująca nazwę pliku testowego
test_file="DeviceMonitor_test.cpp"

# Zmienna przechowująca nazwę pliku wykonywalnego
executable="test_executable"

# Kompilacja pliku testowego
g++ -o $executable $test_file "../DeviceMonitor.cpp" -ljsoncpp

# Uruchomienie testów
./$executable