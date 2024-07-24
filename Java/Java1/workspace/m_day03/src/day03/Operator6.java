package day03;

import java.util.Scanner;

public class Operator6 {

	public static void main(String[] args) {

		// 조건식
		System.out.println(10 > 0);
		System.out.println(10 > 0 && 10 > 11);
		System.out.println("ABC".equals("ABC"));

		// 삼항 연산자
		// 조건식 ? 조건식이 참이면 사용할 값 : 거짓이면 사용할 값
		String result = 10 > 0 ? "양수" : "음수";
		System.out.println(result);

		// 사용자에게 정수를 입력받고 홀수, 짝수여부를 출력하기

		Scanner sc = new Scanner(System.in);
		// 사용자에게 입력받은 정수를 저장할 변수
		int num = 0;
		// 홀짝여부를 저장할 변수
		String result2 = null;

		// 사용자에게 정수를 입력받는다
		System.out.println("정수를 입력하세요 >>");
		num = sc.nextInt();

		// 입력받은 정수의 홀짝여부를 판단하여 결과를 저장한다
		result2 = num % 2 == 0 ? "짝수" : "홀수";
		System.out.println(result2);

	}

}
