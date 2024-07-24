package ex01_inheritance;

// 자식클래스
public class ApplePhone extends Phone{

	
	// 자식 메소드
	void connectAirdrop() {
		System.out.println("air drop에 연결");
	}
	
	// 메소드 오버라이딩
	@Override
	void call() {
		System.out.println("시리에게 전화 연결 요청합니다");
		// 기존 상속받은 부모메소드의 앞뒤에 새로운 로직을 추가한다
		super.call();
	}
	
	@Override
	void text() {
		// 기존 상속받은 부모메소드의 로직을 모두 수정한다
		System.out.println("시리를 통해 문자를 전송합니다");
	}

	// 메소드 오버라이딩 단축키(alt + shift + s + v)
	@Override
	void powerOn() {
		System.out.println("아이폰 전원을 킵니다");
	}
	
	

	
	
}
