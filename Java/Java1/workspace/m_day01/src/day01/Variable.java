package day01;

public class Variable {

	public static void main(String[] args) {
		
		
		// a : 아이디
		// b : 비밀번호
		String id = "min";
		String password = "min1234";
		
		
		// main + ctrl + 스페이스 -> main 메소드 자동완성
		// syso + ctrl + 스페이스 -> println() 메소드 자동완성
		System.out.println("안녕하세요");
		
		
		// 변수 선언
		int age;
		
		// 변수 사용
		// age 변수에 처음으로 값이 저장된다(초기화)
		age = 10;	
		System.out.println(age);
		
		// 변수 선언 및 초기화
		// 변수의 이름은 중복될수 없다
		
		int age2 = 10;
		System.out.println(age2);
		
		// age 변수에 10, 30 두개의 값이 저장되는게 아니라
		// 기존에 있는 10을 꺼내고 새로운 값 30이 저장된다
		age = 30;
		System.out.println(age);
		
		String msg = "안녕하세요";
		System.out.println(msg);
		
	
		// 변수명은 숫자부터 시작할수 없다(문자부터 시작해야 한다)
//		int 3age = 10;
		
		// 변수명에는 허용된 특수문자만 사용 가능하다(_, $만 사용가능)
//		int age4! = 20;
		
		// 변수명에는 띄어쓰기가 허용되지 않는다
//		int age 5 = 20;
		
		// 스네이크 케이스
		int my_age = 30;
		// 카멜 케이스(자바에서 주로 사용)
		int myAge = 40;
		
		// 자바에서 이름을 지을때는 한글을 사용하지 않는다
		int 나이 = 50;
		System.out.println(나이);
		
		// 키워드를 변수명으로 사용할수 없다
//		int int = 3;
		

	
	}
}
