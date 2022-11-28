import java.util.*;
abstract class the_shape {
	int le, br, r;

	Scanner input = new Scanner(System.in);

	abstract void printArea();

}

class rect extends the_shape {
	void printArea() {
		System.out.println("*_*_* For rectangle *_*_*");
		System.out.print("Enter lenght and breadth: ");
		le = input.nextInt();
		br = input.nextInt();
		System.out.println("The area of ractangle with given dimensions: " + le * br);
	}
}

class trig extends the_shape {
	void printArea() {
		System.out.println("\n*_*_* For Triangle *_*_*");
		System.out.print("Enter Base And Height: ");
		le = input.nextInt();
		br = input.nextInt();
		System.out.println("The area of triangle with given dimensions : " + (le * br) / 2);
	}
}

class circ extends the_shape {
	void printArea() {
		System.out.println("\n*_*_* For Cricle *_*_*");
		System.out.print("Enter the radius: ");
		r = input.nextInt();
		System.out.println("The area of Cricle with given dimensions: " + 3.14f * r * r);
	}
}

public class q9 {
	public static void main(String[] args) {
		rect rec = new rect();
		rec.printArea();

		trig tri = new trig();
		tri.printArea();
		
		circ cri = new circ();
		cri.printArea();
	}
}
