import java.util.concurrent.*;

class MyThread implements Runnable
{
	int count = 10;
	private final int id;
	public MyThread(int id)
	{
		this.id = id;
	}
	public String toString()
	{
		return "Thread:" + id + " count:" + count;
	}
	public void run()
	{
		while(count >= 0)
		{
			System.out.println(this);
			count--;
			try
			{
				Thread.sleep(100);
				//Thread.yield();
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}
			
		}
	}
}

public class ThreadsUsingExecutor
{
	public static void main(String[] args)
	{
		
		ExecutorService serv = Executors.newCachedThreadPool();
		System.out.println("Starting the threads");
		for(int i = 0 ; i < 5 ; i++)
		{
			serv.execute(new MyThread(i));
		}
		System.out.println("Done creating Threads");
		serv.shutdown();
		


		/*ExecutorService serv = Executors.newFixedThreadPool(5);
		System.out.println("Starting the threads");
		for(int i = 0 ; i < 7 ; i++)
		{
			serv.execute(new MyThread(i));
		}
		System.out.println("Done creating Threads");
		serv.shutdown();
		*/


		/*
		ExecutorService serv = Executors.newSingleThreadExecutor();
		System.out.println("Starting the threads");
		for(int i = 0 ; i < 5 ; i++)
		{
			serv.execute(new MyThread(i));
		}
		System.out.println("Done creating Threads");
		serv.shutdown();
		*/
	}
}













