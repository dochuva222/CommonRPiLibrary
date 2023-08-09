import ctypes
import time
import inspect

# Load the shared library
lib = ctypes.cdll.LoadLibrary('/home/pi/test_common_lib/CommonRPiLibrary/CommonRPiLibrary/build/libCommonRPiLibrary.so.1.0.1')  # Update the path as needed
# Define argument types and return type for RP_ReadWriteSPI function
lib.RP_Init()
lib.RP_StartSPI()
lib.RP_ReadWriteSPI.argtypes = [ctypes.POINTER(ctypes.c_ubyte), ctypes.c_uint]
lib.RP_ReadWriteSPI.restype = ctypes.POINTER(ctypes.c_ubyte)  # Set the return type to pointer



# Run the example
if __name__ == '__main__':    
    while True:
        data = [0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xde]
        # Call the function
        data_array = (ctypes.c_ubyte * len(data))(*data)
        data_length = len(data)
        returned_array_ptr = lib.RP_ReadWriteSPI(data_array, data_length)

        # Convert the returned pointer to a Python list
        returned_array = []
        for i in range(data_length):
            value = returned_array_ptr[i]
            returned_array.append(value)
        print(returned_array)
        time.sleep(0.1)
        
