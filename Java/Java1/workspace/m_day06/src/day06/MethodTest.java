package day06;

public class MethodTest { // 클래스 영역 시작

	// 메소드를 만들때는 클래스 영역 안에서 만든다
	// 단, 다른 메소드 영역에서는 만들지 않는다
	
	/*
	 * 리턴타입 메소드명(자료형 매개변수명) {
	 * 		실행할 코드
	 * 		return 리턴값;
	 * }
	 */
	
	// 전달해준 문자열을 5번 출력하는 기능을 사용하고 싶다
	// 리턴타입 : void (출력만 하면 되기때문에 반환받을 값이 없다 
	// 메소드명 : printFiveTimes
	// (자료형 매개변수명) : 문자열 매개변수 1개
	
	void printFiveTimes(String msg) {
		for(int i = 0; i < 5; i++) {
			System.out.println(msg);
		}
	}
	
	
	public static void main(String[] args) { // 메인 메소드 영역 시작

		// 안녕하세요 문자열을 5번 출력한다
		for(int i = 0; i < 5; i++) {
			System.out.println("안녕하세요");
		}
		

		// 안녕! 문자열을 5번 출력한다
		for(int i = 0; i < 5; i++) {
			System.out.println("안녕!");
		}
		
		for(int i = 0; i < 5; i++) {
			System.out.println("메리크리스마스!");
		}
	
		MethodTest mt = new MethodTest();
		mt.printFiveTimes("bye");
		
		
		
	} // 메인 메소드 영역 끝

} // 클래스 영역 끝
