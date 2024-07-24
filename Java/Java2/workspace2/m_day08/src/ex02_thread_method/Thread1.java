package ex02_thread_method;

public class Thread1 implements Runnable{

	@Override
	public void run() {

		for(int i = 0; i < 5; i++) {
			System.out.println(Thread.currentThread().getName() + "A작업중..");
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
