package ex02_thread;

public class Thread2 implements Runnable{

	@Override
	public void run() {
		// 멀티쓰레드로 처리하고 싶은 작업을 작성 
		for(int i = 0; i < 5; i++) {
			System.out.println("C작업중...");
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

	
}
