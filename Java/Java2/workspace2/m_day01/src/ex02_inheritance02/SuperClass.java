package ex02_inheritance02;

public class SuperClass {

	// 필드
	
	int superData;

	// 생성자(alt + shift + s + o)
	
	public SuperClass(int superData) {
		super();
		this.superData = superData;
		System.out.println("부모 클래스 생성자1");
	}

	public SuperClass() {
		super();
		System.out.println("부모 클래스 생성자2");
	}
	
	// 메소드
	
	void superMethod() {
		System.out.println("부모 클래스 메소드");
	}
	
	void superMethod2() {
		System.out.println("부모 클래스 메소드2");
	}
	

	
}
