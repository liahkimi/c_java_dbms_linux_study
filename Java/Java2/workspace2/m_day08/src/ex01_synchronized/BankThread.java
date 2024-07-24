package ex01_synchronized;

public class BankThread implements Runnable {

	// 필드(field)
	Bank bank;

	// 생성자(constructor)
	public BankThread(Bank bank) {
		super();
		this.bank = bank;
	}

	// run() 메소드 재정의
	@Override
	public void run() {
		// 가지고 있는 필드 bank에서 1000원씩 5번 인출한다
		for(int i = 0; i < 5; i++){
			// 동기화 처리가 되지 않은 인출 메소드
			// bank.minusMoney(1000);
			// 메소드 동기화 처리가 된 인출 메소드
			bank.minusMoneyWithSyn2(1000);
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
		}
	
	}
	
	
	
	
	
	
	
}
