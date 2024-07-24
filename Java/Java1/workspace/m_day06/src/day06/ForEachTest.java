package day06;

import java.util.Scanner;

public class ForEachTest {

	public static void main(String[] args) {

		// for-each 문
		
		String[] ar = {"홍길동", "나훈아", "김철수", "박영희"};
		
		// 일반 for문
		
		for(int i = 0; i < ar.length; i++) {
			System.out.println(ar[i]);
		}
		
		// for-each문
		
		for(String name : ar) {
			System.out.println(name);
		}
		
		// 실습1.
		// 아이디 중복 체크
		// 사용자에게 사용할 아이디를 입력받고, 중복 여부를 판별하기
		// 만약 기존 아이디와 중복된다면 중복 아이디 라고 출력
		// 기존 아이디와 중복되지 않는다면 사용 가능 아이디 라고 출력
		
		String[] idList = {"kim1234", "hong1234", "seo1234"};
		
		Scanner sc = new Scanner(System.in);
		// 입력한 아이디를 저장할 변수
		String id = null;
		// 중복 여부를 저장할 변수
		boolean isDuplicated = false;
		// 출력 메세지를 저장할 변수
		String result = null;
		
		// 사용자에게 아이디를 입력받는다
		System.out.println("아이디를 입력하세요 >>");
		id = sc.next();
		
		
		for(String userId: idList) {
			// 배열안에서 꺼낸 하나의 아이디와 입력한 아이디 일치 여부 판별
			if(userId.equals(id)) {
				isDuplicated = true;
				break;
			}
		}
		
		if(isDuplicated) {
			System.out.println("중복된 아이디 입니다");
		}else {
			System.out.println("사용 가능한 아이디 입니다");
		}
		
		result = isDuplicated ? "중복된 아이디" : "사용 가능한 아이디";
		System.out.println(result);
		


		
		
		
		
		
		
		
		
		
		
	}

}
