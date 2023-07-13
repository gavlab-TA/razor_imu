#include "razor_imu_serial.hpp"

RazorImuSerial::RazorImuSerial(std::string port_name, int baudrate, int connection_attempts)
{
    is_connected = false;
    deg2rad = M_PI / 180.0;
    gravity_scale = 9.81/1000.0;

    for (int i = 0; i < connection_attempts && !is_connected; i++)
    {
        serial_port = new serial::Serial(port_name, baudrate, serial::Timeout::simpleTimeout(50));
        if (serial_port -> isOpen())
        {
            is_connected = true;
            break;
        }

        sleep(1);
        serial_port -> flush();
    }

    if (is_connected)
    {
        std::cout << "Connected to Port " << port_name << std::endl;
    }
    else
    {
        std::cout << "Razor Imu Failed to Connect" << std::endl;
    }
}

RazorImuSerial::~RazorImuSerial()
{
    if (serial_port != nullptr)
    {
        delete serial_port;
        serial_port = nullptr;
    }
}

bool RazorImuSerial::readMessage(ImuData &data)
{
    serial_message = serial_port->readline();        
    split_message.clear();
    boost::split(split_message, serial_message, boost::is_any_of(","));

    if (split_message.size() >= 13)
    {
        data.accel.x = std::atof(split_message.at(2).c_str()) * gravity_scale;
        data.accel.y = std::atof(split_message.at(3).c_str()) * gravity_scale;
        data.accel.z = std::atof(split_message.at(4).c_str()) * gravity_scale;

        data.gyro.x = std::atof(split_message.at(5).c_str()) * deg2rad;
        data.gyro.y = std::atof(split_message.at(6).c_str()) * deg2rad;
        data.gyro.z = std::atof(split_message.at(7).c_str()) * deg2rad;

        data.mag.x = std::atof(split_message.at(8).c_str());
        data.mag.y = std::atof(split_message.at(9).c_str());
        data.mag.z = std::atof(split_message.at(10).c_str());

        data.temp = std::atof(split_message.at(11).c_str());
        return true;
    }
    else
    {
        return false;
    }
}