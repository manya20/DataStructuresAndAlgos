import java.util.concurrent.*;

class MyFactory implements ThreadFactory
{
	public Thread newThread(Runnable r)
	{
		Thread myThread = new Thread(r);
		myThread.setDaemon(true);
		return myThread;
	}
}

class ProducerAndConsumer
{
	static int count = 0;
	boolean produced = false;
	public synchronized void produce()
	{
		while(produced == true)
		{
			try
			{
				wait();
			}
			catch(InterruptedException e)
			{
				System.out.println("Exaception caught and dealt with");
			}
		}
		count++;
		produced = true;
		this.notify();
	}

	public synchronized void consume()
	{
		
		while(produced == false)
		{
			try
			{
				wait();
			}
			catch(InterruptedException e)
			{
				System.out.println("Exaception caught and dealt with");
			}
		}
		System.out.println("Consumer consumed " + count + " !!");
		produced = false;
		this.notify();
		
	}
}

class ProducerThread implements Runnable
{
	public ProducerAndConsumer producer;
	public ProducerThread(ProducerAndConsumer producer)
	{
		this.producer = producer; 
	}
	public void run()
	{
		while(true)
		{
			producer.produce();
		}
	}
}

class ConsumerThread implements Runnable
{
	public ProducerAndConsumer consumer;
	public ConsumerThread(ProducerAndConsumer consumer)
	{
		this.consumer = consumer;
	}
	public void run()
	{
		while(true)
		{
			consumer.consume();
		}
	}
}

public class ProducerAndConsumerUsingSameClass
{
	public static void main(String[] mohit)
	{
		ProducerAndConsumer pc = new ProducerAndConsumer();
		ExecutorService exec = Executors.newCachedThreadPool(new MyFactory());
		exec.execute(new ProducerThread(pc));
		exec.execute(new ConsumerThread(pc));
		try
		{
			Thread.sleep(10);
		}
		catch(InterruptedException e)
		{
			System.out.println("Exception caught and dealt with");	
		}
		
	}
}

















































