package ex02_access_modifier02;

import ex02_access_modifier01.Access;

public class Access2 extends Access {


	// 생성자
	public Access2(double protectedData) {
		super(protectedData);
	}
	
	void methodA() {
		// 메소드
		super.protectedMethod();
		
		// 필드
		System.out.println(super.protectedData);
	}
	
	public static void main(String[] args) {
		
		Access2 ac = new Access2(3.7);
		
		// 상속받은 자식 클래스의 객체를 통해 부모 클래스의 protected 필드와 메소드를 사용한다
		System.out.println(ac.protectedData);
		ac.methodA();
		ac.protectedMethod();
		
	}
	
	
}
