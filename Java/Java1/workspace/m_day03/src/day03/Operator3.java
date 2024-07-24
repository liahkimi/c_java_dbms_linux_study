package day03;

import java.util.Scanner;

public class Operator3 {

	public static void main(String[] args) {

		// 관계 연산자

//		System.out.println(1 == 3);
//		System.out.println(1 != 3);
//		System.out.println(1 > 3);
//		System.out.println(1 >= 3);
//		
//		// 문자열은 일치여부를 비교할때
//		// equals() 메소드를 사용한다
//		System.out.println("AB" == "AB");
//		System.out.println("AB".equals("ABC"));
//		System.out.println(!"AB".equals("ABC"));
//		
//		String msg1 = "안녕하세요";
//		String msg2 = "안녕하세요";
//		
//		System.out.println(msg1.equals(msg2));
//		
//		// 논리 연산자
//		
//		// && (AND) : 두개다 참이라면 참
//		System.out.println(true && true);
//		System.out.println(false && true);
//
//		// || (OR) : 둘중 하나라도 참이면 참
//		System.out.println(true || true);
//		System.out.println(false || true);
//		
//		System.out.println(1 == 3 && 1 == 1);
//		System.out.println(1 == 3 || 1 == 1);
//		
//		String id = "min";
//		String pw = "min1234";
//		
//		// id.equals("min")
//		// pw.equals("min12")
//		System.out.println(id.equals("min") && pw.equals("min12"));
//		
//		int num = 15;
////		System.out.println(10 <= num <= 20);
//		// 관계연산자가 논리연산자보다 먼저 실행된다
//		System.out.println(num >= 10 && num <= 20);
//		
//		// 대입 연산자
//		// 복합 대입 연산자
//		
//		int num2 = 10;
//		
//		// num2 = num2 + 1
//		num2 += 1;
//		System.out.println(num2);
//		// num2 = num2 - 1
//		num2 -= 1;
//		System.out.println(num2);
//		// num2 = num2 * 10
//		num2 *= 10;
//		System.out.println(num2);
//		// num2 = num2 / 10
//		num2 /= 10;
//		System.out.println(num2);
//		// num2 = num2 % 3
//		num2 %= 3;
//		System.out.println(num2);
//		
		// 실습1.
		// 사용자가 입력한 사물번호와 비밀번호 일치 여부 출력하기
		// 사물함 번호 11, 비밀번호 kim

		Scanner sc = new Scanner(System.in);

		int lockerNumber = 11;
		String lockerPw = "kim";
		// 입력한 사물함 번호를 저장할 변수
		int userNumber = 0;
		// 입력한 비밀번호를 저장할 변수
		String userPw = null;

		// 결과예시:
		// 사물함 번호 입력 >> 11
		// 비밀번호 입력 >> seo
		// 사물함 번호 = true
		// 비밀번호 = false

		// 사용자에게 사물함 번호를 입력받는다
		System.out.println("사물함 번호 입력 >>");
		userNumber = sc.nextInt();
		// 사용자에게 비밀번호를 입력받는다
		System.out.println("비밀번호 입력 >>");
		userPw = sc.next();

		System.out.println("사물함 번호 = " + (userNumber == lockerNumber));
		System.out.println("비밀번호 = " + (lockerPw.equals(userPw)));

	}
}
