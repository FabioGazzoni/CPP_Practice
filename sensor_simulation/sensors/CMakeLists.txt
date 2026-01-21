add_library(sensors
    src/Sensor.cpp
    src/SensorTempException.cpp)

target_include_directories(sensors PUBLIC include)