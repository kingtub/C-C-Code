public class S {
	private native void pass(String s);
	static {
		System.loadLibrary("S");
	}
	
	public static void main(String[] args) {
		new S().pass("i am good man");
	}
}