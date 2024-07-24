package ex01_interface1;

public class InterTest {

	public static void main(String[] args) {

		// 인터페이스는 클래스가 아니다
		// 생성자가 존재하지 않아 객체화 할수 없다
		
//		InterA interA = new InterA();
		
		// 인터페이스의 상수 사용
		// 인터페이스의 상수는 public static final 이다
		System.out.println(InterA.DATA1);
		System.out.println(InterA.DATA2);
		
		// 인터페이스를 구현하는 클래스 객체화
		ClassB classB = new ClassB();
		
		classB.method1();
		classB.method2();
		classB.methodA();
		
		// 인터페이스도 타입이다(상위타입)
		System.out.println(classB instanceof InterA);
		
		// 인터페이스를 구현하는 클래스가 인터페이스 타입으로
		// up casting 될수 있기때문에 up casting 후 재정의된 메소드 사용
		InterA classB2 = new ClassB();
		classB2.method1();
		
		// methodA() 는 인터페이스의 메소드가 아닌 ClassB의 일반메소드이므로
		// down casting 후에 사용한다
		
		((ClassB)classB2).methodA();
		
		ClassB classB3 = (ClassB)classB2;
		classB3.methodA();
		
		
		
	}

}
