package ex02_abstract1;

public abstract class AbstractClass {

	/*
	 * method1() : 구현된 메소드(일반메소드) -> 자식에서 재정의를 선택해서 사용
	 * method2() : 미구현된 메소드(추상메소드) -> 자식에서 반드시 재정의
	 */
	
	// 필드(field)
	int abstractData;

	// 생성자(constructor)
	public AbstractClass(int abstractData) {
		super();
		this.abstractData = abstractData;
	}
	
	public AbstractClass() {;}
	
	// 메소드(method)
	void method1() {
		System.out.println("부모의 구현된 메소드");
	}
	
	abstract void method2();
	

	
}
