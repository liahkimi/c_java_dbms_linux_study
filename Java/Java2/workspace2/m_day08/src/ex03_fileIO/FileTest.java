package ex03_fileIO;

import java.io.File;
import java.io.IOException;

public class FileTest {

	public static void main(String[] args) {

		// java.io 패키지에 있어서 import 후에 사용한다
		// 파일을 객체로 다루기 위해서는 파일의 이름과 파일의 경로가 필요하다
		// 경로를 생략하면 현재 프로젝트를 기준경로로 사용한다
		File file1 = new File("test.txt");
		
		
		try {
			// 파일명과 경로를 이용하여 새로운 파일을 생성한다
			file1.createNewFile();
			System.out.println("파일 생성 완료!");
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		

		File file2 = new File("src/test.txt");
		
		try {
			file2.createNewFile();
			System.out.println("파일 생성 완료!");
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		// 역슬래시(\) 사용할때는 2번 작성한다
		File file3 = new File("D:\\0930_JAVA2_sms\\memo\\test.txt");
		
		try {
			file3.createNewFile();
			System.out.println("파일 생성 완료!");
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		// 파일 존재 여부 확인
		System.out.println(file3.exists());
		
		// 파일의 경로 확인
		
		// 상대경로
		System.out.println(file2.getPath());
		// 절대경로
		System.out.println(file2.getAbsolutePath());
		
		// 파일삭제
		if(file3.exists()) { // 해당 파일이 존재하면
			file3.delete(); // 삭제한다
			System.out.println("삭제 완료");
		}
		
		
		
	}

}
