package ex01_object;

import java.util.Objects;

public class NewUser {

	// 필드(field)
	// 회원 번호
	private int userNumber;
	// 회원 이름
	private String userName;
	
	// 생성자(constructor)
	public NewUser(int userNumber, String userName) {
		super();
		this.userNumber = userNumber;
		this.userName = userName;
	}

	// 게터와 세터(getter, setter)
	public int getUserNumber() {
		return userNumber;
	}

	public void setUserNumber(int userNumber) {
		this.userNumber = userNumber;
	}

	public String getUserName() {
		return userName;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}


	
	// toString() 메소드 재정의
	
//	@Override
//	public String toString() {
//		return "userName = " + userName + " userNumber = " + userNumber;
//	}
	
	// alt + shift + s + s
	@Override
	public String toString() {
		return "NewUser [userNumber=" + userNumber + ", userName=" + userName + "]";
	}


	// equals() 메소드 재정의
	// 만약에 전달된 객체와 타입이 같고, userNumber가 같고, userName이 같다면
	// 동등한 객체라고 판단한다
	
	// Object obj : 자바의 모든 클래스는 Object 클래스를 상속받기 때문에
	// obj 매개변수에 모든 클래스의 객체가 전달될 수 있다(up casting이 가능하기 때문에)
//	@Override
//	public boolean equals(Object obj) {
//		// 전달된 객체의 타입 체크
//		// 전달된 객체가 NewUser 타입이 아니라면 return false
//		if(!(obj instanceof NewUser)) {
//			return false;
//		}
//		
//		// 전달된 객체의 userNumber와 userName 체크
//		// obj 변수에는 up casting된 NewUser 객체가 저장되어 있다
//		// up casting된 상태에서는 자식 클래스의 멤버에 접근할수 없기 때문에
//		// down casting 후에 값을 비교해야 한다
//		NewUser other = (NewUser)obj;
//		
//		boolean result = userNumber == other.userNumber 
//				&& userName.equals(other.userName);
//
//		return result;
//	}
	
	// alt + shift + s + h
	
	@Override
	public int hashCode() {
		return Objects.hash(userName, userNumber);
	}
	
	@Override
	public boolean equals(Object obj) {
		// 전달된 객체와 해당 객체가 동일하다면(자기자신)
		if (this == obj)
			return true;
		// 전달된 객체가 null이라면(객체가 아니라면)
		if (obj == null)
			return false;
		// 전달된 객체와 해당 객체가 동일한 타입이 아니라면(클래스가 같지 않다면)
		if (getClass() != obj.getClass())
			return false;
		// 전달된 객체의 필드와 해당 객체의 필드값을 비교한다
		NewUser other = (NewUser) obj;
		return Objects.equals(userName, other.userName) && userNumber == other.userNumber;
	}
	
	
	
	
	
	
	
	
	
	
}
