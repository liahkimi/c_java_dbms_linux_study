package ex01_interface4;

public interface InterB {

	default void method1() {
		System.out.println("InterB의 method1");
	}
}
