package ex02_wrapper;

public class StringTest {

	public static void main(String[] args) {

		// == 연산자는 객체의 동일성을 비교하는 연산자인데
		// "a" 객체와 "a" 객체가 동일하다는 결과가 나온다
		
		// string constant pool 에 생성된 String 객체
		String str1 = "a";
		String str2 = "a";
		
		System.out.println(str1 == str2);
		System.out.println(str1.equals(str2));
		
		// heap 에 생성된 String 객체
		String str3 = new String("a");
		
		// 동일성(주소값)을 비교하는 == 연산자의 결과는 false
		System.out.println(str1 == str3);
		// 동등성(값)을 비교하는 equals() 메소드의 결과는 true
		System.out.println(str1.equals(str3));
		
		// 기존 "a" 문자열 값을 가지고 있는 String 클래스의 객체
		System.out.println(str1.hashCode());
		str1 = "b";
		// 기존 객체가 아닌 "b" 문자열 값을 가지고 있는 새로운 객체
		System.out.println(str1.hashCode());
		
		// StringBuffer, StringBuilder 클래스
		// 가변 문자열 클래스 -> 문자열 객체가 가지고 있는 값을 변경할수 있다
		System.out.println("a" + "b");
		
		StringBuffer sb1 = new StringBuffer("a");
		StringBuffer sb2 = new StringBuffer("a");
		
		System.out.println(sb1 == sb2);
		System.out.println(sb1.hashCode());
		System.out.println(sb2.hashCode());
		
		sb1.append("b");
		System.out.println(sb1.hashCode());
		System.out.println(sb1);
		
		
	}

}
