package day05;

import java.util.Scanner;

public class WhileTest {

	public static void main(String[] args) {

		// while문

		int count = 0;

		while (count > 5) {
			System.out.println("안녕하세요");
			count++;
		}

		// 사용자에게 정수를 입력받아 정답과 비교하여
		// 정답과 일치하면 입력을 종료한다
		// 정답과 일치하지 않으면 다시 정수를 입력받는다

		// 정답
		int answer = 23;

//		Scanner sc = new Scanner(System.in);
//		// 입력받은 정수를 저장할 변수
//		int num = 0;
//		
//		// 사용자에게 정수를 입력받는다
//		while(num != answer) {
//			System.out.println("정수를 입력하세요 >>");
//			num = sc.nextInt();
//		}
//		
//		System.out.println("프로그램 종료");

		// 실습1.
		// 사용자에게 양의 정수 3개를 입력받기(1개씩 입력받는다)
		// 단, 음수를 입력하였을 경우 음의 정수를 입력하였습니다 출력하고 다시 입력받기
		// 누적된 양의 정수 개수가 3개가 아니라면 다시 입력받기
		// 누적된 양의 정수 개수가 3개가 된다면 반복을 종료하고 프로그램 종료 출력하기

		// 1. 사용자에게 정수를 입력받는다
		// 2. 입력된 정수의 양수 음수 여부를 판별한다
		// 3. 입력받은 양의 정수 개수를 기억해야한다

//		Scanner sc = new Scanner(System.in);
//		// 양의 정수의 개수를 저장할 변수
//		int userCount = 0;
//		// 입력받은 정수를 저장할 변수
//		int userNum = 0;
//
//		while (userCount < 3) {
//			// 사용자에게 정수를 입력받는다
//			System.out.println("양의 정수를 입력하세요>>");
//			userNum = sc.nextInt();
//
//			// 입력한 정수의 양수 음수 여부를 판별한다
//			if (userNum > 0) {
//				userCount++;
//			} else {
//				System.out.println("음의 정수를 입력하였습니다");
//			}
//
//		}
//
//		System.out.println("프로그램 종료");

		int count2 = 0;

		while (true) {
			if (count2 == 3) {
				break;
			}

			System.out.println("안녕!");
			count2++;

		}
		


	}

}
