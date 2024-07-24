package ex01_inheritance;


public class InheritanceTest {

	public static void main(String[] args) {

		ApplePhone applePhone = new ApplePhone();
		
		// 자식 클래스의 메소드 호출
		applePhone.connectAirdrop();
		
		// 상속받은 부모 클래스 메소드 호출(재정의된 메소드)
		// 기존 부모 메소드의 구현부를 모두 수정한다
		applePhone.powerOn();
		
		// 상속받은 부모 클래스 메소드 호출(재정의된 메소드)
		// 기존 부모 메소드의 구현부와 새로운 로직을 추가하여 수정한다
		applePhone.call();
		
	
		
	}

}
