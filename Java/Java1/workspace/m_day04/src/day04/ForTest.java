package day04;

public class ForTest {

	public static void main(String[] args) {

		// for문

		// i 변수의 값을 0으로 초기화하고, i 가 10보다 작은동안
		// i 의 값을 1씩 증가하면서 코드를 반복실행하겠다
		// 제어변수를 가지고 증감을 하면서 조건식이 참인동안 코드를 반복 실행
		for (int i = 0; i < 3; i++) {
			System.out.println("홍길동");
		}

		// 제어변수 i는 for문 영역 안에서만 사용이 가능하다
//		System.out.println(i);

		for (int i = 0; i < 3; i++) {
			System.out.println(i);
		}

		// i의 값을 감소시키면서 코드를 반복
		for (int i = 3; i > 0; i--) {
			System.out.println(i);
		}

		// i의 값을 2씩 증가시키면서 코드를 반복
		for (int i = 0; i < 10; i += 2) {
			System.out.println(i);
		}

		// main 메소드 영역에서 선언된 변수를
		// for문 영역에서 사용할수 있다
		// 대신에 증감식을 통해 값이 변화된다
		int num = 0;
		for (; num < 5; num++) {
			System.out.println("num = " + num);
		}

		System.out.println(num);

		String name = "홍길동";
		for (int i = 0; i < 3; i++) {
			System.out.println(name);
			String name2 = "김길동";
			System.out.println(name2);
		}

		// for문 영역에서 선언된 변수이기때문에
		// for문 영역을 벗어나면 사용 불가
//		System.out.println(name2);

	}

}
