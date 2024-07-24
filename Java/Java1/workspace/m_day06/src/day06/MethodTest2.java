package day06;

public class MethodTest2 {

	// 메소드 선언 및 구현(메소드 생성)
	void printHello() {
		for (int i = 0; i < 3; i++) {
			System.out.println("hello");
		}
	}

	// int num1 = 10;
	// int num2 = 3;
	void printSum(String num1, int num2) {
		System.out.println(num1 + num2);
	}

	void printEvenTotal() {
		int total = 0;

		for (int i = 1; i < 51; i++) {
			if (i % 2 == 0) {
				total += i;
			}
		}
		System.out.println(total);
	}

	boolean isEvenNum(int num) {

		// if 문 사용
//		if(num % 2 == 0) {
//			return true;
//		}else {
//			return false;
//		}

		return num % 2 == 0 ? true : false;
	}

	public static void main(String[] args) {

		MethodTest2 mt = new MethodTest2();
		
		// 메소드1.
		// "hello" 문자열을 3번 출력한다
		/*
		 * 리턴타입 : void 메소드명 : printHello 자료형 매개변수명 : X 실행할 코드 :
		 */
		
		// 메소드 호출(사용)
		mt.printHello();
		System.out.println("printHello() 호출 완료!");
	

		// 메소드2.
		// 두개의 정수의 합계를 출력한다
		/*
		 * 리턴타입 : void 메소드명 : printSum 자료형 매개변수명 : int num1, int num2 실행할 코드 :
		 * System.out.println(num1 + num2);
		 */
		
		// 메소드의 매개변수의 자료형와 개수, 순서에 일치해야 한다
		mt.printSum("10", 3);

		// 메소드3.
		// 1~50까지 정수중에 짝수의 합계를 출력한다
		/*
		 * 리턴타입 : void 메소드명 : printEvenTotal 자료형 매개변수명 : X 실행할 코드 :
		 */
		
		mt.printEvenTotal();
		

		// 메소드4.
		// 전달한 정수의 짝수 여부를 구한다
		/*
		 * 리턴타입 : boolean 메소드명 : isEvenNum 자료형 매개변수명 : int num 실행할 코드 :
		 */

		boolean result = mt.isEvenNum(17);
		System.out.println(result);
		
		
		
	}

}
