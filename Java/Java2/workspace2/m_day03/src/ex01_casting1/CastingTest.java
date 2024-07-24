package ex01_casting1;

public class CastingTest {

	/*
	 * 자동차 객체를 주유하거나 충전한다
	 */
	static void getDieselCar(DieselCar diesel) {
		// 전달받은 자동차 객체의 주유 또는 충전 메소드를 사용한다
		diesel.fillUp(0);
	}
	
	static void getElectricCar(ElectricCar electric) {
		electric.charge(0);
	}
	
	// 오버로딩
	static void getCar(DieselCar diesel) {
		// 전달받은 자동차 객체의 주유 또는 충전 메소드를 사용한다
		diesel.fillUp(0);
	}
	
	static void getCar(ElectricCar electric) {
		electric.charge(0);
	}
	
	// up casting
	static void getAllCar(Car car, int num) {
		
		// up casting된 상태이기 때문에 자식 클래스의 메소드 사용 불가!
//		car.fillUp(0);
//		car.charge(0);
		
		// 전달받은 자동차의 시동을 끈다
		car.turnOff();
		
		if(car instanceof DieselCar) {
			// 전달받은 객체가 DieselCar 클래스 타입일때
			DieselCar diesel = (DieselCar) car;
			diesel.fillUp(num);
		}else if(car instanceof ElectricCar) {
			// 전달받은 객체가 ElectricCar 클래스 타입일때
			((ElectricCar)car).charge(num);
		}else {
			// 전달받은 객체가 Car 클래스로 만든 객체일때
			System.out.println("아직 존재하지 않는 기능입니다");
		}
		
	}

	

	public static void main(String[] args) {

		DieselCar diesel = new DieselCar("red", 50);
		ElectricCar electric = new ElectricCar("blue", 70);
		ElectricCar electric2 = new ElectricCar("blue", 70);
		
		// 상속받은 부모메소드 호출
		diesel.turnOn();
		electric.turnOn();
		
		diesel.checkInfo();
		getAllCar(diesel, 20);
		diesel.checkInfo();
		
		// 최대 충전량보다 더 많은양을 충전하려고 할때
		electric.checkInfo(); // 현재 충전량 : 0
		getAllCar(electric, 100); // 충전량 : 100 
		electric.checkInfo(); // 현재 충전량 : 70(최대만큼)
		
		// 정상적인 충전량을 사용할때
		getAllCar(electric2, 20);
		electric2.checkInfo();
		
		// 기존 현재 충전량과 충전량의 합계가 최대 충전량을 넘을때
		getAllCar(electric2, 60);
		electric2.checkInfo();
		
		
		
		
		
		
		
		
	}

}
