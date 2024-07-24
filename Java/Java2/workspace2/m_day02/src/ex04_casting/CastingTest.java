package ex04_casting;

public class CastingTest {

	public static void main(String[] args) {

		// 객체의 타입 비교
		
		Parent parent1 = new Parent(100);
		Child child1 = new Child(1, 2);
		
		// 객체 instanceof 클래스명
		// parent1 객체는 Parent 클래스 타입을 가지는가?
		System.out.println(parent1 instanceof Parent);
		// child1 객체는 Child 클래스 타입을 가지는가?
		System.out.println(child1 instanceof Child);
		
		// 상속을 받으면 부모 클래스의 멤버와 타입을 가지게된다
		// child1 객체는 Parent 클래스 타입을 가져야한다
		
		// 상속받은 부모 클래스 타입을 가진다(상위 타입을 가진다)
		// 하위 타입의 객체는 상위타입을 가진다
		System.out.println(child1 instanceof Parent);
		
		// 부모 객체는 자식 클래스 타입을 가지는가?
		// 상위 객체는 하위 타입을 가지는가?
		System.out.println(parent1 instanceof Child);
		
		// 하나의 객체가 여러개의 타입을 가진다
		// 자기 자신의 타입, 상속받은 부모클래스의 타입(상위 타입)
		
		// 자료형 변수명 = 값;
		// 클래스명 객체명 = 주소값;
		
		
	
		
	}

}
