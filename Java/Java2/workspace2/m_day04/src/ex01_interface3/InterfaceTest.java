package ex01_interface3;

public class InterfaceTest {

	public static void main(String[] args) {

		MyClass myClass1 = new MyClass();
		
		System.out.println(myClass1 instanceof MyClass);
		System.out.println(myClass1 instanceof Inter1);
		System.out.println(myClass1 instanceof Inter2);
		System.out.println(myClass1 instanceof Inter3);
		System.out.println(myClass1 instanceof Object);
		
		// Inter3 타입으로 up casting
		Inter3 upClass = new MyClass();
		
		upClass.method3();
		upClass.method2();
		upClass.method1();
		
		// Inter2 타입으로 up casting
		Inter2 upClass2 = new MyClass();
		
		upClass2.method2();
//		upClass2.method1();
//		upClass2.method3();
		
		
		
		
	}

}
