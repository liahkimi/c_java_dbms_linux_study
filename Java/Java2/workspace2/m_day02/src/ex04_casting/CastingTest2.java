package ex04_casting;

public class CastingTest2 {

	public static void main(String[] args) {

		// up casting
		// 하위 타입 객체를 상위 타입으로 형변환하는것
		
		Child child1 = new Child(1, 2);
		
		// 부모 타입 변수에 자식객체를 저장하여 자동 형변환한다
		Parent parent1 = child1;
		Parent parent2 = (Parent)child1;
		
		Parent parent3 = new Child(3, 4);
		Parent parent4 = (Parent)new Child(5, 6);
		
		// up casting된 상태에서
		// 자식 클래스에 있는 메소드
		// up casting된 상태로는 자식 클래스에 메소드에 접근할수 없다
		// 자식 클래스에서 선언한 메소드는 up casting 상태로 접근 불가!
//		parent1.childMethod();
		
		// 부모 클래스에 있는 메소드
		parent1.parentMethod1();
		
		// 자식클래스에서 해당 메소드를 재정의 하였지만,
		// up casting 된 상태에서 호출이 가능하다
		parent1.parentMethod2();
		
		// down casting
		// 상위 타입 객체를 하위 타입으로 형변환한다
		// 자식 클래스의 객체는 가능하지만, 부모 클래스로 만든 객체는 안된다
		// up casting된 자식객체를 다시 자식 클래스 타입으로 원상복귀한다
		
		// 자식클래스 객체명 = (자식클래스)up casting 자식객체

		Child child2 = (Child)parent2;
		
		child2.childMethod();
		child2.parentMethod2();
		child2.parentMethod1();
		
		// 부모 클래스로 만든 부모 객체는 자식 클래스 타입으로 형변환 불가
		// 코드를 실행하면 예외가 발생한다 -> 부모클래스는 자식클래스 타입을 가지지 않는다
//		Parent originParent = new Parent(10);
//		Child child3 = (Child)originParent;
		
		// 형변환을 하고 childMethod()를 사용한다
		// 형변환에 우선순위를 주기위해 () 소괄호 안에 넣는다
		((Child)parent3).childMethod();
		
		
		
		
	}

}
