package ex03_exception;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ExceptionTest {

	public static void main(String[] args){

//		System.out.println("hello");
//		Scanner sc = new Scanner(System.in);
//		// 입력값이 숫자형태이면 예외가 발생하지 않는다
//		// 입력값이 문자형태이면 예외가 발생한다
//		int num = sc.nextInt();
//		System.out.println("world");
		
		
		
//		System.out.println("hello");
//		Scanner sc = new Scanner(System.in);
//		try {
//			int num = sc.nextInt();
//		}catch(InputMismatchException e) {
//			// InputMismatchException 예외가 발생하면 실행할 코드 
//			System.out.println("잘못된 입력입니다");
//		}finally{
//			// 예외 발생 여부와 상관없이 무조건 실행할 코드
//			System.out.println("finally 코드");
//		}
//		
//		System.out.println("world");
		
		
		// Exception 클래스는 모든 예외클래스의 최상위 부모클래스이다
		
		try {
		Scanner sc = new Scanner(System.in);
		System.out.println("몇칸 짜리 배열을 만들까요?");
		// InputMismatchException 예외 발생 코드
		int num2 = sc.nextInt();
		// NegativeArraySizeException 예외 발생 코드
		int[] ar = new int[num2];
		System.out.println(ar.length);
		
		}catch(InputMismatchException e) {
			System.out.println("잘못된 숫자 입력");
			
			// 예외클래스의 메소드
			System.out.println(e);
			System.out.println(e.getMessage());
			System.out.println(e.toString());
			e.printStackTrace();
			System.out.println("예외처리 완료");
			
		}catch(NegativeArraySizeException e) {
			System.out.println("음수 길이의 배열은 존재할수 없습니다");
		}catch(Exception e) {
			System.out.println("예외 발생");
		}
		
		
		
		
		
		
		
	}

}
