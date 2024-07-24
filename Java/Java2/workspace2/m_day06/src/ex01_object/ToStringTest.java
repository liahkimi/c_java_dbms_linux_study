package ex01_object;

import java.util.Arrays;

public class ToStringTest {

	public static void main(String[] args) {

		User user1 = new User(1, "min");
		
		System.out.println(user1);
		// 출력메소드는 전달된 객체에서 toString() 메소드를 자동 호출한다
		// User 클래스는 Object 클래스에서 상속받은 toString() 메소드를 재정의
		// 하지 않았기 때문에 Object 클래스의 toString() 메소드가 호출된다
		System.out.println(user1.toString());
		
		int[] ar = {1,2,3};
		System.out.println(Arrays.toString(ar));
		
		NewUser newUser1 = new NewUser(2, "kim");
		
		// 객체의 필드와 클래스를 편리하게 확인하기 위해 toString() 재정의한다
		// NewUser 클래스는 Object 클래스의 toString() 메소드를 재정의했기 때문에
		// 재정의된 toString() 메소드가 호출된다
		System.out.println(newUser1);
		System.out.println(newUser1.toString());
		
		System.out.println(newUser1.getUserName());
		System.out.println(newUser1.getUserNumber());
		
		
		
		
		
		
		
		
		
	}

}
