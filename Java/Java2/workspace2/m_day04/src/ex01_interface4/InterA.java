package ex01_interface4;

public interface InterA {

	default void method1() {
		System.out.println("InterA의 method1");
	}
}
