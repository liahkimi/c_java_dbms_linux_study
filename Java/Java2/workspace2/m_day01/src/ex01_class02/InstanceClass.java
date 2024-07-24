package ex01_class02;

import ex01_class01.ClassA;

public class InstanceClass {

	
	// 명시적 초기화
	int data1 = 10;
	
	// 생성자 초기화
	int data2;
	
	InstanceClass(int data2){
		System.out.println("생성자 호출");
		this.data2 = data2;
	}
	
	// 인스턴스 초기화 블록
	int[] instanceAr;
	
	{
		System.out.println("인스턴스 초기화 블록");
		instanceAr = new int[] {100, 200, 300};
	}
	
	// 객체 필드
	ClassA instance;
	
	InstanceClass(ClassA instance){
		this.instance = instance;
	}
	

	
	
	
	
	
	
}
