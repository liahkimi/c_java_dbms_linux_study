package ex03_exception;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Scanner;

public class ThrowsTest {

	
	static void myMethod() {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("정수를 입력하세요>>");
		// 메소드를 정의할때 예외처리를 한다
		try {
			int num = sc.nextInt();
		}catch(Exception e) {
			System.out.println("잘못된 정수 입력");
		}
	}
	
	static void myMethod2() throws InputMismatchException{
		Scanner sc = new Scanner(System.in);
		System.out.println("정수를 입력하세요>>");
		int num = sc.nextInt();
	
	}
	
	
	
	public static void main(String[] args) {

//		ThrowsTest.myMethod();
		
		try {
			ThrowsTest.myMethod2();
		}catch(InputMismatchException e) {
			System.out.println("잘못된 입력");
		}
		
		
		
	}

}
