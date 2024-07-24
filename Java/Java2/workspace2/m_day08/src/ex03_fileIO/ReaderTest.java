package ex03_fileIO;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class ReaderTest {

	public static void main(String[] args) {

		// 읽기(입력)

		BufferedReader br = null;
		// 읽은 문자열을 저장할 변수
		String line = null;

		try {
			br = new BufferedReader(new FileReader("myFile.txt"));

			while ((line = br.readLine()) != null) {
				// 줄바꿈 문자는 가져오지 않는다 -> 한줄을 판단하는 용도로 사용한다
				// System.out.print(line);
				System.out.println(line);
			}

		} catch (FileNotFoundException e) { // IOException을 상속받는다
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if (br != null) {
				try {
					br.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}

		}

	}

}
