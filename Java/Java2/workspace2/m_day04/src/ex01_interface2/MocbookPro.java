package ex01_interface2;

// 인터페이스 2개를 구현하는 클래스(다중구현)
public class MocbookPro implements Mocbook, TouchBar {

	
	@Override
	public void powerOn() {
		System.out.println("전원을 킵니다");
	}

	@Override
	public void powerOff() {
		System.out.println("전원을 끕니다");
	}
	
	@Override
	public void addFingerPrint() {
		System.out.println("사용자 지문 등록");
	}
	

	
	
}
