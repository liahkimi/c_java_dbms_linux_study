package ex01_interface1;

public interface InterA {

	// 상수(public static final)
	// static 키워드를 사용하면 글씨가 굵어지고, 파란색으로 변경된다
	// final 키워드를 사용할때는 변수명을 대문자로 작성한다(상수)
	
	int DATA1 = 10;
	public static final int DATA2 = 20;
	
	// 추상메소드(public abstract)
	
	void method1();
	public abstract void method2();
	

	
}
