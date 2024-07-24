package ex01_object;

import java.util.Scanner;

public class EqualsTest {

	public static void main(String[] args) {

		System.out.println(1 == 1);
		System.out.println("ab".equals("ab"));
		
		User user1 = new User(1, "min");
		User user2 = new User(1, "min");
		
		// user1 객체랑 user2 객체가 같니?
		// 동일성(identity) : 객체의 주소값을 비교
		// 동등성(equality) : 객체의 주소값은 다르지만 가지고있는 정보의 동등성 비교
		
		// == : 객체의 동일성 비교(주소값 비교)
		System.out.println(user1 == user2);
		// equals() : 객체의 동등성 비교
		System.out.println(user1.equals(user2));
		
//		Scanner sc = new Scanner(System.in);
//		System.out.println("문자열을 입력하세요 >>");
//		String msg = sc.next();
//		
//		// 문자열의 값을 서로 비교하기 위해서
//		// 주소값을 비교하는 ==(관계연산자)가 아닌 equals() 메소드를 사용한다
//		System.out.println(msg.equals("abc"));
//		System.out.println(msg == "abc");
		
		NewUser newUser1 = new NewUser(2, "kim");
		NewUser newUser2 = new NewUser(2, "kim");
		
		// 동일성 비교
		System.out.println(newUser1 == newUser2);
		
		// 동등성 비교
		// 두 객체가 NewUser 타입이고, 가지고있는 필드의 값이 같다면 동등한 객체이다
		System.out.println(newUser1.equals(newUser2));
		
		
		
	}

}
