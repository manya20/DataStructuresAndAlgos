class MyRunnable implements Runnable
{
	private final int id;
	public MyRunnable(int id)
	{
		this.id = id;
	}
	public void run()
	{
		for(int i = 10;i > 0 ; i--)
		{
			System.out.println("Thread:" + id + " hi");
			try
			{
				Thread.sleep(100);
			}
			catch(InterruptedException e)
			{
				System.out.println("Exception caught and dealt with");
			}
		}
	}
}

public class ThreadJoinMethodExample
{
	public static void main(String[] arg) 
	{
		
		Thread t1 = new Thread(new MyRunnable(1));
		Thread t2 = new Thread(new MyRunnable(2));
		System.out.println("Strating the threads");
		t1.start();
		t2.start();
		try
		{
			t1.join();
			t2.join();
		}
		catch(InterruptedException e)
		{
			System.out.println("Exception caught and dealt with");
		}
		System.out.println("back in main()");
		
	}
}





