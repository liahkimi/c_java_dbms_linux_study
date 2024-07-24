package ex04_casting;

public class Child extends Parent{

	// 필드
	int childData;

	// 생성자
	public Child(int parentData, int childData) {
		super(parentData);
		this.childData = childData;
	}

	// 메소드
	void childMethod() {
		System.out.println("child method");
	}
	
	@Override
	void parentMethod2() {
		System.out.println("오버라이딩된 parent method2");
	}
	
	
	
}
