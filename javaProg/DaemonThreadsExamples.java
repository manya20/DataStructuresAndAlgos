import java.util.concurrent.*;

class MyRunnable implements Runnable
{
	final private int id;
	public MyRunnable(int id)
	{
		this.id = id;
	}
	public String toString()
	{
		return "Thread:" + id + " is running";
	}
	public void run()
	{
		while(true)
		{
			System.out.println(this);
			try
			{
				Thread.sleep(50);
			}
			catch(InterruptedException e)
			{
				System.out.println("Exception caught");
			}
		}
	}
}

class MyThreadFactory implements ThreadFactory
{
	public Thread newThread(Runnable r)
	{
		Thread t = new Thread(r);
		t.setDaemon(true);
		return t;
	}
}

public class DaemonThreadsExamples
{
	public static void main(String[] args)
	{
		/*
	
		//Daemon threads using Thread class only
		Thread[] t = new Thread[5];
		System.out.println("Starting the daemon threads");
		for(int i = 0; i < 5; i++)
		{
			t[i] = new Thread(new MyRunnable(i));
			t[i].setDaemon(true);
			t[i].start();
		}
		try
		{
			Thread.sleep(1000);
			System.out.println("Exiting from main()");
		}
		catch(Exception e)
		{
			System.out.println("Exception caught in main()");
		}
	
		*/
		ExecutorService exec = Executors.newCachedThreadPool(new MyThreadFactory());
		System.out.println("Starting daemon threads");
		for(int i = 0 ; i < 5 ; i++)
			exec.execute(new MyRunnable(i));
		try
		{
			Thread.sleep(1000);
		}
		catch(Exception e)
		{
			System.out.println("Exception is caught in main()");
		}
		System.out.println("Exiting from main()");
		
	}
}















