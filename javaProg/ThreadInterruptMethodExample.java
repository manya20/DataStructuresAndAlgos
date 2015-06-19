class MyRunnable implements Runnable
{
	public void run()
	{
		try
		{
			while(true)
			{
				System.out.println(this);
				Thread.sleep(50);
			}
		}
		
		catch(InterruptedException e)
			{
				System.out.println("Exception caught and dealt with in run()");
			}
	}
}

public class ThreadInterruptMethodExample
{
	public static void main(String[] arg) 
	{
		Thread t = new Thread(new MyRunnable());
		t.start();
		try
		{
			Thread.sleep(500);
		}
		catch(InterruptedException e)
		{
			System.out.println("Exception caught and dealt with in main()");
		}
		t.interrupt();		
	}
}





