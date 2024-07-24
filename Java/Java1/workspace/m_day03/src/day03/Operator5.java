package day03;

import java.util.Scanner;

public class Operator5 {

	public static void main(String[] args) {

		// 실습1.
		// 사용자에게 두자리 정수를 입력받는다(nextInt() 메소드 사용)
		// 입력받은 두자리 정수에서 십의자리, 일의자리 출력하기
		
		// 결과예시 : 두자리 정수를 입력 >> 48
		// 십의 자리 = 4
		// 일의 자리 = 8
		
		Scanner sc = new Scanner(System.in);
		// 사용자에게 입력받은 정수를 저장할 변수
		int num = 0;
		// 십의 자리 숫자를 저장할 변수
		int ten = 0;
		// 일의 자리 숫자를 저장할 변수
		int one = 0;
		
		// 사용자에게 두자리 정수를 입력받는다
		System.out.println("두자리 정수를 입력 >>");
		num = sc.nextInt();
		
		// 입력받은 두자리 정수에서 십의자리를 구한다
		ten = num / 10;
		// 입력받은 두자리 정수에서 일의자리를 구한다
		one = num % 10;
		
		System.out.println("십의자리 = " + ten);
		System.out.println("일의자리 = " + one);
		
		
		// 실습2.
		// 사용자에게 금액을 입력받고 부를수 있는 노래곡수와 잔돈을 출력하기
		// 1곡당 300원
		
		// 결과예시 : 금액 입력(1곡당 300원) >> 1000
		// 노래 3곡을 부를수 있으며, 잔돈은 100원 입니다
		
//		Scanner sc = new Scanner(System.in);
//		// 노래 금액을 저장하는 변수
//		int price = 300;
//		// 사용자가 입력한 금액을 저장할 변수
//		int money = 0;
//		// 부를수 있는 노래 곡수를 저장할 변수
//		int count = 0;
//		// 잔돈을 저장하는 변수
//		int charge = 0;
//		
//		// 사용자에게 금액을 입력받는다
//		System.out.println("금액 입력(1곡당 300원) >> ");
//		money = sc.nextInt();
//		
//		// 부를수 있는 곡 수를 계산한다
//		count = money / 300;
//		// 잔돈을 계산한다
//		charge = money % 300;
//		
//		System.out.println("노래 " + count + "곡을 부를수 있고, 잔돈은 " + charge + "원 입니다");
//		System.out.printf("노래 %d곡을 부를수 있고, 잔돈은 %d원 입니다", count, charge);
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}

}
