package ex02_abstract2;

public abstract class ThreeStarPhone extends Phone{

	// 추상클래스의 추상메소드 강제성 해소하는 방법
	// 1. 해당 자식클래스에서 추상메소드를 재정의
	// 2. 해당 자식클래스도 추상클래스로 선언 -> 이 클래스를 상속받는 자식클래스에서 구현
	
	abstract void powerOff();
}
