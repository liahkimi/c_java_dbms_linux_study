package ex01_casting1;

public class ElectricCar extends Car{

	/*
	 * 실습1. Car 클래스를 상속받는 ElectricCar 선언하기
	 * 필드 : maxPower(최대 충전량), currentPower(현재 충전량)
	 * 생성자 : 1개
	 * 메소드 : charge(충전 메소드), checkInfo(정보 확인 메소드)
	 * 
	 * charge() 메소드에 충전량에 대한 로직을 추가한다
	 * 1. 충전하려는 충전량은 음수일수 없다(잘못된 충전량이라고 출력)
	 * 2. 충전하려는 충전량은 최대 충전량까지만 가능하다(최대까지만 충전)
	 * 3. 현재 충전량과 충전하려는 충전량의 합은 최대 충전량까지만 가능하다(최대까지만 충전)
	 * 4. 충전은 시동이 꺼진 상태에서만 가능하다(시동이 켜진 상태입니다 출력)
	 */
	
	
	// 필드(field)
	// 최대 충전량
	int maxPower;
	// 현재 충전량
	int currentPower;
	
	
	// 생성자(constructor)
	public ElectricCar(String color, int maxPower) {
		super(color);
		this.maxPower = maxPower;
	}
	
	// 쉬는시간 11:34시까지~!
	// 메소드(method)
	
	void charge(int powerNum) {
		// 시동이 꺼진 상태에서만 충전이 가능하다
		if(engineState) {
			// 시동이 켜진 상태이면 출력을 하고, 메소드 실행을 종료한다
			System.out.println("시동이 켜진 상태입니다");
			return;
		}
		
		// 충전하려는 충전량은 음수일수 없다
		if(powerNum <= 0) {
			System.out.println("잘못된 충전량 입니다");
			return;
		}
		// 충전하려는 충전량은 최대 충전량을 넘을수 없다 -> 최대만큼만 충전
		// 현재 충전량과 충전하려는 충전량의 합계가 최대 충전량을 넘을수 없다 -> 최대만큼만 충전
		if(powerNum >= maxPower || powerNum + currentPower >= maxPower) {
			currentPower = maxPower;
		}else {
			// 원하는 충전량만큼 충전한다
			System.out.println("충전완료");
			currentPower += powerNum;
		}
		
	}

	@Override
	void checkInfo() {
		super.checkInfo();
		System.out.println("maxPower = " + maxPower);
		System.out.println("currentPower = " + currentPower);
	}


	
	
	
}
