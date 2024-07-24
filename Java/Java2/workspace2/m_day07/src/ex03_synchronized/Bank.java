package ex03_synchronized;

public class Bank {

	// 필드(field)
	// 사용자의 잔액
	private int money;

	// 생성자(constructor)
	public Bank(int money) {
		super();
		this.money = money;
	}
	
	// 인출 메소드
	void minusMoney(int money) {
		this.money -= money;
		System.out.println(Thread.currentThread().getName() + "인출. 현재잔고 = " + this.money);
	}
	
	
	
	
}
