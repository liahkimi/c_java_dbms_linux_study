package ex01_class01;

import java.util.Arrays;

public class ClassTest {

	public static void main(String[] args) {

		
		ClassB classB = new ClassB();
		
		// 기본 자료형 매개변수
//		classB.printData(10);
		
		int num = 20;
//		classB.printData(num);
		
		// 배열 매개변수(참조자료형)
//		classB.printAr(new int[3]);
		
		int[] ar = {10, 20, 30};
		classB.printAr(ar);
		
		// 객체(클래스) 매개변수(참조자료형)
//		classB.printInstance(new ClassA(30));
		
		ClassA classA = new ClassA(100);
		classB.printInstance(classA);
		
		// 리턴타입 기본자료형
		// num을 매개변수로 전달받아 값을 77로 변경하는 메소드
		System.out.println(num);
		classB.changeData(num);
		System.out.println(num);
		
		// 변경된 값을 외부에서 다시 사용하려면 리턴받은 값을 저장해야한다
		num = classB.changeData(num);
		System.out.println(num);
		
		// 리턴타입 배열
		System.out.println(ar);
		System.out.println(Arrays.toString(ar));
		
		classB.changeAr(ar);
		System.out.println(ar);
		System.out.println(Arrays.toString(ar));
	
		// 리턴타입 클래스
		System.out.println(classA);
		System.out.println(classA.data);
		
		classB.changeInstance(classA);
		System.out.println(classA);
		System.out.println(classA.data);
		
		
		
		
		
		
		
		
		
		
	}

}
