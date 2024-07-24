package day07;

public class MethodTest {
	
	
	// 매개변수의 자료형을 다르게 하여 오버로딩
	void printData(int data) {
		System.out.println("정수형 데이터 = " + data);
	}
	
	void printData(String data) {
		System.out.println("문자열 데이터 = " + data);
	}
	
	void printData(boolean data) {
		System.out.println("논리형 데이터 = " + data);
	}
	
	// 매개변수의 개수를 다르게하여 오버로딩
	void printData(int data1, int data2) {
		System.out.println("정수형 데이터1 = " + data1);
		System.out.println("정수형 데이터2 = " + data2);
	}
	
	// 매개변수의 순서를 다르게 하여 오버로딩
	void printData(String data1, int data2) {
		System.out.println("정수형 데이터 = " + data2);
		System.out.println("문자열 데이터 = " + data1);
	}
	
	void printData(int data1, String data2) {
		System.out.println("정수형 데이터 = " + data1);
		System.out.println("문자열 데이터 = " + data2);
	
	}
	
	// 리턴타입은 오버로딩에 영향을 주지 않는다
//	int printData(int data1, String data2) {
//		return data1;
//	}
	


	public static void main(String[] args) {

		
		// 메소드 오버로딩 
		
		System.out.println(10);
		System.out.println("hello");
		System.out.println(true);
		
		MethodTest mt = new MethodTest();
		
		// 메소드 오버로딩으로 인해 하나의 메소드를 3번
		// 호출하는것이 아니라 메소드 3개를 호출하는것
		
		mt.printData(10);
		mt.printData("hello");
		mt.printData(true);
		
		
		
		
		
	}

}
