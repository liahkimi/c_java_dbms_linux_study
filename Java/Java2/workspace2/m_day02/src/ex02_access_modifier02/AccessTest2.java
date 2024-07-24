package ex02_access_modifier02;

import ex02_access_modifier01.Access;

public class AccessTest2 {

	public static void main(String[] args) {

		// Access 클래스 외부(다른 패키지)

		// 생성자(객체화 가능 여부)

		// default 생성자
//		Access access1 = new Access(10);
		// protected 생성자
//		Access access2 = new Access(10.7);
		// public 생성자
		Access access3 = new Access("public");

		// 필드

		// default 필드
//		System.out.println(access3.defaultData);

		// protected 필드
//		System.out.println(access3.protectedData);

		// public 필드
		System.out.println(access3.publicData);

		// private 필드
		// The field Access.privateData is not visible
//		System.out.println(access3.privateData);
		// name cannot be resolved or is not a field
//		System.out.println(access3.name);

		// 메소드

		// default 메소드
//		access3.defaultMethod();

		// protected 메소드
//		access3.protectedMethod();

		// public 메소드
		access3.publicMethod();

		// private 메소드
		// The method privateMethod() from the type Access is not visible
//		access3.privateMethod();
		// The method method1() is undefined for the type Access
//		access3.method1();

	}

}
