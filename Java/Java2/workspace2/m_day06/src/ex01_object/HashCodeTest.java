package ex01_object;

public class HashCodeTest {

	public static void main(String[] args) {

		User user1 = new User(1, "min");
		User user2 = new User(1, "min");
		
		// 두 객체는 동일한 객체도, 동등한 객체도 아니기때문에
		// 서로 다른 hashCode 값이 나온다
		System.out.println(user1 == user2);
		System.out.println(user1.equals(user2));
		
		System.out.println(user1.hashCode());
		System.out.println(user2.hashCode());
		
		NewUser newUser1 = new NewUser(2, "kim");
		NewUser newUser2 = new NewUser(2, "kim");
		
		// 두 객체는 동일한 객체는 아니지만, equals() 메소드 재정의를 통해
		// 동등한 객체이므로 hashCode 값도 같다
		System.out.println(newUser1 == newUser2);
		System.out.println(newUser1.equals(newUser2));

		System.out.println(newUser1.hashCode());
		System.out.println(newUser2.hashCode());
		
		
	}

}
