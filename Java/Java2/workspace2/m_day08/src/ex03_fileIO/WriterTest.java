package ex03_fileIO;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class WriterTest {

	public static void main(String[] args) {

		// 쓰기(출력)
		
		// java.io 패키지에 있어서 import 후에 사용한다(BufferedWriter, FileWriter)
		// 보조 스트림
		BufferedWriter bw = null;
		
		// 보조 스트림 생성자에 기본 스트림 객체를 전달하여 보조스트림 객체화(객체 생성)
		// 기본 스트림 생성자에 파일 경로와 파일명을 작성한다
		try {
			// 기존에 파일이 존재한다면 덮어쓴다
			// FileWriter​(File file, boolean append) : append -> 이어쓰기 여부
			bw = new BufferedWriter(new FileWriter("myFile.txt", true));
			
			// 직접 줄바꿈에 해당하는 문자를 사용해야 한다
//			bw.write("hello\n");
			bw.write("안녕!");
			
			// \r\n : Windows 운영체제의 줄바꿈, \n : 다른 운영체제 줄바꿈
			// newLine() : 운영체제 따른 줄바꿈을 사용한다
			bw.newLine(); 
			bw.write("world");

			// 버퍼에 쌓인 데이터를 비운다 
			// bw.flush();
			
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			
			// 연결된 스트림을 닫는다(종료)
			try {
				// bw == null : 스트림 생성 실패
				// bw != null : 스트림 생성 성공
				if(bw != null) { // 스트림이 정상적으로 생성되었다면
					bw.close();	// 스트림을 닫는다(종료한다)
					// close()를 사용하면 자동으로 flush()가 사용된다
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		
		
		
		
		
		
		
		
		
		
		
	}

}
