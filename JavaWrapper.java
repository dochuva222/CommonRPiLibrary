import java.util.*;

public class JavaWrapper
{
	static 
	{
		System.load("/home/pi/test_common_lib/CommonRPiLibrary/CommonRPiLibrary/build/libCommonRPiLibrary.so");
	}
	
	private static native void Java_StartSPI();
	private static native void Java_StartUSB();
	private static native void Java_StopSPI();
	private static native void Java_StopUSB();
	private static native byte[] Java_ReadWriteSPI(byte[] data, int len);
	private static native byte[] Java_ReadWriteUSB(byte[] data, int len);

	public static void main(String[] args)
	{
		System.out.println("Test");
		
		Java_StartSPI();
		
		while (true)
		{
			byte[] data = hexStringToByteArray("010000000000000000de");
			byte[] result = Java_ReadWriteSPI(data, 10);
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
