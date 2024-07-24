package ex02_thread_method;

public class WaitThread implements Runnable {

	@Override
	public void run() {

		try {
			waitMethod();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	// 10번 작업 쓰레드의 이름과 작업중이라고 출력한다
	// 5번째 출력할때는 wait!를 출력한후 기다린다
	public synchronized void waitMethod() throws InterruptedException {

		for (int i = 0; i < 10; i++) {
			if (i == 4) {
				System.out.println("wait!");
				wait();
			}

			System.out.println(Thread.currentThread().getName() + " 작업중..");
			Thread.sleep(1000);

		}
	}
	
	// 현재 작업중인 쓰레드 이름과 작업중을 3번 출력하고
	// 대기중인 쓰레드를 깨운다
	public synchronized void notifyMethod() throws InterruptedException {
		
		for (int i = 0; i < 3; i++) {
			System.out.println(Thread.currentThread().getName() + " 작업중..");
			Thread.sleep(1000);

		}
		
		System.out.println("notify!");
		notify();
	}
	
	
	
	
	
	
	

}
