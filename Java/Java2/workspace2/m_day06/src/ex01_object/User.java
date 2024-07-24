package ex01_object;

public class User {

	// 필드(field)
	// 회원 번호
	private int userNumber;
	// 회원 이름
	private String userName;
	
	// 생성자(constructor)
	public User(int userNumber, String userName) {
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
	
	
	
	
	
	
	
	
	
	
	
}
