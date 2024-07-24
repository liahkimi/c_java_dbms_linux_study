package day08;

public class Car {
	
	/*
	 * 	Car 클래스 선언
		색상, 제조사명, 가격, 좌석수 상태를 가진다
		-> 각각의 자동차 객체마다 상태값은 다르다

		엔진을 킵니다, 엔진을 끕니다 기능을 가진다
		-> startEngine(), turnOffEngine()
		-> 각각의 기능을 출력하는 메소드
		
	 */
	
	// 필드(field)
	
	String color;
	String companyName;
	int price;
	int seats;
	
	// 메소드(method)
	
	void startEngine() {
		System.out.println("엔진을 킵니다");
	}
	
	void turnOffEngine() {
		System.out.println("엔진을 끕니다");
	}

	// 생성자(constructor)
	
	// 기본생성자 -> 개발자가 직접 선언하지 않으면 컴파일러가 자동으로 선언
	Car(){
		
	}
	
	// 생성자도 메소드 중 하나이므로 오버로딩 할수 있다
	// 생성자의 매개변수의 개수는 객체를 생성할때 초기화 하고 싶은 
	// 값의 개수와 동일하다
	Car(String color){
		// 필드를 초기화하기 위해 초기화 코드를 작성한다
		// color 는 같은 객체의 필드 이므로 바로 사용할수 있다
		// 매개변수에 필드와 같은 이름의 변수를 선언하게 되면
		// 필드가 아니라 매개변수로 사용이 된다
		// 매개변수 color = 매개변수 color;
//		color = color;
		
//		int num = 10;
//		num = num;
		
		// 필드 color = 매개변수 color;
		this.color = color;
		System.out.println(this);
		
		
		
	}
	
	
	
	
	
	
	

}
