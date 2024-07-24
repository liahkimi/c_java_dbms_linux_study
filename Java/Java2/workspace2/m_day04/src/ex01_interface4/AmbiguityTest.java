package ex01_interface4;

public class AmbiguityTest {

	public static void main(String[] args) {

		ClassC classC = new ClassC();
		
		// 구현하는 2개의 인터페이스에 있는 일반 메소드(default)가 
		// 선언부가 동일하기 때문에 2개중에 1개를 선택하여 재정의한다
		
		classC.method1();
		
		Child child = new Child();
		
		// 상속받은 메소드와 구현하는 인터페이스의 일반 메소드가 동일할경우,
		// 상속받은 메소드가 사용된다 
		child.method2();
		
		// 상속받은 부모 클래스로 up casting
		Parent parent = new Child();
		parent.method2();
		
		// 인터페이스의 추상메소드를 parent 타입으로는 접근하지 못한다
//		parent.method3();
			
		// 구현하는 인터페이스로 up casting
		InterD interD = new Child();
		interD.method2();
		
		interD.method3();
		
		// parent 객체가 가지고 있는 타입
		// 1. Child 클래스
		// 2. Parent 클래스
		// 3. InterD 인터페이스
		// 4. Object 클래스
		
		// 부모 클래스 타입 -> 인터페이스 타입 : 명시적 형변환(down casting)
		// 인터페이스 타입 -> 부모 클래스 타입 : 명시적 형변환(down casting)
		InterD interD2 = (InterD)parent;
		Parent parent2 = (Parent)interD;
		
		
		
	}

}
