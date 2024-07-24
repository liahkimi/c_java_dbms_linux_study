package day06;

public class MultiArryTest {

	public static void main(String[] args) {

		// 1차원 배열
		int[] ar = {10, 20, 30};
		
		// 2차원 배열
		int[][] arr = {{1, 2}, {3, 4}};
		
		System.out.println(ar);
		System.out.println(ar[0]);
		
		System.out.println(arr);
		System.out.println(arr[0]);
		
		System.out.println(arr[0][0]);
		System.out.println(arr[0][1]);
		System.out.println(arr[1][0]);
		System.out.println(arr[1][1]);
		
		for(int i = 0; i < arr.length; i++) {
			for(int j = 0; j < arr[i].length; j++) {
				System.out.println(arr[i][j]);
			}
		}
		
		/*
		 * 1. int i = 0;
		 * 2. i < arr.length;
		 * 3. int j = 0;
		 * 4. j < arr[i].length;
		 * 5. System.out.println...
		 * 6. j++
		 * 7. j < arr[i].length;
		 * 8. System....
		 * 9. i++
		 * ...
		 */
		
		
		for(int i = 0; i < arr.length; i++) {
//			System.out.println("i = " + i);
			for(int j = 0 ; j < arr[i].length; j++) {
				System.out.println("i = " + i + ", j = " + j);
			}
		}
		
		// 실습1.
		// for문을 이용하여 아래와 같은 출력결과 만들기
		
		// ****
		// ****
		// ****
		
		// 1. * 문자열이 4번 이어서 출력된다
		// 2. * 문자열이 출력된 다음에는 줄바꿈이 이루어진다
		// 3. 별 4개씩 3줄을 출력한다
		
		for(int i = 0; i < 3; i ++) {
			for(int j = 0; j <4; j++) {
				System.out.print("*");
			}
			System.out.println();
		}
		
		for(int i = 0; i < 3; i++) {
			System.out.println("****");
		}
		
		
		// 실습1.
		// int[] arr = {{1,2},{3,4}};
		// 위의 배열을 아래와 같이 출력결과를 만들기
		
		// 1 2 
		// 3 4 
		
		// arr[0] -> arr[0][1], arr[0][1]
		// arr[1] -> arr[1][0], arr[1][1]
		
		for(int i = 0; i < arr.length; i++) {
			for(int j = 0; j < arr[i].length; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
		
		
		// 과제1.
		
		// *
		// **
		// ***
		// ****
		
		//    *
		//   **
		//  ***
		// ****
		
		// *000 : i = 0 j = ?
		// **00
		// ***0
		// ****
		
		
	}

}
