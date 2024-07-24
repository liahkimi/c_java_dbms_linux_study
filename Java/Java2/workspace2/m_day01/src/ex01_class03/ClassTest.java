package ex01_class03;

public class ClassTest {
	
	static boolean checkDuplicateId(User[] userList, String newId) {
		// for-each문
		for(User user:userList) {
			if(user.id.equals(newId)) {
				return true;
			}
		}	
		return false;
		
	}

	public static void main(String[] args) {

		// 배열안에 배열 -> 2차원 배열
		// 배열안에 객체가 들어갈수 있을까?
		
		// int[] : [10][20][30]
		// int[][] : [[1,2]][[3,4]] / [new int[2]][new int[2]]
		// [] : [new User()][new User()][new User()]
		
		// 왼쪽 저장공간 = 값
		int age = 10;
		
		// 왼쪽 저장공간 = 주소값(참조값)
		User user1 = new User("hong", "hong123");
		User user2 = new User("kim", "kim123");
		User user3 = new User("seo", "seo123");
		
		User[] userList= {user1, user2, user3};
		
		System.out.println(userList[0]);
		System.out.println(user1);
		
		System.out.println(userList[1]);
		System.out.println(user2);
		
		System.out.println(userList[2]);
		System.out.println(user3);
		
		System.out.println(userList[0].id);
		System.out.println(user1.id);
		
		boolean result = checkDuplicateId(userList, "park");
		System.out.println(result);
		
		result = checkDuplicateId(userList, "kim");
		System.out.println(result);
		
		
		// 배열안에 배열이 들어갈수 있는 이유 -> 배열은 결국 주소값이기 때문에
		// 배열안에 객체가 들어갈수 있는 이ㅠ -> 객체도 결국 주소값이기 때문에
		
		
		
		
	}

}
