/* This Code is to control gpio extendor with i2c communication MCP23017 

@Author : Ramvilas Gurjar
Date    : 28 November 2022
Email   : rv.babera@gmail.com

*/

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/i2c-dev.h>
#include<unistd.h>


#define I2C_FILE_NAME      "/dev/i2c-3" // location of i2c port
#define I2C_SLAVE_ADDRESS  0x27         // Address of MCP23017 IC (Slave)
#define IOCON              0x05         // IOCON register address used to change BANK
#define IODIR              0x00         // Register address for IO directions


int main()
{
    uint32_t i2c_bus;
    uint8_t  data[2];

    /* Opening i2c file /dev/i2c-3 */

    i2c_bus = open(I2C_FILE_NAME,O_RDWR);

    if(i2c_bus < 0)
    {
        printf("Failed to open /dev/i2c-3\n");
        return -1;
    }

    /* Assigning slave address */

    if(ioctl(i2c_bus,I2C_SLAVE,I2C_SLAVE_ADDRESS) < 0)
    {
        printf("failed to access i2c slave\n");
        return -2;
    }

    data[0] = IOCON;

    if(read(i2c_bus,data,1) != 1)
    {
        printf("Failed to read data of IOCON\n");
        return -3;
    }

    /* Setting BANK = 1 */

    data[1] = data[0] | 0x80;
    data[0] = 0x05;

    /* Setting IO direction of port A */

    data[0] = 0x00;
    data[1] = 0x00;

    if(write(i2c_bus,data,2) != 2)
    {
        printf("failed to set data in registers\n");
        return -4;
    }
    
    data[0] = 0x09;
    data[1] = 0xaa;
    
    if(write(i2c_bus,data,2) != 2)
    {
        printf("Failed to Write on GPIO A\n");
        return -5;

    return 0;
}
