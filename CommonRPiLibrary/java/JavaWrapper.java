package io.github.crackanddie;

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
	
	public JavaWrapper(){}
	
	public void StartSPI(){
			Java_StartSPI();
	}
	
	public void StartUSB(){
			Java_StartUSB();
	}
	
	public byte[] ReadWriteSPI(byte[] data, int len){
			return Java_ReadWriteSPI(data, len);
	}
	
	public byte[] ReadWriteUSB(byte[] data, int len){
			return Java_ReadWriteUSB(data, len);
	}
	
	public void StopSPI(){
			Java_StopSPI();
	}
	
	public void StopUSB(){
			Java_StopUSB();
	}
}
