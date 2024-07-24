package day07;

import java.util.Arrays;

public class MethodTest2 {

	// 정수형 값을 출력하는 메소드
	void printData(int data) {
		System.out.println("정수형 데이터 = " + data);
//		System.out.println(data2);
		int data3 = 1000;
	}
	
	// 정수형 배열의 값을 출력하는 메소드
	void printAr(int[] methodAr) {
		System.out.println("배열 데이터 = " + methodAr);
		System.out.println(Arrays.toString(methodAr));
		
	}
	
	// 정수형 데이터를 30으로 변경하는 메소드
	int changeData(int data) {
		data = 30;
		return data;
	}
	
	// 정수형 배열의 데이터를 100, 200, 300으로 변경하는 메소드
	void changeAr(int[] methodAr) {
		for(int i = 0; i < methodAr.length; i++) {
			methodAr[i] *= 10;
		}
		
//		return methodAr;
	}
	
	
	public static void main(String[] args) {

		// ar 변수에는 1개의 주소값이 저장되어있다
		int[] ar = {10, 20, 30};
		System.out.println(ar);
		
		int data = 10;
		MethodTest2 mt = new MethodTest2();
		int data2 = 100;
		
		// 전달한 인수 data의 10 값을 복사하여 매개변수에 저장한다
		mt.printData(data);
		
		System.out.println(data);
		
		// 반환한 값을 재사용하기 위해 변수에 담는다
		data = mt.changeData(data);
		System.out.println(data);
		
		// data3는 메소드 내에서 선언된 변수이므로 접근할수 없다
//		System.out.println(data3);
		
		// 배열의 값을 출력하는 메소드
		mt.printAr(ar);
		// 배열의 값을 변환하는 메소드
		mt.changeAr(ar);
	
		// 배열은 참조 자료형이기 때문에 매개변수에는 heap 메모리 영역에 있는
		// 배열의 주소값을 저장하게 된다. 저장된 주소값을 따라 heap 메모리 영역에 
		// 있는 배열을 접근할수 있고, 값을 변경하게 되면 메소드 밖에서 사용하는
		// 배열의 주소값을 저장한 변수에도 똑같이 영향을 받게 된다(동일한 배열이므로)
		
		// 전달된 주소값을 통해 배열의 값을 변경하므로 리턴하지 않아도,
		// 리턴값을 다시 변수에 담지 않아도 값의 변경이 적용된다
		System.out.println(Arrays.toString(ar));
		
		// call by value : 메소드의 매개변수에 값을 전달한다
		// call by reference : 메소드의 매개변수에 참조를 전달한다
		
		// 기본 자료형 매개변수, 참조 자료형 매개변수 둘다 인수로 전달한 값을
		// 복사하여 매개변수에 저장하여 사용하기 때문에 call by value

		
		
	}

}
