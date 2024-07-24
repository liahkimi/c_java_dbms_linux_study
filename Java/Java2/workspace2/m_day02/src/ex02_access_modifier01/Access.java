package ex02_access_modifier01;

public class Access {

	// 필드(field)
	
	int defaultData;
	public String publicData;
	protected double protectedData;
	private boolean privateData;
	
	// 생성자(constructor)
	// default 생성자
	Access(int defaultData){
		this.defaultData = defaultData;
	}
	
	// public 생성자
	public Access(String publicData) {
		this.publicData = publicData;
	}
	
	// protected 생성자
	protected Access(double protectedData) {
		this.protectedData = protectedData;
	}
	
	// private 생성자
	private Access(boolean privateData) {
		this.privateData = privateData;
	}

	// 메소드(method)
	
	void defaultMethod() {
		System.out.println("default method");
	}
	
	public void publicMethod() {
		System.out.println("public method");
	}
	
	protected void protectedMethod() {
		System.out.println("protected method");
	}
	
	private void privateMethod() {
		System.out.println("private method");
	}
	

}
