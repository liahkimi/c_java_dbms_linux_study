package ex01_collection;

import java.util.Objects;

public class Item {
	
	// 필드(field)
	int number;
	String name;
	int price;
	
	// 생성자(constructor)
	public Item(int number, String name, int price) {
		super();
		this.number = number;
		this.name = name;
		this.price = price;
	}

	// toString() 재정의
	@Override
	public String toString() {
		return "Item [number=" + number + ", name=" + name + ", price=" + price + "]";
	}

	@Override
	public int hashCode() {
		return Objects.hash(name, number, price);
	}

	// equals() 재정의
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Item other = (Item) obj;
		return Objects.equals(name, other.name) && number == other.number && price == other.price;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	

}
