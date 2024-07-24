package day03;

public class Operator4 {

	public static void main(String[] args) {

		// 비트 연산자
		
		System.out.println(Integer.toBinaryString(10));
		System.out.println(Integer.toBinaryString(11));
		
		// &(논리곱) : 두 비트가 모두 1이면 1
		System.out.println(10 & 11);
		
		// |(논리합) : 두 비트중 하나라도 1이면 1
		System.out.println(10 | 11);
		
		// ^(베타논리합) : 두 비트가 서로 다르면 1
		System.out.println(10 ^ 11);
		
		// ~(논리부정) : 비트를 반대로 바꾼다(0->1, 1->0)
		System.out.println(~10);

		// 쉬프트 연산자
		System.out.println(10 >> 1);
		System.out.println(10 << 1);
		
		
		
	}

}
