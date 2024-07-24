package ex01_collection;

import java.util.HashSet;

public class HashSetTest2 {

	public static void main(String[] args) {

		// Item 객체의 중복은 어떻게 판단할까..?
		
		HashSet<Item> itemSet = new HashSet<>();
		
		Item item1 = new Item(1, "item1", 10000);
		Item item2 = new Item(1, "item1", 10000);
		Item item3 = new Item(1, "item1", 10000);
		Item item4 = new Item(1, "item1", 10000);
		
		itemSet.add(item1);
		itemSet.add(item2);
		itemSet.add(item3);
		itemSet.add(item4);
		
		// 각각 객체의 주소값이 다르기때문에 중복이 아니어서 값이 추가된다
		System.out.println(itemSet);
		
		// 4개의 객체가 동일한 객체는 아니지만, 필드의 값이 일치하기 때문에
		// 동등한 객체라고 판단하기 위해서 equals() 재정의한다
		// -> equals() 를 재정의했지만, 여전히 중복이 아니라고 판단한다
		
		// equals() 를 통해 동등한 객체라고 판단한다 -> 두 객체를 같다라고 보겠다
		// HashSet안에 2개의 객체가 추가되면 안된다 -> 중복된것으로 판단해야 한다
		
		// HashSet은 두 객체의 중복여부를 판단할때 equals()와 hashCode()를
		// 모두 사용하기 때문에 만약에 equals()를 재정의했다면 반드시 hashCode() 도 같이 재정의한다
		
		
	
		
		
		
		
		
		
	}

}
