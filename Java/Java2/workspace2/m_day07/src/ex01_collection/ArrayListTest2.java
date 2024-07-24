package ex01_collection;

import java.util.ArrayList;

public class ArrayListTest2 {

	public static void main(String[] args) {

		Item item1 = new Item(1, "item1", 10000);
		Item item2 = new Item(2, "item2", 20000);
		Item item3 = new Item(3, "item3", 30000);
		
		ArrayList<Item> itemList = new ArrayList<>();
		
		// 배열과 달리 요소를 추가하는 만큼 길이가 늘어난다
		itemList.add(item1);
		System.out.println(itemList.size());
		itemList.add(item2);
		System.out.println(itemList.size());
		itemList.add(item3);
		
		System.out.println(itemList);
		
		for(Item item:itemList) {
			System.out.println(item.name);
		}
		
		
		
		
		
		
	}

}
