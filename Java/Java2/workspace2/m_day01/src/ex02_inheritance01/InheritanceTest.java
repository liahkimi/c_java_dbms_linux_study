package ex02_inheritance01;

public class InheritanceTest {

	public static void main(String[] args) {

		// 자식 클래스 객체화
		Child child1 = new Child();
		
		// 자식 객체의 필드 사용
		System.out.println(child1.childData);
		
		// 선언되지 않은 필드이므로 사용할수 없다
		// extends 키워드를 통해 Parent 클래스를 상속받으면 사용가능
		
		// 부모 클래스의 필드
		System.out.println(child1.parentData);
		// 부모 클래스의 메소드
		child1.parentMethod();
		
		// 부모클래스 객체화
		Parent parent1 = new Parent();
		
		// 자식클래스 필드
		// 부모 클래스는 자식클래스의 필드를 사용하지 못한다
//		System.out.println(parent1.childData);
		
		// 자식클래스 메소드
		// 부모 클래스는 자식클래스의 메소드를 사용하지 못한다
//		parent1.childMethod();
		
		child1.childMethod2();
		
		
		
		
	}

}
