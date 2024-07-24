package ex01_collection;

import java.util.HashSet;
import java.util.Iterator;

public class HashSetTest1 {

	public static void main(String[] args) {

		// java.util 패키지에 있어 import 후에 사용한다
		HashSet<Integer> set1 = new HashSet<Integer>();
		
		// 추가
		set1.add(1);
		set1.add(2);
		set1.add(3);
		
		System.out.println(set1);
		// 중복된 값을 허용하지 않는다
		set1.add(1);
		set1.add(1);
		set1.add(1);
	
		System.out.println(set1);
		
		// 삭제
		// 4(int) -> 4(Integer) -> 4(Object)
		set1.remove(4); // auto-boxing -> up casting
		System.out.println(set1);
		
		set1.remove(3);
		System.out.println(set1);
		
		
		// Iterator
		// java.util 패키지에 있어 import 후에 사용한다
		Iterator<Integer> iter = set1.iterator();
		
		// 다음에 꺼낼 데이터가 있는 동안에
		while(iter.hasNext()) {
			// 다음에 존재하는 데이터를 꺼낸다
			System.out.println(iter.next());
		}
		
		// for-each문	
		for(int num : set1) {
			System.out.println(num);
		}
		
		// 포함여부
		System.out.println(set1.contains(17));
		
		// 길이
		System.out.println(set1.size());
		

		
	}

}
