package ex02_thread_method;

public class InterThread implements Runnable{

	@Override
	public void run() {
		
		// 1. InterruptException을 통한 종료 처리
//		for(int i = 0; i < 5; i ++) {
//			System.out.println("작업중..");
//			try {
//				Thread.sleep(1000);
//			} catch (InterruptedException e) {
//				System.out.println("InterruptedException!");
//				// 쓰레드의 종료를 위한 코드를 작성한다
//				return;
//			}
//		}

		// 2. interrupted()를 통한 종료 처리
		
		for(int i = 0; i < 5; i++) {
			System.out.println("B작업중...");
			if(Thread.interrupted()) {
				System.out.println("interrupted!");
				// 쓰레드의 종료를 위한 코드를 작성한다
				return;
			}
			
		}
		
		
		
		

	}
}
