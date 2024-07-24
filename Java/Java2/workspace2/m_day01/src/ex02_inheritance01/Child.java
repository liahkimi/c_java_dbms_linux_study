package ex02_inheritance01;

// 상속받겠다 어떤 클래스를
// extends 부모 클래스명
public class Child extends Parent{

	
	// 필드(field)
	int childData;
	
	// 메소드(method)
	void childMethod() {
		System.out.println("자식 클래스 메소드");
	}
	
	// 부모클래스의 메소드를 자식클래스의 메소드 안에서 호출할수 있다
	void childMethod2() {
		// 부모클래스 메소드 호출
		parentMethod();
		
		// 부모클래스 필드 호출
		System.out.println(parentData);
		
	}


	
}
