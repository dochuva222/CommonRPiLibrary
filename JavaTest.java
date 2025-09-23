
import java.util.*;
import io.github.crackanddie.*;

public class JavaTest
{
	static 
	{
		System.load("/home/pi/test_common_lib/CommonRPiLibrary/CommonRPiLibrary/build/libCommonRPiLibrary.so");
	}

	public static void main(String[] args)
	{
		JavaWrapper jw = new JavaWrapper();
		int spiResult = jw.StartSPI("/dev/spidev1.2", 2, 1000000, 0);
		if (spiResult != 0)
			System.out.println("Failed to start SPI");
		int comResult = jw.StartUSB("/dev/ttyACM0", 115200);
		if (comResult != 0)
			System.out.println("Failed to start COM");
		
		while (true)
		{
			// TEST SPI
			/*
			byte[] data = hexStringToByteArray("010000000000000000de");
			byte[] result = jw.ReadWriteSPI(data, 10);
			System.out.println(Arrays.toString(result));
			try{
				Thread.sleep(100);
			}
			catch (InterruptedException e){}
			*/
			
			// TEST USB
			byte[] tx_data = new byte[48];
			tx_data[0] = 0x01;
			tx_data[2] = (byte)0xff;
			tx_data[3] = 0x00;
			tx_data[4] = 0x00;
			tx_data[5] = 0x00;
			tx_data[6] = 0x00;
			tx_data[7] = 0x00;
			tx_data[8] = 0x00;
			tx_data[9] = 0x00;
			tx_data[10] = (byte)0xC1; //int('1' + '1' + '000001', 2)
			tx_data[11] = (byte)0xA1; //int('1' + '0100001', 2)
			tx_data[20] = (byte)0xDE; //222;
			byte[] result = jw.ReadWriteUSB(tx_data, 48);
			System.out.println(Arrays.toString(result));
			try{
				Thread.sleep(100);
			}
			catch (InterruptedException e){}
		}
	}
	
	public static byte[] hexStringToByteArray(String s) {
		int len = s.length();
		byte[] data = new byte[len / 2];
		for (int i = 0; i < len; i += 2) {
			data[i / 2] = (byte) ((Character.digit(s.charAt(i), 16) << 4)
								 + Character.digit(s.charAt(i+1), 16));
		}
		return data;
	}
}
