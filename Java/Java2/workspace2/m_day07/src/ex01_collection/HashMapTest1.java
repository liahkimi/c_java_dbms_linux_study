package ex01_collection;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map.Entry;

public class HashMapTest1 {

	public static void main(String[] args) {

		// java.util 패키지에 있어 import 후에 사용한다
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		
		// 추가
		map.put("반 번호", 10);
		map.put("학생수", 30);	
		System.out.println(map);
		
		// 기존에 있는 key로 value를 추가하면
		// 기존 value가 수정된다
		map.put("반 번호", 20);
		System.out.println(map);
		
		// 삭제
		map.put("반 점수", 90);
		
		// key를 통해 key와 value 둘다 삭제한다
		map.remove("반 번호");
		System.out.println(map);
		
		// 길이
		System.out.println(map.size());
		
		// 키 포함 여부
		System.out.println(map.containsKey("반 번호"));
		
		// 값 포함 여부
		System.out.println(map.containsValue(90));
		
		// key만 순차적으로 가져오기
		// map.keySet() : key들만 모아서 Set에 담는다
		// map.keySet().iterator() : 해당 키가 담긴 Set을 iterator로 변환한다
		Iterator<String> keyIter = map.keySet().iterator();
		
		while(keyIter.hasNext()) {
			System.out.println("key = " + keyIter.next());
		}
		
		// value만 순차적으로 가져오기
		Iterator<Integer> valIter = map.values().iterator();
		
		while(valIter.hasNext()) {
			System.out.println("value = " + valIter.next());
		}
		
		// key-value 한쌍으로 순차적으로 가져오기
		// Entry<String, Integer> -> Set<Entry<String, Integer>> 
		// -> Iterator<Entry<String, Integer>>
		
		Iterator<Entry<String, Integer>> mapIter = map.entrySet().iterator();
		
		while(mapIter.hasNext()) {
//			System.out.println("entry = " + mapIter.next());
			Entry<String, Integer> item = mapIter.next();
			System.out.println("entry = " + item);
			System.out.println("entry(key) = " + item.getKey());
			System.out.println("entry(value) = " + item.getValue());
			
		}
		
		
		
		
		
		
	}

}
