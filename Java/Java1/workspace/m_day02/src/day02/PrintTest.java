package day02;

public class PrintTest {

	public static void main(String[] args) {

		// 출력 메소드

		System.out.println("안녕하세요");
		System.out.println("여러분");

		// print(): 전달한 값을 출력하고 자동 줄바꿈 되지 않는다
		System.out.print("안녕하세요");
		System.out.print("여러분\n");

		// 서식문자

		String weather = "맑음";
		int month = 12;
		int date = 10;
		double max = 16.123456789;
		double min = 8.123;

		System.out.println("오늘의 날씨는 맑음입니다");
		System.out.println("오늘의 날씨는 " + weather + " 입니다");

		System.out.printf("오늘의 날씨는 %s 입니다\n", weather);
		// %d : 십진수 정수
		System.out.printf("오늘은 %d 월입니다\n", month);
		// %f : 실수
		// %f는 소수점 7번째 자리에서 반올림하여 6번째 자리까지 출력한다
		System.out.printf("오늘의 최고기온은 %f도 입니다\n", max);
		System.out.printf("오늘의 최저기온은 %f도 입니다\n", min);
		// %.Nf : 반올림하여 소수점 N번째 자리까지 출력한다
		System.out.printf("오늘의 최저기온은 %.3f도 입니다\n", min);

		// 문자열: 문자의 나열이다
		String menu = "코카콜라";
		// 문자열에서 지정한 개수의 문자만 출력한다
		System.out.printf("%.2s의 가격은 1000원 입니다\n", menu);

		// 실습1.
		// 원주율 perimeter 의 값을 3.1416으로 출력하기
		// printf() 를 사용하여 출력

		double perimeter = 3.14159265358979;

		// 지정한 자리까지 반올림하여 출력한다
		System.out.printf("원주율 = %.4f\n", perimeter);
		
		// 제어문자
		
		System.out.println("줄바꿈\n연습");
		System.out.println("\t탭 연습");
		System.out.println("\'이것\'을 강조");
		System.out.println("안녕은 \"hello\"입니다");
		
		// 실습1.
		// 출력메소드를 1번만 사용하여 아래와 같이 출력하기
		// 실행결과 :
		// 봄
		// 		여름
		// 가을 
		// 		겨울
		
		System.out.println("봄\n\t여름\n가을\n\t겨울");
		

	}

}
