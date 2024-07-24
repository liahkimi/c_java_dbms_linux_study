package ex01_interface4;

public class ClassC implements InterA, InterB {

	@Override
	public void method1() {
		InterA.super.method1();
		System.out.println("InterA의 method1 재정의");
	}
}
