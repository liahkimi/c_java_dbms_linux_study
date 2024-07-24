package day08;

public class ClassTest1 {

	// 실행용 클래스이므로 main 메소드를 선언한다
	public static void main(String[] args) {

		// Car 클래스 객체화	
		Car car1 = new Car();
		
		// 객체의 필드를 사용한다
		// Car 클래스에 직접 생성자를 선언하지 않았기 때문에
		// 컴파일러가 자동으로 기본형태의 생성자를 선언한다(매개변수 x, 실행할 코드 x)
		// 기본 형태의 생성자는 필드를 해당 자료형의 기본값으로 초기화한다
	
		System.out.println(car1.color);
		
		// 객체의 메소드를 사용한다
		car1.startEngine();
		
		// 객체의 필드값을 변경한다
		car1.color = "black";
		System.out.println(car1.color);
		
		// car2 객체를 생성한다(색상은 red로 지정한다)
		Car car2 = new Car("red");
		
		System.out.println(car2.color);
		System.out.println(car2);
		

		
		
	}

}
