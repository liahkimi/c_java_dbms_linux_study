package day08;

public class ItBook {

	// 필드(field)
	
	String name;
	int price;
	// 명시적 초기화 
	String category = "IT";
	// static 필드
	static String category2 = "로맨스";
	

	// alt + shift + s + o : 필드를 이용하여 생성자 생성
	
	public ItBook(String name, int price) {
		// 생성자를 통한 초기화
		this.name = name;
		this.price = price;
	}
	
	void methodA() {
		System.out.println("methodA");
		// 필드
		System.out.println(category);
		// static 필드
		System.out.println(ItBook.category2);
	}
	
	static void methodB() {
		System.out.println("static method");
	}
	
	
	
	

	
}
