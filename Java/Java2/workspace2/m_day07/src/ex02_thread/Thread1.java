package ex02_thread;

public class Thread1 extends Thread{

	@Override
	public void run() {
		// 멀티 쓰레드로 처리하고 싶은 작업 작성		
		for(int i = 0; i < 5; i++) {
			System.out.println("B작업중..");
			// alt + shift + z
			try {
				// long millis : 1/1000초
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	}

	
}
