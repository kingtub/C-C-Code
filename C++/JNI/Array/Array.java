public class Array {
	static {
		System.loadLibrary("Array");
	}
	
	private native int[] sumAndSquare(int[] arr);
	
	public static void main(String[] args) {
		int[] arr = new int[]{1, 3, 5, 7, 9};
		int[] result = new Array().sumAndSquare(arr);
		System.out.println("sum=" + result[0] + ", square=" + result[1]);
	}
}