package ex03_collection;

public class GenericTest {

	public static void main(String[] args) {

		GenericClass<Integer> intGen = new GenericClass<Integer>(10);
		GenericClass<String> strGen = new GenericClass<>("abc");
		GenericClass<Boolean> boolGen = new GenericClass<>(true);
		
		System.out.println(intGen.data);
		System.out.println(strGen.data);
		System.out.println(boolGen.data);
		
		
	}

}
