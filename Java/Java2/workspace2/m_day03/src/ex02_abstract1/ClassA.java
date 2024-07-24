package ex02_abstract1;

public class ClassA extends AbstractClass {

	// 상속받은 추상메소드를 받드시 재정의해야한다
	@Override
	void method2() {
		System.out.println("재정의된(구현된) 추상메소드");
	}

	
	
	
}
