package day08;

public class Person {
	
	// 필드(field)
	
	String name;
	char gender;
	int age;
	
	// 생성자(constructor)
	
	Person(String name){
		this.name = name;
		System.out.println("생성자1 호출");
	}
	
	Person(String name, char gender){
		this(name);
		this.gender = gender;
		System.out.println("생성자2 호출");
	}
	
	Person(String name, char gender, int age){
		this(name, gender);
		this.age = age;
		System.out.println("생성자3 호출");
	}
	
	

}
