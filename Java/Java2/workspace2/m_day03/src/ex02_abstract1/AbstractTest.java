package ex02_abstract1;

public class AbstractTest {

	public static void main(String[] args) {

		// 추상클래스 객체화 할수 없다
//		AbstractClass ac = new AbstractClass();

		// 추상메소드를 상속받았는데(미구현된 멤버) 왜 객체화가 가능할까?
		// 추상메소드를 상속받아 재정의(구현)하였기 때문에
		ClassA classA = new ClassA();

		// 추상클래스를 상속받는 자식클래스도 추상클래스의 타입을 가진다
		System.out.println(classA instanceof AbstractClass);

		// 상속받은 필드
		System.out.println(classA.abstractData);

		// 상속받은 일반메소드
		classA.method1();

		// 상속받은 추상메소드
		classA.method2();

		// 추상클래스는 new 연산자와 생성자를 통해 독립적으로 객체화 불가
		// 자식클래스를 통해서는 객체화가 가능하다(super())

	}

}
