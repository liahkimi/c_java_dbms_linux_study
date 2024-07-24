package ex03_exception;

public class ValidEmailException extends Exception{

	public ValidEmailException(String message) {
		super(message);	
	}
}
