package ex02_access_modifier03;

public class AccessTest {

	public static void main(String[] args) {

		User user1 = new User("min", "min1234", false);
		
		// private 필드는 클래스 외부에서 접근할수 없다
//		System.out.println(user1.id);
//		user1.pw = "min12";
		
		// 비밀번호를 변경할때
		user1.setPw("min12");
		// 변경된 비밀번호를 확인한다
		System.out.println(user1.getPw());
		
		User user2 = new User("kim", "kim1234", true);
		// 조건에 맞는 유저가 아닌데 관리자로 지정되어있다
		System.out.println(user2.isAdmin());
		
		User user3 = new User("admin", "admin1234");
		User user4 = new User("hong", "hong1234");
		
		user3.updateAdmin();
		user4.updateAdmin();
		
		System.out.println(user3.isAdmin());
		System.out.println(user4.isAdmin());
		
		Person person1 = new Person(null, 30);
		System.out.println(person1.getName());
		System.out.println(person1.getAge());
		
		Person person2 = new Person("홍길동", -20);
		System.out.println(person2.getAge());
		System.out.println(person2.getName());
		
		
		
		
	}

}
