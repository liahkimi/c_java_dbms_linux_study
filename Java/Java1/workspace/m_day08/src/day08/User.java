package day08;

public class User {


	/*
	 * User 클래스 선언하기
	 * id(아이디), pw(비밀번호), gender(성별), email(이메일주소)
	 * 아이디, 비밀번호, 이메일주소는 필수 정보이다
	 * 성별은 선택정보 이다
	 * 
	 * 메소드1. 비밀번호 변경 메소드
	 * 새로운 비밀번호를 전달받아 기존 비밀번호를 변경하는 메소드
	 * 
	 * 생성자
	 * 사이트의 유저는 필수정보만 입력해서도 회원가입 할 수 있다
	 * 사이트의 유저는 필수정보와 선택정보를 입력해서 회원가입 할 수 있다
	 */
	
	// 필드(field)
	
	String id;
	String pw;
	String gender;
	String email;
	
	// 메소드(method)
	// 비밀번호를 변경하는 메소드이므로 사용할 필드는 비밀번호밖에 없다
	// 그러므로 매개변수의 이름을 필드의 이름과 달리하여도
	// 어떤 필드에 값을 사용할지 알수 있다
	void changePw(String newPw){
		pw = newPw;
		System.out.println("비밀번호 변경 완료!");
		
		// 같은 객체의 다른 메소드를 호출할수 있다
		// 메소드명();
		int num = method1();
	}
	
	int method1() {
		// 다른 메소드에 선언된 변수이므로(현재 메소드에서 선언한 변수가 아니므로)
		// 사용하지 못한다
//		System.out.println(newPw);
		// 객체의 필드이므로 사용 가능
		System.out.println(pw);
		
		String id = "test"; // method1에서 선언한 변수(지역변수)
		System.out.println(this.id); // 필드
		System.out.println(id); // 지역변수
		
		int num = 10;
		return num;
		
		
	}
	
	
	// 생성자(constructor)
	// 유저 객체를 생성하면 코드상으로 회원가입이라고 생각할수 있다
	// 회원은 회원가입할때 정보를 2가지 방식으로 입력할수 있으니
	// 생성자를 2개 선언한다
	
	// 필수정보만 입력했을 경우 사용할 생성자
	User(String id, String pw, String email){
		this.id = id;
		this.pw = pw;
		this.email = email;
		System.out.println("생성자1 호출");
		
	}
	
	// 모든정보를 입력했을 경우 사용할 생성자
	User(String id, String pw, String gender, String email){
		this.id = id;
		this.pw = pw;
		this.gender = gender;
		this.email = email;
		System.out.println("생성자2 호출");
	}
	
	
	
	
}
