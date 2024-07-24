package day02;

public class PromotionTest {

	public static void main(String[] args) {

		// 자동 형변환(묵시적 형변환)

		// 작은 자료형 -> 큰 자료형

		// int -> long
		// int 3을 long 3으로 자동 형변환한 후에 값을 저장한다
		long longVar = 3;

		// float -> double
		// float 10.7f를 double 10.7로 자동 형변환 후에 값을 저장한다
		double doubleVar = 10.7f;

		// 저장공간의 크기가 값의 크기보다 작기때문에 자동 형변환 되지 않고
		// 값을 저장할수도 없다
//		int intVar = 3L;
//		float floatVar = 3.9;

		// 정수형 -> 실수형

		// int -> double
		double doubleVar2 = 10;

		// int -> float
		float floatVar2 = 3;

		// long -> double
		double doubleVar3 = 10L;

		// long -> float
		float floatVar3 = 3L;

		// 문자형와 정수형
		// char -> int
		int intVar2 = 'A';

		// int -> char
		char charVar = 65;

		// 아스키코드값이 존재하기때문에 해당하는 코드값으로 자동 형변환된다
		System.out.println(intVar2);
		System.out.println(charVar);

		// 논리형
		// boolean은 다른 자료형으로 자동 형변환되지 않는다
//		int intVar3 = true;
//		char charVar2 = true;

		// 오버플로우
		// 자료형이 표현할수 있는 최대범위보다 큰 수를 저장할때
		// 최솟값을 얻게되는 현상

		int num1 = 2147483647;
//		int num2 = 2147483648;
		long longNum = 2147483648L;

		// int 의 최소값 : -2147483648
		System.out.println(num1 + 1);

		// 언더플로우
		// 자료형이 표현할수 있는 최소범위보다 작은 수를 저장할때
		// 최대값을 얻게되는 현상

		int num3 = -2147483648;
//		int num4 = -2147483649;

		// int 의 최대값 : 2147483647
		System.out.println(num3 - 1);

	}

}
