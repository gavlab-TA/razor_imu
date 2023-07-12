#!/bin/bash
git clone git@github.com:wjwwood/serial.git
cd serial
make
make install
cd ../
rm -rf serial
