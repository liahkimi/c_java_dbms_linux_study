package ex03_fileIO;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class TryTest {

	public static void main(String[] args) {

		// try-with-resource(java.lang.AutoCloseable 인터페이스를 구현한 클래스만 사용가능)
		// close()를 자동으로 호출하는 try-catch문
		// close()를 자동호출 하기때문에 flush()도 같이 자동 호출된다
		
		try(BufferedWriter bw = new BufferedWriter(new FileWriter("myFile2.txt"))){
			
			bw.write("hello");
			
		}catch(IOException e) {
			e.printStackTrace();
		}
				
		
		
		
		
	}

}
