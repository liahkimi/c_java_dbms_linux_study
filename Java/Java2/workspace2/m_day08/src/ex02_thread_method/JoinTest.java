package ex02_thread_method;

public class JoinTest {

	public static void main(String[] args) {

		Thread t1 = new Thread(new Thread1(), "t1");
		Thread t2 = new Thread(new Thread1(), "t2");
		
		t1.start();
		t2.start();
		
		try {
			// main 쓰레드가 t1, t2 쓰레드의 작업이
			// 끝나기를 기다린 다음에 main 쓰레드 종료를 출력한다
			t1.join();
			t2.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		System.out.println("main 쓰레드 종료");
		
		
		
	}

}
