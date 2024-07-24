package ex01_interface2;

public class InterfaceTest {

	public static void main(String[] args) {

		// 클래스는 여러개의 인터페이스를 구현할수 있다
		MocbookPro mocbookPro = new MocbookPro();

		// 여러개의 인터페이스를 구현하면, 여러개의 타입을 가진다
		System.out.println(mocbookPro instanceof Mocbook);
		System.out.println(mocbookPro instanceof TouchBar);

		mocbookPro.powerOn();
		mocbookPro.addFingerPrint();

		// up casting

		Mocbook mocbook = new MocbookPro();
		TouchBar touchBar = new MocbookPro();

		// TouchBar 인터페이스가 가진 추상메소드의 재정의에는 접근 불가
		// 각각의 인터페이스가 정의한 추상메소드만 접근 가능

//		mocbook.addFingerPrint();
//		touchBar.powerOn();

		mocbook.powerOff();
		mocbook.powerOn();

		touchBar.addFingerPrint();

	}

}
