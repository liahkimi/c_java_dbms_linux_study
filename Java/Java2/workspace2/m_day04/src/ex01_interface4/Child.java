package ex01_interface4;

// 상속과 구현을 동시에 할때는 상속 -> 구현 : extends > implements
public class Child extends Parent implements InterD  {

	
	@Override
	public void method3() {
		System.out.println("method3 재정의");
	}
}
