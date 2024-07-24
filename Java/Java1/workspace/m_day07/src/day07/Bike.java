package day07;

public class Bike {

	// 필드(field)
	// 자전거는 바퀴, 안장, 가격, 색상을 가지고 있다

	int wheel;
	int saddle;
	int price;
	String color;

	// 메소드(method)

	void move() {
		System.out.println("자전거를 움직인다");
	}

	void stop() {
		System.out.println("자전거를 멈춘다");
	}

	// 생성자(constructor)

	Bike() {
		System.out.println("Bike 클래스 생성자 호출!");

		// 생성자는 리턴타입이 void로 지정되어 있다
		// return 1;
	}

}
