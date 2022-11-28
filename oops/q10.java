import java.util.Random;

class ranomnums extends Thread {
	public void run() {
		Random random = new Random();
		for (int i = 0; i < 10; i++) {
			int rand_int = random.nextInt(100);
			System.out.println("*******************************************");
			System.out.println("the random number is: " + rand_int);
			if((rand_int%2) == 0) {
				Thread_for_square sq_Thread = new Thread_for_square(rand_int);
				sq_Thread.start();
			}
			else {
				Thread_for_cube cu_Thread = new Thread_for_cube(rand_int);
				cu_Thread.start();
			}
			try {
				Thread.sleep(1000);
			} 
			catch (InterruptedException ex) {
				System.out.println(ex);
			}
		}
	}
}

class Thread_for_square extends Thread {
	int number;

	Thread_for_square(int rando) {
		number = rando;
	}

	public void run() {
		System.out.println("THE Square of " + number + " equals: " + (number * number));
	}
}

class Thread_for_cube extends Thread {
	int number;

	Thread_for_cube(int rando) {
		number = rando;
	}

	public void run() {
		System.out.println("THE Cube of " + number + " equals: " + number * number * number);
	}
}

public class q10 {
	public static void main(String args[]) {
		ranomnums Thread_for_random = new ranomnums();
		Thread_for_random.start();
	}
}

