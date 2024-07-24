package ex02_access_modifier01;

public class AccessTest1 {

	public static void main(String[] args) {

		// Access 클래스 외부(같은 패키지)
		
		// 생성자(객체화 가능 여부)
		
		// default 생성자
		Access access1 = new Access(10); 
		// protected 생성자
		Access access2 = new Access(10.7);
		// public 생성자
		Access access3 = new Access("public");
		
		
		// 필드 
		
		// default 필드
		System.out.println(access1.defaultData);
		
		// protected 필드
		System.out.println(access1.protectedData);
		
		// public 필드
		System.out.println(access1.publicData);
		
		// private 필드
		// The field Access.privateData is not visible
//		System.out.println(access1.privateData);
		// name cannot be resolved or is not a field
//		System.out.println(access1.name);
		
		
		// 메소드
		
		// default 메소드
		access1.defaultMethod();
		
		// protected 메소드
		access1.protectedMethod();
		
		// public 메소드 
		access1.publicMethod();
		
		// private 메소드
		// The method privateMethod() from the type Access is not visible
//		access1.privateMethod();
		// The method method1() is undefined for the type Access
//		access1.method1();
		
		
		
		
		
		
	}

}
