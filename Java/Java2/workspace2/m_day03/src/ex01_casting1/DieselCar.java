package ex01_casting1;

public class DieselCar extends Car {

	// 필드(field)
	
	// 최대 주유량
	int maxOil;
	// 현재 주유량 
	int currentOil;
	
	// 생성자(constructor)
	public DieselCar(String color, int maxOil) {
		super(color);
		this.maxOil = maxOil;
	}
	
	// 메소드(method)
	
	void fillUp(int oilNum) {
		// 시동이 꺼진 상태에서만 주유가 가능하다
		if(!engineState) {
			currentOil += oilNum;
			System.out.println("주유 완료");
		}else {
			System.out.println("시동이 켜진 상태입니다");
		}
	}
	
	// 필드 정보를 확인하는 메소드를 어떻게 선언할까?
	// 기존 메소드를 재사용할수 있으니 오버라이딩 한다
	
	@Override
	void checkInfo() {
		super.checkInfo();
		System.out.println("maxOil = " + maxOil);
		System.out.println("currentOil = " + currentOil);
	}
	

	
	
	
	
}
