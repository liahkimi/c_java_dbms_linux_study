package ex02_abstract2;

// 교재 p308
public abstract class Phone {

	/*
	 * Phone 클래스(부모)
	 * ThreeStartPhone(자식)
	 * PineapplePhone(자식)
	 */
	
	// 추상메소드
	abstract void openLogo();
	
	// 일반메소드
	// powerOn() 메소드를 호출하는 시점에는 이미 openLogo() 메소드가 구현되어 있다
	void powerOn() {
		// Phone 클래스로 만든 객체는 powerOn() 메소드 호출불가(객체화 불가)
		openLogo();
		System.out.println("핸드폰이 켜집니다");
	}
	
	
	
}
