package ex03_multi_inheritance;

public class InheritanceTest {

	public static void main(String[] args) {

		// SchoolBus가 몇개의 멤버를 가지고 있을까?
		SchoolBus schoolBus = new SchoolBus();
		
		// 자식의 메소드
		schoolBus.checkStudent();
		
		// 부모의 메소드
		schoolBus.takePerson();
		
		// 부모의 부모 메소드
		schoolBus.moveOn();
		
	}

}
