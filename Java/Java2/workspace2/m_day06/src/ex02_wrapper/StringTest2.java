package ex02_wrapper;

public class StringTest2 {

	public static void main(String[] args) {

		// + (연결) 연산자와 append() 의 차이
		// String 클래스와 StringBuffer 클래스의 차이
		// 불변 클래스와 가변 클래스의 차이
		
		// 시작시간
		long startTime1 = System.currentTimeMillis();
		
		// 코드 실행
		String data1 = "";
		
		for (int i = 0; i < 100000; i++) {
			data1 += i;
		}
		
		// 종료시간
		long endTime1 = System.currentTimeMillis();
		
		// 종료시간 - 시작시간
		System.out.println("소요시간 = " + (endTime1 - startTime1));
		
		
		// 시작시간
		long startTime2 = System.currentTimeMillis();
		
		// 코드 실행
		StringBuilder data2 = new StringBuilder();
		
		for (int i = 0; i < 100000; i++) {
			data2.append(i);
		}
		
		// 종료시간
		long endTime2 = System.currentTimeMillis();
		
		// 종료시간 - 시작시간
		System.out.println("소요시간 = " + (endTime2 - startTime2));
		
		
		
		
		
		
		
		
	}

}
