#include <iostream>

#include "razor_imu/razor_imu_serial.hpp"

int main()
{
    RazorImuSerial driver("/dev/ttyUSB0", 115200);
    RazorImuSerial::ImuData data;
    for(;;)
    {

        driver.readMessage(data);
    }

    return 0;
}