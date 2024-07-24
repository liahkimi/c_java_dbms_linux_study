package ex01_synchronized;

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

	// 동기화 처리가 된 인출 메소드
	// 메소드 동기화
	synchronized void minusMoneyWithSyn(int money) {
		this.money -= money;
		System.out.println(Thread.currentThread().getName() + "인출. 현재잔고 = " + this.money);
	}

	// 동기화 처리가 된 인출 메소드
	// 블록 동기화
	void minusMoneyWithSyn2(int money) {
		synchronized (this) {
			this.money -= money;
			System.out.println(Thread.currentThread().getName() + "인출. 현재잔고 = " + this.money);
		}
		System.out.println(Thread.currentThread().getName() + "동기화 블럭 밖의 코드");
	}

}
