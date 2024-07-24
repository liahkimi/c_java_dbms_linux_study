package ex02_abstract2;

public class AbstractTest {

	public static void main(String[] args) {

//		Phone phone = new Phone();
//		phone.power();
		
		PineapplePhone pineapple = new PineapplePhone();
		pineapple.powerOn();
		
		// PineapplePhone 타입의 객체를 Phone 타입으로 up casting
		Phone phone2 = new PineapplePhone();
		phone2.powerOn();
		
		
	}

}
