package ex02_inheritance02;

public class InheritanceTest {

	public static void main(String[] args) {

		// 자식 클래스 객체화
		
		SubClass sc1 = new SubClass();
		// 10 값은 자식 생성자에서 초기화 한다(subData)
		// 20 값은 부모 생성자에서 초기화 한다(superData)
		SubClass sc2 = new SubClass(10, 20);
		
		System.out.println(sc2.subData);
		System.out.println(sc2.superData);
		
		sc2.subMethod();
		
		// 만약에 부모 클래스의 필드와 자식 클래스의 필드가 같다면?
		sc2.subMethod2();
		
		// 만약에 부모 클래스의 메소드와 자식 클래스의 메소드가 선언부가 같다면?
		sc2.superMethod2();
		
		sc2.subMethod3();
		
		
		
		

		
	}

}
