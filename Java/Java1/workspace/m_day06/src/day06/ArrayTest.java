package day06;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class ArrayTest {

	public static void main(String[] args) {

		// 과제1.
		// 사용자에게 양의 정수 3개를 입력받기(1개씩 입력받는다)
		// 단, 음수를 입력하였을 경우 음의 정수를 입력하였습니다 출력하고 다시 입력받기
		// 누적된 양의 정수 개수가 3개가 아니라면 다시 입력받기
		// 누적된 양의 정수 개수가 3개가 된다면 반복을 종료하고 
		// 입력한 3개의 양의 정수를 출력한뒤 프로그램 종료 출력하기
		
		
//		Scanner sc = new Scanner(System.in);
//		// 사용자에게 입력받은 정수를 저장할 변수
//		int num = 0;
//		// 입력한 양의 정수를 저장할 배열
//		int[] ar = new int[3];
//		// 배열의 인덱스 번호를 저장할 변수
//		int idx = 0;
//			
//		while(idx < 3) {
//			// 사용자에게 정수를 입력받는다
//			System.out.println("정수를 입력하세요 >>");
//			num = sc.nextInt();
//			
//			// 양의 정수를 입력했다면
//			if(num > 0) {
//				// 배열의 빈칸에다가 입력한 양의 정수를 저장한다
//				ar[idx] = num;
//				// 다음 칸에 정수를 저장하기 위해 인덱스 번호를 증가시킨다
//				idx++;
//			}else {
//				System.out.println("음의 정수를 입력하였습니다");
//			}
//			
//		}
//		
//		System.out.println("프로그램 종료");
//		
//		for(int i = 0; i < ar.length; i++) {
//			System.out.println(ar[i]);
//		}
		
		
		
		int[] ar = {40,10,30,20};
		
		// Arrays.toString()
		System.out.println(ar);
		
		for(int i=0; i < ar.length; i++) {
			System.out.println(ar[i]);
		}
		
		// 배열안의 모든 요소를 가지고와서 하나의 문자열로 합쳐준다
		System.out.println(Arrays.toString(ar));
		
		// 오름차순 정렬
		Arrays.sort(ar);
		System.out.println(Arrays.toString(ar));
		
		// 내림차순 정렬(Integer 타입으로만 사용 가능하다)
		Integer[] ar2 = {10,20,30};
		
		Arrays.sort(ar2, Comparator.reverseOrder());
		System.out.println(Arrays.toString(ar2));
		
		// 얕은 복사
		
		int num1 = 10;
		int num2 = num1;
		System.out.println(num2);
		
		int[] ar3 = {10,20,30};
		int[] ar4 = ar3;
		
		System.out.println(ar3);
		System.out.println(ar4);
		
		// ar3의 0번째 값을 변경한다
		ar3[0] = 100;
		System.out.println(ar3[0]);
		System.out.println(Arrays.toString(ar3));
		
		// ar3[0] = 100; 으로 참조하고 있는 배열의 0번째 값을 100으로 변경한다
		// ar4도 같은 배열을 참조하고 있기때문에 값이 함께 변경된다
		System.out.println(Arrays.toString(ar4));
		
		
		// 깊은 복사
		int[] ar5 = {20, 30};
		int[] newAr = Arrays.copyOf(ar5, 2);
		
		System.out.println(Arrays.toString(ar5));
		System.out.println(Arrays.toString(newAr));
		
		// 배열 요소의 값을 복사하여 새로운 배열에 채워넣기 때문에
		// 주소값이 다르다!
		System.out.println(ar5);
		System.out.println(newAr);
		
		ar5[0] = 1000;
		System.out.println(newAr[0]);
		
		
		// 기본변수
		int num3 = 10;
		int num4 = num3;
		
		num3 = 20;
		System.out.println(num4);
		
		
		
		
		
	}

}
