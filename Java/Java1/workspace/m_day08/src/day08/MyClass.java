package day08;

public class MyClass {

	// 필드(field)
	
	// 인스턴스 필드
	int instanceField;
	
	// 스태틱 필드
	static int staticField;

	// 메소드(method)
	// 인스턴스 메소드
	void instanceMethod() {
		System.out.println("instanceMethod");
		System.out.println(instanceField);
		// 인스턴스 메소드는 스태틱 필드를 사용할수 있다
		System.out.println(staticField);
	}
	
	// 스태틱 메소드
	static void staticMethod() {
		System.out.println("staticMethod");
		// 스태틱 메소드는 인스턴스 필드를 사용할 수 없다
		// System.out.println(instanceField);
		System.out.println(staticField);
		
		
	}
	
	void methodA(int parameter) {
		int localVariable = 10;
		
		// 매개변수
		System.out.println(parameter);
		// 지역변수
		System.out.println(localVariable);
		// 인스턴스 필드(전역변수)
		System.out.println(instanceField);
		// 스태틱 필드(전역변수)
		System.out.println(staticField);
		
		// 필드와 동일한 이름으로 지역변수를 선언했기때문에
		// 필드가 아닌 지역변수로 사용하게 된다
		String instanceField = "hello";
		// 지역변수
		System.out.println(instanceField);
		// 필드
		System.out.println(this.instanceField);
		
	}

	
	public static void main(String[] args) {
	
		// 스태틱 메소드 : 클래스명.메소드명();
		MyClass.staticMethod();
		
		// 스태틱 필드 : 클래스명.필드명;
		System.out.println(MyClass.staticField);
		
		MyClass mc = new MyClass();
		
		// 인스턴스 메소드 : 객체명.메소드명();
		mc.instanceMethod();
		
		// 인스턴스 필드 : 객체명.필드명;
		System.out.println(mc.instanceField);
		
		System.out.println("================");
		mc.methodA(100);
		
	}

}
