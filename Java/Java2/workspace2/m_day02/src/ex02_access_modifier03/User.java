package ex02_access_modifier03;

public class User {

	// 필드(field)
	// 아이디
	private String id;
	// 비밀번호
	private String pw;
	// 관리자 여부
	private boolean isAdmin;
	
	// 생성자(constructor)
	public User(String id, String pw, boolean isAdmin) {
		super();
		this.id = id;
		this.pw = pw;
		this.isAdmin = isAdmin;
	}
	
	// 관리자 여부는 생성자를 통해서 결정할수 없다
	public User(String id, String pw) {
		super();
		this.id = id;
		this.pw = pw;
	}


	// 메소드(method)
	// id 필드를 가져오는 메소드(getter)
	public String getId() {
		return id;
	}
	// pw 필드를 가져오는 메소드
	public String getPw() {
		return pw;
	}
	// isAdmin 필드를 가져오는 메소드
	public boolean isAdmin() {
		return isAdmin;
	}
	
	// pw 필드에 새로운 값을 저장하는 메소드(setter)
	public void setPw(String pw) {
		this.pw = pw;
	}
	
	// isAdmin 필드에 새로운 값을 저장하는 메소드
	public void updateAdmin() {
		// 아이디가 admin가 일치한다면 관리자로 지정한다
		if(id.equals("admin")) {
			this.isAdmin = true;			
		}
	}
		
	
	
	
	
	
	
	
	
	
	
}
