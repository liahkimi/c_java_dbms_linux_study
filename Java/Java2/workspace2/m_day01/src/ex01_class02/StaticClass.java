package ex01_class02;

public class StaticClass {

	
	// 명시적 초기화
	static int staticData1 = 100;
	
	// 스태틱 초기화 블럭
	static int[] staticAr;
	
	static {
		System.out.println("스태틱 초기화 블록");
		staticAr = new int[] {5,6,7};

	}
	
	
}
