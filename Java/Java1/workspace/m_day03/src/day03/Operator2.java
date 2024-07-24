package day03;

import java.util.Scanner;

public class Operator2 {

	public static void main(String[] args) {

		// 산술 연산자
		
		int num1 = 10;
		int num2 = 3;
		
		System.out.println(num1 + num2);
		System.out.println(num1 - num2);
		System.out.println(num1 * num2);
		System.out.println(num1 / num2);
		System.out.println(num1 % num2);
		
		// 10 / 3 -> 3(int / int = int)
		// 10 / 3.0 -> 3.33333333(int / double = double)
	
		System.out.println(num1 / (double)num2);
		
		// 문자열(String)은 연산이 아닌 연결이다
		System.out.println("kim" + "hong");
		
		// 실습1.
		// 사용자에게 수학점수, 국어점수, 영어점수를 입력받아
		// 합계점수와 평균점수를 출력하기
		
		// 결과예시 : 100, 90, 100
		// 합계점수 = 290
		// 평균점수 = 96.66666666666667...
		
		// import : ctrl + shift + o
		Scanner sc = new Scanner(System.in);
		// 수학점수를 저장할 변수
		int math = 0;
		// 국어점수를 저장할 변수
		int kor = 0;
		// 영어점수를 저장할 변수
		int eng = 0;
		// 합계점수를 저장할 변수
		double sum = 0; 
		// 평균점수를 저장할 변수
		double avg = 0;
		
		System.out.println("수학점수 입력 >> ");
		math = sc.nextInt();
		System.out.println("국어점수 입력 >> ");
		kor = sc.nextInt();
		System.out.println("영어점수 입력 >> ");
		eng = sc.nextInt();
		
		// 변수에 합계점수를 저장한다
		sum = math + kor + eng;
		
		// 변수에 평균점수를 저장한다
		avg = sum / 3;
		
		// 저장된 변수의 값을 출력한다
		System.out.println("합계점수 = " + sum);
		System.out.println("평균점수 = " + avg);
		
		// 평균점수가 96이 나오는경우
		// 평균점수가 96.0이 나오는경우
		// 평균점수가 정확하게 나오는 경우
		
		
		

		
		
	}

}
