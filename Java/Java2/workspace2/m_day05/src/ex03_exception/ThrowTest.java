package ex03_exception;

import java.util.Scanner;

public class ThrowTest {

	public static void main(String[] args) {

		// 사용자가 입력한 이메일에 @가 포함되어 있지 않으면
		// ValidEmailException 을 발생시킨다
		
		Scanner sc = new Scanner(System.in);
		String email = null;
		
		System.out.println("이메일 주소를 입력하세요");
		email = sc.next();
		try {
			if(!email.contains("@")) {
				throw new ValidEmailException("잘못된 이메일 형식");
			}
			System.out.println(email);
		}catch(ValidEmailException e) {
			System.out.println(e.getMessage());
		}
		
		
	}

}
