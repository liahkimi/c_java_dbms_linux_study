package ex01_class01;

import java.util.Arrays;

public class ClassB {

	// 메소드(method)
	
	// 매개변수 : 기본자료형
	void printData(int data) {
		System.out.println("기본 자료형 " + data);
	}
	
	
	// 매개변수 : 배열
	void printAr(int[] ar) {
		System.out.println("배열 " + ar);
		System.out.println("배열의 요소 " + Arrays.toString(ar));
	}
	
	
	// 매개변수 : 클래스
	// ClassA instance = 객체;
	void printInstance(ClassA instance) {
		System.out.println("객체 " + instance);
		System.out.println("객체의 필드 " + instance.data);
		
	}
	
	// 리턴타입 : 기본타입
	int changeData(int data) {
		data = 77;
		return data;
	}
	
	// 리턴타입 : 배열
	int[] changeAr(int[] ar) {
		ar[0] = 1000;
		return ar;
	}
	
	// 리턴타입 : 클래스 -> 객체를 리턴하겠다
	ClassA changeInstance(ClassA instance) {
		instance.data = 99;
		return instance;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
