package day08;

public class ClassTest2 {

	public static void main(String[] args) {

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
		
		// 필수 정보만 입력한 유저
		
		User user1 = new User("hong", "hong1234", "hong@hong.com");
		
		System.out.println(user1.pw); // hong1234	
		user1.changePw("hong12"); 		
		System.out.println(user1.pw); // hong12
		
		// 모든 정보를 입력한 유저
		
		User user2 = new User("kim", "kim1234", "남성", "kim@kim.com");
		
		System.out.println(user2.pw); // kim1234
		// String newPw = null;
		// pw = null;
		user2.changePw(null);
		System.out.println(user2.pw); // null
			
		
		user1.method1();
		
		
		
		
	}

}
