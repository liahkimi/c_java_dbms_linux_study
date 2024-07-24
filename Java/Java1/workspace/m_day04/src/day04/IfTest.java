package day04;

public class IfTest {

	public static void main(String[] args) {

		// if문
		
		int num = -10;
		
		if(num > 0) {
			System.out.println("양수 입니다");
		}
		
		boolean bool = false;
		
		if(bool) {
			System.out.println("bool 변수의 값이 true이면 실행할 코드");
		}
		
		if(!bool) {
			System.out.println("bool 변수의 값이 false이면 실행할 코드");
		}
		
		if(bool == false) {
			System.out.println("bool 변수의 값이 false이면 실행할 코드2");
		}
		
		String id = "min";
		
		if(id.equals("min1")) {
			// id 변수의 문자열 값과 min1 문자열 값이 일치하면
			System.out.println("로그인 성공");
		}
		
		if(!id.equals("min1")) {
			// id.equals("min1") == false
			// id 변수의 문자열 값과 min1 문자열 값이 일치하지 않으면
			System.out.println("로그인 실패");
		}
		
		
		// if-else문
		
		if(id.equals("min1")) {
			System.out.println("로그인 성공");
		}else {
			System.out.println("로그인 실패");
		}
		
		
		if(num > 0) {
			System.out.println("양수 입니다");
		}else {
			System.out.println("음수 입니다");
		}
		
		
		// if-else if문
		
		if(num > 0) {
			System.out.println("양수 입니다");
		}else if(num == 0) {
			System.out.println("0 입니다");
		}else {
			System.out.println("음수 입니다");
		}
		
		
		// else의 특징
		// else는 단독으로 사용할수 없고, 여러개의 if문이 있다면
		// 가장 가까운 if문과 연결된다
		
		int num2 = 100;
		
		if(num2 == 100) {
			System.out.println("100 입니다");
		}
		
		if(num2 == 1000) {
			System.out.println("1000 입니다");
		}
	
		else {
			System.out.println("둘다 아닙니다");
		}
		
		
		
		
		
		
		
		
	}

}
