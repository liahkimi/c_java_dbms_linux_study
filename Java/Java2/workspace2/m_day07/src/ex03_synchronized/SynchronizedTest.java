package ex03_synchronized;

public class SynchronizedTest {

	public static void main(String[] args) {

		// bank.money = 10000
		Bank bank = new Bank(10000);
		
		Thread bankThread1 = new Thread(new BankThread(bank));
		Thread bankThread2 = new Thread(new BankThread(bank));
		
		// bank.money = 10000
		// 2명이 1000원씩 5번 인출 
		bankThread1.start();
		bankThread2.start();
		
	}

}
