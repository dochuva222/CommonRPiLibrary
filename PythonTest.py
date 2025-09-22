import ctypes
import time
import inspect

# Load the shared library
lib = ctypes.cdll.LoadLibrary('/home/pi/test_common_lib/CommonRPiLibrary/CommonRPiLibrary/build/libCommonRPiLibrary.so')  # Update the path as needed
# Define argument types and return type for RP_ReadWriteSPI function
lib.StartSPI.argtypes = [ctypes.c_char_p, ctypes.c_int, ctypes.c_int, ctypes.c_int]
lib.StartUSB.argtypes = [ctypes.c_char_p, ctypes.c_int]
lib.ReadWriteSPI.argtypes = [ctypes.POINTER(ctypes.c_ubyte), ctypes.c_uint]
lib.ReadWriteSPI.restype = ctypes.POINTER(ctypes.c_ubyte)  # Set the return type to pointer
lib.ReadWriteUSB.argtypes = [ctypes.POINTER(ctypes.c_ubyte), ctypes.c_uint]
lib.ReadWriteUSB.restype = ctypes.POINTER(ctypes.c_ubyte)  # Set the return type to pointer


# Run the example
if __name__ == '__main__':   
    lib.StartSPI()
    lib.StartUSB() 
    while True:
        # TEST SPI
        '''
        data = [0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xde]
        data_array = (ctypes.c_ubyte * len(data))(*data)
        data_length = len(data)
        returned_array_ptr = lib.ReadWriteSPI(data_array, data_length)

        returned_array = []
        for i in range(data_length):
            value = returned_array_ptr[i]
            returned_array.append(value)
        print(returned_array)
        time.sleep(0.1)
        '''
        
        # TEST USB
        tx_data: bytearray = bytearray([0] * 48)
        tx_data[0] = 1
        tx_data[2] = 0xff
        tx_data[3] = 0x00
        tx_data[4] = 0x00
        tx_data[5] = 0x00
        tx_data[6] = 0x00
        tx_data[7] = 0x00
        tx_data[8] = 0x00
        tx_data[9] = 0x00
        tx_data[10] = int('1' + '1' + '000001', 2)
        # third bit is for ProgramIsRunning
        tx_data[11] = int('1' + '0100001', 2)
        tx_data[20] = 222
        data_array = (ctypes.c_ubyte * len(tx_data))(*tx_data)
        data_length = len(tx_data)
        
        returned_array_ptr = lib.ReadWriteUSB(data_array, data_length)
        returned_array = []
        for i in range(data_length):
            value = returned_array_ptr[i]
            returned_array.append(value)
        print(returned_array)
        time.sleep(0.1)
        
