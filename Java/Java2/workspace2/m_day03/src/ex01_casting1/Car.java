package ex01_casting1;

// 부모클래스
public class Car {

	/*
	 * DieselCar(경유차)
	 * ElectricCar(전기차)
	 */
	
	// 필드(field)
	
	String color;
	// 시동 상태
	boolean engineState;
	
	// 생성자(constructor)
	
	public Car(String color) {
		super();
		this.color = color;
	}
	
	// 메소드(method)
	
	void turnOn() {
		System.out.println("자동차 시동을 킵니다");
		engineState = true;
	}
	
	void turnOff() {
		System.out.println("자동차 시동을 끕니다");
		engineState = false;
	}
	
	void checkInfo() {
		System.out.println("color = " + color);
		System.out.println("engineState = " + engineState);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
