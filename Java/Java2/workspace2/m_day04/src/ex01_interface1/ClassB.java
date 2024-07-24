package ex01_interface1;

public class ClassB implements InterA{

	
	@Override
	public void method1() {
		System.out.println("classB에서 재정의된 method1");
	}

	@Override
	public void method2() {
		System.out.println("classB에서 재정의된 method2");
	}
	
	void methodA() {
		System.out.println(InterA.DATA1);
	}
	
}
