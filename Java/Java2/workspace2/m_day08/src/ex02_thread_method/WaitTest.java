package ex02_thread_method;

public class WaitTest {

	public static void main(String[] args) {

		WaitThread wt = new WaitThread();
		Thread t1 = new Thread(wt, "t1");
		
		t1.start();
		
		try {
			Thread.sleep(1000);
			wt.notifyMethod();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		
	}

}
