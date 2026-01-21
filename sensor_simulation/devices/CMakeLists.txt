add_library(devices
    src/LED.cpp
    src/Buzzer.cpp
    src/DevicesException.cpp)

target_include_directories(devices PUBLIC include)