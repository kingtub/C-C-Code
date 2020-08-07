public class Dim2Arr {
	private native int[][] get2DimArr(int size);
	static {
		System.loadLibrary("Dim2Arr");
	}
	
	public static void main(String[] args) {
		int size = 8;
		if(args.length > 0) {
			try {
				size = Integer.parseInt(args[0]);
			} catch(Exception e) {
			}
		}
		int[][] arr = new Dim2Arr().get2DimArr(size);
		System.out.println("Return from C++:");
		for(int i = 0; i < arr.length; i++) {
			for(int j = 0; j < arr[i].length; j++)
			{
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}
}