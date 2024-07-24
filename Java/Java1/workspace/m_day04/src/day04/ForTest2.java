package day04;

import java.util.Scanner;

public class ForTest2 {

	public static void main(String[] args) {

		// 실습1. 1부터 50까지 출력
//		for(int i = 1; i <= 50; i++) {
//			System.out.println("i = " + i);
//		}

		// 실습2. 50부터 1까지 출력
//		for(int i = 50; i >= 1; i--) {
//			System.out.println("i = " + i);
//		}

		// 실습3. 주어진 for문을 가지고 5부터 1까지 출력
//		for(int i = 0; i < 5; i++) {
//			System.out.println(5-i);
//		}
//
//		// 1~10까지의 정수중에서 짝수만 출력하기
//
//		System.out.println(2);
//		System.out.println(4);
//		System.out.println(6);
//		System.out.println(8);
//		System.out.println(10);
//
//		for (int i = 1; i < 11; i++) {
//			if (i % 2 == 0) {
//				System.out.println(i);
//			}
//		}
//		
//		// if문을 사용하지 않는다면?
//		for(int i = 2; i < 11; i+=2) {
//			System.out.println("i = " + i);
//		}

//		// 사용자가 입력한 범위까지 정수를 출력하기
//		Scanner sc = new Scanner(System.in);
//		// 범위를 저장할 변수
//		int num = 0;
//		
//		System.out.println("1부터 몇까지 출력할까요?");
//		num = sc.nextInt();
//		
//		for(int i = 1; i <= num; i++) {
//			System.out.println("i = " + i);
//		}

		// 실습4.
		// 1부터 사용자가 입력한 정수까지의 합계를 구하기

		Scanner sc = new Scanner(System.in);
		// 입력한 정수를 저장할 변수
		int num = 0;
		// 변화하는 정수를 누적해서 더할 변수
		int total = 0;

		// 사용자에게 정수를 입력받는다
		System.out.println("1부터 몇까지 합계를 구할까요?");
		num = sc.nextInt();

		for (int i = 1; i <= num; i++) {
			total += i;
		}

		System.out.println(total);

		// 실습5.
		// 0부터 사용자가 입력한 정수까지 이어붙여서 출력하기
		// 만약 정수가 홀수일 경우에는 숫자 뒤에 !를 붙여서 출력한다

		// 결과예시 : 정수를 입력하세요 >> 10
		// 01!23!45!67!89!10
		
		

	}

}
