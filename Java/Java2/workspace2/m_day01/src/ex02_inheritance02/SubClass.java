package ex02_inheritance02;

public class SubClass extends SuperClass {

	// 필드
	int subData;
	
	int superData = 100;
	
	// 생성자

	public SubClass(int subData, int superData) {
		// 매개변수가 1개 있는 부모 생성자를 호출한다
		// 부모 필드를 초기화 하기 위한 값을 전달한다
		// 부모필드는 부모 생성자에서 초기화한다
		// 자식필드는 자식 생성자에서 초기화한다
		super(superData);
		this.subData = subData;
		System.out.println("자식 클래스 생성자1");
	}

	public SubClass() {
		// 매개변수가 없는 부모 생성자를 호출한다
		super();
		System.out.println("자식 클래스 생성자2");
	}
	
	// 메소드 
	
	void subMethod() {
		superMethod();
		super.superMethod();
	}
	
	void subMethod2() {
		// 자식 클래스에서 선언한 필드
		System.out.println(this.superData);
		// 부모 클래스에서 상속받은 필드
		System.out.println(super.superData);
		
		System.out.println(superData);
	}
	
	// 메소드 오버라이딩
	void superMethod2() {
		System.out.println("재정의된 부모 클래스 메소드");
	
	}
	
	void subMethod3() {
		// 자식클래스에서 선언된 메소드(오버라이딩된 메소드)
		this.superMethod2();
		// 부모클래스에서 선언된 메소드
		super.superMethod2();
	}
	

	
	
}
