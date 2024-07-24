package day04;

import java.util.Scanner;

public class Operator {

	public static void main(String[] args) {

		// 삼항 연산자
		int num = 0;
		String result = num > 0 ? "양수" : "음수";
		// 삼항 연산자는 연산의 결과가 1개 이기때문에
		// 삼항 연산자의 참 또는 거짓 자리에도 사용이 가능하다
		String result2 = num > 0 ? "양수" : num == 0 ? "0입니다" : "음수";

		System.out.println(result);
		System.out.println(result2);

		// 실습1.
		// 사용자에게 나이를 입력받고, 취득 가능한 면허를 출력하기
		// 19세 이상 자동차 운전면허
		// 17세 이상 오토바이 운전면허
		// 17세 미만 도보 가능
		// 삼항 연산자를 사용

		Scanner sc = new Scanner(System.in);
		// 입력한 나이를 저장할 변수
		int age = 0;
		// 결과를 저장할 변수
		String result3 = null;

		// 사용자에게 나이를 입력받는다
		System.out.println("나이 입력 >>");
		age = sc.nextInt();

		// 입력받은 나이를 통해 결과를 저장한다
		result = age >= 19 ? "자동차 운전면허" : age >= 17 ? "오토바이 운전면허" : "도보";

		// 결과를 출력한다
		System.out.println(result + "가능합니다");

	}

}
