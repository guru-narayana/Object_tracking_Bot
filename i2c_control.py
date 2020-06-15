import smbus
import time
def writenumber(value):
    bus = smbus.SMBus(1)
    address = 0x04
    bus.write_byte(address,value)
    time.sleep(0.1)
