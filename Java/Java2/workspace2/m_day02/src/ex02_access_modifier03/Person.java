package ex02_access_modifier03;

public class Person {

	// 필드
	private String name;
	private int age;
	
	// 생성자
	public Person(String name, int age) {
		super();
		setName(name);
		setAge(age);
	}

	// 게터와 세터 자동 생성 단축키
	// alt + shift + s + r
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		// 만약에 올바르지 않은 이름이라면 미정이라는 이름으로 저장한다
		if(name == null) {
			this.name = "미정";
			return;
		}
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		// 만약에 나이가 음수라면 0이라는 나이로 저장한다
		if(age < 0) {
			this.age = 0;
			return;
		}
		this.age = age;
	}
	

	
	
	
	
}
