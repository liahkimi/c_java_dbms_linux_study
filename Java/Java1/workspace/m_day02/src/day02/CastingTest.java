package day02;

public class CastingTest {

	public static void main(String[] args) {

		// 강제 형변환(명시적 형변환)

		// double 값 -> float 값
		float floatVar = (float) 10.3;
		System.out.println((float) 10.9);
		System.out.println((float) 9.123456789);

		// long 값-> int 값
		int intVar = (int) 3L;
		System.out.println((int) 3L);
		System.out.println((int) 2147483648L);

		// 실수형 -> 정수형
		int intVar2 = (int) 13.7;
		System.out.println(intVar2);

		// 문자형
		System.out.println((int) 'A');
		System.out.println((char) 65);

		// 논리형
		// 논리형은 자동 형변환, 강제 형변환 둘다 불가능하다
//		System.out.println((int)true);
//		System.out.println((int)false);
//		System.out.println((char)true);
//		System.out.println((double)true);

		// 문자열
		System.out.println(13 + "ABC");
		System.out.println(true + "입니다");

		System.out.println(13 + "");
		String strVar = 13 + "";
		
		// 다른 자료형 -> 문자열
		
		String doubleStr = 13.9 + "";
		String booStr = true + "";
		String charStr = 'A' + "";
		
		// 문자열 -> 다른 자료형
		
		int strInt = Integer.parseInt("19");
//		int strInt2 = Integer.parseInt("안녕");
		
		System.out.println(strInt);
		// "안녕" 문자열은 정수로 변환할수 없어서 에러가 발생한다
//		System.out.println(strInt2);
		
		double strDou = Double.parseDouble("13.7");
		// "안녕" 문자열은 실수로 변환할수 없어서 에러가 발생한다
//		double strDou2 = Double.parseDouble("안녕");
		
		double strDou3 = Double.valueOf("1.25");
		System.out.println(strDou3);
		
		// 문자형
		String msg = "가나다라";
		
		char spell = msg.charAt(0);
		// 문자열에서 존재하지 않는 자리번호를 사용했기때문에 에러 발생
//		char spell2 = msg.charAt(10);
		
		

	}

}
