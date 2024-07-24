package ex01_interface4;

public interface InterD {

	// method2() 메소드의 접근제한자는 public 이다
	default void method2() {
		System.out.println("InterD의 method2");
	}
	
	void method3();
	
}
