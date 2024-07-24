package ex03_collection;

// <> 안에 들어간 글자를 제네릭으로 사용하겠다
public class GenericClass<T> {

	// T 글자가 들어간 자리는 외부에서 알려준 자료형으로 사용하겠다
	T data;

	// 매개변수에서 제네릭 사용
	public GenericClass(T data) {
		super();
		this.data = data;
	}
	
	// 리턴타입에서 제네릭 사용
	public T getData() {
		return data;
	}
	
	
}
