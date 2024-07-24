package day04;

import java.util.Scanner;

public class IfTest2 {

	public static void main(String[] args) {

		// 사용자에게 나이를 입력받고, 나이에 따라 출력하기
		// 20살 미만이면 미성년자
		// 20살 이상이면 성인
		// 음수 입력시 잘못된 입력

//		Scanner sc = new Scanner(System.in);
//		int age = 0;
//		
//		System.out.println("나이 입력 >>");
//		age = sc.nextInt();
//		
//		if(age >= 20) {
//			System.out.println("성인");
//		}else if(age > 0) {
//			// 0 < age < 20
//			System.out.println("미성년자");
//		}else {
//			// age <= 0
//			System.out.println("잘못된 입력");
//		}

		// 실습1.
		// 사용자에게 점수를 입력받고 등급을 출력하기
		// 최대점수 = 100, 최하점수 = 0
		// 90점 이상 : A등급
		// 80점 이상 : B등급
		// 70점 이상 : C등급
		// 70점 미만 : F등급

		// 결과예시 : 점수를 입력하세요 >> 97
		// A등급 입니다

//		Scanner sc = new Scanner(System.in);
//		// 입력한 점수를 저장할 변수
//		int score = 0;
//		// 등급을 저장할 변수
//		String grade = null;
//		
//		// 사용자에게 점수를 입력받는다
//		System.out.println("점수를 입력하세요 >>");
//		score = sc.nextInt();
//		
//		// 입력한 점수에 따라 등급을 저장한다
//		if(score >= 90) {
//			// 90 <= score <= 100
//			grade = "A등급";
//		}else if(score >= 80) {
//			// 80 <= score < 90
//			grade = "B등급";
//		}else if(score >= 70) {
//			// 70 <= score < 80
//			grade = "C등급";
//		}else {
//			grade = "F등급";
//		}
//		
//		System.out.println(grade + " 입니다");

		// 실습2.
		// 사용자에게 주민번호 맨 뒷자리(한자리)를 입력받고 해당 일자에 따라
		// 예방접종일을 출력하기

		// 뒷자리가 1,6이면 월
		// 뒷자리가 2,7이면 화
		// 뒷자리가 3,8이면 수
		// 뒷자리가 4,9이면 목
		// 뒷자리가 5,0이면 금

		// 결과예시 : 주민번호 뒷자리를 입력(한자리) >> 3
		// 예방접종일은 수요일 입니다

		Scanner sc = new Scanner(System.in);
		// 입력한 번호를 저장할 변수
		int number = 0;
		// 결과를 저장할 변수
		String day = null;

		// 사용자에게 주민번호 뒷자리를 입력받는다
		System.out.println("주민번호 뒷자리를 입력(한자리) >> ");
		number = sc.nextInt();

		// 입력받은 주민번호 뒷자리로 결과를 판별한다
		if (number < 0 || number > 9) {
			System.out.println("잘못된 입력입니다");
		} else if (number == 1 || number == 6) {
			day = "월요일";
		} else if (number == 2 || number == 7) {
			day = "화요일";
		} else if (number == 3 || number == 8) {
			day = "수요일";
		} else if (number == 4 || number == 9) {
			day = "목요일";
		} else {
			day = "금요일";
		}

		if (day != null) {
			System.out.println(day + " 입니다");
		}

		// 나머지를 이용하여 판별하는 방법

		if (number % 5 == 1) {
			day = "월요일";
		} else if (number % 5 == 2) {
			day = "화요일";
		} else if (number % 5 == 3) {
			day = "수요일";
		} else if (number % 5 == 4) {
			day = "목요일";
		} else if (number % 5 == 0) {
			day = "금요일";
		}

	}

}
