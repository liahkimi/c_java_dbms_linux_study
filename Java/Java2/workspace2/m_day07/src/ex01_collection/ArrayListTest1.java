package ex01_collection;

import java.util.ArrayList;
import java.util.List;

public class ArrayListTest1 {

	public static void main(String[] args) {

		// String 자료형의 데이터를 담을 ArrayList
		// java.util 패키지에 있기때문에 import 후에 사용한다
		ArrayList<String> list1 = new ArrayList<String>();
		
		// 추가
		// add(E e) : 새로운 요소를 마지막 자리에 추가한다
		list1.add("A");
		
		System.out.println(list1);
		System.out.println(list1.toString());
		
		list1.add("B");
		System.out.println(list1);
		
		// add(int index, E e) : 새로운 요소를 지정한 인덱스 위치에 추가한다
		list1.add(1, "C");
		System.out.println(list1);
		
		// 수정
		// set(int index, E e) : 지정한 인덱스의 요소를 새로운 요소로 수정한다
		list1.set(1,  "D");
		System.out.println(list1);
		
		// 삭제
		list1.add("F");
		list1.add("E");
		System.out.println(list1);
		
		// remove(int index) : 지정한 위치의 요소 삭제
		list1.remove(0);
		System.out.println(list1);

		// remove(Object e) : 요소가 존재하면 삭제
		list1.remove("안녕");
		System.out.println(list1);
		System.out.println(list1.remove("안녕"));
		
		list1.remove("D");
		System.out.println(list1);
		
		// 조회
		System.out.println(list1.get(0));
		System.out.println(list1.get(1));
		
		// ArrayList에 저장한 여러개의 데이터는 저장공간이 아닌
		// 값으로 가져오기 때문에 할당연산자 왼쪽에서 사용 불가!
//		String msg = list1.get(0);
//		list1.get(0) = "AB";
		
		
		// for문과 ArrayList
		// size() : ArrayList의 길이를 가져온다(데이터의 개수)
		
		for(int i = 0; i < list1.size(); i++) {
			System.out.println(list1.get(i));
		}
		
		// for-each문
		
		ArrayList<Integer> list2 = new ArrayList<>();
		
		list2.add(1); // auto-boxing
		list2.add(2);
		
		// 1(int) -> 1(Integer) -> 1(int)
		
		for(int num : list2) { // auto-unboxing
			System.out.println("num = " + num);
		}
		
		
		// List 인터페이스로 up casting 하여 사용한다
		// 다른 구현 클래스로 유연하게 변경할수 있다
		List<Integer> list3 = new ArrayList<>();
		
	
		
		
	}

}
