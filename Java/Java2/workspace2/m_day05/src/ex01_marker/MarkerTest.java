package ex01_marker;

public class MarkerTest {
	
	// MammalMarker 타입을 가진 동물 객체만 달릴수 있다
	// 매개변수의 타입을 MammalMarker 타입으로 지정해서 매개변수에서 타입을 확인
	static void runAnimal(MammalMarker animal) {
		// 전달된 동물 객체가 달릴수 있는지 타입을 확인
		System.out.println(animal + " 달리기~!");
	}
	
	// BirdsMarker 타입을 가진 동물 객체만 날수 있다
	// 매개변수의 타입을 BirdsMarker 타입으로 지정해서 매개변수에서 타입을 확인
	static void flyAnimal(BirdsMarker animal) {
		// 전달된 동물 객체가 날수 있는지 타입을 확인
		System.out.println(animal + " 날기~!");
	}
	

	public static void main(String[] args) {

		/*
		 * Animal 클래스(부모클래스)
		 * Cat, Dog, Eagle, Pigeon 클래스(자식클래스)
		 * 
		 * Cat is a animal
		 * Dog is a animal
		 * Eagle is a animal
		 * Pigeon is a animal
		 */
		
		Cat cat = new Cat();
		Dog dog = new Dog();
		Eagle eagle = new Eagle();
		Pigeon pigeon = new Pigeon();
		
//		MarkerTest.runAnimal(eagle);
//		MarkerTest.flyAnimal(dog);
		
		MarkerTest.runAnimal(dog);
		MarkerTest.flyAnimal(pigeon);
		
		
		
		
	}

}
