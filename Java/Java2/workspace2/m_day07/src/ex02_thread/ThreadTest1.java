package ex02_thread;

public class ThreadTest1 {

	public static void main(String[] args) {

		// A작업중 5번 출력
		// B작업중 5번 출력
		
		// 싱글 쓰레드일 경우
		
//		for (int i = 0; i < 5; i++) {
//			System.out.println("A작업중..");
//		}
//		
//		for (int i = 0; i < 5; i++) {
//			System.out.println("B작업중..");
//		}
		
		// 멀티 쓰레드일 경우
		
		// 1. Thread 클래스 상속받은 Thread1 클래스 객체화
		Thread1 t1 = new Thread1();
		
		// 2. JVM에게 멀티쓰레드 작업을 요청
		// start() 메소드를 사용하면 JVM이 t1객체 안의 run() 메소드를 사용한다
		t1.start();
			
		// 1. Runnable 인터페이스 구현한 Thread2 클래스 객체화
		Thread2 t2 = new Thread2();
		
		// 2. JVM에게 멀티쓰레드 작업을 요청
//		t2.start(); // Runnable 인터페이스에는 start() 메소드가 존재하지 않는다
		
		Thread t3 = new Thread(t2);
		t3.start();
		
		for (int i = 0; i < 5; i++) {
			System.out.println("A작업중..");
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
		
		
		
		
	}

}
