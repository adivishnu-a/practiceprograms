class A {
	int i,j;
	void showij() {
		System.out.println("i and j: " +i+ " " +j );
	}
}

class B extends A {
	int k;
	void showk(){
		System.out.println("K: " +k);
	}
	void sum() {
		System.out.println("i+j+k: " +(i+j+k));
	}
}
class simpleinheritance {
	public static void main(String args[]) {
		A superobj = new A();
		B subobj = new B();
		System.out.println("Contents of Superobj: ");
		superobj.showij();
		System.out.println();
		subobj.i = 7;
		subobj.j = 9;
		subobj.k = 9;
		System.out.println("Contents of Subobj : ");
		subobj.showij();
		subobj.showk();
		System.out.println();
		System.out.println("Sum of i j k in subobj : ");
		subobj.sum();
	}
}