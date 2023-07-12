#ifndef RAZOR_IMU_HPP
#define RAZOR_IMU_HPP

#include <serial/serial.h>
#include <cmath>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

#include <iostream>

class RazorImuSerial
{
    private:
    serial::Serial* serial_port = nullptr;

    double gravity_scale;
    double deg2rad;

    std::string serial_message;
    std::vector<std::string> split_message;
    std::string buffer;

    public:

    bool is_connected;

    typedef struct
    {
        double x;
        double y;
        double z;
    } Vector3;
    
    
    typedef struct
    {
        Vector3 accel;
        Vector3 gyro;
        Vector3 mag;
        double temp;
    } ImuData;

    bool readMessage(ImuData& data);
    RazorImuSerial(std::string port, int baudrate, int connection_attempts = 5);
    ~RazorImuSerial();
};

#endif