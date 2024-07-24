package day03;

public class Operator1 {

	public static void main(String[] args) {

		// 단항 연산자

		int num = 10;
		System.out.println(+num);
		System.out.println(-num);

		// 변수에 저장된 값은 변경되지 않는다
		System.out.println(num);
		// 변수에 음수값을 저장하기 위해 대입연산자 사용
		num = -num;
		System.out.println(num);

		// 논리 부정(!)
		boolean isTrue = true;

		System.out.println(isTrue);
		System.out.println(!isTrue);

		System.out.println(isTrue);

		// 증감 연산자
		int num2 = 5;

		// 증가 연산자
		// num2++ : num2 = num2 + 1
		// 후위형(변경된 값이 다음 라인부터)
		System.out.println(num2++);
		System.out.println(num2);

		// 전위형(변경된 값이 현재 라인부터)
		System.out.println(++num2);
		System.out.println(num2);

		// 변수에 담기지 않은 값에다가 바로 사용할수 없다
//		System.out.println(5++);

		num2 = 5;

		// 후위형
		System.out.println(num2--);
		System.out.println(num2);

		// 전위형
		System.out.println(--num2);
		System.out.println(num2);

	}

}
