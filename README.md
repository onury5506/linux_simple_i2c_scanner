# linux_simple_i2c_scanner
I2C Scanner for linux systems

This application is a simple i2c scanner for linux systems. I tested it with lichee pi zero but it could work with other embedded linux systems like raspberry pi.

You can run this application with following commands : 

gcc main.c -std=gnu99
./a.out


Example run : 

root@LicheePi:~/test/i2c# gcc main.c -std=gnu99
root@LicheePi:~/test/i2c# ./a.out
i2c scanner
0) /dev/i2c-0
Select an device : 0
finded 0x3C
