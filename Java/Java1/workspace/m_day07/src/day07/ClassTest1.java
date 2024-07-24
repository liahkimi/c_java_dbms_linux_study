package day07;

public class ClassTest1 {

	public static void main(String[] args) {

		
		// Bike 클래스 객체화
		
		Bike bike1 = new Bike();
		
		// 객체의 참조값이 출력된다
		System.out.println(bike1);
		
		// 객체의 메소드를 사용한다
		// bike1 변수에 저장된 객체의 참조값을 통해
		// heap 메모리에 할당된 객체가 가지고 있는 move() 메소드를 호출한다
		bike1.move();
		bike1.stop();
		
		// 객체의 필드를 사용한다
		// 필드를 초기화 하지 않았음에도 불구하고 출력할수 있다
		// 누군가 필드를 초기화 해준다
		System.out.println(bike1.color);
		System.out.println(bike1.price);
		
		Bike bike2 = new Bike();
		
		System.out.println(bike1);
		System.out.println(bike2);
		
		System.out.println(bike2.color);
		System.out.println(bike2.price);
		
		bike1.color = "red";
		System.out.println(bike1.color);
		
		bike2.color = "blue";
		System.out.println(bike2.color);
		
		
		
		
		
		
		
	}

}
