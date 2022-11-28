# MCP23017

This Code Shows Hoe to interact with a GPIO extender MCP23017 with i2c communication.

In This I have used regiter addresses to control the external GPIO. MCP23017 IC provides 2 8-bit IO Banks or you c an use these two as one 16-bit
IO bank.

To control this You Have to set the slave address first wich will be in range of (0x20 to 0x27) which you can set using A0,A2,A3 pins of IC.

After that you can set the BANK using IOCON 8-bit register the last bit of IOCON register is the BANK no which is either 1 or 0.

After that you can set the IO Directions using the IODIR register where 0 is output and 1 is input.

After that you can set the values of output registers and read the values of input registers.
