package day08;

public class ClassTest4 {
	
	void method1() {
		System.out.println("method1");
	}
	
	static void method2() {
		System.out.println("method2");
	}

	public static void main(String[] args) {

		// 필드 3개중에서 2개는 각각 독립된 값으로 가지고,
		// 1개의 필드는 동일한 값으로 가진다
		
		ItBook book1 = new ItBook("자바의비밀", 15000);
		ItBook book2 = new ItBook("파이썬의비밀", 13000);
		
//		System.out.println(book1.category);
//		System.out.println(book2.category);
		
		book1.category = "아이티";
//		System.out.println(book1.category);
//		System.out.println(book2.category);
//		
		
		// static 키워드가 붙은 필드는 객체화 후에 메모리에 할당되는것이 아니라
		// 컴파일러가 메모리에 할당하기 때문에 객체화 하지 않아도 사용할수 있다
		System.out.println(ItBook.category2);
		
		book1.methodA();
		book2.methodA();
		
		// category 필드는 book1, boo2 객체가 명시적 초기화를 통해
		// "IT" 값으로 초기화는 되지만 결국 독립된 값으로 사용한다
		
		// book1.category = "아이티" -> book2의 category 는 변경되지 않는다
		
		// category2 는 static 키워드로 인해 heap 메모리의 객체에 할당되는게
		// 아니라 static 영역에 하나의 저장공간으로 할당되므로 모든 객체가 공유해서
		// 사용한다
		
		// 즉, category2 = "자연과학" -> book1, book2 모두 변경
		
		// static 필드 : 클래스명.필드명 
		ItBook.category2 = "자연과학";
		
		book1.methodA();
		book2.methodA();
		
		// static 메소드 : 클래스명.메소드명();
		ItBook.methodB();
		
		
		// method2() 는 같은 static 키워드가 붙어있기 때문에
		// main 메소드에서 객체화 없이 사용이 가능하다
		ClassTest4.method2();
		
		// method1() 은 static 키워드가 없기 때문에
		// 메모리에 할당되는 시점이 달라 객체화 없이 사용이 불가능하다
		ClassTest4 ct = new ClassTest4();
		ct.method1();
		
	
		
		
	}

}
