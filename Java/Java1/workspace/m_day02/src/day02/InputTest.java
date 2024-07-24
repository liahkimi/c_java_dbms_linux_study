package day02;

import java.util.Scanner;

public class InputTest {

	public static void main(String[] args) {

		// import 단축키 : ctrl + shift + o
		// sc 변수에 Scanner 클래스의 정보를 저장한다
//		Scanner sc = new Scanner(System.in);
//		
//		System.out.println("이름을 입력하세요");
//		
//		// sc.next() : 사용자가 콘솔창에 입력한값
////		String name = sc.next();
////		System.out.println(name + "님 안녕하세요");
//		
////		String firstName = sc.next();
////		String lastName = sc.next();
////		System.out.println(lastName +firstName + "님");
//		
//		// nextLine() 메소드
//		String fullName = sc.nextLine();
//		System.out.println(fullName + "님 안녕하세요");
		
		// 실습1. 
		// 사용자에게 두자리 정수를 입력받아 십의 자리와
		// 일의 자리 숫자를 출력하기
		
		// 입력예시 : 두자리 정수를 입력하세요 >>
		// 결과예시 : 98
		// 십의 자리는 9 입니다
		// 일의 자리는 8 입니다
		
		// 사용자에게 두자리 정수를 입력받는다
		// 입력클래스 코드를 작성한다
		Scanner sc = new Scanner(System.in);
		// 사용자에게 두자리 정수를 입력하세요 >> 라고 출력한다
		System.out.println("두자리 정수를 입력하세요 >>");
		// 입력 메소드를 사용한다
		// 콘솔창에 입력한 값을 문자열 변수에 저장한다
		String number = sc.next();
		// 입력한 문자열의 0번째는 십의자리 숫자이다
		// 입력한 문자열에서 0번째를 가져와서 char 변수에 담는다
		char ten = number.charAt(0);
		// 입력한 문자열의 1번째는 일의자리 숫자이다
		// 입력한 문자열에서 1번째를 가져와 char 변수에 담는다
		char one = number.charAt(1);
		
		// 변수에 담긴 2개의 값을 문자열로 연결하여 출력한다
		System.out.println("십의 자리는 " + ten + " 입니다");
		System.out.println("일의 자리는 " + one + " 입니다");
		
		
	}

}
