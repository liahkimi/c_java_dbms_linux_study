package ex01_collection;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map.Entry;

public class HashMapTest2 {

	public static void main(String[] args) {

		
		HashMap<Integer, Item> itemMap = new HashMap<>();
		
		Item item1 = new Item(1, "item1", 10000);
		Item item2 = new Item(2, "item2", 20000);
		Item item3 = new Item(3, "item3", 30000);
		
		itemMap.put(item1.number, item1);
		itemMap.put(item2.number, item2);
		itemMap.put(item3.number, item3);
		
		System.out.println(itemMap);
		
		// Iterator를 통해 데이터 가져오기
		
		Iterator<Entry<Integer, Item>> itemIter = itemMap.entrySet().iterator();
		
		while(itemIter.hasNext()) {
			Entry<Integer, Item> item = itemIter.next();
			System.out.println("itemNumber = " + item.getKey());
			System.out.println("itemName = " + item.getValue().name);
		}
		

		
		
		
		
		
	}

}
