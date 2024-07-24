package ex01_class02;

import java.util.Arrays;

import ex01_class01.ClassA;

public class ClassTest {

	public static void main(String[] args) {

		InstanceClass it = new InstanceClass(200);
		
		// 명시적 초기화
		System.out.println(it.data1);
		
		// 생성자 
		System.out.println(it.data2);
		
		// 인스턴스 초기화 블록
		System.out.println(Arrays.toString(it.instanceAr));
		
		// 객체 필드
		ClassA classA = new ClassA(10);
		
		InstanceClass it2 = new InstanceClass(classA);
		InstanceClass it3 = new InstanceClass(new ClassA(20));
		
		System.out.println(it2.instance);
		System.out.println(it3.instance);
		
		// 스태틱 필드 명시적 초기화
		System.out.println(StaticClass.staticData1);
		
		// 스태틱 초기화 블럭
		System.out.println(StaticClass.staticAr);
		System.out.println(Arrays.toString(StaticClass.staticAr));
		
		
	}

}
