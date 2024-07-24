package ex02_thread_method;

public class InterruptTest {

	public static void main(String[] args) throws InterruptedException {

		Thread t1 = new Thread(new InterThread(), "t1");
		
		t1.start();
		
		// Thread.sleep(1000);
		// t1 쓰레드를 방해한다(InterruptedException)
		t1.interrupt();
		
	}

}
