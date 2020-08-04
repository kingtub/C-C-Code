public class A {
	public static void main(String[] args) {
		System.out.println(new A().getStringFromCpp());
	}
	
	private native String getStringFromCpp();
	
	static {
		System.loadLibrary("A");
	}
}