#Razor Imu Serial
This package handles serial communication and data parsing for the Sparkfun Razor Imu. 

All necessary files for installing/uninstalling are located in the utils directory. The install_depends.sh file installs the Public Serial package that is used in the Razor package. All the both of the razor imu scripts need sudo permissions to run.

To untilize this library in another cmake package the following additions need to be made to your CMakeLists.txt.

```
find_package(razor_imu_serial)
```

Also in target_link_libraries the following item also needs to be added:
```
${RAZOR_IMU_LIBS}
```
