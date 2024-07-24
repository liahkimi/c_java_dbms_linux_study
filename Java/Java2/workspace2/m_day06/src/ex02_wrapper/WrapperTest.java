package ex02_wrapper;

public class WrapperTest {

	public static void main(String[] args) {

		// boxing : 기본 자료형의 값을 클래스의 객체로
		
		// 예전 방법
		Integer intNum = new Integer(10);
		Integer intNum2 = Integer.valueOf(10);
		// auto-boxing
		Integer intNum3 = 10;
		
		System.out.println(intNum);
		System.out.println(intNum2);
		System.out.println(intNum3);

		// Integer 타입의 객체이기 때문에 메소드가 존재한다
		System.out.println(intNum3.toString());
		// 기본자료형 int의 값이기때문에 메소드가 존재하지 않는다
//		System.out.println(10.toString());
		
		Double doubleNum = 10.7;
		Double doubleNum2 = Double.valueOf(10.3);
		
		// 실수는 정확한 값을 표현하지 못하는 경우가 있어
		// 연산결과가 실제 연산의 값과 다를수 있다
		// 정확한 연산을 하고 싶다면 BigDecimal 클래스 등을 이용한다
		System.out.println(1.0 + 1.32);
		
		// unboxing
		
		int intVar1 = intNum.intValue();
		
		// auto-unboxing
		int intVar2 = intNum3;
		
		System.out.println(intVar1);
		System.out.println(intVar2);
		
		
		
	}

}
